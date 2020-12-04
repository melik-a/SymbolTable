// SymbolTable.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "HashMap.h"
#include "Pair.h"
#include "ListTable.h"
#include <string>
#include <forward_list>


int main()
{
	std::forward_list<int> l;
	setlocale(LC_ALL, "RUS");
	

	LinkedList melik;
	melik.append("hpesh");
	melik.append("dnar");
	melik.append("heb");
	melik.append("10");
	melik.append("20");
	melik.append("30");
	std::cout << "empty = " << melik.empty() << std::endl;

	Node* node = melik.search("20");

	node->key = "poluchilos";

	melik.remove();

	melik.clear();


	system("pause");
	return 0;
}

