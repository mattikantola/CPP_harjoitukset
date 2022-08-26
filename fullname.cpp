/*
Trying to print the full name of a person that is described in a class

*/

#include<iostream>
#include<string>

class Person{

	private:
	
		std::string called;
		std::string family;
		
	friend std::ostream& operator<<(std::ostream &os, Person const &arg){
			return os << arg.called << " " << arg.family;
		}

	public:
		Person(std::string first, std::string last){
			called = first;
			family = last;
		}
		
};

int main(){

	std::string etunimi = "Matti";
	std::string sukunimi = "Kantola";
	Person nimi = Person(etunimi, sukunimi);
	std::cout << nimi << std::endl;

}
