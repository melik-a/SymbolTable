#pragma once

#include <utility>
#include <iostream>

//
//template <typename K, typename V>
//struct HashMap
//{
//	HashMap() : 
//		_size(200), _mass(new std::pair<K, V>[200]){}
//	
//	HashMap(size_t size) : 
//		_size(size), _mass(new std::pair<K, V>[size]){}
//	
//	// implement methods for getting: all entries, all keys, all values
//	void print_all_entries();
//	void print_all_keys();
//	void print_all_values();
//
//	std::pair<K, V>* get_pairs();
//
//	// implement methods to: finding, inserting, ...
//	
//	std::pair<K, V>& get_pair(K key);
//
//	std::pair<K, V>* insert(K key, V value);
//
//	std::pair<K, V>* search_pair(K key, V value);
//
//	V search_value(K key);
//
//	void remove_pair(K key);
//
//
//
//	HashMap<K, V>& operator = (HashMap<K, V>& other)
//	{
//		std::move(other, this);
//		return this;
//	}
//	// implement operators: [ ], =, ...
//
//
//
//	private:
//		//std::string _key;
//		size_t _size;
//		std::pair <K, V>* _mass;
//		
//		size_t hash(K key);
//};
//
//
//template <typename K, typename V>
//size_t HashMap<K, V>::hash(K key)
//{
//
//}
//
//
//template <typename K, typename V>
//void HashMap<K, V>::print_all_entries()
//{
//	std::cout << "{";
//	for (std::pair<K, V>& elem : _mass)
//	{
//		std:cout << elem.first << ":" << elem.second << ", ";
//	}
//	std::cout << "}\n";
//}
//
//
//template <typename K, typename V>
//void HashMap<K, V>::print_all_keys()
//{
//	std::cout << "{";
//	for (std::pair<K, V>& elem : _mass)
//	{
//		std:cout << elem.first << ", ";
//	}
//	std::cout << "}\n";
//}
//
//
//template <typename K, typename V>
//void HashMap<K,V>::print_all_values()
//{
//	std::cout << "{";
//	for (std::pair<K, V>& elem : _mass)
//	{
//		std:cout << elem.second << ", ";
//	}
//	std::cout << "}\n";
//}
//
//
//template <typename K, typename V>
//std::pair<K, V>* HashMap<K, V>::get_pairs()
//{
//	return _mass;
//}
//
//
//template <typename K, typename V>
//std::pair<K, V>& HashMap<K, V>::get_pair(K key)
//{
//
//}
//
//
//template <typename K, typename V>
//std::pair<K, V>* HashMap<K, V>::insert(K key, V value);
//
//
//template <typename K, typename V>
//std::pair<K, V>* HashMap<K, V>::search_pair(K key, V value);
//
//
//template <typename K, typename V>
//V HashMap<K, V>::search_value(K key);
//
//
//template <typename K, typename V>
//void HashMap<K, V>::remove_pair(K key);
//
//
