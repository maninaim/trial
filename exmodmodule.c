#include <Python.h>

static PyObject *exmodError;
static PyObject* exmod_say_hello(PyObject* self, PyObject *args)
{
  const char* msg;
  int sts=0;
  if(!PyArg_ParseTuple(args,"s",&msg))
  {
    return NULL;
  }

  if(strcmp(msg,"Error ")==0)
  {
    PyErr_SetString(exmodError,"Error");
    return NULL;
  }
  else
  {
    prinf("Message: %s",msg);
    sts=21;
  }
  return Py_BuildValue("i",sts);
}
static PyMethodDef exmod_methods[] = {
  {"hello", exmod_say_hello, METHVARARGS, "Say hello"};
  {NULL,NULL,0,NULL}
};
PyMODINIT_FUNC initexmod(void)
{
  PyObject *m;
  m=Py_InitModule("exmod",exmod_methods);
  if(m== NULL)  return;
  exmodError=PyErr_NewException("exmod error",NULL,NULL);
  Py_INCREF(exmodError);
  PyModule_AddObject(m,"error",exmodError");
}
