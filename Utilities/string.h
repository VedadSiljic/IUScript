#include "list.h"

class string {
protected:
  List<char> str;

public:
  string(char *charArray = NULL) {
    if (charArray)
      while (*charArray)
        str.Add(*charArray++);
  }

  string(string &objToCopy) { this->str = objToCopy.str; }

  string &operator=(string &objToCopy) {
    this->str = objToCopy.str;
    return *this;
  }
  ~string() { str.clear(); }
}