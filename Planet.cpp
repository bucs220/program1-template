#include "Planet.h"
#include <iostream>

Planet::Planet(int distance){
	int rand_pos = rand() % 360;
	int rand_num = rand() % 3;

	this->id = &this;
	this->distance = distance;
    	this->position = rand_pos;

	if(rand_num == 0) 
		this->type = 'r';
	else if(rand_num == 1)
		this->type = 'h';
	else if (rand_num == 2)
		this->type = 'g';
}

int Planet::orbit(){
	if(position >= 0 && position < 359)
		position = position+1;
	else
		position = 0;
	return this->position;
}
