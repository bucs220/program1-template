#ifndef HEADER_BR2
#define HEADER_BR2
#include "Star.h"
#include "Planet.h"

class Vector{
	private:
		int size;
	public:
		Planet ** vec_planets;
		~Vector();
		void insert(int, Planet*);
		Planet * read(int);
		bool remove(int);
		unsigned size();
};

#endif

