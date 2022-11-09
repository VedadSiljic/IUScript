#include <iostream>
#include <string>
#include <fstream>

std::string read(std::string input) {
    return input;
}

std::string eval(std::string input) {
    return input;
}

std::string print (std::string input) {
    return input;
}

std::string rep(std::string input) {
    std::string ast = read(input);
    std::string result = eval(ast);
    return print(result);
}

int main() {

    std::ifstream main;
    main.open("main.ius");
    if (!main.is_open()) {
        std::cout << "main.ius is missing.";
        return 1;
    }
    std::string input;
    while(!main.eof()) {
        std::cout << "<user> ";
        std::getline(main, input);
        std::cout << rep(input) << std::endl;
    }

    return 0;
}