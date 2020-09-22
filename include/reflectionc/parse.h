#ifndef REFLECTIONC_PARSE_H
#define REFLECTIONC_PARSE_H

#include "utilc/strviu.h"

#include "types.h"


HrParameterInfo_s hr_parse_parameter_info_text(strviu viu);

HrInfo_s hr_parse_info_text(strviu viu);

char *hr_parse_type(strviu viu);

HrParameter_s hr_parse_parameter(strviu viu);

HrFunction_s hr_parse_function(strviu info, strviu definition);

HrFunctionArray hr_parse_file_text(strviu filetext);

HrFunctionArray hr_parse_file(const char *file);

#endif //REFLECTIONC_PARSE_H

