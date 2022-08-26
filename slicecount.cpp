#include<iostream>
#include<unordered_map>
#include<vector>

template<class C>
std::vector<int> count(std::vector<C> data, int window_size){

	/* This algorithm keeps record of the unique elements in a slice
	of length 'window_size' in a vector 'data'. Template is used to make
	this code valid for different data types that support hashing. */

	std::unordered_map<C, int> uniques;
	std::vector<int> result = {};
	int iii = 0;
	int end = data.size();
	
	for (iii = 0; iii < end; iii++){
	
		C elem = data[iii];
		
		if (iii < window_size){
			
			/* This is just a normal counter function: if an occurrence
			of the element is found, the count is increased. Otherwise a
			new occurrence is initialized. */
			
			if (uniques.find(elem) != uniques.end()){
				uniques[elem]++;
			}
			else{
				uniques[elem] = 1;
			}
		}
		else{
			
			/* We keep updating the counter, but this time we have to
			remove the leftmost element on every step as well. 
			The count of the leftmost element is decreased and if 
			it equals zero, it is deleted. The rightmost element is
			treated as above. On every step, the amount of unique elements
			is our answer and it is pushed to the result. */
			
			result.push_back(uniques.size());
			C remov = data[iii-window_size];
			
			if (uniques.find(elem) != uniques.end()){
				uniques[elem]++;	
			}
			else{
				uniques[elem] = 1;
			}
			uniques[remov]--;
			if (uniques[remov] == 0){
				uniques.erase(remov);
			}
		}
	}
	
	result.push_back(uniques.size());
	return result;
}

int main(){

	std::vector<int> data1 = {1,1,2,2,2,3,3,4};
	std::vector<int> data2 = {1,1,1,1,2,3,4,4,4,1,1,1,1,1,2,3,4,2};
	std::vector<int> data3 = {1,2,3,3,3,4,3,3,3,4,2};

	std::vector<int> count1 = count<int>(data1, 2);
	std::vector<int> count2 = count<int>(data2, 4);
	std::vector<int> count3 = count<int>(data3, 3);
	
	int end1 = count1.size();
	int end2 = count2.size();
	int end3 = count3.size();
	
	for (int iii = 0; iii < end1; iii++){
		std::cout << count1[iii] << " ";
	}
	std::cout << std::endl;
	
	for (int iii = 0; iii < end2; iii++){
		std::cout << count2[iii] << " ";
	}
	std::cout << std::endl;
	for (int iii = 0; iii < end3; iii++){
		std::cout << count3[iii] << " ";
	}
	std::cout << std::endl;
}
