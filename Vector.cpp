#include "Star.h"
#include "Planet.h"
#include "Vector.h"
#include <iostream>

Vector::Vector(){
	size = 0;
	vec_planets = NULL;
}

Vector::~Vector(){
	for(int i = 0; i< current_planets; i++)
		delete vec_planets[i];

	delete [] vec_planets;
}

void Vector::insert(int index, Planet* new_planet){
	if(size < index){
		Planet ** temp_vec = new Planets*[index+1];
		for(int i = 0; i < size; i++)
			temp_vec[i] = vec_planets[i];
		
		temp_vec[index] = new_planet;
		size = index + 1;	
	}
	else{
		Planet ** temp_vec = new Planets*[size+1];
		for(int i = 0; i < size; i++)
			temp_vec[i] = vec_planets[i];
		temp_vec[index] = new_planet;
		size = size +1;
	}
	
	delete [] vec_planets;
	vec_planets = temp_vec;	
}

Planet * Vector::read(int index){
	if(index > size)
		return NULL;

	else
		return vec_planets[index];

}

bool Vector::remove(int index){
	if(index < size){
		Planet *temp_planet;
		temp_planet = vec_planets[index];
		Planet ** temp_vec = new Planet*[size-1];
		int j = 0;
		for(int i = 0; i < size; i++){
			if(index != i){
				temp_vec[j] = vec_planets[i]; 
				j++;		
			}
		}
	delete temp_planet;

	size = size - 1;	

	delete [] vec_planets;
	vec_planets = temp_vec;
	
	return true;
	}

	return false;
}

unsigned Vector::size(){
	return this->size;

}

