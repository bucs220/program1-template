#include "Star.h"
#include "Planet.h"
#include "List.h"
#include "Vector.h"
#include <iostream>

Starvector::Starvector(){
	current_planets = 0;
	planets = NULL;
}

Starvector::~Starvector(){
	for(int i = 0; i< current_planets; i++)
		delete planets[i];

	delete [] planets;

}

long int Starvector::addPlanet(){
	int rand_dis = rand() % 3000;
	Planet** tem_planets = new Planet*[current_planets+1];
	for(int i = 0; i < current_planets; i++){
		tem_planets[i] = planets[i];
	}

	Planet * new_planet = new Planet(rand_dis);
	tem_planets[current_planets] = new_planet;	

	delete [] planets;
	planets = tem_planets;
	current_planets = current_planets + 1;

	return (unsigned)new_planet->getID();
}

#if 1
bool Starvector::findPlanet(long id){
	for(int i = 0; i <current_planets; i++){
		if(planets[i]->getID() == id)
			return true;
	}
	return false;
}
#endif

#if 1
bool Starvector::removePlanet(long id){
	if(findPlanet(id)){
		Planet *temp_planet; 
		int j = 0;			
		Planet ** tem_planets = new Planet*[current_planets-1];
		for(int i = 0; i < current_planets; i++){
			if(planets[i]->getID() != id){
				tem_planets[j] = planets[i];
				j++;
			}
			else
				temp_planet = planets[i];
		}
	delete temp_planet;

	current_planets = current_planets - 1;	

	//for(int i = 0; i< current_planets; i++)
		//delete planets[i];

	delete [] planets;
	planets = tem_planets;
	
	return true;	
	}

	return false;
}
#endif

#if 1
Planet* Starvector::getPlanet(long id){
	for(int i = 0; i < current_planets; i++){
		if(planets[i]->getID() == id)
			return planets[i];
	}
	return NULL;

}
#endif

#if 1
void Starvector::orbit(){
	for(int i = 0; i <current_planets; i++)
		planets[i]->orbit();
}
#endif

#if 1
void Starvector::printStarInfo(){
  std::cout << "The star currently has " << current_planets << " planets." << std::endl;

	std::cout << "Planets: " << std::endl;

	for(int i = 0; i < current_planets; i++){	
	  std::cout << "Planet " << planets[i]->getType() << planets[i]->getID() << " is " <<  planets[i]->getDistance() << " million miles away at positon " << planets[i]->getPos() << " around the star." << std::endl;
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

long Starlist::addPlanet(){
	
	int rand_dis = rand() % 3000;
	
	Node * temp = head;
	//Planet * temp_planets = new Planet * list_planet;
	
	while(temp->next != NULL){
		temp = temp->next;
	}

	Planet * new_planet = new Planet(rand_dis);
	temp->list_planet = new_planet;	

	//delete [] list_planet;
	//list_planet = temp_planets;
	current_planets = current_planets + 1;
	
	tail = temp;

	return (unsigned)new_planet->getID();
	
}

bool Starlist::removePlanet(long id) {
	
	Node * temp = head;
	if(temp->list_planet->getID() == id) {
		delete temp->list_planet;
		temp->list_planet = NULL;
		return true;
	}
	while(temp->next != NULL){
		temp = temp->next;
		if(temp->list_planet->getID() == id) {
			delete temp->list_planet;
			temp->list_planet = NULL;
			return true;
		}
	}
	return false;
	
}

Planet * Starlist::getPlanet(long id) {
	Node * temp = head;
	if(temp->list_planet->getID() == id) {
		return temp->list_planet;
	}
	while(temp->next != NULL){
		temp = temp->next;
		if(temp->list_planet->getID() == id) {
			return temp->list_planet;
		}
	}
	return NULL;
}

void Starlist::orbit() {
	Node * temp = head;	
	while(temp != NULL) {
		temp->list_planet->orbit();
		temp = temp->next;
	}
}

void Starlist::printStarInfo() {
	Node * temp = head;
	
	std::cout << "The star currently has " << current_planets << " planets." << std::endl;

	std::cout << "Planets: " << std::endl;

	while(temp != NULL) {	
		std::cout << "Planet " << temp->list_planet->getType() << temp->list_planet->getID() << " is " <<  temp->list_planet->getDistance() << " million miles away at positon " << temp->list_planet->getPos() << " around the star." << std::endl;
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
