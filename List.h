#ifndef LIST_H
#define LIST_H
#include "Planet.h"

class Node {
	public:
		Planet *p;
		Node *next;
		Node *previous;
};

class List {
	private:
		Node *head, *tail;
	public:
		List();
		~List();
		void insert(int, Planet*);
		Planet* read(int);
		bool remove(int);
		unsigned size();
};

#endif
