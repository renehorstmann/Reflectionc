#include <stdio.h>
#include <string.h>

#include "reflectionc/types.h"
#include "reflectionc/parse.h"
#include "test_helper.h"

int main() {

    char *filetext = open_file_as_string("file_example.h");
    if (!filetext)
        exit(EXIT_FAILURE);

    HrParsedFunctionArray res = hr_parse_file(ToStrViu(filetext));

    for (int f = 0; f < res.size; f++) {
        hr_parsedfunction function = res.array[f];
        printf("\nFunction[%d]: <%s>:\n", f, function.name);
        printf("return type: <%s>\n", function.return_type);
        for (int p = 0; p < function.parameters_size; p++) {
            hr_parsedparameter param = function.parameters[p];
            printf("parameter[%d]: name <%s>, type <%s>\n", p, param.name, param.type);
        }
        printf("info:\n");
        printf("info text: <%s>\n", function.info.text);
        printf("info return: <%s>\n", function.info.return_info);
        printf("info error: <%s>\n", function.info.error_info);
        for (int p = 0; p < function.info.parameter_infos_size; p++) {
            hr_parsedparameterinfo param_info = function.info.parameter_infos[p];
            printf("info parameter[%d]: name <%s>, def_val <%s>, info <%s>\n",
                   p, param_info.name, param_info.default_value, param_info.info);
        }
    }

    return 0;
}
