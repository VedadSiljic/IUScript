#include "./Utilities/List.h"
#include "./Utilities/string.h"
#include <fstream>
#include <iostream>

std::string read(std::string input) { return input; }

std::string eval(std::string input) { return input; }

std::string print(std::string input) { return input; }

std::string rep(std::string input) {
  std::string ast = read(input);
  std::string result = eval(ast);
  return print(result);
}

template <typename VT> void printList(List<VT> &listToPrint) {
  for (ListItterator<VT> i = listToPrint; !i.outside(); i++)
    std::cout << *i << " ";
  std::cout << std::endl << std::endl;
}
int main() {
  List<int> List1;
  char *someText = "abc";
  for (unsigned int i = 0; i < 5; i++)
    List1.Add(i);

  try {
    List<int> List2 = List1;
    List2.Remove();
    List2 = List1;
    List1.Add(4);
    List2[0] = 9;
    printList(List1);
    printList(List2);
    List1 += List2;
    std::cout << "-> ";
    printList(List1);
    std::cout << "DONE USING CLASS'S";
    string test(someText);
    
    std::cout << test[0];

  } catch (const char *e) {
    std::cout << e;
  }
  return 0;
}