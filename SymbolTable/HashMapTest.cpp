#include "HashMap.h"

void hash_map_general_test()
{
	// initializing check
	HashMap<std::string, std::string> table;


	// insert check
	table.insert("random", "word");
	table.insert("one", "pen");
	table.insert("two", "three");

	std::cout << "table[1].first = " << table[1].first << std::endl;


	// search check
	size_t search_index = table.search_pair("random");


	// search returned pointer access check
	if (search_index != table.get_size())
		std::cout << "search result pair = { " << table[search_index].first << " : " << table[search_index].second << " }\n";
	
	// acces under control. thats doesn't work
	// search->first = "changed_first"; 
	// search->second = "changed_second";


	size_t new_search= table.search_pair("changed_first");

	// obviously, nothing changed
	if (new_search != table.get_size())
		std::cout << "any changes? pair = { "<< table[new_search].first << " : " << table[new_search].second << " }\n";


	// table fields check
	std::cout << "last_number_of_comparisons = " << table.get_last_number_of_comparisons() << std::endl;
	std::cout << "number_of_entries = " << table.get_number_of_entries() << std::endl;
	std::cout << "load_factor = " << table.load_factor() << std::endl;
	std::cout << "size = " << table.get_size() << std::endl;


	// get_pairs access check
	const std::pair<std::string, std::string>* pairs = table.get_pairs();
	std::cout << "pairs[0] = { " << pairs[0].first << " : " << " }\n";

	// remove check
	table.remove_pair("one");


	// check operator << and print_all_keys
	std::cout << table;
	table.print_all_keys();
}


void hash_map_load_test()
{
	HashMap<std::string, std::string> map(5);

	map.insert("one", "1");
	map.insert("two", "2");
	map.insert("three", "3");
	map.insert("four", "4");
	map.insert("five", "5");

	map.insert("six", "6");

	map.remove_pair("three");
	map.remove_pair("two");

	map.search_pair("four");
}