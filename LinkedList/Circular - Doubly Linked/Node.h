#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node {
private:
	T data;

public:
	Node* next;
	Node* prev;//doubly linked list
	Node();
	Node(T val);
	~Node();
	T getData() const;
	void setData(T value);
};

#endif
