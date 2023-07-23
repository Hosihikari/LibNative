#include <string>

std::string* std_string_new() { return new std::string(); }
std::string* std_string_new_str(const char* s) { return new std::string(s); }
void std_string_delete(std::string* str) { delete str; }
int std_string_length(std::string* str) { return str->size(); }
void std_string_append(std::string* str, const char* s) { str->append(s); }
void std_string_append_std_string(std::string* str, const std::string* s) {
    str->append(*s);
}
void std_string_clear(std::string* str, const char* s) { str->clear(); }
const char* std_string_data(std::string* str) { return str->data(); }
