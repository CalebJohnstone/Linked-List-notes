#include <iostream>

using namespace std;

void moveDiscs(int, int, int, int);

int count = 0;

int main() {
	const int NUM_DISCS = 3;
	const int FROM_PEG = 1;
	const int TO_PEG = 3;
	const int TEMP_PEG = 2;

	//cout << "moveDiscs(3, 1, 3, 2);" << endl;

	moveDiscs(NUM_DISCS, FROM_PEG, TO_PEG, TEMP_PEG);
	cout << "All of the pegs have been moved!" << endl;

	cout << "count = " << count << endl;

	return 0;
}

void moveDiscs(int num, int fromPeg, int toPeg, int tempPeg) {
	//cout << "moveDiscs(" << num << ", " << fromPeg << ", " << toPeg << ", " << tempPeg << ");" << endl;

	if (num > 0) {
		//cout << "moveDiscs(" << (num - 1) << ", " << fromPeg << ", " << tempPeg  << ", " << toPeg << ");" << endl;

		moveDiscs(num - 1, fromPeg, tempPeg, toPeg);

		cout << "Move a disc from peg " << fromPeg << " to peg " << toPeg << endl;
		count++;

		//cout << "moveDiscs(" << (num - 1) << ", " << tempPeg << ", " << toPeg << ", " << fromPeg << ");" << endl;
		moveDiscs(num - 1, tempPeg, toPeg, fromPeg);
	}
}