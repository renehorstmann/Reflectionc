#include "reflectionc/parse.h"
#include "reflectionc/filter.h"

#include "test_helper.h"

int main() {

    char *file = open_file_as_string("filetest1.txt");
    if(!file)
        error("couldnt open file");

    HrFunctionArray functions = hr_parse_file_text(ToStrViu(file));
    if(functions.size != 6)
        error("hr_parse_file_text failed");

    functions = hr_filter_function_non_static(functions, true);
    if(functions.size != 6)
        error("hr_filter_function_non_static failed");

    functions = hr_filter_function_name_prefix(functions, "hr_", true);
    if(functions.size != 6)
        error("hr_filter_function_name_prefix failed");



    return 0;
}


