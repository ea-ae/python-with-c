#define PY_SSIZE_T_CLEAN
#include <Python.h>



static PyObject *hello(PyObject* self, PyObject* args) {
    const char* command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return nullptr;
}
