#include "LinkedList.cpp"

#include <vector>
#include <algorithm>

/*
links used:


*/

int main() {
	cout << "list" << endl;

	LinkedList<int> list;

	//cout << list->getHead() << endl;

	/*
	list += 4;
	list += 3;
	list += 7;
	list += 0;
	*/
	
	
	list.appendNode(4);
	list.appendNode(3);
	list.appendNode(7);
	list.appendNode(12);

	list.push(9);
	list.push(73);

	cout << list;
	cout << "recursiveDelete" << endl;
	//list.recursiveDelete(list.getHead()->next->next);
	list.recursiveDelete(list.getTail(list.getHead()));

	cout << list;
	cout << endl;

	return 0;

	cout << "list" << endl;
	list.print(list.getHead());

	cout << "list.deleteNodeNumber(list.getHead(), 3)" << endl;
	list.deleteNodeNumber(list.getHead(), 3);
	cout << list;

	cout << "from both ends" << endl;
	list.printFromBothEnds(list.getHead(), list.getTail(list.getHead()));

	cout << "list reversed using for loop" << endl;

	if (list.getHead() == list.getTail(list.getHead())) {
		cout << list.getHead()->getData() << endl;
	}

	for (Node<int>* nodePtr = list.getTail(list.getHead()); nodePtr->prev; nodePtr = nodePtr->prev) {
		cout << nodePtr->getData() << ",";
	}

	
	cout << list.getHead()->getData() << endl;

	
	
	cout << "list reversed using printFromTail" << endl;
	list.printFromTail(list.getTail(list.getHead()));
	
	return 0;

	cout << "toFront: ";

	if (list.toFront(4)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	cout << "toEnd: ";
	if (list.toEnd(7)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	
	cout << "head->prev: ";
	if (list.getHead()->prev) {
		cout << list.getHead()->prev << endl;
	}
	else {
		cout << "NULL" << endl;
	}
	
	list += 5;
	cout << "list += 5" << endl;
	list.print(list.getHead());

	cout << endl;
	cout << "testing: " << endl;
	cout << "VALUE: " << list.getHead()->next->next->getData() << endl;
	cout << endl;

	cout << "list reversed using printFromTail" << endl;
	list.printFromTail(list.getTail(list.getHead()));

	cout << endl;
	cout << "listCopy" << endl;

	LinkedList<int> listCopy(list);

	listCopy.print(listCopy.getHead());
	cout << endl;

	cout << "list head value => " << list.getHead()->getData() << endl;
	cout << "listCopy head value => " << listCopy.getHead()->getData() << endl;
	

	list -= 3;
	list -= 0;


	cout << "list reversed using reversePrint --> recursive using next pointers" << endl;
	list.reversePrint(list.getHead());
	cout << endl;

	cout << "listCopy reversed using reversePrint --> recursive using next pointers" << endl;
	listCopy.reversePrint(listCopy.getHead());
	cout << endl;

	cout << "listCopy reversed using printFromTail --> recursive using prev pointers" << endl;
	listCopy.printFromTail(listCopy.getTail(listCopy.getHead()));
	cout << endl;

	/*
	vector<double> dblVector;

	dblVector.push_back(4.5);
	dblVector.push_back(2.2);
	dblVector.push_back(2.3);

	sort(dblVector.begin(), dblVector.end());

	if (binary_search(dblVector.begin(), dblVector.end(), 2.2)) {
		cout << "The value of 2.2 was found in the vector called dblVector" << endl;
	}
	*/

	
	LinkedList<int> list2;
	list2 = list;

	cout << "list2" << endl;
	list2.print(list2.getHead());
	cout << endl;

	cout << "list2 reversed using reversePrint --> recursive using next pointers" << endl;
	list2.reversePrint(list2.getHead());
	cout << endl;

	cout << "list2 reversed using printFromTail --> recursive using prev pointers" << endl;
	list2.printFromTail(list2.getTail(list2.getHead()));
	cout << endl;

	cout << "list (after removing the zeros)" << endl;//
	list -= 0;
	list.print(list.getHead());
	cout << endl;

	cout << "list reversed using printFromTail" << endl;
	list.printFromTail(list.getTail(list.getHead()));
	cout << endl;

	cout << "list" << endl;
	list.print(list.getHead());
	cout << endl;

	cout << "list2" << endl;
	list2.print(list2.getHead());
	cout << endl;

	cout << "list2 (after adding list to it and a zero back)" << endl;
	list2 += list;
	list2 += 0;
	list2.print(list2.getHead());

	list2.toFront(9);
	list2.toFront(3);
	list2.toFront(4);
	list2.toFront(7);
	list2.toFront(0);

	list2.toEnd(3);
	list2.toEnd(7);
	list2.toEnd(7);
	list2.toEnd(9);
	list2 += 6;
	
	list2.print(list2.getHead());

	cout << "list2 reversed using printFromTail --> recursive using prev pointers" << endl;
	list2.printFromTail(list2.getTail(list2.getHead()));
	cout << endl;

	cout << "list2.toEnd(6)" << endl;
	list2.toEnd(6);

	list2.print(list2.getHead());
	cout << endl;

	cout << "list2 (after removing list from it)" << endl;
	list2 -= list;
	list2.print(list2.getHead());

	list2 = list2 + 5;
	list2 = list2 - 0;

	list2.print(list2.getHead());
	cout << endl;

	cout << "listCopy" << endl;
	listCopy.print(listCopy.getHead());
	cout << endl;

	cout << "list2 = listCopy + 16" << endl;
	list2 = listCopy + 16;
	list2.print(list2.getHead());
	cout << endl;

	cout << "list2 (''skipping'' the first two values)" << endl;
	list2.print(list2.getHead()->next->next);
	cout << "head->getData() => " << list2.getHead()->getData() << endl;

	cout << "list2 tail data --> by doing list2.print(list2.getTail(list2.getHead()));" << endl;
	list2.print(list2.getTail(list2.getHead()));
	cout << endl;

	cout << "list2.pop()" << endl;
	list2.pop();
	cout << "head->getData() => " << list2.getHead()->getData() << endl;
	list2.print(list2.getHead());
	cout << endl;

	cout << "list2 reversed using printFromTail --> recursive using prev pointers" << endl;
	list2.printFromTail(list2.getTail(list2.getHead()));
	cout << endl;

	cout << "list2 reversed using printTailForward --> recursive using prev pointers" << endl;
	list2.printTailForward(list2.getTail(list2.getHead()));
	cout << endl;

	cout << "list (after adding the zero back)" << endl;
	list += 0;

	list.appendNode(2);
	list.appendNode(-1);
	list.appendNode(16);
	list.appendNode(1);
	
	cout << "BubbleSort applied" << endl;
	list.BubbleSort(1, NULL);
	

	/*
	Node<int>** ptr = new Node<int>*;
	*ptr = list.getHead();

	cout << "quickSort applied" << endl;
	list.quickSort(ptr);

	list.print(list.getHead());
	*/

	cout << "list" << endl;
	list.print(list.getHead());
	cout << endl;

	cout << "list (after inserting 77 at index 5)" << endl;
	list.insertAtIndex(77, 5);
	list.print(list.getHead());
	//list.print(listCopy.getHead());

	cout << "list reversed using for loop" << endl;

	if (list.getHead() == list.getTail(list.getHead())) {
		cout << list.getHead()->getData() << endl;
	}

	for (Node<int>* nodePtr = list.getTail(list.getHead()); nodePtr->prev; nodePtr = nodePtr->prev) {
		cout << nodePtr->getData() << ",";
	}

	cout << list.getHead()->getData() << endl;

	cout << "list reversed using printFromTail" << endl;
	
	cout << "tail data: " << list.getTail(list.getHead())->getData() << endl;
	if (list.getTail(list.getHead())->prev) {
		cout << "tail->prev data: " << list.getTail(list.getHead())->prev->getData() << endl;
	}
	
	list.printFromTail(list.getTail(list.getHead()));
	cout << endl;

	cout << "list.removeAtIndex(3)" << endl;
	list.removeAtIndex(3);
	list.print(list.getHead());
	cout << endl;

	list.printFromTail(list.getTail(list.getHead()));

	cout << "Bubble Sort applied to list" << endl;
	list.BubbleSort(1, NULL);
	list.print(list.getHead());
	cout << endl;

	//17,5,42,56,6

	cout << "list2 (after removing list from it again)" << endl;
	list2 -= list;
	
	list2 = list2 - list;
	list2 = list2 - 5;

	list2.insertAtIndex(56, 1);
	list2.insertAtIndex(17, 0);
	list2.insertAtIndex(42, 2);

	list2.print(list2.getHead());

	list2.insertAtIndex(list, list2.getSize());
	list2 += list;
	

	list2.print(list2.getHead());

	cout << "BubbleSort applied" << endl;
	list2.BubbleSort(1, NULL);

	list2.print(list2.getHead());
	list2.reversePrint(list2.getHead());
	cout << "size => " << list2.getSize() << endl;
	cout << endl;

	list2.removeAtIndex(0);
	list2.removeAtIndex(4);
	list2.removeAtIndex(2);

	cout << "size => " << list2.getSize() << endl;
	cout << list2;

	//n: the number of nodes to "save" at the end
	int n = 3;

	list2.removeRange(0, list2.getSize() - (n+1));
	list2.removeRange(2, 1);
	cout << list2;
	

	if (list.isEmpty()) {
		cout << "list is empty" << endl;
	}
	
	if(listCopy.isEmpty()){
		cout << "listCopy is empty" << endl;
	}

	
	if (list2.isEmpty()) {
		cout << "list2 is empty" << endl;
	}
	
	
	cout << "list2 (after removing list from it)" << endl;
	list2 -= list;
	list2.print(list2.getHead());
	cout << endl;

	LinkedList<int> v;

	int array[] = { 4, 5, 1, 8, 9, 6, 21 };
	int values[] = { 9, 15, 40 };

	v.appendNodes(array, 7);
	v.pushArray(values, 3);

	cout << "v" << endl;

	LinkedList<int> c;

	int numbers[] = { 74, 125, 6 };
	c.appendNodes(numbers, 3);

	v.insertAtIndex(c, 2);

	cout << "forwards using print" << endl;
	v.print(v.getHead());
	cout << endl;

	v.moveValue(74, 0);
	v.print(v.getHead());
	cout << endl;

	v.moveValue(74, 3);
	v.moveValue(9, 6);
	v.print(v.getHead());
	cout << endl;

	for (int i = 0; i < 3; i++) {
		v.moveValue(21, 2 - i);
		v.print(v.getHead());
		cout << endl;
	}
	
	cout << "forwards using print" << endl;
	v.print(v.getHead());
	cout << endl;

	cout << "forwards using printTailForward" << endl;
	v.printTailForward(v.getTail(v.getHead()));
	cout << endl;

	cout << "reverse using printFromTail" << endl;
	v.printFromTail(v.getTail(v.getHead()));
	cout << endl;

	cout << "reverse using reversePrint" << endl;
	v.reversePrint(v.getHead());
	cout << endl;

	cout << "v.removeAtIndex(7)" << endl;
	v.removeAtIndex(7);
	v.print(v.getHead());
	cout << endl;

	cout << "v.removeRange(3,6)" << endl;
	v.removeRange(3, 6);
	v.print(v.getHead());
	cout << endl;

	cout << "v.insertAtIndex(nums, 6, 4)" << endl;
	int nums[] = { 88, 5, 9, 54, 32, 63 };
	v.insertAtIndex(nums, 6, 4);
	v.print(v.getHead());
	cout << endl;

	cout << "reverse using printFromTail" << endl;
	v.printFromTail(v.getTail(v.getHead()));
	cout << endl;

	cout << "v = c + 4" << endl;
	v = c + 4;
	v.print(v.getHead());
	cout << endl;

	v.printFromTail(v.getTail(v.getHead()));

	cout << "v = v - 6" << endl;
	v = v - 6;
	v -= 6;
	
	v.print(v.getHead());
	cout << endl;

	v.printFromTail(v.getTail(v.getHead()));

	cout << "v = c + v + v - v" << endl;
	v = c + v + v - v;

	v.print(v.getHead());
	cout << endl;

	v.printFromTail(v.getTail(v.getHead()));

	cout << "v.appendNodes(values, 3)" << endl;
	v.appendNodes(values, 3);

	v.print(v.getHead());
	cout << endl;

	v.printFromTail(v.getTail(v.getHead()));

	Node<int>** ptr = new Node<int>*;
	*ptr = v.getHead();

	cout << "quickSort applied" << endl;
	list.quickSort(ptr);

	v.print(v.getHead());
	cout << endl;

	cout << "forwards using printTailForward" << endl;
	v.printTailForward(v.getTail(v.getHead()));
	cout << endl;

	cout << "reverse using printFromTail" << endl;
	v.printFromTail(v.getTail(v.getHead()));
	cout << endl;

	cout << "reverse using reversePrint" << endl;
	v.reversePrint(v.getHead());
	cout << endl;

	cout << v + c - v;
	cout << c + 9;
	cout << v;
	++v;
	v++;

	cout << v;
	v.printFromTail(v.getTail(v.getHead()));
	cout << endl;

	--v;
	v--;
	cout << v;
	v.printFromTail(v.getTail(v.getHead()));

	cout << "------------END OF THE MAIN.CPP OUTPUT--------------" << endl;

	return 0;
}