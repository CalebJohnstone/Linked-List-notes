//relevant links are in main.cpp

#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() {
	head = NULL;
	size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs) {
	//assume it is an empty list until you know it is not
	head = NULL;
	size = 0;

	//if the rhs list is empty --> make this one empty as well
	if (!rhs.head) {
		return;
	}	
	
	//loop through the rhs list an add each value to this list
	Node<T>* nodePtr = rhs.head;

	while (nodePtr) {		
		Node<T>* newNode = new Node<T>(nodePtr->getData());

		if (!head) {
			head = newNode;
		}
		else {
			//append newNode to the this list
			Node<T>* currentPtr = head;

			while (currentPtr->next) {
				currentPtr = currentPtr->next;
			}

			currentPtr->next = newNode;
		}

		size++;
		nodePtr = nodePtr->next;
	}
}

template <class T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& rhs) {
	//check for self assignment
	if (this == &rhs) {
		return *this;
	}

	//clear what is already in the linked list
	this->~LinkedList();

	head = NULL;
	size = 0;

	//copy the rhs's linked list node data into this's linked list data
	if (rhs.head)
		for (Node<T>* nodePtr = rhs.head; nodePtr; nodePtr = nodePtr->next)
			*this += nodePtr->getData();

	return *this;
}

template <class T>
LinkedList<T>::~LinkedList() {
	while (head) {
		pop();
	}
	
	//can do either way

	//recursiveDelete(head);
}

template <class T>
LinkedList<T>& LinkedList<T>::operator +=(T val) {
	//create a new Node
	Node<T>* newNode = new Node<T>(val);

	if (!head) {
		head = newNode;
	}
	else {
		//helper pointer
		Node<T>* nodePtr = head;

		while (nodePtr->next && nodePtr->next->getData() < val) {
			nodePtr = nodePtr->next;
		}

		if (nodePtr == head) {
			if (head->getData() < val) {//insert after the head
				newNode->next = head->next;
				head->next = newNode;
			}
			else {//insert before the head
				head = newNode;
				newNode->next = nodePtr;
			}
		}
		else {
			newNode->next = nodePtr->next;
			nodePtr->next = newNode;
		}
	}

	size++;

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
	if (!rhs.head) {
		return *this;
	}

	Node<T>* currentPtr = rhs.head;

	for (; currentPtr; currentPtr = currentPtr->next) {
		*this += currentPtr->getData();
	}

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
	if (!head) {
		return *this;
	}

	//find the Node
	Node<T>* prevNode = NULL;
	Node<T>* nodePtr = head;

	while (nodePtr && nodePtr->getData() != val) {
		prevNode = nodePtr;
		nodePtr = nodePtr->next;
	}

	if (!prevNode) {
		pop();
		return *this;
	}

	if (nodePtr) {
		prevNode->next = nodePtr->next;
		delete nodePtr;
	}

	size--;
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
	if (!head) {
		return false;
	}

	Node<T>* prevNode = NULL;
	Node<T>* nodePtr = head;

	while (nodePtr && nodePtr->getData() != val) {
		prevNode = nodePtr;
		nodePtr = nodePtr->next;
	}

	//if got the end without finding val
	if (!nodePtr) {
		return false;
	}

	//already at the front
	if (nodePtr == head) {
		return true;
	}

	prevNode->next = nodePtr->next;
	nodePtr->next = head;
	head = nodePtr;

	return true;
}

template <class T>
bool LinkedList<T>::toEnd(T val) {
	if (!head) {
		return false;
	}

	Node<T>* nodePtr = head;
	Node<T>* keep;

	//move the current head node to the end of the list
	if (head->getData() == val) {
		head = head->next;

		nodePtr = head;
		keep = head;

		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}

		nodePtr->next = keep;
		keep->next = NULL;
	}

	bool found = false;

	while (nodePtr->next && !found) {
		if (nodePtr->next->getData() == val) {
			found = true;
			keep = nodePtr->next;

			if (nodePtr->next->next) {
				nodePtr->next = nodePtr->next->next;
			}
			else {
				return true;
			}
		}
		else {
			nodePtr = nodePtr->next;
		}
	}

	if (found) {
		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}

		nodePtr->next = keep;
		keep->next = NULL;
		//appending the node
	}
	else {
		return false;//value does not exist
	}
}

template <class T>
Node<T>* LinkedList<T>::pop() {
	if (!head) {
		return NULL;
	}

	Node<T>* keep = head;
	delete head;
	head = keep->next;

	size--;
	return keep;
}

template <class T>
Node<T>* LinkedList<T>::getHead() {
	return head;
}

template <class T>
int LinkedList<T>::getSize() const {
	return size;
}

//use recursion and the next pointers of each node to print the list in reverse order
//intitial value of node ==> head
template <class T>
void LinkedList<T>::reversePrint(Node<T>* node) {
	if (!head) {
		return;
	}

	if (!head->next) {
		cout << head->getData() << endl;
		return;
	}
	
	if (!node->next) {
		cout << node->getData() << ",";
	}
	else {
		reversePrint(node->next);
		cout << node->getData();

		if (node != head) {
			cout << ",";
		}
		else {
			cout << endl;
		}
	}
}

//use recursion to delete the nodes in reverse order
//intitial value of node ==> head
template <class T>
void LinkedList<T>::recursiveDelete(Node<T>* node) {
	if (node) {
		Node<T>* nodePtr;

		if (node != head) {
			nodePtr = head;

			while (nodePtr->next && nodePtr->next != node) {
				nodePtr = nodePtr->next;
			}
		}

		if (node != getTail(head)) {
			recursiveDelete(node->next);
		}

		delete node;
		size--;

		//double free or corruption (fasttop) error if left out
		//happens because the destructor can use while(tail){pop();}
		if (size == 0) {
			head = NULL;
		}
		else {
			nodePtr->next = NULL;//
		}
	}
}

template <class T>
void LinkedList<T>::appendNode(T newValue) {
	Node<T>* newNode = new Node<T>(newValue);
	size++;

	if (!head) {
		head = newNode;
	}
	else {
		Node<T>* nodePtr = head;

		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
	}

}

template <class T>
void LinkedList<T>::appendNodes(T* array, int length) {
	for (int i = 0; i < length; i++) {
		appendNode(array[i]);
	}
}

//use recursion to print normally
//intitial value of node ==> head

template <class T>
void LinkedList<T>::print(Node<T>* node) {
	if (!head) {
		return;
	}

	if (!node->next) {
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
	//multiple occurrences of a value that are found in the rhs list are deleted
	//eg: if 4 is in the this list 3 times and is thr rhs list, all 3 of the nodes will be removed from the this list

	Node<T>* thisPtr = this->head;

	for (; thisPtr; thisPtr = thisPtr->next) {
		Node<T>* rhsPtr = rhs.head;

		bool found = false;

		int count = 0;

		while (rhsPtr && !found) {
			if (thisPtr->getData() == rhsPtr->getData()) {
				found = true;
			}
			else {
				rhsPtr = rhsPtr->next;
			}
		}

		if (found) {
			*this -= thisPtr->getData();//remove the data
		}
	}
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
	push(7);
}

//post-fix increment
template <class T>
LinkedList<T>& LinkedList<T>::operator++(int) {
	appendNode(8);
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
	return (head == NULL);
}

template <class T>
void LinkedList<T>::push(T val) {
	Node<T>* newNode = new Node<T>(val);
	newNode->next = head;
	head = newNode;

	size++;
}

template <class T>
void LinkedList<T>::pushArray(T* array, int length) {
	for (int i = length - 1; i >= 0; i--) {
		push(array[i]);
	}
}

//uncomment the commented out lines and make Bubble Sort take no parameters to do the, i.e: void LinkedList<T>::BubbleSort(){...}
//iterative solution

//* next to a line means comment out that line for the iterative solution
template <class T>
void LinkedList<T>::BubbleSort(int swap, Node<T>* r) {
	if (!head) {
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
		leftPtr = head;
		while (leftPtr->next != rightPtr) {
			if (leftPtr->getData() > leftPtr->next->getData()) {
				//could have use swap function here
				T temp = leftPtr->getData();
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
	if (!head || index < 0 || index > size) {
		return;
	}

	//put in the front
	if (index == 0) {
		push(val);
		return;
	}

	Node<T>* nodePtr = head;
	int current = 0;

	while (current < index - 1) {
		current++;
		nodePtr = nodePtr->next;
	}

	//insert the new node
	Node<T>* newNode = new Node<T>(val);

	newNode->next = nodePtr->next;
	nodePtr->next = newNode;

	size++;
}


//inserting a linked list at a certain index
template <class T>
void LinkedList<T>::insertAtIndex(const LinkedList& rhs, int index) {
	if (!head || index < 0 || index > size) {
		return;
	}

	Node<T>* rhsPtr = rhs.head;

	int difference = 0;

	while (rhsPtr) {
		insertAtIndex(rhsPtr->getData(), index + difference);
		difference++;
		rhsPtr = rhsPtr->next;
	}
}

//insert an array at a certain index
template <class T>
void LinkedList<T>::insertAtIndex(T* array, int length, int index) {
	if (!head || index < 0 || index > size) {
		return;
	}

	//could just use: insertAtIndex(array[i], index + i); in the for loop
	int difference = 0;

	for (int i = 0; i < length; i++) {
		insertAtIndex(array[i], index + difference);
		difference++;
	}
}

template <class T>
void LinkedList<T>::removeAtIndex(int index) {
	if (!head || index < 0 || index >= size) {
		return;
	}

	//remove from the front
	if (index == 0) {
		pop();
		return;
	}

	Node<T>* nodePtr = head;
	int current = 0;

	while (current < index - 1) {
		current++;
		nodePtr = nodePtr->next;
	}

	//delete from within the list
	Node<T>* keep = nodePtr->next;
	
	delete nodePtr->next;
	nodePtr->next = keep->next;
	size--;
}

//remove a range of values
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


//move a value that is already in the list to a different index in the list
template <class T>
bool LinkedList<T>::moveValue(T val, int index) {
	if (index < 0 || index >= size) {
		return false;
	}

	if (!head) {
		return false;
	}

	if (head->getData() == val) {
		//wanting to move to the front, but is already there
		if (index == 0) {
			return true;
		}


		//moving the front node
		Node<T>* oldHead = head;
		head = head->next;

		Node<T>* currentNode = head;

		for (int current = 0; current < index - 1; current++) {
			currentNode = currentNode->next;
		}

		oldHead->next = currentNode->next;
		currentNode->next = oldHead;

		return true;
	}

	//moving a value that is somewhere that is not at the front

	Node<T>* nodePtr = head;
	bool found = false;
	int foundIndex = 1;

	for (; nodePtr->next != NULL && !found; nodePtr = nodePtr->next) {
		//cout << "nodePtr->getData(): " << nodePtr->getData() << endl;
		if (nodePtr->next->getData() == val) {
			found = true;
			break;
		}
		else {
			foundIndex++;
		}
	}

	//cout << "foundIndex: " << foundIndex << endl;
	//cout << "nodePtr->getData(): " << nodePtr->getData() << endl;

	//the value is already at the position that is being attempted to move it to
	if (foundIndex == index) {
		return true;
	}

	if (found) {
		Node<T>* keep = nodePtr->next;

		nodePtr->next = nodePtr->next->next;

		nodePtr = head;
		int current = 0;

		for (; nodePtr != NULL && current < index - 1; nodePtr = nodePtr->next, current++) {
			//nothing
			//cout << " nodePtr->getData(): " << nodePtr->getData() << endl;
		}

		//cout << "current: " << current << endl;

		//moving to the front
		if (nodePtr == head && index == 0) {
			head = keep;
			keep->next = nodePtr;
		}
		else {//moving somewhere else
			keep->next = nodePtr->next;
			nodePtr->next = keep;
		}

		return true;
	}
	else {
		return false;//value does not exist in the list
	}
}

//outputting iteratively
template <class T>
ostream& operator <<(ostream& output, const LinkedList<T>& rhs) {
	if (!rhs.head) {
		output << "the list is EMPTY --> failed output" << endl;
	}
	else {
		Node<T>* nodePtr = rhs.head;

		for (; nodePtr->next; nodePtr = nodePtr->next) {
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
Node<T>* LinkedList<T>::partition(Node<T>* head, Node<T>* end, Node<T>** newHead, Node<T>** newEnd){
	Node<T>* pivot = end;
	Node<T>* prev = NULL;
	Node<T>* cur = head;
	Node<T>* tail = pivot;

	// During partition, both the head and end of the list might change 
	// which is updated in the newHead and newEnd variables 
	while (cur != pivot){
		if (cur->getData() < pivot->getData()){
			// First node that has a value less than the pivot - becomes 
			// the new head 
			if ((*newHead) == NULL)
				(*newHead) = cur;

			prev = cur;
			cur = cur->next;
		}
		else {// If cur node is greater than pivot
			// Move cur node to next of tail, and change tail 
			if (prev) {
				prev->next = cur->next;
			}

			Node<T>* temp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = temp;
		}
	}

	// If the pivot data is the smallest element in the current list, 
	// pivot becomes the head 
	if ((*newHead) == NULL)
		(*newHead) = pivot;

	// Update newEnd to the current last node 
	(*newEnd) = tail;

	// Return the pivot node 
	return pivot;
}

// here the sorting happens exclusive of the end node
template <class T>
Node<T>* LinkedList<T>::quickSortRecur(Node<T>* head, Node<T>* end) {
	//print(head);

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
		temp->next = NULL;

		// Recur for the list before pivot 
		newHead = quickSortRecur(newHead, temp);

		// Change next of last node of the left half to pivot 
		temp = getTail(newHead);
		temp->next = pivot;
	}

	// Recur for the list after the pivot element 
	pivot->next = quickSortRecur(pivot->next, newEnd);

	return newHead;
}

template <class T>
void LinkedList<T>::quickSort(Node<T>** headRef) {
	(*headRef) = quickSortRecur(*headRef, getTail(*headRef));
	return;
}

template <class T>
Node<T>* LinkedList<T>::getTail(Node<T>* cur) {
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}

//middle function
// function to find out middle element 
template <class T>
Node<T>* LinkedList<T>::middle(Node<T>* start, Node<T>* last){
	if (start == NULL)
		return NULL;

	Node<T>* slow = start;
	Node<T>* fast = start->next;

	while (fast != last)
	{
		fast = fast->next;

		if (fast != last)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	return slow;
}

//uncomment the commented out lines and make Bubble Sort take no parameters to do the, i.e: void LinkedList<T>::BubbleSort(){...}
//iterative solution

//* next to a line means comment out that line for the iterative solution

//binary search function

template <class T>
//Node<T>* LinkedList<T>::binarySearch(Node<T>* head, int value) {
Node<T>* LinkedList<T>::binarySearch(Node<T>* s, Node<T>* l, int value){//(head, NULL, value)
	//Node<T>* start = head;
	Node<T>* start = s;//*
	//Node<T>* last = NULL;
	Node<T>* last = l;

	//do	{
		// Find middle 
		Node<T>* mid = middle(start, last);

		// If middle is empty 
		if (mid == NULL)
			return NULL;

		// If value is present at middle 
		if (mid->getData() == value)
			return mid;

		// If value is more than mid 
		else if (mid->getData() < value)
			start = mid->next;

		// If the value is less than mid. 
		else
			last = mid;

	//} while (last == NULL || last != start);

		if (last == NULL || last != start) {//*
			binarySearch(start, last, value);//*
		}
		else {//*

			// value not present 
			return NULL;
		}//*
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
		delete start;
		return rest;
	}

	start->next = deleteNodeNumber(start->next, k - 1);
	return start;
}

template <class T>
void LinkedList<T>::printEvenIndexes() {
	if (!head){
		return;
	}

	if (!head->next || !head->next->next) {
		cout << head->getData() << endl;
		return;
	}

	int evenCounter = size / 2;

	if (size % 2 != 0) {
		evenCounter++;
	}

	Node<T>* nodePtr = head;

	for (int current = 0; nodePtr != NULL, current < evenCounter - 1; current++, nodePtr = nodePtr->next->next) {
		cout << nodePtr->getData() << ",";
	}

	if (nodePtr) {
		cout << nodePtr->getData() << endl;
	}
}

template <class T>
void LinkedList<T>::printOddIndexes() {
	if (!head || !head->next) {
		return;
	}

	if (!head->next->next) {
		cout << head->next->getData() << endl;
		return;
	}

	int oddCounter = size / 2;

	Node<T>* nodePtr = head->next;

	for (int current = 0; nodePtr != NULL, current < oddCounter - 1; current++, nodePtr = nodePtr->next->next) {
		cout << nodePtr->getData() << ",";
	}

	if (nodePtr) {
		cout << nodePtr->getData() << endl;
	}
}