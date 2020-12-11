#include "Hash.h"


void hash_test()
{
	//srand(time(NULL));
	
	std::string m = "melik";

	Hash<std::string> my_hash;

	size_t h = my_hash(m);

	std::cout << "hash - melik : " << my_hash(m) << std::endl;
	std::cout << "hash - melik : " << Hash<std::string>{}(m) << std::endl;
	std::cout << "hash - melik : " << my_hash(m) << std::endl;
	std::cout << "h - melik : " << h << std::endl;

	std::cout << "string_hash - kilem : " << my_hash("kilem") << std::endl;
	std::cout << "int_hash - 30 : " << Hash<int>{}(30) << std::endl;
	std::cout << "char_hash - a : " << Hash<char>{}('a') << std::endl;


	std::cout << "std::hash - melik : " << std::hash<std::string>{}(m) << std::endl;

	std::cout << "std::hash - kilem : " << std::hash<std::string>{}("kilem") << std::endl;
}

