#include <stdlib.h>
#include <string.h>

#include "reflectionc/utilc/dynarray.h"
#include "reflectionc/utilc/alloc.h"

#include "reflectionc/filter.h"


DynArray(int, IntArray, int_array)


static HrFunctionArray apply_indices_function_array(HrFunctionArray array, IntArray indices) {
    HrFunctionArray res = {0};
    if (indices.size > 0) {
        res.array = New0(HrFunction_s, (res.size = indices.size));
        for (size_t i = 0; i < indices.size; i++)
            res.array[i] = array.array[indices.array[i]];
    }
    return res;
}

HrFunctionArray hr_filter_function_non_static(HrFunctionArray array, bool free_array) {
    IntArray indices = {0};
    int_array_set_capacity(&indices, array.size);

    for (size_t i = 0; i < array.size; i++) {
        if (strstr(array.array[i].return_type, "static") == NULL)
            int_array_push(&indices, i);
    }

    HrFunctionArray res = apply_indices_function_array(array, indices);
    int_array_kill(&indices);
    if (free_array)
        hr_function_array_kill(&array);
    return res;
}


HrFunctionArray hr_filter_function_name_prefix(HrFunctionArray array, const char *name_prefix, bool free_array) {
    IntArray indices = {0};
    int_array_set_capacity(&indices, array.size);

    for (size_t i = 0; i < array.size; i++) {
        if (strncmp(array.array[i].name, name_prefix, strlen(name_prefix)) == 0)
            int_array_push(&indices, i);
    }

    HrFunctionArray res = apply_indices_function_array(array, indices);
    int_array_kill(&indices);
    if (free_array)
        hr_function_array_kill(&array);
    return res;
}
