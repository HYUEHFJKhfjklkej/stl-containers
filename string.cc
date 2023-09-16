#include <cstring>
#include <iostream>
#include <memory>

namespace stl {
class string {
  std::unique_ptr<char[]> buf;
  size_t sz;
  size_t cap;
  size_t len;

 public:
  string() {}
  string(const char* str) {
    len = strlen(str) + 1;
    buf = std::make_unique<char[]>(len);
    strcpy(buf.get(), str);
  }
  const char& operator[](const size_t& it) {
    if (it < 0 || it >= (len - 1)) throw "bad index";
    return buf[it];
  }
  friend std::ostream& operator<<(std::ostream& out, const string& str) {
    if (str.buf) out << str.buf.get();
    return out;
  }
};
}  // namespace stl

int main() {
  stl::string b{"123"};
  std::cout << b[2];
  return 0;
}