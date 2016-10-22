
// default includes
#include "Global/Macros.h"
CLANG_DIAG_OFF(mismatched-tags)
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
GCC_DIAG_OFF(missing-declarations)
GCC_DIAG_OFF(uninitialized)
GCC_DIAG_UNUSED_LOCAL_TYPEDEFS_OFF
#include <shiboken.h> // produces many warnings
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <typeresolver.h>
#include <typeinfo>
#include "natronengine_python.h"

#include "int3dparam_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyParameter.h>


// Native ---------------------------------------------------------

void Int3DParamWrapper::pysideInitQtMetaTypes()
{
}

Int3DParamWrapper::~Int3DParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Int3DParamFunc_get(PyObject* self, PyObject* args, PyObject* kwds)
{
    Int3DParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (Int3DParamWrapper*)((::Int3DParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_INT3DPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Int3DParam.get(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:get", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: get(QString)const
    // 1: get(double,QString)const
    if (numArgs == 0) {
        overloadId = 0; // get(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // get(double,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // get(double,QString)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // get(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Int3DParamFunc_get_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // get(const QString & view) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Int3DParam.get(): got multiple values for keyword argument 'view'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                        goto Sbk_Int3DParamFunc_get_TypeError;
                }
            }
            ::QString cppArg0 = QLatin1String("Main");
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // get(QString)const
                Int3DTuple* cppResult = new Int3DTuple(const_cast<const ::Int3DParamWrapper*>(cppSelf)->get(cppArg0));
                pyResult = Shiboken::Object::newObject((SbkObjectType*)SbkNatronEngineTypes[SBK_INT3DTUPLE_IDX], cppResult, true, true);
            }
            break;
        }
        case 1: // get(double frame, const QString & view) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Int3DParam.get(): got multiple values for keyword argument 'view'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Int3DParamFunc_get_TypeError;
                }
            }
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QLatin1String("Main");
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // get(double,QString)const
                Int3DTuple* cppResult = new Int3DTuple(const_cast<const ::Int3DParamWrapper*>(cppSelf)->get(cppArg0, cppArg1));
                pyResult = Shiboken::Object::newObject((SbkObjectType*)SbkNatronEngineTypes[SBK_INT3DTUPLE_IDX], cppResult, true, true);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Int3DParamFunc_get_TypeError:
        const char* overloads[] = {"unicode = QLatin1String(\"Main\")", "float, unicode = QLatin1String(\"Main\")", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Int3DParam.get", overloads);
        return 0;
}

static PyObject* Sbk_Int3DParamFunc_set(PyObject* self, PyObject* args, PyObject* kwds)
{
    Int3DParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (Int3DParamWrapper*)((::Int3DParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_INT3DPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Int3DParam.set(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Int3DParam.set(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:set", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: set(int,int,int,QString)
    // 1: set(int,int,int,double,QString)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // set(int,int,int,QString)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 1; // set(int,int,int,double,QString)
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
                overloadId = 1; // set(int,int,int,double,QString)
            }
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
            overloadId = 0; // set(int,int,int,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Int3DParamFunc_set_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // set(int x, int y, int z, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Int3DParam.set(): got multiple values for keyword argument 'view'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                        goto Sbk_Int3DParamFunc_set_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // set(int,int,int,QString)
                // Begin code injection

                cppSelf->set(cppArg0,cppArg1,cppArg2);

                // End of code injection


            }
            break;
        }
        case 1: // set(int x, int y, int z, double frame, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Int3DParam.set(): got multiple values for keyword argument 'view'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                        goto Sbk_Int3DParamFunc_set_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            double cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // set(int,int,int,double,QString)
                // Begin code injection

                cppSelf->set(cppArg0,cppArg1,cppArg2,cppArg3);

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Int3DParamFunc_set_TypeError:
        const char* overloads[] = {"int, int, int, unicode = QLatin1String(\"All\")", "int, int, int, float, unicode = QLatin1String(\"All\")", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Int3DParam.set", overloads);
        return 0;
}

static PyMethodDef Sbk_Int3DParam_methods[] = {
    {"get", (PyCFunction)Sbk_Int3DParamFunc_get, METH_VARARGS|METH_KEYWORDS},
    {"set", (PyCFunction)Sbk_Int3DParamFunc_set, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Int3DParam_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Int3DParam_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Int3DParam_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.Int3DParam",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             0,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             0,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_Int3DParam_traverse,
    /*tp_clear*/            Sbk_Int3DParam_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Int3DParam_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
    /*tp_free*/             0,
    /*tp_is_gc*/            0,
    /*tp_bases*/            0,
    /*tp_mro*/              0,
    /*tp_cache*/            0,
    /*tp_subclasses*/       0,
    /*tp_weaklist*/         0
}, },
    /*priv_data*/           0
};
} //extern

static void* Sbk_Int3DParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Param >()))
        return dynamic_cast< ::Int3DParam*>(reinterpret_cast< ::Param*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Int3DParam_PythonToCpp_Int3DParam_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Int3DParam_Type, pyIn, cppOut);
}
static PythonToCppFunc is_Int3DParam_PythonToCpp_Int3DParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Int3DParam_Type))
        return Int3DParam_PythonToCpp_Int3DParam_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Int3DParam_PTR_CppToPython_Int3DParam(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Int3DParam*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Int3DParam_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_Int3DParam(PyObject* module)
{
    SbkNatronEngineTypes[SBK_INT3DPARAM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Int3DParam_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "Int3DParam", "Int3DParam*",
        &Sbk_Int3DParam_Type, &Shiboken::callCppDestructor< ::Int3DParam >, (SbkObjectType*)SbkNatronEngineTypes[SBK_INT2DPARAM_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Int3DParam_Type,
        Int3DParam_PythonToCpp_Int3DParam_PTR,
        is_Int3DParam_PythonToCpp_Int3DParam_PTR_Convertible,
        Int3DParam_PTR_CppToPython_Int3DParam);

    Shiboken::Conversions::registerConverterName(converter, "Int3DParam");
    Shiboken::Conversions::registerConverterName(converter, "Int3DParam*");
    Shiboken::Conversions::registerConverterName(converter, "Int3DParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Int3DParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::Int3DParamWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_Int3DParam_Type, &Sbk_Int3DParam_typeDiscovery);


    Int3DParamWrapper::pysideInitQtMetaTypes();
}
