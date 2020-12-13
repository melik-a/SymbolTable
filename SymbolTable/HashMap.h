#pragma once

#include <utility>
#include <iostream>
#include "Hash.h"
#include <cassert>

/***  
 *** this implementation has a large drawback - std::pair initializes pair with zero values 
 *** (std::string with "", int with 0, double with 0.0 and so on)
 *** that makes some trouble to inserting new pair or searching,
 *** because all pairs not empty by default
 ***/

template <typename K, typename V>
struct HashMap
{
	HashMap() : 
		_size(200), _mass(new std::pair<K, V>[200]) {}
	
	HashMap(size_t size) : 
		_size(size), _mass(new std::pair<K, V>[size]) {}
	
	~HashMap()
	{
		delete[] _mass;
	}
	
	bool is_empty() const;
	bool is_full() const;
	double load_factor() const;

	void print_all_entries() const;
	void print_all_keys() const;
	void print_all_values() const;

	const std::pair<K, V>* get_pairs() const;

	bool insert(K key, V value);
	bool insert(std::pair<K, V>&& new_pair);

	size_t search_pair(K key);

	void remove_pair(K key);

	size_t get_number_of_entries() const;
	size_t get_size() const;
	size_t get_last_number_of_comparisons() const;

	// implement operators: [ ], =, ...
	const std::pair<K, V>& operator[](size_t index) const;

	private:
		size_t _size;
		std::pair <K, V>* _mass;
		size_t _number_of_entries{};
		int _last_num_comparisons{};

		size_t hash(K key) const;
		size_t simple_rehash(K key, size_t bias) const;
};


template <typename K, typename V>
std::ostream& operator << (std::ostream& os, const HashMap<K, V>& table)
{
	os << "{ ";
	for (size_t i = 0; i < table.get_size(); i++)
	{
		os << table[i].first << " : " << table[i].second << ", ";
	}
	os << " }\n";
	return os;
}


template <typename K, typename V>
const std::pair<K, V>& HashMap<K,V>::operator[](size_t index) const
{
	assert(index < _size, "index out of bound");
	return _mass[index];
}


template <typename K, typename V>
size_t HashMap<K, V>::get_number_of_entries() const
{
	return _number_of_entries;
}


template <typename K, typename V>
size_t HashMap<K, V>::get_size() const
{
	return _size;
}


template <typename K, typename V>
size_t HashMap<K, V>::get_last_number_of_comparisons() const
{
	return _last_num_comparisons;
}


template <typename K, typename V>
bool HashMap<K, V>::is_empty() const
{
	return _number_of_entries ? false : true;
}


template <typename K, typename V>
bool HashMap<K, V>::is_full() const
{
	return _number_of_entries == _size ? true : false;
}


template <typename K, typename V>
double HashMap<K, V>::load_factor() const
{
	return (double)_number_of_entries / _size;
}


template <typename K, typename V>
size_t HashMap<K, V>::hash(K key) const
{
	return Hash<K>{}(key) % _size;
}


template <typename K, typename V>
size_t HashMap<K, V>::simple_rehash(K key, size_t bias) const
{
	return (Hash<K>{}(key) + bias) % _size;
}


template <typename K, typename V>
void HashMap<K, V>::print_all_entries() const
{
	if (is_empty()) {
		std::cout << "\n[ all pairs are empty. there is nothing to print ]\n";
		return;
	}
	std::cout << "\n{";
	for (int i = 0; i < _size; i++)
	{
		if (_mass[i].first != K)
			std::cout << _mass[i].first << " : " << _mass[i].second << ", ";
	}
	std::cout << "}\n";
}


template <typename K, typename V>
void HashMap<K, V>::print_all_keys() const
{
	if (is_empty()) {
		std::cout << "\n[ all pairs are empty. there is nothing to print ]\n";
		return;
	}
	std::cout << "\n{";
	for (int i = 0; i < _size; i++)
	{
		std::cout << _mass[i].first << ", ";
	}
	std::cout << "}\n";
}


template <typename K, typename V>
void HashMap<K,V>::print_all_values() const
{
	if (is_empty()) {
		std::cout << "\n[ all pairs are empty. there is nothing to print ]\n";
		return;
	}
	std::cout << "\n{";
	for (int i = 0; i < _size; i++)
	{
		std::cout << _mass[i].second << ", ";
	}
	std::cout << "}\n";
}


template <typename K, typename V>
const std::pair<K, V>* HashMap<K, V>::get_pairs() const
{
	return _mass;
}


template <typename K, typename V>
bool HashMap<K, V>::insert(K key, V value)
{
	if (is_full())
	{
		std::cout << "\n[ can't insert new pair. table is filled ]\n";
		return false;
	}
	
	_last_num_comparisons = 0;

	size_t index = hash(key);
	std::pair<K, V> empty_pair;

	_last_num_comparisons++;
	if (_mass[index] != empty_pair)
	{
		for (size_t i = 1; i < _size; i++)
		{
			index = simple_rehash(key, i);
			_last_num_comparisons++;
			if (_mass[index] == empty_pair)
				break;
		}
	}

	if (_mass[index] == empty_pair)
	{
		_mass[index] = std::make_pair(key, value);
		_number_of_entries++;
		std::cout << "\n[ pair inserted successfully ]\n";
		return true;
	}

	std::cout << "\n[ can't insert new pair. table is filled ]\n";
	return false;
}


template <typename K, typename V>
bool HashMap<K, V>::insert(std::pair<K, V>&& new_pair)
{
	if (is_full())
	{
		std::cout << "\n[ can't insert new pair. table is filled ]\n";
		return false;
	}

	_last_num_comparisons = 0;

	size_t index = hash(new_pair.first);
	std::pair<K, V> empty_pair;

	_last_num_comparisons++;
	if (_mass[index].first != empty_pair)
	{
		for (size_t i = 1; i < _size; i++)
		{
			index = simple_rehash(new_pair.first, i);
			_last_num_comparisons++;
			if (_mass[index].first == empty_pair)
				break;
		}
	}

	if (_mass[index].first == empty_pair)
	{
		std::move(_mass[index], new_pair);
		_number_of_entries++;
		std::cout << "\n[ pair inserted successfully ]\n";
		return true;
	}

	std::cout << "\n[ can't insert new pair. table is filled ]\n";
	return false;
}


template <typename K, typename V>
size_t HashMap<K, V>::search_pair(K key)
{
	_last_num_comparisons = 0;

	size_t index = hash(key);

	_last_num_comparisons++;
	if (_mass[index].first != key)
	{
		for (size_t i = 1; i < _size; i++)
		{
			index = simple_rehash(key, i);
			_last_num_comparisons++;
			if (_mass[index].first == key)
				break;
		}
	}

	if (_mass[index].first == key)
	{
		std::cout << "\n[ search completed successfully ]\n";
		return index;
	}

	std::cout << "\n[ there is no pair with that key. end() returned ]\n";
	return _size;
}


template <typename K, typename V>
void HashMap<K, V>::remove_pair(K key)
{
	_last_num_comparisons = 0;

	size_t index = hash(key);
	_last_num_comparisons++;
	if (_mass[index].first != key)
	{
		for (size_t i = 1; i < _size; i++)
		{
			index = simple_rehash(key, i);
			_last_num_comparisons++;
			if (_mass[index].first == key)
				break;
		}
	}

	if (_mass[index].first == key)
	{
		_number_of_entries--;
		std::pair<K, V> empty_pair;
		_mass[index] = empty_pair;
		std::cout << "\n[ pair removed successfully ]\n";
		return;
	}

	std::cout << "\n[ there is no pair with that key ]\n";
}

