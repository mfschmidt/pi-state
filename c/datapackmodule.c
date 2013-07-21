#include "datapackmodule.h"

//------------------------------------------------------------------------------
// Implementation

static PyObject * datapack_syscall(PyObject *self, PyObject *args)
{
        const char *command;
        int sts;

        if (!PyArg_ParseTuple(args, "s", &command)) {
                return NULL;
        }
        sts = system(command);
        if (sts < 0) {
                PyErr_SetString(PyExc_SystemError, "The command failed on the system.");
                return NULL;
        }
        return Py_BuildValue("i", sts);
}

//------------------------------------------------------------------------------
// Define methods available to Python

static PyMethodDef DatapackMethods[] = {
        {"syscall", datapack_syscall, METH_VARARGS, "Execute a shell command."},
        {NULL, NULL, 0, NULL} /* sentinel ? */
};

//------------------------------------------------------------------------------
// Initialization

PyMODINIT_FUNC initdatapack(void)
{
        (void) Py_InitModule("datapack", DatapackMethods);
}

//------------------------------------------------------------------------------
// main

int main(int argc, char *argv[])
{
        Py_SetProgramName(argv[0]);
        Py_Initialize();
        initdatapack();
        return 0;
}


