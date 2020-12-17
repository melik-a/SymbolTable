#include "Hash.h"
#include <vector>

void hash_test()
{
	std::cout << "--- start hash test ---" << std::endl;
	
	std::string m = "melik";

	Hash<std::string> my_hash;

	size_t h = my_hash(m);

	std::cout << "hash - melik : " << my_hash(m) << std::endl;
	std::cout << "Hash<std::string>{}(m) - melik : " << Hash<std::string>{}(m) << std::endl;
	std::cout << "hash - melik : " << my_hash(m) << std::endl;
	std::cout << "h - melik : " << h << std::endl;

	std::cout << "string_hash - kilem : " << my_hash("kilem") << std::endl;
	std::cout << "int_hash - 30 : " << Hash<int>{}(30) << std::endl;
	std::cout << "char_hash - a : " << Hash<char>{}('a') << std::endl;


	std::cout << "std::hash - melik : " << std::hash<std::string>{}(m) << std::endl;
	std::cout << "std::hash - kilem : " << std::hash<std::string>{}("kilem") << std::endl;
	std::cout << "std::hash - kilme : " << std::hash<std::string>{}("kilme") << std::endl;
	std::cout << "std::hash - kemli : " << std::hash<std::string>{}("kemli") << std::endl;

	std::cout << "hash - melik : " << Hash<std::string>{}(m) << std::endl;
	std::cout << "hash - kilem : " << Hash<std::string>{}("kilem") << std::endl;
	std::cout << "hash - kilme : " << Hash<std::string>{}("kilme") << std::endl;
	std::cout << "hash - kemli : " << Hash<std::string>{}("kemli") << std::endl;

	std::cout << "--- end hash test ---" << std::endl;
}

