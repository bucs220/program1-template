#include "list.h"
#include <stdlib.h>
#include <iostream>
#include <ctime> 
#include <cstdlib>

List::List() {
	Node *head = NULL;
	Node *tail = NULL;
}

List::~List() {
	delete head;
	head = NULL;
}

void List::insert(int index, Planet *p) {
	
	Node temp = head;
	Node newhead = head;
	int temp_index = 0;
	
	if (size() <= index) {
		while(temp->next != NULL) {
			temp_index++;
			temp = temp->next;
			newhead = newhead->next;
			
			if (temp_index = index) {
				newhead->p = p;
				newhead = newhead->next;
				break;
			}
		}
	} else {
		while(temp->next != NULL) {
			temp_index++;
			temp = temp->next;
			newhead = newhead->next;
			
			if (temp->next = NULL) {
				newhead = newhead->next;
				newhead->p = p;
				break;
			}
		}
	}
	
	head = newhead;
}

Planet* List::read(int index) {
	
	if(head == NULL) {
		return NULL;
	}
	
	Node temp = head;
	int temp_index = 0;
	
	while(temp->next != NULL) {
		temp_index++;
		temp = temp->next;
		
		if (temp_index = index) {
			return temp->p;
		}
	}
	
	return NULL:
}

bool List::remove(int index) {

}

unsigned List::size() {

	Node temp = head;
	unsigned temp_index = 0;
	
	while(temp->next != NULL) {
		temp_index++;
		temp = temp->next;		
	}
	
	return temp_index;
}
