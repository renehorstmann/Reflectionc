
#include "reflectionc/utilc/alloc.h"

#include "reflectionc/types.h"

void hr_FunctionArray_kill(hr_FunctionArray *self) {
    Free0(self->array);
    self->size = 0;
}
