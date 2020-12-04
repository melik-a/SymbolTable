#pragma once
#include <string>

struct Node
{
	std::string key;
	Node* next;

	Node() :
		next(nullptr) {}

	Node(const std::string& n_key) :
		key(n_key), next(nullptr) {}

	Node(std::string&& n_key) :
		key(n_key), next(nullptr) {}
	
	Node(std::string& n_key) : 
		key(n_key), next(nullptr) {}
};


class LinkedList
{
	public:
		explicit LinkedList();
		~LinkedList();

		void clear();
		void remove();

		void append(const std::string& new_node);
		void append(std::string&& new_node);
		void append(std::string& new_node);

		Node* search(const std::string& new_node);
		Node* search(std::string&& new_node);
		Node* search(std::string& new_node);

		bool empty();
		size_t get_size();
		size_t get_max_size() const noexcept;
	private:
		size_t size;
		static const size_t max_size = 500;
		Node *head;
};
