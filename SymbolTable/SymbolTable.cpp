// SymbolTable.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "HashMap.h"
#include "Pair.h"
#include "ListTable.h"
#include <string>
#include <forward_list>
#include <unordered_map>
#include "Hash.h"

int main()
{
	std::forward_list<int> l;
	setlocale(LC_ALL, "RUS");
	//srand(time(NULL));
	//HashMap<std::string, std::string> my_map;

	std::string m = "melik";
	
	Hash<std::string> my_hash;
	size_t h = my_hash(m);
	std::cout << "hash = " << h << std::endl;
	std::cout << "hash = " << h << std::endl;
	std::cout << "hash = " << h << std::endl;
	std::cout << "hash = " << h << std::endl;
	
	std::cout << "sec_hash = " << my_hash("kilem") << std::endl;
	std::cout << "int_hash = " << Hash<int>{}(30) << std::endl;
	std::cout << "char_hash = " << Hash<char>{}('a') << std::endl;
	/*std::cout << "hash = " << std::hash<std::string>{}(m) << std::endl;
	std::cout << "hash = " << std::hash<std::string>{}(m) % 222 << std::endl;

	std::cout << "hash = " << std::hash<std::string>{}("kilem") << std::endl;*/




	system("pause");
	return 0;
}

