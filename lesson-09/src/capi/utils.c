#include <stdio.h>
#include <stdlib.h>

#include <Python.h>

PyObject* utils_sum(PyObject* self, PyObject* args)
{
    PyObject* list_obj;
    int max_len;
    if (!PyArg_ParseTuple( args, "Oi", &list_obj, &max_len))
    {
        printf("ERROR: Failed to parse arguments\n");
        return NULL;
    }
    long list_len = PyList_Size(list_obj);
    long res = 0;
    for (int i = 0; i < list_len && i < max_len; ++i)
    {
        PyObject* item = PyList_GetItem(list_obj, i);
        res += PyLong_AsLong(item);
    }
    return Py_BuildValue("i", res);
}

int fibonacci(int n)
{
    if (n < 2)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

PyObject* utils_fibonacci(PyObject* self, PyObject* args)
{
    int n;
    if (!PyArg_ParseTuple( args, "i", &n))
    {
        printf("ERROR: Failed to parse arguments\n");
        return NULL;
    }
    return Py_BuildValue("i", fibonacci(n));
}

static PyMethodDef methods[] = {
    { "sum", utils_sum, METH_VARARGS, "sum of elements of the list"},
    { "fibonacci", utils_fibonacci, METH_VARARGS, "get n-th element of fibonacci sequence"},
    { NULL, NULL, 0, NULL}
};

static struct PyModuleDef utilsmodule = {
    PyModuleDef_HEAD_INIT, "utils",
    NULL, -1, methods
};

PyMODINIT_FUNC PyInit_utils(void)
{
    return PyModule_Create( &utilsmodule);
}
