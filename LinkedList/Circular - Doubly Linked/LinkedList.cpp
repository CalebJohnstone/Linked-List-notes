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
		newNode->prev = newNode;

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
	/*
	while (tail) {
		pop();
	}
	*/

	//can do either way

	//recursiveDelete(getHead());

	reverseDelete(tail);
}

template <class T>
LinkedList<T>& LinkedList<T>::operator +=(T val) {
	//create a new Node
	Node<T>* newNode = new Node<T>(val);
	size++;

	if (!tail) {
		tail = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else {
		if (tail == getHead()) {
			newNode->next = tail;
			newNode->prev = tail;
			tail->next = newNode;
			tail->prev = newNode;

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
				newNode->prev = tail;
				(tail->next)->prev = newNode;
				tail->next = newNode;
			}
			else {//insert after the head
				newNode->next = (tail->next)->next;
				(tail->next)->prev = newNode;

				(tail->next)->next = newNode;
				newNode->prev = tail->next;
			}
		}
		else if (tail->getData() < val) {
			appendNode(val);
			size--;
		}
		else {
			newNode->next = nodePtr->next;
			(nodePtr->next)->prev = newNode;

			nodePtr->next = newNode;
			newNode->prev = nodePtr;
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

	if (prevNode == tail) {
		pop();
		return *this;
	}

	size--;

	if (nodePtr == tail) {
		tail = prevNode;
	}

	prevNode->next = nodePtr->next;
	(nodePtr->next)->prev = prevNode;
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

				//"detach"
				nodePtr->next = (nodePtr->next)->next;//(keep)->next
				(nodePtr->next)->prev = nodePtr;

				//connect to front
				(keep)->next = tail->next;
				(tail->next)->prev = keep;

				//connect to end
				tail->next = keep;
				keep->prev = tail;
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
		(nodePtr->next)->prev = nodePtr;

		(keep)->next = tail->next;
		(tail->next)->prev = keep;

		tail->next = keep;
		keep->prev = tail;

		tail = keep;

		return true;
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
		(tail->next)->prev = tail;//
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
	if (node != getHead()) {
		temp = node->prev;
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
		temp->next = getHead();
		(temp->next)->prev = temp;
		tail = temp;
	}
}

template <class T>
void LinkedList<T>::reverseDelete(Node<T>* node) {
	if (!tail) {
		return;
	}

	if (node != tail->next) {
		Node<T>* prevNode = node->prev;
		delete node;
		reverseDelete(prevNode);
	}
	else {
		delete tail->next;
		tail = NULL;
		size = 0;
	}
}

template <class T>
void LinkedList<T>::appendNode(T newValue) {
	Node<T>* newNode = new Node<T> (newValue);
	size++;

	if (!tail) {
		tail = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
		return;
	}

	newNode->next = tail->next;
	(tail->next)->prev = newNode;

	tail->next = newNode;
	newNode->prev = tail;

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
LinkedList<T> LinkedList<T>::operator -(const LinkedList& rhs) {
	LinkedList<T> temp(*this);
	temp -= rhs;

	return temp;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator-=(const LinkedList& rhs) {
	if (!rhs.tail) {
		return *this;
	}

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

//pre-fix increment
template <class T>
LinkedList<T>& LinkedList<T>::operator++() {
	push(76);
}

//post-fix increment
template <class T>
LinkedList<T>& LinkedList<T>::operator++(int) {
	appendNode(832);
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
		newNode->prev = newNode;
		return;
	}

	newNode->next = tail->next;
	(tail->next)->prev = newNode;

	newNode->prev = tail;
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
void LinkedList<T>::BubbleSort(int swap, Node<T>* r) {
	if (!tail) {
		return;
	}

	//use bubble sort on the node data
	//int swapped;
	int swapped = swap;//*

	Node<T>* leftPtr;
	//Node<T>* rightPtr = NULL;
	Node<T>* rightPtr = r;//*

	//do {
	if(swapped){//*
		swapped = 0;
		leftPtr = tail->next;

		while (leftPtr->next != rightPtr) {
			if (leftPtr->getData() > leftPtr->next->getData()) {
				//could have use swap function here
				int temp = leftPtr->getData();
				leftPtr->setData(leftPtr->next->getData());
				leftPtr->next->setData(temp);

				swapped = 1;
			}

			leftPtr = leftPtr->next;
		}

		rightPtr = leftPtr;
		BubbleSort(swapped, rightPtr);//*
	}//*
	//} while (swapped);
}

//inserting a value at a given index
template <class T>
void LinkedList<T>::insertAtIndex(T val, int index) {
	//cout << "size = " << size << endl;

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

	//cout << "current = " << current << endl;

	Node<T>* newNode = new Node<T>(val);

	newNode->next = nodePtr->next;
	(nodePtr->next)->prev = newNode;

	nodePtr->next = newNode;
	newNode->prev = nodePtr;

	if (index == size) {
		tail = newNode;
	}

	size++;
}


//inserting a linked list at a certain index
template <class T>
void LinkedList<T>::insertAtIndex(const LinkedList& rhs, int index) {
	if (!tail || index < 0 || index > size) {
		return;
	}

	Node<T>* rhsPtr = rhs.tail;

	int difference = 0;

	do {
		insertAtIndex(rhsPtr->next->getData(), index + difference);
		difference++;
		rhsPtr = rhsPtr->next;
	} while (rhsPtr != rhs.tail);
}

template <class T>
void LinkedList<T>::insertAtIndex(T* array, int length, int index) {
	if (!tail || index < 0 || index > size) {
		return;
	}

	int difference = 0;

	for(int i = 0; i < length; i++){
		//cout << "insertAtIndex(" << array[i] << "," << index << "+" << difference << ");" << endl;
		insertAtIndex(array[i], index + difference);//+ difference
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

	

	Node<T>* nodePtr = tail;
	int current = 0;

	if (index == size - 1) {
		(tail->prev)->next = tail->next;
		(tail->next)->prev = tail->prev;

		Node<T>* keep = tail;
		delete tail;
		tail = keep->prev;
		size--;

		return;
	}

	do {
		current++;
		nodePtr = nodePtr->next;
	} while ((current < index - 1) && (nodePtr != tail));

	Node<T>* keep = nodePtr->next;
	
	delete nodePtr->next;
	nodePtr->next = keep->next;
	(keep->next)->prev = nodePtr;
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
		removeAtIndex(start+1);
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

		
		tail->next = tail->next->next;

		(tail->next)->prev = tail;//

		Node<T>* currentNode = tail->next;

		for (int current = 0; current < index - 1; current++) {
			currentNode = currentNode->next;
		}

		oldHead->next = currentNode->next;
		(currentNode->next)->prev = oldHead;

		currentNode->next = oldHead;
		oldHead->prev = currentNode;

		tail = tail->next;//

		return true;
	}

	Node<T>* nodePtr = tail;
	bool found = false;
	int foundIndex = 0;

	do {
		if (nodePtr->next->getData() == val) {
			found = true;
			break;
		}
		else {
			foundIndex++;
			nodePtr = nodePtr->next;
		}
	} while (nodePtr != tail && !found);

	if (foundIndex == index) {
		return true;
	}

	/*
	cout << "foundIndex: " << foundIndex << endl;
	cout << "nodePtr->getData(): " << nodePtr->getData() << endl;
	cout << "nodePtr->next->getData(): " << nodePtr->next->getData() << endl;
	*/

	if (found) {
		Node<T>* keep = nodePtr->next;

		nodePtr->next = nodePtr->next->next;
		(nodePtr->next)->prev = nodePtr;
		
		//cout << "inner print" << endl;
		//print(getHead());

		nodePtr = tail->next;
		int current = 0;

		while (current < index - 1) {
			current++;
			nodePtr = nodePtr->next;
		}

		//cout << "current: " << current << endl;

		if (nodePtr == tail->next && index == 0) {
			tail->next = keep;
			keep->prev = tail;

			keep->next = nodePtr;
			nodePtr->prev = keep;
		}
		else {
			keep->next = nodePtr->next;
			(nodePtr->next)->prev = keep;

			nodePtr->next = keep;
			keep->prev = nodePtr;
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
		Node<T>* nodePtr = rhs.tail;

		do {
			output << nodePtr->next->getData() << ",";
			nodePtr = nodePtr->next;
		} while (nodePtr->next != rhs.tail);

		cout << rhs.tail->getData() << endl;
	}

	return output;
}

//this code is online at: https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
//the comments are there and explain it well

// Partitions the list taking the last element as the pivot 
template <class T>
Node<T>* LinkedList<T>::partition(Node<T>* head, Node<T>* end, Node<T>** newHead, Node<T>** newEnd) {
	Node<T>* pivot = end;
	//Node<T>* prev = NULL;
	Node<T>* prev = tail;
	Node<T>* cur = head;
	Node<T>* tailVariable = pivot;

	// During partition, both the head and end of the list might change 
	// which is updated in the newHead and newEnd variables 
	while (cur != pivot) {
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
			if (prev != tail) {
				prev->next = cur->next;
				(prev->next)->prev = prev;//
			}

			Node<T>* temp = cur->next;
			cur->next = tail->next;//cur->next = NULL;
			(tail->next)->prev = temp;//cur->next

			tailVariable->next = cur;
			cur->prev = tailVariable;//
			tailVariable = cur;
			cur = temp;
		}
	} //while (cur != pivot);// && cur != tail

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
Node<T>* LinkedList<T>::quickSortRecur(Node<T>* head, Node<T>* end) {
	// base condition 
	if (!head || head == end)
		return head;

	Node<T>* newHead = NULL;
	Node<T>* newEnd = NULL;

	// Partition the list, newHead and newEnd will be updated 
	// by the partition function 
	Node<T>* pivot = partition(head, end, &newHead, &newEnd);

	// If pivot is the smallest element - no need to recur for 
	// the left part. 
	if (newHead != pivot)
	{
		// Set the node before the pivot node as NULL 
		Node<T>* temp = newHead;
		while (temp->next != pivot)
			temp = temp->next;
		//temp->next = NULL;
		temp->next = tail->next;//
		(tail->next)->prev = temp;//

		// Recur for the list before pivot 
		newHead = quickSortRecur(newHead, temp);

		// Change next of last node of the left half to pivot 
		temp = getTail();
		temp->next = pivot;
		pivot->prev = temp;//
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

template <class T>
void LinkedList<T>::printFromTail(Node<T>* node) {
	//cout << "apples" << endl;

	if (node == tail->next) {//could of tested if(!node->prev)
		cout << node->getData() << endl;
	}
	else {
		cout << node->getData() << ",";
		//cout << endl;
		//cout << "previous value: " << node->prev->getData() << endl;
		printFromTail(node->prev);
	}
}

template <class T>
void LinkedList<T>::printTailForward(Node<T>* node) {
	if (node->prev != tail) {
		printTailForward(node->prev);
	}
	cout << node->getData();

	if (node == getTail()) {
		cout << endl;
	}
	else {
		cout << ",";
	}
}

//requires to be a double linked list (circular or not)

//could be implemented with single link (circular or not) but would
//require looping over the list a lot

//intitial parameters: head and tail

template <class T>
void LinkedList<T>::printFromBothEnds(Node<T>* left, Node<T>* right) {
	if (!getHead()) {
		return;
	}

	//base case for odd lengths of lists
	//last node to output
	if (left == right) {
		cout << left->getData() << endl;
		return;
	}

	cout << left->getData() << ",";

	if (left->next != right) {
		cout << right->getData() << ",";

		printFromBothEnds(left->next, right->prev);
	}
	else {
		//base case for even lengths of lists
		//last node to output
		cout << right->getData() << endl;
	}
}

//deletes the k-th node --> indexing from zero

//the recursive version of removeAtIndex(int index)

template <class T>
Node<T>* LinkedList<T>::deleteNodeNumber(Node<T>* start, int k) {
	//invalid k
	if (k < 0 || k >= size) {
		return start;
	}

	if (!start) {
		return NULL;
	}

	if (k == 0) {
		Node<T>* rest = start->next;
		(start->next)->prev = start->prev;//

		delete start;
		size--;
		return rest;
	}

	start->next = deleteNodeNumber(start->next, k - 1);
	return start;
}