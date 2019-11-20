#include "LinkedList.cpp"

#include <vector>
#include <algorithm>

/*
links used:


*/

int main() {
	LinkedList<int> a;
	a.appendNode(5);
	a.appendNode(17);

	int numbers[] = { 7, 89, 65 };
	a.appendNodes(numbers, 3);

	int values[] = { 14, 42, 333 };
	a.pushArray(values, 3);

	cout << a;
	cout << "from both ends" << endl;
	a.printFromBothEnds(a.getHead(), a.getTail());

	cout << "a.deleteNodeNumber(a.getHead(), 3)" << endl;
	a.deleteNodeNumber(a.getHead(), 3);
	cout << a;

	cout << "from both ends" << endl;
	a.printFromBothEnds(a.getHead(), a.getTail());
	
	cout << "a.recursiveDelete(a.getHead())" << endl;
	//a.recursiveDelete(a.getHead());
	a.recursiveDelete(a.getTail());
	cout << a;
	cout << endl;

	return 0;

	a.pop();
	a.push(45);
	++a;
	a++;
	--a;

	a.print(a.getHead());
	a.removeRange(2, 5);

	cout << "size of a => " << a.getSize() << endl;
	a.print(a.getHead());
	a--;
	a.removeAtIndex(a.getSize() - 1);

	a.print(a.getHead());
	a.insertAtIndex(9, 2);
	a.insertAtIndex(147, 0);
	a.insertAtIndex(858, a.getSize());
	a.print(a.getHead());

	LinkedList<int> b;
	int b_values[] = { 85, 52, 25, 59659, 46 };
	b.appendNodes(b_values, 5);
	cout << "b" << endl;
	b.print(b.getHead());
	cout << endl;

	cout << "a.insertAtIndex(b, 4)" << endl;
	a.insertAtIndex(b, 4);
	a.print(a.getHead());

	cout << "size of a => " << a.getSize() << endl;

	cout << "a.insertAtIndex(s_values, 6, 3)" << endl;
	int s_values[] = { 96, 100, 3, 4777, 5, 17 };
	
	a.insertAtIndex(s_values, 6, 3);
	//a--;
	a.print(a.getHead());

	cout << "a.moveValue(42, 0)" << endl;
	a.moveValue(42, 0);
	a.moveValue(4777, 0);
	a.moveValue(89756465, 6);
	a.print(a.getHead());
	cout << endl;

	cout << "a" << endl;
	cout << "forwards using print" << endl;
	a.print(a.getHead());
	cout << endl;

	cout << "forwards using the ostream operator" << endl;
	cout << a;
	cout << endl;

	cout << "forwards using printTailForward" << endl;
	a.printTailForward(a.getTail());
	cout << endl;

	cout << "size of a => " << a.getSize() << endl;

	cout << "reverse using reversePrint" << endl;
	a.reversePrint(a.getHead());
	cout << endl;

	cout << "reverse using printFromTail" << endl;
	a.printFromTail(a.getTail());
	cout << endl;

	cout << "BubbleSort applied to a" << endl;
	a.BubbleSort(1, a.getHead());
	//a.BubbleSort(0, a.getHead());
	//a.BubbleSort(1, a.getTail());

	/*
	Node<int>** ptr = new Node<int>*;
	*ptr = a.getHead();
	a.quickSort(ptr);
	*/

	cout << "forwards using print" << endl;
	a.print(a.getHead());
	cout << endl;

	cout << "reverse using reversePrint" << endl;
	a.reversePrint(a.getHead());
	cout << endl;

	cout << "reverse using printFromTail" << endl;
	a.printFromTail(a.getTail());
	cout << endl;

	/*
	cout << "tail data: " << a.getTail()->getData() << endl;
	cout << "tail->next data: " << a.getTail()->next->getData() << endl;

	cout << "tail->prev data: " << a.getTail()->prev->getData() << endl;
	cout << "head data: " << a.getHead()->getData() << endl;

	if (a.getHead() == a.getTail()->next && a.getHead() == a.getTail()->prev) {
		cout << "apples" << endl;
 	}
	*/

	cout << "b" << endl;
	b.appendNode(7777);
	b.print(b.getHead());
	cout << endl;

	LinkedList<int> p(b);

	cout << "p" << endl;
	p.print(p.getHead());
	cout << endl;

	cout << "reversed using reversePrint" << endl;
	p.reversePrint(p.getHead());
	cout << endl;

	LinkedList<int> r;
	r = p + 7321;
	r = r + p;
	r -= p;
	r = r - p;
	
	/*
	r = r - r;
	r -= r;
	*/

	r = p - 52;
	r += 34;
	r.appendNode(7777);

	cout << "r.append(7777)" << endl;
	r.toFront(85);
	r.toFront(46);
	r.toEnd(25);
	r.toEnd(25);
	r.toEnd(59659);

	r.toFront(7777);
	r.print(r.getHead());
	r -= b;

	cout << "r" << endl;
	r.print(r.getHead());
	cout << endl;

	cout << "reversed using reversePrint" << endl;
	r.reversePrint(r.getHead());
	cout << endl;

	cout << "------------END OF THE MAIN.CPP OUTPUT--------------" << endl;

	return 0;
}