// SymbolTable.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "HashMap.h"
#include <string>

int main()
{
	const std::string a = "_first_pair_";
	std::string b = "_second_pair_";
	Pair<std::string, std::string> pair(a, b);
	pair.getPair();
    std::cout << "Hello World!\n";
	return 0;
}

