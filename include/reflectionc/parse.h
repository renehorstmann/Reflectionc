#ifndef REFLECTIONC_PARSE_H
#define REFLECTIONC_PARSE_H

#include "utilc/strviu.h"

#include "types.h"


hr_parameterinfo hr_parse_parameter_info_text(strviu viu);

hr_info hr_parse_info_text(strviu viu);

char *hr_parse_type(strviu viu);

hr_parameter hr_parse_parameter(strviu viu);

hr_function hr_parse_function(strviu info, strviu definition);

HrFunctionArray hr_parse_file_text(strviu filetext);

HrFunctionArray hr_parse_file(const char *file);

#endif //REFLECTIONC_PARSE_H

