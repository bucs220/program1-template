#include "List.h"
#include <stdlib.h>
#include "Star.h"
#include "Planet.h"
#include <iostream>
#include <ctime> 
#include <cstdlib>

List::List() {
	head = NULL;
	tail = NULL;
}

List::~List() {
	Node * temp = tail;
	while(temp ->previous != head){
			tail = tail -> previous;
			tail -> next = NULL;
			delete temp -> list_planet;
			delete temp;
			temp = tail;
		}

		delete head ->list_planet;
		delete tail -> list_planet;
		head ->list_planet = NULL;
		tail -> list_planet = NULL;
		delete head;
		delete tail;
		head = NULL;
		tail = NULL;
}

void List::insert(int index, Planet * new_planet) {
	Node * temp = head;
	Node * input_node = new Node(new_planet);
	int temp_index = 0;

	if(head == NULL){
		head = input_node;
		tail = head;
		return;
	}
	
	if(index == 0){
		input_node -> next = head;
		head -> previous = input_node;
		head = input_node;
		return;
	}
	
	if (size() > index){
		while(temp != NULL){
			temp_index++;
			temp->next->previous = temp;
			temp = temp->next;

			if (temp_index == index) {
				input_node->previous = temp;
				input_node->next = temp->next;
				temp->next = input_node;
			}
			tail = temp -> previous;
			delete temp -> list_planet;
			temp -> list_planet = NULL;
			delete temp;
			temp = NULL;
			
		}	
	}
	else{
		input_node -> previous = tail;
		tail -> next = input_node;
		tail = input_node;
	}	

	#if 0
	if (list_size <= index) {
		while(temp->next != NULL) {
			temp_index++;
			temp->next->previous = temp;
			temp = temp->next;
		}

		if (temp_index == index) {
			temp -> list_planet = new_planet;
			temp->next->previous = temp;
			temp = temp->next;
		}
	} 
	else {
		while(temp->next != NULL) {
			temp_index++;
			temp->next->previous = temp;
			temp = temp->next;
			
			if (temp->next == NULL) {
				temp->next->previous = temp;
				temp = temp->next;
				temp-> list_planet = new_planet;
				break;
			}
		}
	}
	
	//head = temp;
	#endif
}

Planet * List::read(int index) {
	
	if(head == NULL) 
		return NULL;
	
	Node * temp = head;
	int temp_index = 0;

	if(index > size())
		return NULL;

	else{
		if(index == 0)
			return temp->list_planet;

		while(temp->next != NULL) {
		temp_index++;
		temp = temp->next;
		
		if (temp_index == index) 
			return temp-> list_planet;
		}
	}	
	return NULL;
}

bool List::remove(int index) {
	
	Node * temp = head;
	int temp_index = 0;
	
	if (size() < index) 	
		return false;

	else{
		if(index == 0){
			head = head ->next;
			head -> previous = NULL;
			delete temp -> list_planet;
			delete temp;
			temp = head;
			return true;
		}

		while(temp != NULL) {
			temp_index++;
			temp = temp->next;
		
			if (temp_index == index){
				temp -> previous -> next = temp -> next;
				temp -> next -> previous = temp -> previous;
				delete temp -> list_planet;
				temp -> list_planet = NULL;
				delete temp;
				temp = NULL;
				return true;
			}
		}
	}

		#if 0

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
		#endif
	return false;
}

unsigned List::size() {
	Node * temp = head;
	int temp_index = 0;
	
	if(head == NULL)
		return 0;
		
	while(temp != NULL) {
		temp_index++;
		temp = temp->next;	
	}
	
	return temp_index;
}
