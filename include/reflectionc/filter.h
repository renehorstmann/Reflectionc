#ifndef REFLECTIONC_FILTER_H
#define REFLECTIONC_FILTER_H

#include <stdbool.h>

#include "parsetypes.h"
#include "types.h"

HrFunctionArray hr_filter_function_non_static(HrFunctionArray array, bool free_array);

HrFunctionArray hr_filter_function_name_prefix(HrFunctionArray array, const char *name_prefix, bool free_array);

hr_parameterarray hr_filter_parameter_name_prefix(hr_parameterarray array, const char *name_prefix);

hr_parameterarray hr_filter_parameter_diff(hr_parameterarray a, hr_parameterarray b);

#endif //REFLECTIONC_FILTER_H

