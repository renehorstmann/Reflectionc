#ifndef REFLECTIONC_TYPES_H
#define REFLECTIONC_TYPES_H

#include "base.h"

// int cnt -> .name="cnt", .type="int"
typedef struct {
    hr_shortstring name;
    hr_shortstring type;
} HrParameter_s;

// @param cnt=10: counter value -> .name="cnt", .default_value="10", .info="counter value"
// @param flag: boolean flag -> .name="flag", .default="", .info="boolean flag"
typedef struct {
    hr_shortstring name;
    hr_shortstring default_value;
    hr_string info;
} HrParameterInfo_s;

// This function divides a with b.
// @param a: value a
// @param b: value b
// @return: div of a / b
// @error: raises SIGFPE if b==0
// -> .text="This function divides a with b.", .return_info="div of a/b", .error_info="raises SIGFPE if b==0
typedef struct {
    hr_longstring text;
    hr_string return_info;
    hr_string error_info;
    HrParameterInfo_s parameter_infos[HR_MAX_PARAMETERS];
    size_t parameter_infos_size;
} HrInfo_s;

// static   const int *get_foo(); -> .name="get_foo", .return_type="static const int *"
typedef struct {
    hr_shortstring name;
    hr_shortstring return_type;
    HrParameter_s parameters[HR_MAX_PARAMETERS];
    size_t parameters_size;
    HrInfo_s info;
} HrFunction_s;

typedef struct {
    HrFunction_s *array;
    size_t size;
} HrFunctionArray;

void hr_function_array_kill(HrFunctionArray *self);

#endif //REFLECTIONC_TYPES_H

