#include <iostream>
#include <string>

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

    std::string input;
    while(true) {
        std::cout << "<user> ";
        if (!std::getline(std::cin, input))
            break;
        std::cout << rep(input) << std::endl;
    }

    return 0;
}