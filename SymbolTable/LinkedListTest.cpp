#include <iostream>
#include "ListTable.h"


void list_test()
{
	LinkedList test_list;

	test_list.append("one");
	test_list.append("two");
	test_list.append("three");
	test_list.append("10");
	test_list.append("20");
	test_list.append("30");

	std::cout << "empty = " << test_list.empty() << std::endl;

	Node* node = test_list.search("20");

	node->key = "poluchilos";

	test_list.remove();

	test_list.clear();
}