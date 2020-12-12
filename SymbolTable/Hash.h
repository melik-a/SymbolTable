#pragma once

#include <string>
#include <iostream>


template <typename K>
struct Hash
{
	size_t operator()(K key)
	{
		size_t hash = 0;
		try
		{
			hash = (size_t) key & 0x07FFFFFFF;
			hash = hash * PRIME_1 ^ PRIME_2;
		}
		catch (...)
		{
			std::cout << "this type can't be hashed -> error code (-1) is returning\n";
			return -1;
		}
		return hash;
	}

	private:
		const size_t PRIME_1 = 12289;
		const size_t PRIME_2 = 18181;
};


template <>
struct Hash<std::string> 
{
	size_t operator()(std::string key)
	{
		size_t hash = 0;
		int i = 1;
		for (char c : key)
		{
			hash += (size_t)pow(c, i + 1) * PRIME_1 ^ PRIME_2;
			i++;
		}
		return hash;
	}

	private:
		const size_t PRIME_1 = 12289;
		const size_t PRIME_2 = 18181;
};

