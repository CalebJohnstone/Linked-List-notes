#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() {
	tail = NULL;
	size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs) {
	//assume it is an empty list until you know it is not
	tail = NULL;
	size = 0;

	//if the rhs list is empty --> make this one empty as well
	if (!rhs.tail) {
		return;
	}	

	//test if there is one element
	if (rhs.tail == rhs.tail->next) {
		Node<T>* newNode = new Node<T>(rhs.tail->getData());
		tail = newNode;
		newNode->next = newNode;
		
		size++;
		return;
	}
	
	//loop through the rhs list an add each value to this list
	Node<T>* nodePtr = rhs.tail->next;

	do {
		appendNode(nodePtr->getData());
		nodePtr = nodePtr->next;
	} while (nodePtr != rhs.tail->next);
}

template <class T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& rhs) {
	//check for self assignment
	if (this == &rhs) {
		return *this;
	}

	//clear what is already in the linked list
	this->~LinkedList();

	tail = NULL;
	size = 0;

	//copy the rhs's linked list node data into this's linked list data
	if (rhs.tail) {
		Node<T>* nodePtr = rhs.tail;

		do {
			*this += (nodePtr->next)->getData();
			nodePtr = nodePtr->next;
		} while (nodePtr != rhs.tail);
	}

	return *this;
}

template <class T>
LinkedList<T>::~LinkedList() {
	while (tail) {
		pop();
	}

	//can do either way

	//recursiveDelete(getHead());
}

template <class T>
LinkedList<T>& LinkedList<T>::operator +=(T val) {
	//create a new Node
	Node<T>* newNode = new Node<T>(val);
	size++;

	if (!tail) {
		tail = newNode;
		newNode->next = newNode;
	}
	else {
		if (tail == getHead()) {
			newNode->next = tail;
			tail->next = newNode;

			if (tail->getData() < val) {
				tail = newNode;
			}

			return *this;
		}

		//helper pointer
		Node<T>* nodePtr = tail;

		while (nodePtr->next != tail && nodePtr->next->getData() < val) {
			nodePtr = nodePtr->next;
		}

		if (nodePtr == tail) {
			if (val < tail->next->getData()) {//insert before the head
				newNode->next = tail->next;
				tail->next = newNode;
			}
			else {//insert after the head
				newNode->next = (tail->next)->next;
				(tail->next)->next = newNode;
			}
		}
		else if (tail->getData() < val) {
			appendNode(val);
			size--;
		}
		else {
			newNode->next = nodePtr->next;
			nodePtr->next = newNode;
		}
	}

	return *this;
}

template <class T>
LinkedList<T> LinkedList<T>::operator +(T val) {
	LinkedList<T> temp(*this);
	temp += val;

	return temp;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator +=(const LinkedList& rhs) {
	if (!rhs.tail) {
		return *this;
	}

	Node<T>* currentPtr = rhs.tail;

	do {
		*this += (currentPtr->next)->getData();
		currentPtr = currentPtr->next;
	} while (currentPtr != rhs.tail);

	return *this;
}

template <class T>
LinkedList<T> LinkedList<T>::operator +(const LinkedList& rhs) {
	LinkedList<T> temp(*this);
	temp += rhs;

	return temp;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator -=(T val) {
	if (!tail) {
		return *this;
	}

	//find the Node
	Node<T>* prevNode = tail;
	Node<T>* nodePtr = tail->next;

	bool found = false;

	do {
		if (nodePtr->getData() == val) {
			found = true;
		}
		else {
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}
	} while (nodePtr != tail->next && !found);

	if (!found) {
		return *this;
	}

	size--;

	if (prevNode == tail) {
		pop();
		return *this;
	}

	if (nodePtr == tail) {
		tail = prevNode;
	}

	prevNode->next = nodePtr->next;
	delete nodePtr;

	return *this;
}

template <class T>
LinkedList<T> LinkedList<T>::operator -(T val) {
	LinkedList<T> temp(*this);
	temp -= val;

	return temp;
}

template <class T>
bool LinkedList<T>::toFront(T val) {
	if (!tail) {
		return false;
	}

	if (tail == tail->next) {
		return (tail->getData() == val);
	}

	Node<T>* nodePtr = tail;
	bool found = false;

	do {
		if (nodePtr->next->getData() == val) {
			found = true;
		}
		else {
			nodePtr = nodePtr->next;
		}
	} while (nodePtr != tail && !found);

	if (found) {
		if (nodePtr->next == tail->next) {
			return true;
		}
		else {
			if (nodePtr->next == tail) {
				tail = nodePtr;//:)
			}
			else {
				//move the node to the front
				Node<T>* keep = nodePtr->next;

				nodePtr->next = (nodePtr->next)->next;
				(keep)->next = tail->next;
				tail->next = keep;
			}

			return true;
		}
	}
	else {
		return false;
	}
}

template <class T>
bool LinkedList<T>::toEnd(T val) {
	if (!tail) {
		return false;
	}

	if (tail == tail->next) {
		return (tail->getData() == val);
	}


	if (tail->getData() == val) {
		return true;
	}

	Node<T>* nodePtr = tail;

	bool found = false;

	do {
		if (nodePtr->next->getData() == val) {
			found = true;
		}
		else {
			nodePtr = nodePtr->next;
		}
	} while (nodePtr != tail && !found);

	if (found) {
		if (nodePtr->next == tail) {
			return true;
		}

		Node<T>* keep = nodePtr->next;

		nodePtr->next = (nodePtr->next)->next;
		(keep)->next = tail->next;
		tail->next = keep;

		tail = keep;
	}
	else {
		return false;
	}
}

template <class T>
Node<T>* LinkedList<T>::pop() {
	if (!tail) {
		return NULL;
	}

	Node<T>* keep = tail->next;
	delete tail->next;

	if (keep->next != keep) {
		tail->next = keep->next;
	}
	else {
		tail = NULL;
	}

	size--;
	return keep;
}

template <class T>
Node<T>* LinkedList<T>::getHead() {
	if (!tail) {
		return tail;
	}

	return tail->next;
}

template <class T>
int LinkedList<T>::getSize() const {
	return size;
}

template <class T>
void LinkedList<T>::reversePrint(Node<T>* node) {
	if (!tail) {
		return;
	}

	if (tail == tail->next) {
		cout << tail->getData() << endl;
		return;
	}
	
	if (node == tail) {
		cout << node->getData() << ",";
	}
	else {
		reversePrint(node->next);
		cout << node->getData();

		if (node != tail->next) {
			cout << ",";
		}
		else {
			cout << endl;
		}
	}
	
}

template <class T>
void LinkedList<T>::recursiveDelete(Node<T>* node) {
	Node<T>* temp = NULL;
	if (node != tail->next) {
		Node<T>* nodePtr = tail->next;

		while (nodePtr->next != tail->next && nodePtr->next != node) {
			nodePtr = nodePtr->next;
		} 

		//nodePtr->next = NULL;
		temp = nodePtr;
	}


	if (node != tail) {
		recursiveDelete(node->next);
	}

	delete node;
	size--;

	//double free or corruption (fasttop) error if left out
	//happens because the destructor can use while(tail){pop();}
	if (size == 0) {
		tail = NULL;
	}
	else {
		temp->next = tail->next;//
	}
}

template <class T>
void LinkedList<T>::appendNode(T newValue) {
	Node<T>* newNode = new Node<T> (newValue);
	size++;

	if (!tail) {
		tail = newNode;
		newNode->next = newNode;
		return;
	}

	newNode->next = tail->next;
	tail->next = newNode;
	tail = newNode;
}

template <class T>
void LinkedList<T>::appendNodes(T* array, int length) {
	for (int i = 0; i < length; i++) {
		appendNode(array[i]);
	}
}

template <class T>
void LinkedList<T>::print(Node<T>* node) {
	if (!tail) {
		return;
	}

	if (node == tail) {
		cout << node->getData() << endl;
	}
	else {
		cout << node->getData() << ",";
		print(node->next);
	}
}

template <class T>
LinkedList<T>& LinkedList<T>::operator-=(const LinkedList& rhs) {
	//loop through the this list and remove any occurences of elements from the rhs list
	LinkedList<T> temp(*this);

	Node<T>* tempPtr = temp.tail;

	do {
		Node<T>* rhsPtr = rhs.tail;
		bool found = false;

		do {
			if (tempPtr->next->getData() == rhsPtr->next->getData()) {
				found = true;
			}
			else {
				rhsPtr = rhsPtr->next;
			}
		} while (rhsPtr != rhs.tail && !found);

		if (found) {
			*this -= tempPtr->next->getData();
		}

		tempPtr = tempPtr->next;
	} while (tempPtr != temp.tail);

	return *this;
}

template <class T>
LinkedList<T> LinkedList<T>::operator -(const LinkedList& rhs) {
	LinkedList<T> temp(*this);
	temp -= rhs;

	return temp;
}

//pre-fix increment
template <class T>
LinkedList<T>& LinkedList<T>::operator++() {
	push(49);
}

//post-fix increment
template <class T>
LinkedList<T>& LinkedList<T>::operator++(int) {
	appendNode(856);
}

//pre-fix decrement
template <class T>
LinkedList<T>& LinkedList<T>::operator--() {
	pop();
}

//post-fix decrement
template <class T>
LinkedList<T>& LinkedList<T>::operator--(int) {
	removeAtIndex(size - 1);
}

template <class T>
bool LinkedList<T>::isEmpty() {
	return (tail == NULL);
}

template <class T>
void LinkedList<T>::push(T val) {
	Node<T>* newNode = new Node<T>(val);
	size++;

	if (!tail) {
		tail = newNode;
		newNode->next = newNode;
		return;
	}

	newNode->next = tail->next;
	tail->next = newNode;
}

template <class T>
void LinkedList<T>::pushArray(T* array, int length) {
	for (int i = length - 1; i >= 0; i--) {
		push(array[i]);
	}
}

//uncomment the commented out lines and make Bubble Sort take no parameters to do
//iterative solution

//* next to a line means comment out that line for the iterative solution
template <class T>
void LinkedList<T>::BubbleSort(int swap) {
	if (!tail) {
		return;
	}

	int swapped = swap;

	if (swapped) {
		swapped = 0;//
		Node<T>* current = getHead();
		while (current->next != getHead()) {
			if (current->getData() > current->next->getData()) {
				//swap the data
				T temp = current->getData();
				current->setData(current->next->getData());
				current->next->setData(temp);

				swapped = 1;//
			}
			
			current = current->next;
		}

		BubbleSort(swapped);
	}
}

//inserting a value at a given index
template <class T>
void LinkedList<T>::insertAtIndex(T val, int index) {
	if (!tail || index < 0 || index > size) {
		return;
	}

	if (index == 0) {
		push(val);
		return;
	}

	Node<T>* nodePtr = tail->next;
	int current = 0;

	while (current < index - 1) {
		current++;
		nodePtr = nodePtr->next;
	}

	Node<T>* newNode = new Node<T>(val);

	if (nodePtr == tail) {
		tail = newNode;
	}

	newNode->next = nodePtr->next;
	nodePtr->next = newNode;

	size++;
}


//inserting a linked list at a certain index
template <class T>
void LinkedList<T>::insertAtIndex(const LinkedList& rhs, int index) {
	if (!tail || index < 0 || index > size) {
		return;
	}

	Node<T>* rhsPtr = rhs.tail->next;

	int difference = 0;

	do{
		insertAtIndex(rhsPtr->getData(), index + difference);
		difference++;
		rhsPtr = rhsPtr->next;
	} while (rhsPtr != rhs.tail->next);
}

template <class T>
void LinkedList<T>::insertAtIndex(T* array, int length, int index) {
	if (!tail || index < 0 || index > size) {
		return;
	}

	int difference = 0;

	for (int i = 0; i < length; i++) {
		insertAtIndex(array[i], index + difference);
		difference++;
	}
}

template <class T>
void LinkedList<T>::removeAtIndex(int index) {
	if (!tail || index < 0 || index >= size) {
		return;
	}

	if (index == 0) {
		pop();
		return;
	}

	Node<T>* nodePtr = tail->next;
	int current = 0;

	while (current < index - 1) {
		current++;
		nodePtr = nodePtr->next;
	}

	Node<T>* keep = nodePtr->next;
	
	delete nodePtr->next;
	nodePtr->next = keep->next;
	size--;
}

//remove from start to end index
template <class T>
void LinkedList<T>::removeRange(int start, int end) {
	if (start > end) {
		return;
	}

	if (start < 0 || end < 0 || start >= size || end >= size) {
		return;
	}
	
	for (int counter = 0; counter < (end-start + 1); counter++) {
		//the next node to remove will now be at the head (start) so can just 
		//remove it
		removeAtIndex(start);
	}
}

template <class T>
bool LinkedList<T>::moveValue(T val, int index) {
	if (index < 0 || index >= size) {
		return false;
	}

	if (!tail) {
		return false;
	}

	if (tail->next->getData() == val) {
		if (index == 0) {
			return true;
		}

		Node<T>* oldHead = tail->next;

		if (index == size - 1) {
			tail = oldHead;
			return true;
		}

		tail->next = tail->next->next;//head replaced with tail->next

		Node<T>* currentNode = tail->next;

		for (int current = 0; current < index - 1; current++) {
			currentNode = currentNode->next;
		}

		oldHead->next = currentNode->next;
		currentNode->next = oldHead;

		return true;
	}

	Node<T>* nodePtr = tail->next;
	bool found = false;
	int foundIndex = 1;

	do {
		if (nodePtr->next->getData() == val) {
			found = true;
			break;
		}
		else {
			foundIndex++;
			nodePtr = nodePtr->next;
		}
	} while (nodePtr != tail->next && !found);

	if (foundIndex == index) {
		return true;
	}

	if (found) {
		Node<T>* keep = nodePtr->next;

		nodePtr->next = nodePtr->next->next;

		nodePtr = tail->next;
		int current = 0;

		while (current < index - 1) {
			current++;
			nodePtr = nodePtr->next;
		}

		if (nodePtr == tail->next && index == 0) {
			tail->next = keep;
			keep->next = nodePtr;
		}
		else {
			keep->next = nodePtr->next;
			nodePtr->next = keep;
		}

		return true;
	}
	else {
		return false;
	}
}

//outputting iteratively
template <class T>
ostream& operator <<(ostream& output, const LinkedList<T>& rhs) {
	if (!rhs.tail) {
		output << "the list is EMPTY --> failed output" << endl;
	}
	else {
		Node<T>* nodePtr = rhs.tail->next;

		for (; nodePtr != rhs.tail; nodePtr = nodePtr->next) {
			cout << nodePtr->getData() << ",";
		}

		cout << nodePtr->getData() << endl;
	}

	return output;
}

//this code is online at: https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
//the comments are there and explain it well

// Partitions the list taking the last element as the pivot 
template <class T>
Node<T>* LinkedList<T>::partition(Node<T>* tail, Node<T>* end, Node<T>** newHead, Node<T>** newEnd){
	Node<T>* pivot = end;
	Node<T>* prev = NULL;
	Node<T>* cur = tail;
	Node<T>* tailVariable = pivot;

	// During partition, both the head and end of the list might change 
	// which is updated in the newHead and newEnd variables 
	while (cur != pivot)
	{
		if (cur->getData() < pivot->getData())
		{
			// First node that has a value less than the pivot - becomes 
			// the new head 
			if ((*newHead) == NULL)
				(*newHead) = cur;

			prev = cur;
			cur = cur->next;
		}
		else // If cur node is greater than pivot 
		{
			// Move cur node to next of tail, and change tail 
			if (prev) {
				prev->next = cur->next;
			}

			Node<T>* temp = cur->next;
			cur->next = NULL;
			tailVariable->next = cur;
			tailVariable = cur;
			cur = temp;
		}
	}

	// If the pivot data is the smallest element in the current list, 
	// pivot becomes the head 
	if ((*newHead) == NULL)
		(*newHead) = pivot;

	// Update newEnd to the current last node 
	(*newEnd) = tailVariable;

	// Return the pivot node 
	return pivot;
}

// here the sorting happens exclusive of the end node
template <class T>
Node<T>* LinkedList<T>::quickSortRecur(Node<T>* tail, Node<T>* end) {
	// base condition 
	if (!tail || tail == end)
		return tail;

	Node<T>* newHead = NULL;
	Node<T>* newEnd = NULL;

	// Partition the list, newHead and newEnd will be updated 
	// by the partition function 
	Node<T>* pivot = partition(tail, end, &newHead, &newEnd);

	// If pivot is the smallest element - no need to recur for 
	// the left part. 
	if (newHead != pivot)
	{
		// Set the node before the pivot node as NULL 
		Node<T>* temp = newHead;
		while (temp->next != pivot)
			temp = temp->next;
		temp->next = NULL;

		// Recur for the list before pivot 
		newHead = quickSortRecur(newHead, temp);

		// Change next of last node of the left half to pivot 
		temp = getTail();
		temp->next = pivot;
		//
	}

	// Recur for the list after the pivot element 
	pivot->next = quickSortRecur(pivot->next, newEnd);

	return newHead;
}

template <class T>
void LinkedList<T>::quickSort(Node<T>** headRef) {
	(*headRef) = quickSortRecur(*headRef, getTail());
	return;
}

template <class T>
Node<T>* LinkedList<T>::getTail() {
	return tail;
}