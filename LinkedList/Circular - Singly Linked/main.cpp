#include "LinkedList.cpp"

#include <vector>
#include <algorithm>

/*
links used:

quickSort for singly linked lists: https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
same code, just different class used: https://www.tutorialcup.com/linked-list/quick-sort-sIngly-linked-list.htm
Bubble Sort on a singly linked list: https://www.prodevelopertutorial.com/perform-bubble-sort-on-singly-linked-list-solution-in-c/

Cirular - single link - Bubble Sort: https://www.javatpoint.com/program-to-sort-the-elements-of-the-circular-linked-list

*/

int main() {
	LinkedList<int> s;
	s.push(4);
	s.push(8);
	s.appendNode(7);

	int s_values[] = { 72, 53, 6, 9 };
	s.appendNodes(s_values, 4);

	int s_nums[] = { 84, 18, 65, 423, 17 };
	s.pushArray(s_nums, 5);

	cout << "s" << endl;
	cout << "forwards using print" << endl;
	s.print(s.getHead());
	cout << "size of s => " << s.getSize() << endl;
	cout << endl;

	s.pop();
	--s;
	++s;
	s++;

	cout << "forwards using print" << endl;
	s.print(s.getHead());
	cout << endl;

	cout << "ostream operator output" << endl;
	cout << s;
	cout << "size of s => " << s.getSize() << endl;
	cout << endl;

	cout << "reverse using reversePrint" << endl;
	s.reversePrint(s.getHead());
	cout << endl;

	/*
	cout << "BubbleSort applied to s" << endl;
	s.BubbleSort(1);
	s.print(s.getHead());
	cout << endl;
	*/

	Node<int>** ptrA = new Node<int>*;
	*ptrA = s.getHead();

	/*
	cout << "quickSort applied to s" << endl;
	s.quickSort(ptrA);

	s.print(s.getHead());
	cout << endl;
	*/

	LinkedList<int> d(s);
	cout << "d" << endl;
	d.print(d.getHead());
	cout << endl;

	LinkedList<int> e;
	e = d;
	cout << "e" << endl;
	cout << "e = d" << endl;
	e.print(e.getHead());
	cout << "size of e => " << e.getSize() << endl;
	cout << "size of d => " << d.getSize() << endl;
	cout << endl;

	cout << "e = d + s" << endl;
	
	e = e + 444;
	//e = d + s;
	e.print(e.getHead());
	cout << endl;

	LinkedList<int> f;

	int f_values[] = { 78, 55, 142, 9663, 4 };
	f.appendNodes(f_values, 5);

	cout << "f" << endl;
	f.print(f.getHead());
	cout << endl;

	LinkedList<int> g;
	g = f + 72;
	g.print(g.getHead());

	g = g - 4;
	g.print(g.getHead());

	g -= 78;
	cout << "g before" << endl;
	g.print(g.getHead());

	

	g -= f;

	g = f + 79;
	g.appendNode(70);
	g.appendNode(800);
	g.appendNode(963);
	g.appendNode(1);
	//g += f;
	//g = g + f;

	//g -= f;
	//g = g - f;

	cout << "g" << endl;
	g.print(g.getHead());
	cout << endl;

	g.toFront(142);
	g.print(g.getHead());
	cout << endl;

	g.toEnd(9663);
	g.print(g.getHead());
	cout << endl;

	cout << "g reversed using reversePrint" << endl;
	g.reversePrint(g.getHead());
	cout << endl;

	cout << "BubbleSort applied to g and appended 85 (before sort) plus pushed 27 (after sort) " << endl;
	g.appendNode(85);
	g.BubbleSort(1);
	g.push(27);
	g.print(g.getHead());
	cout << endl;

	cout << "size of g => " << g.getSize() << endl;

	cout << "g.insertAtIndex(94, 12)" << endl;
	g.insertAtIndex(94, g.getSize());
	g.print(g.getHead());
	cout << endl;

	cout << "g.insertAtIndex(100, 12) and g.insertAtIndex(452, 0) and g.insertAtIndex(754, 2)" << endl;
	g.insertAtIndex(100, g.getSize());
	g.insertAtIndex(452, 0);
	g.insertAtIndex(754, 2);
	g.print(g.getHead());
	cout << endl;

	
	LinkedList<int> x;
	x.appendNode(7);
	x.appendNode(2);
	x.appendNode(32);

	cout << "x" << endl;
	x.print(x.getHead());
	cout << endl;

	cout << "size of g => " << g.getSize() << endl;
	cout << "g.insertAtIndex(x, 16)" << endl;
	g.insertAtIndex(x, 16);
	g.print(g.getHead());
	cout << endl;

	int lava[] = { 19, 62, 25, 107, 4 };

	cout << "g.insertAtIndex(lava, 5, 19)" << endl;
	g.insertAtIndex(lava, 5, 19);
	g.print(g.getHead());
	cout << endl;

	cout << "g.removeAtIndex(4)" << endl;
	g.removeAtIndex(4);
	g.print(g.getHead());
	cout << endl;

	cout << "g.removeRange(2, 8)" << endl;
	g.removeRange(2, 8);
	g.print(g.getHead());
	cout << endl;

	g.moveValue(62, 6);
	g.moveValue(2, 0);
	g.print(g.getHead());

	cout << "g reversed using reversePrint" << endl;
	g.reversePrint(g.getHead());
	cout << endl;

	cout << "------------END OF THE MAIN.CPP OUTPUT--------------" << endl;
	return 0;

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

	list.push(9);
	

	
	if (list.toFront(4)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	
	

	list.print(list.getHead());

	cout << endl;
	cout << "listCopy" << endl;

	LinkedList<int> listCopy(list);

	listCopy.print(listCopy.getHead());
	cout << endl;

	cout << "list head value => " << list.getHead()->getData() << endl;
	cout << "listCopy head value => " << listCopy.getHead()->getData() << endl;
	

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
	Node<int>** ptr = new Node<int>*;
	*ptr = list.getHead();

	cout << "quickSort applied" << endl;
	list.quickSort(ptr);

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
	list2.BubbleSort(1);

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