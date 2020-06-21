#include "doublylinkedlist.hpp"

DoublyLinkedList::DoublyLinkedList()
{
	m_head = nullptr;
	m_tail = nullptr;
	m_size = 0;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& list)
{
	m_head = list.m_head;
	m_tail = list.m_tail;
	m_size = list.m_size;
}

DoublyLinkedList::~DoublyLinkedList()
{
	if(isEmpty())
		return;

	Node *node = m_head;

	while(node != nullptr)
	{
		Node *delNode = node;
		node = node -> getNext();

		delete delNode;
	}
}
	
int& DoublyLinkedList::head()
{
	return m_head -> value();
}

const int& DoublyLinkedList::head() const
{
	return m_head -> value();
}

int& DoublyLinkedList::tail()
{
	return m_tail -> value();
}

const int& DoublyLinkedList::tail() const
{
	return m_tail -> value();
}

bool DoublyLinkedList::isEmpty() const
{
	return (m_head == nullptr && m_tail == nullptr);
}

std::size_t DoublyLinkedList::size() const
{
	return m_size;
}
	
void DoublyLinkedList::push_head(const int& value)
{
	Node* node = new Node(value);
	if(isEmpty())
	{
		m_head = node;
		m_tail = node;
		m_size++;

		return;
	}

	node -> setNext(m_head);
	m_head -> setPrev(node);
	m_head = node;

	m_size++;
}

void DoublyLinkedList::push_tail(const int& value)
{
	Node* node = new Node(value);
	if(isEmpty())
	{
		m_head = node;
		m_tail = node;
		m_size++;
		return;
	}

	node -> setPrev(m_tail);
	m_tail -> setNext(node);
	m_tail = node;
	m_size++;
}

void DoublyLinkedList::pop_head()
{
	if(isEmpty())
		return;

	if(m_head == m_tail)
	{
		Node* delNode = m_head;

		m_head = nullptr;
		m_tail = nullptr;
		m_size--;

		delete delNode;
		return;
	}

	Node* delNode = m_head;

	m_head = m_head -> getNext();
	m_head -> setPrev(nullptr);
	
	delete delNode;
	m_size--;
}

void DoublyLinkedList::pop_tail()
{
	if(isEmpty())
		return;

	if(m_head == m_tail)
	{
		Node* delNode = m_head;
		m_head = nullptr;
		m_tail = nullptr;
		m_size--;

		delete delNode;
		return;
	}

	Node* delNode = m_tail;
	m_tail = m_tail -> getPrev();
	m_tail -> setNext(nullptr);
	m_size--;

	delete delNode;
}

void DoublyLinkedList::clean()
{
	if(isEmpty())
		return;

	while(!isEmpty())
		pop_head();
}
void DoublyLinkedList::insert(std::size_t pos, const int& value)
{
	if(pos == 0)
	{
		push_head(value);
		return;
	}

	if(pos == m_size - 1)
	{
		push_tail(value);
		return;
	}

	Node *node = new Node(value);

	Node *prevNode = _at(pos);
	Node *nextNode = prevNode -> getNext();

	prevNode -> setNext(node);
	node -> setPrev(prevNode);

	nextNode -> setPrev(node);
	node -> setNext(nextNode);

	m_size++;
}

void DoublyLinkedList::remove(std::size_t pos)
{
	if(pos == 0)
	{
		pop_head();
		return;
	}

	if(pos == m_size - 1)
	{
		pop_tail();
		return;
	}

	Node *delNode = _at(pos);

	Node *prevNode = delNode -> getPrev();
	Node *nextNode = delNode -> getNext();

	prevNode -> setNext(nextNode);
	nextNode -> setPrev(prevNode);

	delete delNode;

	m_size--;
}

Node* DoublyLinkedList::_at(std::size_t pos) const
{
	if(_isOutOfRange(pos))
		throw std::out_of_range("element is not exist");

	if(pos > m_size / 2)
		return _at_head(pos); //run from head will faster
	else
		return _at_tail(m_size - pos - 1);
}

Node* DoublyLinkedList::_at_head(std::size_t pos) const
{
	if(_isOutOfRange(pos))
		throw std::out_of_range("element is not exist");

	Node* node = m_head;
	for(std::size_t i = 0; i < pos; i++)
		node = node -> getNext();

	return node;
}

Node* DoublyLinkedList::_at_tail(std::size_t pos) const
{
	if(_isOutOfRange(pos))
		throw std::out_of_range("element is not exist");

	Node* node = m_tail;
	for(std::size_t i = 0; i < pos; i++)
		node = node -> getPrev();

	return node;
}


int& DoublyLinkedList::at(std::size_t pos)
{
	return _at(pos) -> value();
}

const int& DoublyLinkedList::at(std::size_t pos) const
{
	return _at(pos) -> value();
}

int& DoublyLinkedList::operator[](std::size_t pos)
{
	return _at(pos) -> value();
}
	
const int& DoublyLinkedList::operator[](std::size_t pos) const
{
	return _at(pos) -> value();
}

bool DoublyLinkedList::_isOutOfRange(std::size_t pos) const
{
	return (pos >= m_size || pos < 0);
}

DoublyLinkedList DoublyLinkedList::subList(std::size_t begin, std::size_t last) const
{
	if(begin > last)
		throw std::out_of_range("can\'t get the sub list because position begin is behind position last");

	DoublyLinkedList sub;

	for(std::size_t i = begin; i <= last; i++)
		sub.push_tail(at(i));

	return sub;

}

DoublyLinkedList DoublyLinkedList::subList(std::size_t begin) const
{
	return subList(begin, m_size - 1);
}

