#ifndef REFLECTIONC_PARSE_H
#define REFLECTIONC_PARSE_H

#include "utilc/strviu.h"

#include "parsetypes.h"


hr_parsedparameterinfo hr_parse_parameter_info_text(strviu viu);

hr_parsedinfo hr_parse_info_text(strviu viu);

char *hr_parse_type(strviu viu);

hr_parsedparameter hr_parse_parameter(strviu viu);

hr_parsedfunction hr_parse_function(strviu info, strviu definition);

//hr_ParsedTypeDeclaration hr_parse_type_declaration(strviu viu);

//hr_ParsedStruct hr_parse_struct(strviu info, strviu definition);

hr_ParsedFunctionArray hr_parse_file(strviu filetext);

#endif //REFLECTIONC_PARSE_H

