
#include "reflectionc/utilc/alloc.h"

#include "reflectionc/parsetypes.h"

void hr_parsed_function_array_kill(HrParsedFunctionArray *self) {
    Free0(self->array);
    self->size = 0;
}

//void hr_ParsedTypeDeclarationArray_kill(hr_ParsedTypeDeclarationArray *self) {
//    Free0(self->array);
//    self->size = 0;
//}

//void hr_ParsedStruct_kill(hr_ParsedStruct *self) {
//    hr_ParsedTypeDeclarationArray_kill(&self->members);
//}

