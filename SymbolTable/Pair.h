#pragma once


template <typename F = int, typename S = std::string>
struct Pair
{
	F _first;
	S _second;

	Pair() : 
		_first(), _second() {}

	Pair(F &first, S &second) :
		_first(first), _second(second) {}

	Pair(const Pair<F, S>& pair_el) : 
		_first(pair_el._first), _second(pair_el._second) {}

	//template <typename Other1, typename Other2>

	Pair(F&& first, S&& second) :
		_first(first), _second(second) {}

	void getPair()
	{
		std::cout << "first = " << this->_first << "\nsecond = " << this->_second << std::endl;
	}

};