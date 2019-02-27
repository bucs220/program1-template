#ifndef HEADER_RGBR
#define HEADER_RGBR
#include "Star.h"
#include "Planet.h"
#include "List.h"
#include "Vector.h"
#include <iostream>

class Starvector{
	private:
        	int current_planets;
	public:
        	Vector * vec_star;
        	Starvector();
		~Starvector();
        	long addPlanet();
		bool removePlanet(long);
		bool findPlanet(long);
		Planet * getPlanet(long);
        	void orbit();
        	void printStarInfo();
        	unsigned int getCurrentNumPlanets(){return this->current_planets;}
};

/*
class Node {
	public:
		Star * list_star;
		Starnode * next;
		Starnode * previous;
		Node (Star * temp_star){list_star = temp_star; next = NULL; previous = NULL;}
};
*/



class Starlist {
	private:
		int current_planets;
		Node * head, * tail;
		//Node (Planet * temp_planet){list_planet = temp_planet; next = NULL; previous = NULL;}
	public:
		List * list_star;
		Starlist();
		~Starlist();
		long addPlanet();
		bool removePlanet(long);
		Planet * getPlanet(long);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets();
};


#endif
