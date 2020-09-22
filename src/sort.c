#include <string.h>

#include "reflectionc/utilc/alloc.h"

#include "reflectionc/sort.h"

hr_parameterarray hr_get_parameters(const hr_parsedfunction *function) {
    hr_parameterarray res = {0};
    if(function->parameters_size > 0) {
        res.size = function->parameters_size;
        for(size_t p=0; p < res.size; p++) {
            strcpy(res.array[p].name, function->parameters[p].name);
            strcpy(res.array[p].type, function->parameters[p].type);
            for(size_t i=0; i<function->info.parameter_infos_size; i++) {
                if(strcmp(res.array[p].name, function->info.parameter_infos[i].name) == 0) {
                    strcpy(res.array[p].default_value, function->info.parameter_infos[i].default_value);
                    strcpy(res.array[p].info, function->info.parameter_infos[i].info);
                }
            }
        }
    }
    return res;
}

hr_function hr_get_function_without_paramaters(const hr_parsedfunction *function) {
    hr_function res = {0};
    strcpy(res.c_name, function->name);
    strcpy(res.out_name, function->name);
    strcpy(res.info, function->info.text);
    strcpy(res.error_info, function->info.error_info);
    strcpy(res.return_parameter.type, function->return_type);
    strcpy(res.return_parameter.info, function->info.return_info);
    strcpy(res.return_parameter.name, "return");
    return res;
}

HrFunctionArray hr_get_function_array_without_paramaters(const HrParsedFunctionArray *array) {
    HrFunctionArray res = {0};
    if(array->size>0) {
        res.array = New0(hr_function, (res.size = array->size));
        for(size_t i=0; i<array->size; i++)
            res.array[i] = hr_get_function_without_paramaters(&array->array[i]);
    }
    return res;
}
