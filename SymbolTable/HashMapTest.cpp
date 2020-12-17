#include "HashMap.h"

void hash_map_general_test()
{
	std::cout << "--- hash map test start ---" << std::endl;
	

	HashMap<std::string, std::string> table(2);
	std::cout << "\n--- table created ---" << std::endl;

	std::cout << "\n--- insert check ---" << std::endl;
	
	// lavalue key and value insert
	std::string ran = "random";
	std::string word = "word";
	table.insert(ran, word);
	
	// rvalue key and value insert
	table.insert("one", "pen");
	table.insert("two", "three");
	
	// lvalue pair insert
	Pair<std::string, std::string> lvalue_pair("lvalue", "pair");
	table.insert(lvalue_pair);

	// rvalue pair insert
	table.insert(Pair<std::string, std::string>("something", "better"));

	std::cout << "------------------------------------------------------------------------" << std::endl;

	
	std::cout << "\n--- search check ---" << std::endl;

	// rvalue key search
	size_t search_index = table.search_pair("random");

	// search returned pointer access check
	if (search_index != table.get_size())
		std::cout << "search result pair = { " << table[search_index]->_first << " : " << table[search_index]->_second << " }\n";

	// lvalue key search
	std::string str = "lvalue";
	search_index = table.search_pair(str);
	if (search_index != table.get_size())
		std::cout << "search result pair = { " << table[search_index]->_first << " : " << table[search_index]->_second << " }\n";

	// acces under control. thats doesn't work
	//table[search_index]->_first = "changed__first"; 
	//table[search_index]->_first = "changed__second";
	size_t new_search = table.search_pair("changed__first");

	// obviously, nothing changed
	if (new_search != table.get_size())
		std::cout << "any changes? pair = { "<< table[new_search]->_first << " : " << table[new_search]->_second << " }\n";

	std::cout << "------------------------------------------------------------------------" << std::endl;


	std::cout << "\n--- fields check ---" << std::endl;
	
	// table fields check
	std::cout << "last_number_of_comparisons = " << table.get_last_number_of_comparisons() << std::endl;
	std::cout << "number_of_entries = " << table.get_number_of_entries() << std::endl;
	std::cout << "load_factor = " << table.load_factor() << std::endl;
	std::cout << "load_factor_threshold = " << table.load_factor_threshold() << std::endl;
	std::cout << "size = " << table.get_size() << std::endl;

	std::cout << "------------------------------------------------------------------------" << std::endl;


	std::cout << "\n--- get_pairs check ---" << std::endl;

	// get_pairs access check
	Pair<std::string, std::string>* const* pairs = table.get_pairs();
	if (pairs[1] != nullptr)
		std::cout << "pairs[1] = { " << pairs[1]->_first << " : " << pairs[1]->_second << " }\n";

	// this legal, because this just a pointer on pair array
	HashMap<std::string, std::string> another(5);
	pairs = another.get_pairs();

	// this not, because get_pairs() returns pointer on const pointer. thats means that pairs can't be changed by this pointers
	//pairs[0] = new Pair<std::string, std::string>("sime", "sime");
	
	std::cout << "------------------------------------------------------------------------" << std::endl;


	std::cout << "\n--- operator[] check ---" << std::endl;

	// by index. before getting access need to check on nullptr, obviously
	if (table[1])
		std::cout << "table[1]._first = " << table[1]->_first << std::endl;

	// by rvalue key. before getting access need to check on nullptr, obviously
	std::cout << "table[\"two\"] = " << table["two"]->_first << " : " << table["two"]->_second << std::endl;
	
	// by lvalue key. before getting access need to check on nullptr, obviously
	std::cout << "table[" << ran << "] = " << table[ran]->_first << " : " << table[ran]->_second << std::endl;

	std::cout << "------------------------------------------------------------------------" << std::endl;


	std::cout << "\n--- upgrade check ---" << std::endl;

	// rvalue key and value
	table.upgrade("two", "upgraded two value");

	// lvalue key and rvalue value
	table.upgrade(ran, "upgraded random value");

	std::cout << "------------------------------------------------------------------------" << std::endl;


	std::cout << "\n--- remove check ---" << std::endl;

	// by rvalue key
	table.remove_pair("one");

	// by lvalue key
	table.remove_pair(lvalue_pair._first);

	std::cout << "------------------------------------------------------------------------" << std::endl;
	

	std::cout << "\n--- operator << check ---" << std::endl;

	std::cout << table;

	std::cout << "------------------------------------------------------------------------" << std::endl;
	
	
	std::cout << "\n--- prints check ---" << std::endl;
	
	std::cout << "all keys = ";
	table.print_all_keys();
	
	std::cout << "all entries = ";
	table.print_all_entries();

	std::cout << "all values = ";
	table.print_all_values();

	std::cout << "------------------------------------------------------------------------" << std::endl;
	
	std::cout << "\n--- hash map test end ---" << std::endl;
}
