#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.cpp"

using namespace std;

template <class T>
class LinkedList;

template <class T>
ostream& operator <<(ostream& output, const LinkedList<T>& rhs);

template <class T>
class LinkedList {
private:

	int size;
	Node<T>* tail;
public:

	//using a function called: getTail to get the tail rather
	//than having a pointer for it

	// // --> means that the function is working
	LinkedList();//
	LinkedList(const LinkedList& rhs);//
	LinkedList<T>& operator =(const LinkedList& rhs);//
	~LinkedList();//
	LinkedList<T>& operator +=(T val);//

	LinkedList<T> operator +(T val);//
	
	LinkedList<T>& operator +=(const LinkedList& rhs);//
	LinkedList<T> operator +(const LinkedList& rhs);//

	LinkedList<T>& operator -=(T val);//

	LinkedList<T> operator -(T val);//

	LinkedList<T>& operator-=(const LinkedList& rhs);//

	LinkedList<T> operator -(const LinkedList& rhs);//

	LinkedList<T>& operator++();//
	LinkedList<T>& operator++(int);//

	LinkedList<T>& operator--();//
	LinkedList<T>& operator--(int);//

	bool isEmpty();//

	bool toFront(T val);//
	bool toEnd(T val);//

	Node<T>* pop();//
	Node<T>* getHead();//
	int getSize() const;//
	void reversePrint(Node<T>* node);//
	void printFromTail(Node<T>* node);//
	void printTailForward(Node<T>* node);//
	void recursiveDelete(Node<T>* node);//
	void reverseDelete(Node<T>* node);

	void appendNode(T newValue);//
	void appendNodes(T* array, int length);//
	void push(T val);//
	void pushArray(T* array, int length);//

	void print(Node<T>* node);//
	friend ostream& operator << <>(ostream& output, const LinkedList& rhs);//
	void BubbleSort(int swap, Node<T>* r);//
	Node<T>* partition(Node<T>* tail, Node<T>* end, Node<T>** newHead, Node<T>** newEnd);
	Node<T>* quickSortRecur(Node<T>* tail, Node<T>* end);
	void quickSort(Node<T>** headRef);

	Node<T>* getTail();//

	void insertAtIndex(T val, int index);//
	void insertAtIndex(const LinkedList& rhs, int index);//
	void insertAtIndex(T* array, int length, int index);//
	void removeAtIndex(int index);//
	void removeRange(int start, int end);//

	bool moveValue(T val, int index);//

	//updates to code --> new functions
	Node<T>* deleteNodeNumber(Node<T>* start, int k);//
	void printFromBothEnds(Node<T>* left, Node<T>* right);//
};

template <class T>
ostream& operator <<(ostream& output, const LinkedList<T>& rhs);//

#endif
