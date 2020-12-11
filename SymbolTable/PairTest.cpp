#include <iostream>
#include "Pair.h"


void testingConstructors()
{
	std::cout << "start\n";

	std::string a = "_first_pair_";
	std::string b = "_second_pair_";

	std::cout << "------------------------------------------------------------------------\n";
	std::cout << "rvalue constructor\n";
	const Pair<std::string, std::string> constPair("constFirst", "constSecond");
	std::cout << "constPair {" << constPair._first << ", " << constPair._second << "}\n";
	std::cout << "&constPair = " << &constPair << std::endl;
	std::cout << "\t\t&newPair._first = " << &constPair._first << std::endl;
	std::cout << "\t\t&newPair._second = " << &constPair._second << std::endl;
	std::cout << "------------------------------------------------------------------------\n";

	std::cout << "lavalue constructor\n";
	Pair<std::string, std::string> pair(a, b);
	std::cout << "pair {" << pair._first << ", " << pair._second << "}\n";
	std::cout << "&pair = " << &pair << std::endl;
	std::cout << "------------------------------------------------------------------------\n";

	std::cout << "pair constructor by const pair\n";
	Pair<std::string, std::string> newPair(constPair);
	std::cout << "newPair {" << newPair._first << ", " << newPair._second << "}\n";
	std::cout << "&newPair = " << &newPair << std::endl;
	std::cout << "------------------------------------------------------------------------\n";


	Pair<int, int> defaultConstr;
	std::cout << "&defaultConstr" << &defaultConstr << std::endl;
	std::cout << "defaultConstr {" << defaultConstr._first << ", " << defaultConstr._second << "}\n";
	std::cout << "------------------------------------------------------------------------\n";
	std::cout << "end\n";

	Pair<> zeroArg;
	zeroArg.getPair();
}