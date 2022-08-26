#include<iostream>
#include<string>
#include<unordered_map>

template<class C>
class Mode{

	private:
	
		/* unordered_map 'occur' keeps record of all the inserted elements.
		I chose to use a template, because I wanted to increase reusability.
		*/
	
		std::unordered_map<C, int> occur;
		C mode; // mode of elements in occur

	public:
	
		C add(C elem); // inserts an element and returns the mode

};

template<class C>
C Mode<C>::add(C elem){

	/* If there are no previous occurrences, a new one is created. Otherwise,
	the occurrence number is increased. The attribute 'mode' is updated: if
	its occurrence number is exceeded, then the new element is the new mode.
	if it is only met, then the minimum of the new element and current
	mode is the mode. */

	if (occur.find(elem) != occur.end()){
		occur[elem]++;
	}
	else{
		occur[elem] = 1;
	}
	if (occur[elem] > occur[mode]){
		mode = elem; 
	}
	else if (occur[elem] == occur[mode]){
		mode = std::min(elem, mode);
	}
	return mode;

}

int main(){

	int ylaraja = 0;
	std::cout << "Kuinka monta alkiota kysytään: ";
	std::cin >> ylaraja;
	Mode<int> data;
	
	for (int iii = 0; iii < ylaraja; iii++){
		int temp;
		std::cout << "Anna luku: ";
		std::cin >> temp;
		std::cout << "Tyyppiarvo on: " << data.add(temp) << std::endl;	
	}
	return 0;
}
