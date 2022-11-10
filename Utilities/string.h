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

  ~string() { str.clear(); }
}