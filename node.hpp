#ifndef NODE_HPP
	#define NODE_HPP

class Node
{
public:
	Node(const int &value);
	
	//getter and setter for value
	int& value();

	//getter and setter for previous node
	Node* getPrev();
	void setPrev(Node* prev);

	//getter and setter for next node
	Node* getNext();
	void setNext(Node* next);

private:
	int m_value;
	Node* m_next;
	Node* m_prev;
};

#endif //NODE_HPP
