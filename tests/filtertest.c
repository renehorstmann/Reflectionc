#include "reflectionc/parse.h"
#include "reflectionc/sort.h"
#include "reflectionc/filter.h"

#include "test_helper.h"

int main() {

    char *file = open_file_as_string("filetest1.txt");
    if(!file)
        return error("couldnt open file");

    hr_ParsedFunctionArray parsed_functions = hr_parse_file(ToStrViu(file));
    if(parsed_functions.size != 6)
        return error("hr_parse_file failed");

    hr_FunctionArray functions = hr_get_function_array_without_paramaters(&parsed_functions);

    functions = hr_filter_function_non_static(functions, true);
    if(functions.size != 6)
        return error("hr_filter_function_non_static failed");

    functions = hr_filter_function_name_prefix(functions, "hr_", true);
    if(functions.size != 6)
        return error("hr_filter_function_name_prefix failed");



    return 0;
}


