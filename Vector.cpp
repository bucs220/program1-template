#include "Star.h"
#include "Planet.h"
#include "Vector.h"
#include <iostream>

Vector::Vector(){
	vec_size = 0;
	vec_planets = NULL;
}

Vector::~Vector(){
	for(int i = 0; i< vec_size; i++)
		delete vec_planets[i];

	delete [] vec_planets;
}

void Vector::insert(int index, Planet * new_planet){
	if(vec_size < index){
		Planet ** temp_vec = new Planet*[index+1];
		for(int i = 0; i < index; i++){
			temp_vec[i] = NULL;
			if(i < vec_size)
				temp_vec[i] = vec_planets[i];
		}
		
		temp_vec[index] = new_planet;
		vec_size = index + 1;
		delete [] vec_planets;
		vec_planets = temp_vec;	
	}
	else{
		Planet ** temp_vec = new Planet*[vec_size+1];
		for(int i = 0; i < vec_size; i++)
			temp_vec[i] = vec_planets[i];
		temp_vec[index] = new_planet;
		temp_vec[vec_size] = new Planet(0);
		vec_size = vec_size +1;
		delete [] vec_planets;
		vec_planets = temp_vec;	
	}	
}

Planet * Vector::read(int index){
	if(index > vec_size)
		return NULL;

	else if(vec_planets[index] == NULL)
		return NULL;

	return vec_planets[index];
}

bool Vector::remove(int index){
	if(index < vec_size){
		Planet *temp_planet;
		temp_planet = vec_planets[index];
		Planet ** temp_vec = new Planet*[vec_size-1];
		int j = 0;
		for(int i = 0; i < vec_size; i++){
			if(index != i){
				temp_vec[j] = vec_planets[i]; 
				j++;		
			}
		}
	delete temp_planet;

	vec_size = vec_size - 1;	

	delete [] vec_planets;
	vec_planets = temp_vec;
	
	return true;
	}

	return false;
}

#if 0
unsigned int Vector::size(){
	return this->size;

}
#endif

