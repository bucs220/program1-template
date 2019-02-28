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

bool Starvector::findPlanet(long id){
	for(int i = 0; i <current_planets; i++){
		Planet * temp_planet = vec_star->read(i);
		if(temp_planet->getID() == id)
			return true;
	}
	return false;
}

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

Planet * Starvector::getPlanet(long id){
	for(int i = 0; i <current_planets; i++){
		Planet * temp_planet = vec_star->read(i);
		if(temp_planet->getID() == id)
			return vec_star-> read(i);
	}
	return NULL;
}

void Starvector::orbit(){
	for(int i = 0; i <current_planets; i++){
		Planet * temp_planet = vec_star->read(i);
		temp_planet->orbit();
	}
}

void Starvector::printStarInfo(){
	std::cout << "The starvector currently has " << current_planets << " planets." << std::endl;

	std::cout << "Planets: " << std::endl;

	for(int i = 0; i < current_planets; i++){
		Planet * temp_planet = vec_star->read(i);	
	  	std::cout << "Planet " << temp_planet->getType() << temp_planet->getID() << " is " <<  temp_planet->getDistance() << " million miles away at positon " << temp_planet->getPos() << " around the star." << std::endl;
	}
}

Starlist::Starlist(){
	list_star = new List();
	current_planets = 0;
}

Starlist::~Starlist() {
	delete list_star;
}

long Starlist::addPlanet(){
	int rand_dis = rand() % 3000;
	Planet * new_planet = new Planet(rand_dis);
	list_star -> insert(current_planets, new_planet);
	current_planets = current_planets + 1;
	
	return (unsigned)new_planet->getID();
	
}

bool Starlist::findPlanet(long id){
	for(int i = 0; i <current_planets; i++){
		Planet * temp_planet = list_star->read(i);
		if(temp_planet->getID() == id)
			return true;
	}
	return false;
}


bool Starlist::removePlanet(long id) {
	if(findPlanet(id)){
		int find_index;
		for(int i = 0; i <current_planets; i++){
			Planet * temp_planet = list_star->read(i);
			if(temp_planet->getID() == id)
				find_index = i;
		}
		current_planets = current_planets - 1;
		if(list_star->remove(find_index))
			return true;		
	}
	return false;	
}

Planet * Starlist::getPlanet(long id) {
	for(int i = 0; i <current_planets; i++){
		Planet * temp_planet = list_star->read(i);
		if(temp_planet->getID() == id)
			return list_star-> read(i);
	}
	return NULL;
}

void Starlist::orbit() {
	for(int i = 0; i <current_planets; i++){
		Planet * temp_planet = list_star->read(i);
		temp_planet->orbit();
	}
}

void Starlist::printStarInfo() {
	std::cout << "The starlist currently has " << current_planets << " planets." << std::endl;

	std::cout << "Planets: " << std::endl;

	for(int i = 0; i < current_planets; i++){
		Planet * temp_planet = list_star->read(i);	
	  	std::cout << "Planet " << temp_planet->getType() << temp_planet->getID() << " is " <<  temp_planet->getDistance() << " million miles away at positon " << temp_planet->getPos() << " around the star." << std::endl;
	}
}
