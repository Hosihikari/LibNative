#include <istream>
#include <string>
#include <vector>

extern "C" {
#pragma region std::string
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
#pragma endregion std::string

#pragma region std::vector
std::vector<char>* std_vector_new() { return new std::vector<char>(); }
void std_vector_delete(std::vector<char>* vec) { delete vec; }
void std_vector_push_back(std::vector<char>* vec, char* c, int length) {
    while (length-- > 0) {
        vec->push_back(*(c++));
    }
}
char* std_vector_data(std::vector<char>* vec) { return vec->data(); }
int std_vector_size(std::vector<char>* vec) { return vec->size(); }
void* std_vector_at(std::vector<char>* vec, int index) {
    return &vec->at(index);
}
void* std_vector_front(std::vector<char>* vec) { return &vec->front(); }
void* std_vector_back(std::vector<char>* vec) { return &vec->back(); }
void std_vector_pop_back(std::vector<char>* vec) { vec->pop_back(); }
void std_vector_clear(std::vector<char>* vec) { vec->clear(); }
#pragma endregion std::vector
#pragma region std::istream
struct membuf : std::streambuf {
    membuf(char* begin, char* end) { this->setg(begin, begin, end); }
};
void std_istream_new(char* buffer, int length, std::istream** stream,
                     membuf** sbuf) {
    *sbuf = new membuf(buffer, buffer + length);
    *stream = new std::istream(*sbuf);
}
void std_istream_delete(std::istream* stream, membuf* sbuf) {
    delete stream; 
    delete sbuf;
}
bool std_istream_read(std::istream* stream, char* buffer, int length) {
    stream->read(buffer, length);
    return stream->good();
}
#pragma endregion
}