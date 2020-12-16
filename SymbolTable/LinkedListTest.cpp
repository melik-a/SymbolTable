#include <vector>
#include <iostream>

template <typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& vec)
{
	os << " [ ";
	for (auto& el : vec)
	{
		os << el << " ";
	}
	os << "] ";
	return os;
}


#include "ListTable.h"

void list_int_test();
void list_string_test();
void list_vector_test();


void list_test()
{
	std::cout << "------ list test begins ------" << std::endl;
	list_int_test();
	list_string_test();
	list_vector_test();
	std::cout << "------ list test is over ------" << std::endl;
}


void list_int_test()
{
	std::cout << "\n--- list int test begins ---" << std::endl;

	LinkedList<int, int> test_list;


	std::cout << "\n--- list created ---" << std::endl;
	std::cout << "test_list: " << typeid(test_list).name() << std::endl;


	std::cout << "\n--- adding elements ---" << std::endl;

	test_list.push_front(1, 1);

	Node<int, int> node(2, 2);
	test_list.push_front(node);

	test_list.push_front(Node<int, int>(3, 3));

	int a = 4, b = 4;
	test_list.push_front(a, b);


	std::cout << "\n--- empty check ---" << std::endl;
	std::cout << "empty = " << test_list.empty() << std::endl;


	std::cout << "\n--- list size ---" << std::endl;
	std::cout << "size = " << test_list.get_size() << std::endl;


	std::cout << "\n--- search check ---" << std::endl;

	auto s_node = test_list.search(node);
	if (s_node)
		std::cout << "search result = " << s_node->_name << " - " << s_node->_info << std::endl;
	s_node = test_list.search(Node<int, int>(3, 3));
	if (s_node)
		std::cout << "search result = " << s_node->_name << " - " << s_node->_info << std::endl;
	s_node = test_list.search(a);
	if (s_node)
		std::cout << "search result = " << s_node->_name << " - " << s_node->_info << std::endl;
	s_node = test_list.search(1);
	if (s_node)
		std::cout << "search result = " << s_node->_name << " - " << s_node->_info << std::endl;


	std::cout << "\n--- last number of comparisons ---" << std::endl;
	std::cout << "number of comparisons = " << test_list.get_last_number_of_comparisons() << std::endl;


	std::cout << "\n--- operator[] check ---" << std::endl;
	if (test_list[1])
		std::cout << "test_list[1] = " << test_list[1]->_name << " - " << test_list[1]->_info << std::endl;
	if (test_list[a])
		std::cout << "test_list[" << a << "] = " << test_list[a]->_name << " - " << test_list[a]->_info << std::endl;


	std::cout << "\n--- removing element ---" << std::endl;
	test_list.pop_front();


	std::cout << "\n--- print check ---" << std::endl;
	test_list.print();


	std::cout << "\n--- operator << check ---" << std::endl;
	std::cout << test_list << std::endl;


	std::cout << "\n--- clear check ---" << std::endl;
	test_list.clear();


	std::cout << "\n--- list int test is over ---\n" << std::endl;
}


void list_string_test()
{
	std::cout << "\n--- list string test begins ---" << std::endl;
	
	LinkedList<std::string, std::string> test_list;


	std::cout << "\n--- list created ---" << std::endl;
	std::cout << "test_list: " << typeid(test_list).name() << std::endl;


	std::cout << "\n--- adding elements ---" << std::endl;
	
	test_list.push_front("rvalue_strs","info1");

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
		std::cout << "search result = " << s_node->_name << " - " << s_node->_info << std::endl;
	s_node = test_list.search(Node<std::string, std::string>("rvlaue_node", "info3"));
	if (s_node)
		std::cout << "search result = " << s_node->_name << " - " << s_node->_info << std::endl;
	s_node = test_list.search(a);
	if (s_node)
		std::cout << "search result = " << s_node->_name << " - " << s_node->_info << std::endl;
	s_node = test_list.search("one");
	if (s_node)
		std::cout << "search result = " << s_node->_name << " - " << s_node->_info << std::endl;
	

	std::cout << "\n--- last number of comparisons ---" << std::endl;
	std::cout << "number of comparisons = " << test_list.get_last_number_of_comparisons() << std::endl;


	std::cout << "\n--- operator[] check ---" << std::endl;
	if (test_list["one"])
		std::cout << "test_list[\"one\"] = " << test_list["one"]->_name << " - " << test_list["one"]->_info << std::endl;
	if (test_list[a])
		std::cout << "test_list["<< a << "] =" << test_list[a]->_name << " - " << test_list[a]->_info << std::endl;


	std::cout << "\n--- removing element ---" << std::endl;
	test_list.pop_front();


	std::cout << "\n--- print check ---" << std::endl;
	test_list.print();


	std::cout << "\n--- operator << check ---" << std::endl;
	std::cout << test_list << std::endl;


	std::cout << "\n--- clear check ---" << std::endl;
	test_list.clear();


	std::cout << "\n--- list string test is over ---" << std::endl;
}


void list_vector_test()
{
	std::cout << "\n--- list vector test begins ---" << std::endl;
	
	using vec_str = std::vector<std::string>;
	LinkedList<vec_str, vec_str> test_list;
	
	
	std::cout << "\n--- list created ---" << std::endl;
	std::cout << "test_list type: " << typeid(test_list).name() << std::endl;

	
	std::cout << "\n--- adding elements ---" << std::endl;

	test_list.push_front(Node<vec_str, vec_str>({ "first", "rvalue", "node" }, { "second", "rvalue", "node" }));
	
	Node<vec_str, vec_str> node({ "first", "lvalue", "node" }, { "second", "lvalue", "node" });
	test_list.push_front(node);

	test_list.push_front({ "first", "rvalue", "vec_str" }, { "second", "rvalue", "vec_str" });

	vec_str a = { "first", "lvalue", "vec_str" }, b = { "second", "lvalue", "vec_str" };
	test_list.push_front(a, b);


	std::cout << "\n--- empty check ---" << std::endl;
	std::cout << "empty = " << test_list.empty() << std::endl;


	std::cout << "\n--- list size ---" << std::endl;
	std::cout << "size = " << test_list.get_size() << std::endl;


	std::cout << "\n--- search check ---" << std::endl;

	auto s_node = test_list.search(Node<vec_str, vec_str>({ "first", "rvalue", "node" }, { "second", "rvalue", "node" }));
	if (s_node)
		std::cout << "search result = " << s_node->_name << " - " << s_node->_info << std::endl;
	s_node = test_list.search(node);
	if (s_node)
		std::cout << "search result = " << s_node->_name << " - " << s_node->_info << std::endl;
	s_node = test_list.search(a);
	if (s_node)
		std::cout << "search result = " << s_node->_name << " - " << s_node->_info << std::endl;
	s_node = test_list.search({ "first", "rvalue", "vec_str" });
	if (s_node)
		std::cout << "search result = " << s_node->_name << " - " << s_node->_info << std::endl;


	std::cout << "\n--- last number of comparisons ---" << std::endl;
	std::cout << "number of comparisons = " << test_list.get_last_number_of_comparisons() << std::endl;


	std::cout << "\n--- operator[] check ---" << std::endl;
	
	auto oper_node = test_list[{ "first", "rvalue", "vec_str" }];
	if (oper_node)
		std::cout << "test_list[{ \"first\", \"rvalue\", \"vec_str\" }] = " << 
											oper_node->_name << " - " << oper_node->_info << std::endl;

	oper_node = test_list[a];
	if (oper_node)
		std::cout << "test_list[" << a << "] = " << oper_node->_name << " - " << oper_node->_info << std::endl;


	std::cout << "\n--- removing element ---" << std::endl;
	test_list.pop_front();


	std::cout << "\n--- print check ---" << std::endl;
	test_list.print();


	std::cout << "\n--- operator << check ---" << std::endl;
	std::cout << test_list << std::endl;


	std::cout << "\n--- clear check ---" << std::endl;
	test_list.clear();


	std::cout << "\n--- list vector test is over ---" << std::endl;
}

