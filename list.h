#ifndef LIST_H
#define LIST_H

class Node {
	public:
		Node(int);
		int data;
		Node *next;
};
class List {
	private:
		Node *head;
		Node *newNode(int);
		int count;
	public:
		List();
		~List();
		void addNode(int);
		bool empty();
		int getCount();
		Node *getHead();
		void print();
};

#endif
