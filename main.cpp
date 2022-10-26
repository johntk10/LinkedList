// John Kutbay
// CS202
// 9/15/2022
// Lab 04: Adding List-Based Integers

#include "list.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

List *sumLists(List *list1, List *list2) {
	// This covers setting and allocating memory for my nodes and new sum list.
	List *sum = new List();
	Node *l1;
	l1 = list1->getHead();
	Node *l2;
	l2 = list2->getHead();
	
	bool l1Count;
	int list1Count = list1->getCount();
	bool l2Count;
	int list2Count = list2->getCount();
	bool same = false;
	int valCount = 0;
	bool run = true;
	bool carry = false;
	while (run == true) {		
		// This does some basic checks to see if the loop should be broken
		// because one or both of the list or lists are empty.
		valCount++;
		if (l1->next == NULL && l2->next != NULL) {
			l2Count = true;
			run = false;
		} else if (l2->next == NULL && l1->next != NULL) {
			l1Count = true;
			run = false;
		} else if (l1->next == NULL && l2->next == NULL) {
			run = false;
			same = true;
		}
		// The next stage checks if the sum needs to be carried and if it 
		// needs to set the next sum to be carried.
		if (carry == false) {
			if (l1->data + l2->data < 10) {
				sum->addNode(l1->data + l2->data);
			} else {
				carry = true;
				sum->addNode(l1->data + l2->data - 10);
			}
		} else {
			if (l1->data + l2->data + 1 < 10) {
				sum->addNode(l1->data + l2->data + 1);
				carry = false;
			} else {
				sum->addNode(l1->data + l2->data + 1 - 10);
			}
		}
		// This checks if the number of nodes is the same, which
		// would only be known true if they were the same and the next
		// node was NULL, thus if needed, it will add the extra 1.
		if (same == true) {
			if (carry == true) {
				sum->addNode(1);
			}
		} else {
			l1 = l1->next;
			l2 = l2->next;
		}
	}
	// These if statements finish up the sum if one number is larger than another 
	// in digits, adding its values one by one, carrying if necessary.
	if (l2Count == true) {
		for (int t = valCount;t < list2Count;t++) {
			if (carry == false) {
				sum->addNode(l2->data);
			} else {
				if (l2->data + 1 < 10) {
					sum->addNode(l2->data + 1);
					carry = false;
				} else {
					sum->addNode(l2->data + 1 - 10);
				}
			}
			if (l2->next != NULL) {
				l2 = l2->next;
			}
		}
		if (carry == true) {
			sum->addNode(1);
		}
	} else if (l1Count == true) {
		for (int t = valCount;t < list1Count;t++) {
			if (carry == false) {
				sum->addNode(l1->data);
			} else {
				if (l1->data + 1 < 10) {
					sum->addNode(l1->data + 1);
					carry = false;
				} else {
					sum->addNode(l1->data + 1 - 10);
				}
			}
			if (l1->next != NULL) {
				l1 = l1->next;
			}
		}
		if (carry == true) {
			sum->addNode(1);
		}
	}
	return sum;
}

int main() {
	int value1;
	int value2;
	string v1;
	string v2;
	stringstream ss;
	// This is a simple while loop that continues taking values, 
	// breaking them into single digits, and converting them to integers
	// Finally they are stored.
	while (cin >> v1 >> v2) {
		List *list1 = new List();
		List *list2 = new List();
		for (int i = v1.length() - 1;i >= 0;i--) {
			ss.clear();
			ss.str("");
			ss << v1[i];
			ss >> value1;
			list1->addNode(value1);
		}
		for (int i = v2.length() - 1;i >= 0;i--) {
			ss.clear();
			ss.str("");
			ss << v2[i];
			ss >> value2;
			list2->addNode(value2);
		}
		List *sum;
		sum = sumLists(list1, list2);
		sum->print();
		cout << endl;
		// I finish by deallocating the memory I used. My memory check does 
		// not pass and I am not sure why. Could I get feedback as to a 
		// possible reason when graded please?
		delete list1;
		delete list2;
		delete sum;
	}
}


