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
	
}

long Starlist::addPlanet(){
	
}

bool Starlist::removePlanet(long id) {
	
}

Planet * Starlist::getPlanet(long id) {
	
}

void Starlist::orbit() {
	
}

void Starlist::printStarInfo() {
	
}

unsigned int Starlist::getCurrentNumPlanets() {
	
}
