#ifndef HEADER_RGBR
#define HEADER_RGBR
#include "Planet.h"
#include "List.h"
#include <iostream>

class Starvector{
	private:
        	int current_planets;
	public:
        	Planet ** planets;
        	Starvector();
		~Starvector();
        	long addPlanet();
		bool removePlanet(long);
		bool findPlanet(long);
		Planet * getPlanet(long);
       		Planet getFurthest();
        	void orbit();
        	void printStarInfo();
        	unsigned int getCurrentNumPlanets(){return this->current_planets;}
};


class Starlist {
	private:
		int current_planets;
		Node * head, * tail;
		Planet * list_planet;
		//Node (Planet * temp_planet){list_planet = temp_planet; next = NULL; previous = NULL;}
	public:
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
