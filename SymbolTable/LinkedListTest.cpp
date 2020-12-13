#include <iostream>
#include "ListTable.h"


void list_test()
{
	std::cout << "\n--- list test started ---" << std::endl;
	
	LinkedList<std::string, std::string> test_list;
	std::cout << "\n--- list created ---" << std::endl;
	std::cout << "test_list: " << typeid(test_list).name() << std::endl;

	std::cout << "\n--- adding elements ---" << std::endl;
	test_list.push_front("one","info1");

	Node<std::string, std::string> node("lvalue_node", "info2");
	test_list.push_front(node);

	test_list.push_front(Node<std::string, std::string>("rvlaue_node", "info3"));
	
	std::string a = "lvalue_strs", b = "info4";
	test_list.push_front(a,b);

	std::cout << "\n--- empty check ---" << std::endl;
	std::cout << "empty = " << test_list.empty() << std::endl;

	std::cout << "\n--- list size ---" << std::endl;
	std::cout << "size = " << test_list.get_size() << std::endl;

	std::cout << "\n--- search check ---" << std::endl;

	auto s_node = test_list.search(node);
	if (s_node)
		std::cout << "search result = " << node._name << " - " << node._info << std::endl;

	s_node = test_list.search(Node<std::string, std::string>("rvlaue_node", "info3"));
	if (s_node)
		std::cout << "search result = " << node._name << " - " << node._info << std::endl;
	s_node = test_list.search(a);
	if (s_node)
		std::cout << "search result = " << node._name << " - " << node._info << std::endl;
	s_node = test_list.search("one");
	if (s_node)
		std::cout << "search result = " << node._name << " - " << node._info << std::endl;
	
	std::cout << "\n--- last number of comparisons ---" << std::endl;
	std::cout << "number of comparisons = " << test_list.get_last_number_of_comparisons() << std::endl;

	std::cout << "\n--- operator[] check ---" << std::endl;
	if (test_list["one"])
		std::cout << "test_list[\"one\"]->_name =" << test_list["one"]->_name << " - " << test_list["one"]->_info << std::endl;

	std::cout << "\n--- removing element ---" << std::endl;
	test_list.pop_front();

	std::cout << "\n--- print check ---" << std::endl;
	test_list.print();

	std::cout << "\n--- clear check ---" << std::endl;
	test_list.clear();
}