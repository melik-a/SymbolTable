#pragma once


template <typename F, typename S>
struct Pair
{
	F _first;
	S _second;

	Pair() : _first(0), _second(0)
	{
	}
	
	Pair(F first, S second) : 
			_first(first), _second(second)
	{
	}
	
	/*Pair(const F first, S second) :
			_first(first), _second(second)
	{
	}*/
	
	void getPair()
	{
		std::cout << "first = " << this->_first << "\nsecond = " << this->_second << std::endl;
	}
		
};


//template <typename id, typename token>
//struct HashMap
//{
//	HashMap() : _size(200)
//	{
//
//	}
//	
//	HashMap(size_t size) : _size(size)
//	{
//		
//	}
//	
//	// implement methods for getting: all entries, all keys, all values
//
//	// implement methods to: finding, inserting, ...
//	
//	// implement operators: [ ], =, ...
//	private:
//		Pair <id,token> *mass;
//		size_t _size;
//		
//		//int hash (id in_key);
//
//};