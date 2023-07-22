#include <string>
std::string* std_string_new() { return new std::string(); }
void std_string_delete(std::string* str) { delete str; }
int std_string_length(std::string* str) { return str->size(); }
void std_string_append(std::string* str, const char* s) { str->append(s); }
const char* std_string_c_str(std::string* str) { return str->c_str(); }