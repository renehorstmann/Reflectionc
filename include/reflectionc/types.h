#ifndef REFLECTIONC_TYPES_H
#define REFLECTIONC_TYPES_H

#include <stdbool.h>
#include <stdlib.h>


#include "base.h"


typedef struct {
    hr_shortstring name;
    hr_shortstring type;
    hr_shortstring default_value;
    hr_string info;
    bool is_input;  // todo: could also be an enum IN, OUT, INOUT, OPT, ERROR, ...
    bool is_output;
} hr_parameter;

typedef struct {
    hr_parameter array[32];
    size_t size;
} hr_parameterarray;

typedef struct {
    hr_shortstring c_name;
    hr_shortstring out_name;
    hr_longstring info;
    hr_string error_info;
    hr_parameter return_parameter;
    hr_parameterarray parameters;
} hr_function;

typedef struct {
    hr_function *array;
    size_t size;
} hr_FunctionArray;

//typedef struct {
//    shortstring name;
//    longstring info;
//    hr_function constructor;
//    hr_function destructor;
//    hr_function methods[64];
//    size_t methods_len;
//} hr_Class;


void hr_FunctionArray_kill(hr_FunctionArray *self);

#endif //REFLECTIONC_TYPES_H

