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


class Starlist{
	private:
		int current_planets;
	public:
		List * list_star;
		Starlist();
		~Starlist();
		long addPlanet();
		bool findPlanet(long);
		bool removePlanet(long);
		Planet * getPlanet(long);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets(){return this->current_planets;}
};
#endif
