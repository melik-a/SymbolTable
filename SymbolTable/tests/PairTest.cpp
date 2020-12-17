#include <iostream>
#include "../HashMap/Pair.h"
#include <vector>

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


void testing_pair()
{
	std::cout << "start pair test\n";

	std::string a = "_first_pair_";
	std::string b = "_second_pair_";

	std::cout << "------------------------------------------------------------------------\n";
	std::cout << "rvalue constructor\n";
	const Pair<std::string, std::string> const_pair("constFirst", "constSecond");
	std::cout << "const_pair {" << const_pair._first << ", " << const_pair._second << "}\n";
	std::cout << "&const_pair = " << &const_pair << std::endl;
	std::cout << "\t\t&const_pair._first = " << &const_pair._first << std::endl;
	std::cout << "\t\t&const_pair._second = " << &const_pair._second << std::endl;
	std::cout << "------------------------------------------------------------------------\n";

	std::cout << "lavalue constructor\n";
	Pair<std::string, std::string> pair(a, b);
	std::cout << "pair {" << pair._first << ", " << pair._second << "}\n";
	std::cout << "&pair = " << &pair << std::endl;
	std::cout << "------------------------------------------------------------------------\n";

	std::cout << "pair constructor by lvalue pair\n";
	Pair<std::string, std::string> new_pair(const_pair);
	std::cout << "new_pair {" << new_pair._first << ", " << new_pair._second << "}\n";
	std::cout << "&new_pair = " << &new_pair << std::endl;
	std::cout << "------------------------------------------------------------------------\n";

	std::cout << "pair constructor by rvalue pair\n";
	Pair<std::string, std::string> rvalue_pair(std::move(Pair<std::string, std::string>("hey", "there")));
	std::cout << "rvalue_pair {" << rvalue_pair._first << ", " << rvalue_pair._second << "}\n";
	std::cout << "&rvalue_pair = " << &rvalue_pair << std::endl;
	std::cout << "------------------------------------------------------------------------\n";

	Pair<int, int> default_constr;
	std::cout << "&default_constr = " << &default_constr << std::endl;
	std::cout << "default_constr {" << default_constr._first << ", " << default_constr._second << "}\n";
	std::cout << "------------------------------------------------------------------------\n";

	Pair<std::vector<std::string>, std::vector<std::string>> move_assignment;
	move_assignment = Pair<std::vector<std::string>, std::vector<std::string>>({ "move", "assignment" }, {"move_", "assignment_"});
	std::cout << "&move_assignment = " << &move_assignment << std::endl;
	std::cout << "move_assignment {" << move_assignment._first << ", " << move_assignment._second << "}\n";
	std::cout << "------------------------------------------------------------------------\n";


	Pair<> zero_arg;
	std::cout << "&zero_arg = " << &zero_arg << std::endl;
	std::cout << "zero_arg {" << zero_arg._first << ", " << zero_arg._second << "}\n";
	std::cout << "------------------------------------------------------------------------\n";
	std::cout << "end pair test\n";
}