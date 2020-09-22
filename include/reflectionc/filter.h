#ifndef REFLECTIONC_FILTER_H
#define REFLECTIONC_FILTER_H

#include <stdbool.h>

#include "types.h"
#include "types.h"

HrFunctionArray hr_filter_function_non_static(HrFunctionArray array, bool free_array);

HrFunctionArray hr_filter_function_name_prefix(HrFunctionArray array, const char *name_prefix, bool free_array);

#endif //REFLECTIONC_FILTER_H

