#include "HashMap.h"

void hash_map_test()
{
	// initializing check
	HashMap<std::string, std::string> table(20);


	// insert check
	table.insert("random", "word");
	table.insert("one", "pen");
	table.insert("two", "three");

	std::cout << "table[1].first = " << table[1]->first << std::endl;


	// search check
	size_t search_index = table.search_pair("random");


	// search returned pointer access check
	if (search_index != table.get_size())
		std::cout << "search result pair = { " << table[search_index]->first << " : " << table[search_index]->second << " }\n";
	
	// acces under control. thats doesn't work
	//table[search_index]->first = "changed_first"; 
	//table[search_index]->first = "changed_second";


	size_t new_search = table.search_pair("changed_first");

	// obviously, nothing changed
	if (new_search != table.get_size())
		std::cout << "any changes? pair = { "<< table[new_search]->first << " : " << table[new_search]->second << " }\n";


	// table fields check
	std::cout << "last_number_of_comparisons = " << table.get_last_number_of_comparisons() << std::endl;
	std::cout << "number_of_entries = " << table.get_number_of_entries() << std::endl;
	std::cout << "load_factor = " << table.load_factor() << std::endl;
	std::cout << "size = " << table.get_size() << std::endl;


	// get_pairs access check
	std::pair<std::string, std::string>* const* pairs = table.get_pairs();
	if (pairs[1] != nullptr)
		std::cout << "pairs[1] = { " << pairs[1]->first << " : " << pairs[1]->second << " }\n";


	// this legal, because this just a pointer on pair array
	HashMap<std::string, std::string> another(5);
	pairs = another.get_pairs();

	// this not, because get_pairs() returns pointer on const pointer. thats means that pairs can't be changed by this pointers
	//pairs[0] = new std::pair<std::string, std::string>("sime", "sime");
	
	
	// remove check
	table.remove_pair("one");

	std::pair<std::string, std::string> just_pair("something", "better");

	// rvalue insert check
	table.insert(std::pair<std::string, std::string>("something", "better"));

	// check operator << and print_all_keys
	std::cout << table;

	// check prints
	table.print_all_keys();

	table.print_all_entries();

	table.print_all_values();
}