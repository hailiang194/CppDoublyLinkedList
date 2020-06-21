#ifndef DOUBLYLINKEDLIST_HPP
	#define DOUBLYLINKEDLIST_HPP

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "node.hpp"

class DoublyLinkedList
{
public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& list);
	~DoublyLinkedList();
	
	//access the value of head 
	int& head();

	//access the value of head when list is constant
	const int& head() const;

	//access the value of tail
	int& tail();

	//access the value of head when list is constant
	const int& tail() const;

	//check if list is empty of not
	bool isEmpty() const;

	//get the number of elements in list
	std::size_t size() const;
	
	//insert new value at the head
	void push_head(const int& value);

	//insert new value at the tail
	void push_tail(const int& value);

	//remove the head of list
	void pop_head();

	//remove the tail of list
	void pop_tail();

	//clean the list
	void clean();

	//insert value after the specific position pos from head
	void insert(std::size_t pos, const int& value);

	//remove element after the specific postion pos from head
	void remove(std::size_t pos);

	//access the value at the specific position pos from head
	int& at(std::size_t pos);

	//access the value at the specific position pos from when list is const
	const int& at(std::size_t pos) const;

	//access the value at the specific position pos from head
	int& operator[](std::size_t pos);
	
	//access the value at the specific position pos from head when list is const
	const int& operator[](std::size_t pos) const;

	//get sub list from position begin to position i from head
	DoublyLinkedList subList(std::size_t begin, std::size_t end) const;

	//get sub list from postion begin to the end of list from head
	DoublyLinkedList subList(std::size_t begin) const;

protected:
	Node* m_head;
	Node* m_tail;
	std::size_t m_size;

	//access the node at the specific postion pos from head
	Node* _at(std::size_t pos) const;

	//access the node at the specific position pos start from head
	Node* _at_head(std::size_t pos) const;

	//access the node at the specific position pos start from tail
	Node * _at_tail(std::size_t pos) const;

	//check if position pos is out of range
	bool _isOutOfRange(std::size_t pos) const;
};

#endif
