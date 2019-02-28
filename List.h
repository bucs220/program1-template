#ifndef LIST_H
#define LIST_H
#include "Planet.h"
#include <iostream>

class Node{
	public:
		Planet * list_planet;
		Node * next;
		Node * previous;
		Node (Planet * temp_planet){list_planet = temp_planet; next = NULL; previous = NULL;}
};

class List{
	private:
		Node * head, * tail;
	public:
		List();
		~List();
		void insert(int, Planet *);
		Planet * read(int);
		bool remove(int);
		unsigned size();
};
#endif
