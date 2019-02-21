#include "List.h"
#include <stdlib.h>
#include "Star.h"
#include "Planet.h"
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
	
	Node *temp = head;
	int temp_index = 0;
	
	if (size() <= index) {
		while(temp->next != NULL) {
			temp_index++;
			temp->next->previous = temp;
			temp = temp->next;
			
			if (temp_index == index) {
				temp->p = p;
				temp->next->previous = temp;
				temp = temp->next;
				break;
			}
		}
	} else {
		while(temp->next != NULL) {
			temp_index++;
			temp->next->previous = temp;
			temp = temp->next;
			
			if (temp->next == NULL) {
				temp->next->previous = temp;
				temp = temp->next;
				temp->p = p;
				break;
			}
		}
	}
	
	head = temp;
}

Planet* List::read(int index) {
	
	if(head == NULL) {
		return NULL;
	}
	
	Node *temp = head;
	int temp_index = 0;
	
	while(temp->next != NULL) {
		temp_index++;
		temp = temp->next;
		
		if (temp_index == index) {
			return temp->p;
		}
	}
	
	return NULL;
}

bool List::remove(int index) {
	
	Node *temp = head;
	int temp_index = 0;
	
	if (size() <= index) {
		while(temp->next != NULL) {
			temp_index++;
			temp->next->previous = temp;
			temp = temp->next;
			
			if (temp_index == index) {
				temp = temp->next;
				temp = temp->next->previous;
				
				head = temp;
				return true;
			}
			
		}
	} else {
		return false;
	}
}

unsigned List::size() {

	Node *temp = head;
	unsigned temp_index = 0;
	
	while(temp->next != NULL) {
		temp_index++;
		temp->next->previous = temp;
		temp = temp->next;	
	}
	
	return temp_index;
}
