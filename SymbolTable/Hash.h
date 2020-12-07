#pragma once

#include <string>
#include <iostream>
#include <ctime>


size_t rand_index(size_t size)
{
	return rand() % (size - 1);
}


template <typename K>
struct Hash
{
	size_t operator()(K key)
	{
		size_t hash = 0;
		try
		{
			hash = (size_t)key;
			size_t rand_ind_1 = rand_index(sizeof(PRIMES) / sizeof(size_t));
			size_t rand_ind_2 = rand_index(sizeof(PRIMES) / sizeof(size_t));
			hash = hash * PRIMES[rand_ind_1] ^ PRIMES[rand_ind_2];
		}
		catch (...)
		{
			std::cout << "this type can't be hashed -> error code (-1) will return\n";
			return -1;
		}
		return hash;
	}

	private:
		const size_t PRIMES[5] = { 12289, 5167, 14741, 797, 18181 };
};


template <>
struct Hash<std::string> 
{
	size_t operator()(std::string key)
	{
		size_t rand_ind_1 = rand_index(sizeof(PRIMES)/sizeof(size_t));
		size_t rand_ind_2 = rand_index(sizeof(PRIMES) / sizeof(size_t));

		std::cout << "rand_1 =" << rand_ind_1 << std::endl;
		std::cout << "rand_1 =" << rand_ind_2 << std::endl;
		std::cout << "prime_1 = " << PRIMES[rand_ind_1] << std::endl;
		std::cout << "prime_2 = " << PRIMES[rand_ind_2] << std::endl;
		size_t hash = 0;
		int i = 1;
		for (char c : key)
		{
			hash += (size_t)pow(c, i + 1) * PRIMES[rand_ind_1] ^ PRIMES[rand_ind_2];
			i++;
		}
		return hash;
	}

	private:
		const size_t PRIMES[5] = { 12289, 5167, 14741, 797, 18181 };
};

