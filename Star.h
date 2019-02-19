#ifndef HEADER_BR
#define HEADER_BR
#include "Planet.h"

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
        	unsigned int getCurrentNumPlanets(){}
};



#endif
