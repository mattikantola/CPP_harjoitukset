#include<unordered_map>
#include<string>
#include<iostream>

std::unordered_map<char, int> charcount(std::string param){

	/* Iterates through a string and counts its characters. Non-alphabetic
	characters are ignored and this is not case-sensitive. */

	std::unordered_map<char, int> count;

	for (std::string::iterator it=param.begin(); it != param.end(); it++){
	
		/* Everything else except letters is ignored and the uppercase
		letters are converted to lowercase. */
	
		char temp = *it;
		
		if (temp < 65){ // not a letter at all
			continue;
		}
		else if (temp < 91){ // uppercase letter
			temp += 32;
		}
		else if (temp < 97){ // again, not a letter at all
			continue;
		}
		else if (temp > 122){ // same as above
			continue;
		}
		if (count.find(temp) == count.end()){
			count[temp] = 1; // first occurrence of this letter
		}
		else{
			count[temp]++; // more occurrences of this letter
		}
	}
	
	return count;
}

int main(){

	std::string eka, toka;
	std::cout << "Anna ensimmäinen sana: ";
	std::getline(std::cin, eka);
	std::cout << "Anna toinen sana: ";
	std::getline(std::cin, toka);
	
	if (charcount(eka) == charcount(toka)){
		std::cout << "Sanat ovat anagrammeja!" << std::endl;
	}
	else{
		std::cout << "Sanat eivät ole anagrammeja!" << std::endl;
	}

 	return 0;
}
