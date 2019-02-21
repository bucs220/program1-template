#ifndef HEADER_BR
#define HEADER_BR
#include "Planet.h"
#include "List.h"

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
		Node *head, *tail;
	public:
		Starlist();
		~StarList();
		long addPlanet();
		bool removePlanet(int);
		Planet * getPlanet(int);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets();
};


#endif
