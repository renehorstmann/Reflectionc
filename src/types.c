
#include "reflectionc/utilc/alloc.h"

#include "reflectionc/types.h"

void hr_function_array_kill(HrFunctionArray *self) {
    Free0(self->array);
    self->size = 0;
}
