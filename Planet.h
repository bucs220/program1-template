#ifndef HEADER_BR1
#define HEADER_BR1

class Planet{
	private:
		long int id;
		int position;
		int distance;
		char type;
	public:
		Planet(int);
        	int orbit();
		long int getID(){return (unsigned)id;}
        	int getDistance(){return this->distance;}
        	int getPos(){return this->position;}
		char getType(){return this->type;}
};

#endif

