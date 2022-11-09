#include <iostream>
#include <string>
#include <fstream>
#include "./Utilities/List.h"

List<char> read(List<char> &input)
{

    List<List<char>> commands;

    return input;
}

List<char> eval(List<char> &input)
{
    return input;
}

List<char> print(List<char> &input)
{
    return input;
}

List<char> rep(List<char> &input)
{
    try
    {
        List<char> ast = read(input);
        //List<char> result = eval(ast);
        //return print(result);
        return input;
    }
    catch (char *e)
    {
        std::cout << "Error: \n";
        while (*e++)
            std::cout << *(--e);
    }
}

int main()
{

    std::ifstream main;
    List<char> input;
    char temp;
    main.open("main.ius");

    if (!main.is_open())
    {
        std::cout << "main.ius is missing.";
        return 1;
    }

    while (!main.eof())
    {
        main >> temp;
        if (temp != ';')
            input.Add(temp);
        else
        {
            std::cout << "<user> ";
            for (ListItterator<char> i = input; !i.outside(); i++)
                std::cout << *i;
            std::cout << std::endl;
            try
            {
                rep(input);
            }
            catch (char *e)
            {
                std::cout << "Error: \n";
                while (*e++)
                    std::cout << *(--e);
            }
            while (input.length())
            {
                input.Remove();
            }
        }
    }

    return 0;
}