#include<string>
#include<iostream>

int main(){

	std::string nimi = "Matti Kantola";
	std::cout << "Arvaa nimi: ";
	std::string toinen;
	std::getline(std::cin, toinen);
	if (nimi == toinen) std::cout << "Oikein meni!\n";
	else std::cout << "Väärin meni!\n";

	return EXIT_SUCCESS;
}
