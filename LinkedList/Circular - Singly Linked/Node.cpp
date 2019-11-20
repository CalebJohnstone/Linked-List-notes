#include "Node.h"

template <class T>
Node<T>::Node(){}

template <class T>
Node<T>::Node(T val) : data(val), next(NULL){}

template <class T>
Node<T>::~Node() {
	//cout << "Node with a value of: " << data << " deleted" << endl;
}

template <class T>
T Node<T>::getData() const {
	return data;
}

template <class T>
void Node<T>::setData(T value) {
	data = value;
}