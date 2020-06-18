#include "node.hpp"

Node::Node(const int &value)
{
	m_value = value;
	m_prev = nullptr;
	m_next = nullptr;
}

int& Node::value()
{
	return m_value;
}


Node* Node::getPrev()
{
	return m_prev;
}

void Node::setPrev(Node* prev)
{
	m_prev = prev;
}

Node* Node::getNext()
{
	return m_next;
}

void Node::setNext(Node* next)
{
	m_next = next;
}
