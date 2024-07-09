#include "Tokenizer.h"
#include "Lang.h"
#include <cassert>
#include <iostream>

using namespace HonestyChecker;

Tokenizer::Tokenizer(const char* text, size_t text_length, std::vector<Token>& target, Lang* lang)
    : _text(text), _target(target), _text_length(text_length), _is_at_begin_of_line(true), _lang(lang)
{

    assert(lang != nullptr);

    _matrix_accept = lang->getAcceptMatrix();
    _matrix_base = lang->getBaseMatrix();
    _matrix_chk = lang->getCheckMatrix();
    _matrix_def = lang->getDefaultMatrix();
    _matrix_ec = lang->getEquivalenceClassMatrix();
    _matrix_meta = lang->getMetaMatrix();
    _matrix_nxt = lang->getNextMatrix();

    _keywords = lang->getKeywords();
    _preprocess_commands = lang->getPreprocessCommands();

    _matched_text_buffer_size = 32;
    _matched_text = new char[_matched_text_buffer_size]();

    setStartState(0);

    _token_count = 0;
}

Tokenizer::~Tokenizer() {
    delete[] _matched_text;
}

void Tokenizer::setupMatchedText() {

    int matchedRangeSize = _currentTextPos - _beginTextPos;
    if (_matched_text_buffer_size <= matchedRangeSize) {
        while (_matched_text_buffer_size <= matchedRangeSize) {
            _matched_text_buffer_size <<= 1;
        }
        delete[] _matched_text;
        _matched_text = new char[_matched_text_buffer_size]();
    }

    strncpy(_matched_text, &_text[_beginTextPos], matchedRangeSize);
    _matched_text[matchedRangeSize] = '\0';
    _matched_text_length = strlen(_matched_text);

    //_backup_char = _text[_currentTextPos];

    if (_matched_text_length > 0) {
        setBOL(_matched_text[_matched_text_length - 1] == '\n');
    }
}

void Tokenizer::setStartState(int state) {
    _startState = 1 + 2 * state;
}

void Tokenizer::recordToken(Token token) {
    _target.push_back(token);
    ++_token_count;
}

void Tokenizer::recordCharacter(char ch) {
    _target.push_back(Token(ch));
    ++_token_count;
}

void Tokenizer::recordEOL() {
    //_target.push_back(Token::EndOfLine);
}

#define CharToSubscript(ch) (static_cast<size_t>(static_cast<unsigned char>((ch))))

void Tokenizer::backToPreviousState() {
    _currentTextPos = _beginTextPos;

    _currentState = _startState;
    if (_is_at_begin_of_line) ++_currentState;

    while (_text[_currentTextPos] != '\0') {
        int offset = _matrix_ec[CharToSubscript(_text[_currentTextPos])];
        if (_matrix_accept[_currentState]) {
            _lastAcceptedState = _currentState;
            _lastAcceptedCurrentPos = _currentTextPos;
        }
        while (_matrix_chk[_matrix_base[_currentState] + offset] != _currentState) {
            _currentState = _matrix_def[_currentState];
            if (_currentState >= _lang->getMagicNumber1()) {
                offset = _matrix_meta[offset];
            }
        }
        _currentState = _matrix_nxt[_matrix_base[_currentState] + offset];
        ++_currentTextPos;
    }

}

void HonestyChecker::Tokenizer::printVector(size_t begin, size_t end, FILE* file) const {
    for (size_t i = begin; i < end; ++i) {
        _target[i].print(file);
    }
    putchar('\n');
}

Token Tokenizer::getTokenFromIdfList(const char* idf, const Idf idf_list[], size_t list_length, Token default_token) {
    int first = 0;
    int last = (int)list_length - 1;

    while (first < last) {
        int middle = (first + last) >> 1;
        int result = strcmp(idf, idf_list[middle].id_tag);
        if (result > 0) {
            first = middle + 1;
        }
        else if (result < 0) {
            last = middle;
        }
        else {
            return idf_list[middle].id_tr;
        }
    }
    return default_token;
}

size_t Tokenizer::run() {
    _currentTextPos = 0;
    _beginTextPos = 0;

    _lastAcceptedState = 0;
    _lastAcceptedCurrentPos = 0;

    bool isFirstIteration = true;

    while (_currentTextPos < _text_length) {

        if (!isFirstIteration) {
            //_text[_currentTextPos] = _backup_char;
            _beginTextPos = _currentTextPos;
        }
        isFirstIteration = false;

        _currentState = _startState;
        if (_is_at_begin_of_line) ++_currentState;

Label_Match:
        do {
            int offset = _matrix_ec[CharToSubscript(_text[_currentTextPos])];
            if (_matrix_accept[_currentState]) {
                _lastAcceptedState = _currentState;
                _lastAcceptedCurrentPos = _currentTextPos;
            }
            while (_matrix_chk[_matrix_base[_currentState] + offset] != _currentState) {
                _currentState = _matrix_def[_currentState];
                if (_currentState >= _lang->getMagicNumber1()) {
                    offset = _matrix_meta[offset];
                }
            }
            _currentState = _matrix_nxt[_matrix_base[_currentState] + offset];
            ++_currentTextPos;
        } while (_matrix_base[_currentState] != _lang->getMagicNumber2());

Label_Find_Action:
        int action = _matrix_accept[_currentState];
        if (action == 0) {
            _currentTextPos = _lastAcceptedCurrentPos;
            _currentState = _lastAcceptedState;
            action = _matrix_accept[_currentState];
        }
        assert(action != 0);

        setupMatchedText();

Label_Do_Action:
        DispatchingActionResult result = _lang->dispatchActionForTokenizer(this, action);
        switch (result) {
            case DispatchingActionResult::Halt: {
                return _token_count;
            }
            case DispatchingActionResult::FindActionAgain:
                goto Label_Find_Action;
                break;
            case DispatchingActionResult::Default:
                break;
            default:
                printf("Unknown dispatching action result");
                exit(-1);
                break;
        }

    }
    
    return _token_count;

}