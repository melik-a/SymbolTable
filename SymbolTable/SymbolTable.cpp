﻿// SymbolTable.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "HashMap.h"
#include "Pair.h"
#include "ListTable.h"
#include <string>
#include <forward_list>
#include <unordered_map>
#include "Hash.h"
#include <typeinfo>


void hash_test();
void hash_map_general_test();
void hash_map_load_test();
void list_test();

void testingConstructors();


int main()
{
	setlocale(LC_ALL, "RUS");
	//hash_map_general_test();
	//hash_map_load_test();


	list_test();

	/*HashMap<int, double> map;
	std::cout << map;
	int i;
	std::string s;
	double d;
	

	std::pair<int, double> my_pair(i,d);*/


	system("pause");
	return 0;
}

