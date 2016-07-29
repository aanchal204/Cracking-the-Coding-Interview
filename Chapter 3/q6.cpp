/*
Animal Shelter: An animal shelter, which holds only dogs and cats, operates on astrcitly 'first in, first out' basis.
People must adopt either the oldest of all animals at the shelter, or they can select whether they would
prefer a dog or a cat(and would receive the oldest of that type).They cannot select which specific animal
they would like. Create a data structure to maintain this system and implement operations such as 
enQueue, deQueueAny, deQueueDog and deQueueCat. You may use the built-in LinkedList data structure. 
*/

#include<list>
#include<iostream>
#define CAT 1
#define DOG 2
using namespace std;
class AnimalShelter{
public:
	list<int> cats;
	list<int> dogs;
	int timestamp ;
	AnimalShelter(){
		timestamp = 0;
	}

	void enQueue(int type){
		if(type == CAT)
			cats.push_back(timestamp++);
		else
			dogs.push_back(timestamp++);
	}

	int deQueueAny(void){
		if(cats.empty() && dogs.empty()){
			cout<<"No animals available"<<endl;
			return -1;
		}
		if(cats.empty())
			return deQueueDog();
		else if(dogs.empty())
			return deQueueCat();
		else{
			int cat = cats.front();
			int dog = dogs.front();
			if(cat < dog)
				return deQueueCat();
			else
				return deQueueDog();
		}
	}

	int deQueueCat(void){
		if(!cats.empty()){
			cout<<"Dequeuing cat"<<endl;
			int cat = cats.front();
			cats.pop_front();
		}else{
			cout<<"No cats available!"<<endl;
			return -1;
		}
	}

	int deQueueDog(void){
		if(!dogs.empty()){
			cout<<"Dequeuing dog"<<endl;
			int dog = dogs.front();
			dogs.pop_front();
		}else{
			cout<<"No dogs available!"<<endl;
			return -1;
		}
	}

};
int main(void){
	AnimalShelter as;
	as.enQueue(CAT);
	as.enQueue(DOG);
	as.enQueue(CAT);
	as.enQueue(DOG);
	as.enQueue(DOG);
	as.enQueue(DOG);
	as.deQueueAny();
	as.deQueueAny();
	as.deQueueAny();
	as.deQueueCat();
	as.deQueueAny();
	return 0;
}