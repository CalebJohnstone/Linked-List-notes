#include "LinkedList.cpp"

#include <vector>
#include <algorithm>

/*
links used:

quickSort for singly linked lists: https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
same code, just different class used: https://www.tutorialcup.com/linked-list/quick-sort-sIngly-linked-list.htm
Bubble Sort on a singly linked list: https://www.prodevelopertutorial.com/perform-bubble-sort-on-singly-linked-list-solution-in-c/
Binary Search: https://www.geeksforgeeks.org/binary-search-on-singly-linked-list/

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
	list.appendNode(0);

	/*
	list.push(8);
	list.push(9);
	*/

	cout << list;

	cout << "even indexes" << endl;
	list.printEvenIndexes();

	cout << "odd indexes" << endl;
	list.printOddIndexes();

	cout << endl;

	
	Node<int>** ptr = new Node<int>*;
	*ptr = list.getHead();

	cout << "quickSort applied" << endl;
	list.quickSort(ptr);

	list.print(list.getHead());

	cout << "after" << endl;
	cout << endl;
	

	list.BubbleSort(1, NULL);
	//binary search
	int look = 3;
	cout << "binary search applied to list" << endl;
	cout << list;
	cout << "value: " << look << endl;
	cout << endl;

	/*
	if (list.binarySearch(list.getHead(), look)) {
		cout << "Value present" << endl;
	}
	else {
		cout << "Value not present" << endl;
	}
	*/

	if (list.binarySearch(list.getHead(), NULL, look)) {
		cout << "Value present" << endl;
	}
	else {
		cout << "Value not present" << endl;
	}

	cout << endl;

	cout << "list.recursiveDelete(list.getHead())" << endl;
	list.recursiveDelete(list.getHead()->next->next);
	cout << list;

	cout << "------------END OF THE MAIN.CPP OUTPUT--------------" << endl;

	return 0;

	list.push(9);
	

	
	if (list.toFront(4)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}


	//cout << "list.deleteNodeNumber(list.getHead(), 3)" << endl;
	//list.deleteNodeNumber(list.getHead(), 3);
	cout << list;

	//cout << "list.recursiveDelete(list.getHead(), list.getHead()->getData())" << endl;
	cout << "list.recursiveDelete(list.getHead())" << endl;

	//list.Delete(list.getHead(), list.getHead()->getData());
	//list.recursiveDelete(list.getHead());
	cout << list.getHead()->next->next->getData() << endl;
	list.recursiveDelete(list.getHead()->next->next);

	//list.insertAtIndex(111, 1);
	cout << "back to main.cpp" << endl;

	list.print(list.getHead());

	cout << "------------END OF THE MAIN.CPP OUTPUT--------------" << endl;

	return 0;

	cout << endl;
	cout << "listCopy" << endl;

	LinkedList<int> listCopy(list);

	listCopy.print(listCopy.getHead());
	cout << endl;

	if (list.getHead()) {
		cout << "list head value => " << list.getHead()->getData() << endl;
	}
	else {
		cout << "list.getHead() is NULL" << endl;
	}

	if (listCopy.getHead()) {
		cout << "listCopy head value => " << listCopy.getHead()->getData() << endl;
	}
	else {
		cout << "listCopy.getHead() is NULL" << endl;
	}
	

	//list -= 3;
	//list -= 0;


	cout << "list reversed" << endl;
	list.reversePrint(list.getHead());
	cout << endl;

	cout << "listCopy reversed" << endl;
	listCopy.reversePrint(listCopy.getHead());
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

	cout << "list2 reversed" << endl;
	list2.reversePrint(list2.getHead());
	cout << endl;

	cout << "list (after removing the zeros)" << endl;
	list -= 0;
	list.print(list.getHead());
	cout << endl;

	cout << "list2 (after adding list to it and a zero back)" << endl;
	list2 += list;
	list2 += 0;
	list2.toFront(9);
	list2.toFront(3);
	list2.toFront(0);
	list2.toFront(4);

	list2 += 6;
	list2.print(list2.getHead());
	list2.toEnd(6);

	list2.print(list2.getHead());
	cout << endl;

	cout << "list2 (after removing list from it)" << endl;
	list2 -= list;
	list2.print(list2.getHead());

	list2 = list2 + 5;

	list2.print(list2.getHead());
	cout << endl;

	cout << "list (after adding the zero back)" << endl;
	list += 0;

	//cout << "BubbleSort applied" << endl;
	//list.BubbleSort();
	Node<int>** pt = new Node<int>*;
	*pt = list.getHead();

	cout << "quickSort applied" << endl;
	//list.quickSort(pt);

	list.print(list.getHead());
	cout << endl;
	//17,5,42,56,6

	cout << "list2 (after removing list from it again)" << endl;
	//list2 -= list;
	list2 = list2 - list;
	list2 = list2 - 5;

	list2.insertAtIndex(56, 1);
	list2.insertAtIndex(17, 0);
	list2.insertAtIndex(42, 2);

	list2.print(list2.getHead());

	//list2.insertAtIndex(list, list2.getSize());
	//list2 += list;
	

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
	/*
	cout << "list2 (after removing list from it)" << endl;
	list2 -= list;
	list2.print(list2.getHead());
	cout << endl;
	*/

	LinkedList<int> v;

	int array[] = { 4, 5, 1, 8, 9, 6, 21 };
	int values[] = { 9, 15, 40 };

	v.appendNodes(array, 7);
	v.pushArray(values, 3);

	cout << endl;
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
		v.moveValue(21, 2-i);
		v.print(v.getHead());
		cout << endl;
	}
	

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

	cout << "------------END OF THE MAIN.CPP OUTPUT--------------" << endl;

	return 0;
}