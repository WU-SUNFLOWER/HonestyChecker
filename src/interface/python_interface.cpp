#include <Python.h>
#include "HonestyChecker.h"
#include "Token.h"
#include "Text.h"
#include "Lang.h"
#include "Tokenizer.h"
#include "Comparer.h"
#include "LangCpp.h"
#include "LangPython.h"
#include <vector>

void callTokenizer(
    HonestyChecker::Tokenizer& tokenizer, 
    std::vector<HonestyChecker::Text>& texts, 
    const char* code
) {
    tokenizer.initialize(code);

    size_t begin = tokenizer.vector().size();
    size_t end = begin + tokenizer.run();
    texts.push_back({tokenizer.vector(), begin, end});

}

static PyObject* compare(PyObject* self, PyObject* args) {

    PyObject* lang_type = nullptr;
    PyObject* new_text = nullptr;
    PyObject* old_texts = nullptr;

    const char* lang_type_string = nullptr;
    const char* new_text_string = nullptr;
    const char* old_text_string = nullptr;

    HonestyChecker::Lang* language = nullptr;

    std::vector<HonestyChecker::Token> tokenVector = {
        HonestyChecker::Token::None
    };
    std::vector<HonestyChecker::Text> texts;

    if (!PyArg_ParseTuple(args, "OOO", 
        &lang_type, &new_text, &old_texts)
    ) {
        return nullptr;
    }

    if (!lang_type || !new_text || !old_texts) {
        return nullptr;
    }

    // check argument "lang_type"
    if (!PyUnicode_Check(lang_type)) {
        PyErr_SetString(PyExc_TypeError, 
            "'lang_type' argument must be a string");
        return nullptr;
    }

    lang_type_string = PyUnicode_AsUTF8(lang_type);
    if (lang_type_string == nullptr) {
        PyErr_SetString(PyExc_ValueError, 
            "Failed to convert argument 'lang_type' to C string");
        return nullptr;
    }

    if (strcmp(lang_type_string, "C") == 0) {
        language = HonestyChecker::LangCpp::getInstance();
    }
    else if (strcmp(lang_type_string, "C++") == 0) {
        language = HonestyChecker::LangCpp::getInstance();
    }
    else if (strcmp(lang_type_string, "Python3") == 0) {
        language = HonestyChecker::LangPython::getInstance();
    }
    else {
        PyErr_SetString(PyExc_ValueError, 
            "Unknown language type");
        return nullptr;
    }
    HonestyChecker::Tokenizer tokenizer(tokenVector, language);

    // check argument "new_text"
    if (!PyUnicode_Check(new_text)) {
        PyErr_SetString(PyExc_TypeError, 
            "'new_text' argument must be a string");
        return nullptr;
    }

    new_text_string = PyUnicode_AsUTF8(new_text);
    if (new_text_string == nullptr) {
        PyErr_SetString(PyExc_ValueError, 
            "Failed to convert argument 'new_text' to C string");
        return nullptr;
    }
    callTokenizer(tokenizer, texts, new_text_string);

    // get iterator object from old_texts
    PyObject* iterator = PyObject_GetIter(old_texts);
    if (iterator == nullptr) {
        PyErr_SetString(PyExc_ValueError, 
            "Failed to get iterator from 'old_texts'");
        return nullptr;
    }

    // process each item
    PyObject* old_text = nullptr;
    while ((old_text = PyIter_Next(iterator))) {
        if (!PyUnicode_Check(old_text)) {
            // Since iterator is never nullptr at this point
            Py_DECREF(iterator);  
            // Use Py_XDECREF as old_text could be nullptr or have an error
            Py_XDECREF(old_text); 
            PyErr_SetString(PyExc_TypeError, 
                "the item of 'old_text' argument must be a string");
            return nullptr;
        }

        old_text_string = PyUnicode_AsUTF8(old_text);
        if (old_text_string == nullptr ) {
            // Since iterator is never nullptr at this point
            Py_DECREF(iterator);  
            // Use Py_XDECREF as old_text could be nullptr or have an error
            Py_XDECREF(old_text); 
            PyErr_SetString(PyExc_ValueError, 
                "Failed to convert the item of 'new_texts' to C string");
            return nullptr;
        }
        callTokenizer(tokenizer, texts, old_text_string);
    }  
    // Decrease the ref count of iterator when done
    Py_DECREF(iterator);

    HonestyChecker::Comparer comparer(tokenVector, texts, language);
    return PyFloat_FromDouble(comparer.run());
}

static PyMethodDef MyMethods[] = {
    {"compare", compare, METH_VARARGS, "HonestyChecker interface"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef mymodule = {
    PyModuleDef_HEAD_INIT,   // PyModuleDef_HEAD_INIT 是头部初始化宏
    "libHonestyChecker",     // 模块的名称
    nullptr,                    // 模块文档字符串（可为空）
    -1,                      // 模块的状态保留 
    MyMethods,               // 模块方法表
    nullptr,                    // m_slots
    NULL,                    // m_traverse
    NULL,                    // m_clear
    NULL,                    // m_free
};

/*
typedef struct PyModuleDef{
  PyModuleDef_Base m_base;
  const char* m_name;
  const char* m_doc;
  Py_ssize_t m_size;
  PyMethodDef *m_methods;
  struct PyModuleDef_Slot* m_slots;
  traverseproc m_traverse;
  inquiry m_clear;
  freefunc m_free;
} PyModuleDef;
*/

PyMODINIT_FUNC PyInit_libHonestyChecker(void) {
    return PyModule_Create(&mymodule);
}