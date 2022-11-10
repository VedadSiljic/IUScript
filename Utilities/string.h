#include "List.h"

class string {
protected:
  List<char> str;

public:
  string(char *charArray = NULL) {
    if (charArray)
      while (*charArray)
        str.Add(*charArray++);
  }

  string &operator=(char *charArray) {
    this->str.clear();
    while (*charArray)
      this->str.Add(*charArray++);
    return *this;
  }

  string(string &objToCopy) { this->str = objToCopy.str; }

  string &operator=(string &objToCopy) {
    this->str = objToCopy.str;
    return *this;
  }

  ~string() { str.clear(); }

  char &operator[](const sizeT index) { return this->str.get(index); }
  sizeT lenght() { return this->str.length(); }

  string operator+(string &objToAdd){
    this->str.operator+(objToAdd.str);
    return *this;
  }

  string &operator+=(string &objToAdd){
    this->str.operator+=(objToAdd.str);
    return *this;
  }

};