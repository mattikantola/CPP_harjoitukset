

#include<iostream>

int main(){

	int eka, toka;
	char toimitus;
	std::cout << "Anna laskutoimitus: ";
	std::cin >> eka >> toimitus >> toka;

	switch (toimitus){
	
		case ('+'):
		
			std::cout << eka << " + " << toka << " = " << eka + toka << '\n';
			break;
		case ('-'):
		
			std::cout << eka << " - " << toka << " = " << eka - toka << '\n';
			break;
			
		case ('*'):
			std::cout << eka << " * " << toka << " = " << eka * toka << '\n';
			break;

		case ('/'):
			std::cout << eka << " / " << toka << " = " << eka / toka << '\n';
			break;
		
		default:
			std::cout << "Virheellinen laskutoimitus!" << std::endl;
		
	}
	return EXIT_SUCCESS;

}
