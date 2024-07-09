#include "HonestyChecker.h"
#include "Comparer.h"
#include "ForwardRefMaker.h"
#include "util.h"
#include <cassert>

using namespace HonestyChecker;

Comparer::Comparer(std::vector<Token>& vec, std::vector<Text>& texts, Lang* lang) :
    _token_vector(vec), _texts(texts), _lang(lang)
{
    ForwardRefMaker preprocessor(texts, vec, lang);
    _forward_reference = preprocessor.run();
}

Comparer::~Comparer() {
    delete[] _forward_reference;
}

double Comparer::run() {
    size_t total = 0;
    Text& subject = _texts[0];
    size_t begin = subject.begin();
    size_t end = subject.end();
    size_t i0 = 0;
    while (i0 + HonestyChecker::MinRunSize < end) {
        size_t result = lcs(subject, i0);
        i0 += result > 0 ? result : 1;
        total += result;
    }
    return 1.0 * total / (end - begin + 1);
}

size_t Comparer::lcs(Text& subject, size_t i0) {

    size_t i1 = _forward_reference[i0];
    while (i1 && i1 < subject.end()) {
        i1 = _forward_reference[i1];
    }

    size_t bestSize = 0;
    size_t begin = subject.end();
    size_t end = _texts.back().end() - 1;
    for (; i1 && Util::inRange(i1, begin, end); i1 = _forward_reference[i1]) {
        // determine which interval i1 falls in
        size_t lowTextIdx = 0;
        size_t highTextIdx = _texts.size() - 1;
        Text* interval = nullptr;
        while (lowTextIdx <= highTextIdx) {
            size_t mid = (lowTextIdx + highTextIdx) >> 1;
            Text& temp = _texts[mid];
            if (i1 < temp.begin()) {
                highTextIdx = mid - 1;
            }
            else if (i1 >= temp.end()) {
                lowTextIdx = mid + 1;
            }
            else {
                interval = &temp;
                break;
            }
        }
        assert(interval != nullptr);

        size_t j0, j1;

        size_t betterSize = bestSize == 0 ? HonestyChecker::MinRunSize : (bestSize + 1);
        j0 = i0 + betterSize - 1;
        j1 = i1 + betterSize - 1;
        // check whether we can get a result which length not less than betterSize
        if (j0 < subject.end() && j1 < interval->end()) {
            size_t cnt = betterSize - HonestyChecker::MinRunSize;
            while (cnt > 0 && _token_vector[j0] == _token_vector[j1]) {
                --cnt, --j0, --j1;
            }
            if (cnt > 0) {
                continue;
            }
        }
        else {
            continue;
        }

        // ok, let's see whether we can match more tokens.
        size_t newSize = betterSize;
        j0 = i0 + betterSize;
        j1 = i1 + betterSize;
        while (j0 < subject.end() && j1 < interval->end() && _token_vector[j0] == _token_vector[j1]) {
            ++j0, ++j1, ++newSize;
        }

        /* Offer the run to the Language module which may
           reject it or may cut its tail.
        */
        while (newSize > 1 && _lang->isNotFinal(_token_vector[i0 + newSize - 1])) {
            --newSize;
        }

        if (newSize > bestSize) bestSize = newSize;
    }


    return bestSize;
}
