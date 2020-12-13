#include "ListTable.h"


Node::Node() :
	next(nullptr) {}


Node::Node(const std::string& n_key) :
	key(n_key), next(nullptr) {}


Node::Node(std::string&& n_key) :
	key(n_key), next(nullptr) {}


Node::Node(std::string& n_key) :
	key(n_key), next(nullptr) {}


LinkedList::LinkedList() :
	head(nullptr), size(0) {}


LinkedList::~LinkedList()
{
	while (head)
		remove();
}


void LinkedList::clear()
{
	while (head)
		remove();
	size = 0;
}


Node* LinkedList::search(const std::string& s_key)
{
	Node* node = head;
	while (node)
	{
		if (node->key == s_key)
			return node;
		node = node->next;
	}
	return node;
}


Node* LinkedList::search(std::string& s_key)
{
	Node* node = head;
	while (node)
	{
		if (node->key == s_key)
			return node;
		node = node->next;
	}
	return node;
}


Node* LinkedList::search(std::string&& s_key)
{
	Node* node = head;
	while (node)
	{
		if (node->key == s_key)
			return node;
		node = node->next;
	}
	return node;
}


void LinkedList::append(const std::string& new_key)
{
	Node* node = new Node(new_key);
	node->next = this->head;
	this->head = node;
	size += 1;
}


void LinkedList::append(std::string&& new_key)
{
	Node* node = new Node(new_key);
	node->next = this->head;
	this->head = node;
	size += 1;
}


void LinkedList::append(std::string& new_key)
{
	Node* node = new Node(new_key);
	node->next = this->head;
	this->head = node;
	size += 1;
}


void LinkedList::remove()
{
	if (head) 
	{
		Node* new_head = this->head->next;
		delete head;
		head = new_head;
		size -= 1;
	}
}


size_t LinkedList::get_max_size() const noexcept
{
	return max_size;
}


size_t LinkedList::get_size()
{
	return head ? 0 : size;
}


bool LinkedList::empty()
{
	return head ? false : true;
}