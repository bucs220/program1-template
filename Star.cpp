#include "Star.h"
#include "Planet.h"
#include "List.h"
#include "Vector.h"
#include <iostream>

Starvector::Starvector(){
	current_planets = 0;
	vec_star = new Vector();
}

Starvector::~Starvector(){
	delete vec_star;

}

long Starvector::addPlanet(){
	int rand_dis = rand() % 3000;
	Planet * new_planet = new Planet(rand_dis);
	vec_star -> insert(current_planets, new_planet);
	current_planets = current_planets + 1;

	return (unsigned)new_planet->getID();
}

#if 1
bool Starvector::findPlanet(long id){
	for(int i = 0; i <current_planets; i++){
		Planet * temp_planet = vec_star->read(i);
		if(temp_planet->getID() == id)
			return true;
	}
	return false;
}
#endif

bool Starvector::removePlanet(long id){
	if(findPlanet(id)){
		int find_index;
		for(int i = 0; i <current_planets; i++){
			Planet * temp_planet = vec_star->read(i);
			if(temp_planet->getID() == id)
				find_index = i;
		}
		current_planets = current_planets - 1;
		if(vec_star->remove(find_index))
			return true;		
	}
	return false;
}

#if 1
Planet * Starvector::getPlanet(long id){
	for(int i = 0; i <current_planets; i++){
		Planet * temp_planet = vec_star->read(i);
		if(temp_planet->getID() == id)
			return vec_star-> read(i);
	}
	return NULL;
}
#endif

#if 1
void Starvector::orbit(){
	for(int i = 0; i <current_planets; i++){
		Planet * temp_planet = vec_star->read(i);
		temp_planet->orbit();
	}
}
#endif

#if 1
void Starvector::printStarInfo(){
	std::cout << "The star currently has " << current_planets << " planets." << std::endl;

	std::cout << "Planets: " << std::endl;

	for(int i = 0; i < current_planets; i++){
		Planet * temp_planet = vec_star->read(i);	
	  	std::cout << "Planet " << temp_planet->getType() << temp_planet->getID() << " is " <<  temp_planet->getDistance() << " million miles away at positon " << temp_planet->getPos() << " around the star." << std::endl;
	}
}
#endif

Starlist::Starlist() {
	head = NULL;
	tail = NULL;
}

Starlist::~Starlist() {
	
	Node * temp = tail;
	while(temp ->previous != head){
		tail = tail -> previous;
		tail -> next = NULL;
		delete temp -> list_star;
		delete temp;
		temp = tail;
	}

	delete head ->list_star;
	delete tail -> list_star;
	head ->list_star = NULL;
	tail -> list_star = NULL;
	delete head;
	delete tail;
	head = NULL;
	tail = NULL;
}

long Starlist::addPlanet(){

	int rand_dis = rand() % 3000;
	Planet * new_planet = new Planet(rand_dis);
	list_star -> insert(current_planets, new_planet);
	current_planets = current_planets + 1;
	
	//temp->list_planet = new_planet;	
	
	//tail = temp;

	return (unsigned)new_planet->getID();
	
}

bool Starlist::removePlanet(long id) {

/*
	if(findPlanet(id)){
		int find_index;
		for(int i = 0; i <current_planets; i++){
			Planet * temp_planet = vec_star->read(i);
			if(temp_planet->getID() == id)
				find_index = i;
		}
		current_planets = current_planets - 1;
		if(vec_star->remove(find_index))
			return true;		
	}
	return false;
*/
	
	Node * temp = head;
	if(temp->list_star->getID() == id) {
		delete temp->list_star->read(id);
		temp->list_star->read(id) = NULL;
		current_planets--;
		return true;
	}
	while(temp->next != NULL){
		temp = temp->next;
		if(temp->list_star->getID() == id) {
			delete temp->list_star->read(id);
			temp->list_star->read(id) = NULL;
			current_planets--;
			return true;
		}
	}
	return false;
	
}

Planet * Starlist::getPlanet(long id) {

	Node * temp = head;
	if(temp->list_star->getID() == id) {
		return temp->list_star->read(id);
	}
	while(temp->next != NULL){
		temp = temp->next;
		if(temp->list_star>getID() == id) {
			return temp->list_star->read(id);
		}
	}
	return NULL;
}

void Starlist::orbit() {
	Node * temp = head;	
	while(temp != NULL) {
		long id = temp->list_star->getID();
		temp->list_star->read(id)->orbit();
		temp = temp->next;
	}
}

void Starlist::printStarInfo() {
	Node * temp = head;
	
	std::cout << "The star currently has " << current_planets << " planets." << std::endl;

	std::cout << "Planets: " << std::endl;

	while(temp != NULL) {	
		long id = temp->list_star->getID();
		std::cout << "Planet " << temp->list_star->read(id)->getType() << temp->list_star->read(id)->getID() << " is " <<  temp->list_star->read(id)->getDistance() << " million miles away at positon " << temp->list_star->read(id)->getPos() << " around the star." << std::endl;
		temp = temp->next;
	}
}

unsigned int Starlist::getCurrentNumPlanets() {
	unsigned int count = 0;
	Node * temp = head;	
	while(temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}
