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
		bool removePlanet(int);
		bool findPlanet(int);
		Planet * getPlanet(int);
       		Planet getFurthest();
        	void orbit();
        	void printStarInfo();
        	unsigned int getCurrentNumPlanets(){return this->current_planets;}
};


class Starlist {
	private:
		Node * head, * tail;
	public:
		Starlist();
		~Starlist();
		long addPlanet();
		bool removePlanet(int);
		Planet * getPlanet(int);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets();
};


#endif
