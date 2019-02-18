#ifndef lIST_H
#define LIST_H

class Node {
public:
	Planet *p;
	Node *next;
};

class List {
private:
	Node *head, *tail;
};

#endif
