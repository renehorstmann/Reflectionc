#ifndef REFLECTIONC_PARSETYPES_H
#define REFLECTIONC_PARSETYPES_H

#include "base.h"

typedef struct {
    hr_shortstring name;
    hr_shortstring type;
} hr_parsedparameter;

typedef struct {
    hr_shortstring name;
    hr_shortstring default_value;
    hr_string info;
} hr_parsedparameterinfo;

typedef struct {
    hr_longstring text;
    hr_string return_info;
    hr_string error_info;
    hr_parsedparameterinfo parameter_infos[HR_MAX_PARAMETERS];
    size_t parameter_infos_len;
} hr_parsedinfo;

typedef struct {
    hr_shortstring name;
    hr_shortstring return_type;
    hr_parsedparameter parameters[HR_MAX_PARAMETERS];
    size_t parameters_len;
    hr_parsedinfo info;
} hr_parsedfunction;

typedef struct {
    hr_parsedfunction *array;
    size_t size;
} hr_ParsedFunctionArray;

//typedef struct {
//    shortstring name;
//    shortstring type;   // char (*)() for function ptr?, char [10] for arrays
//} hr_ParsedTypeDeclaration;
//
//typedef struct {
//    hr_ParsedTypeDeclaration *array;
//    size_t size;
//} hr_ParsedTypeDeclarationArray;
//
//typedef struct {
//    shortstring name;
//    longstring info;
//    hr_ParsedTypeDeclarationArray members;
//} hr_ParsedStruct;

void hr_ParsedFunctionArray_kill(hr_ParsedFunctionArray *self);

//void hr_ParsedTypeDeclarationArray_kill(hr_ParsedTypeDeclarationArray *self);
//
//void hr_ParsedStruct_kill(hr_ParsedStruct *self);

#endif //REFLECTIONC_PARSETYPES_H

