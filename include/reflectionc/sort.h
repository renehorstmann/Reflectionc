#ifndef REFLECTIONC_SORT_H
#define REFLECTIONC_SORT_H

#include "parsetypes.h"
#include "types.h"

hr_parameterarray hr_get_parameters(const hr_parsedfunction *function);

hr_function hr_get_function_without_paramaters(const hr_parsedfunction *function);

HrFunctionArray hr_get_function_array_without_paramaters(const HrParsedFunctionArray *array);

#endif //REFLECTIONC_SORT_H

