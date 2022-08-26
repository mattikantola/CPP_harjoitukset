/*


*/

#include<iostream>
#include<cstdlib>
#include<cassert>

template<class C>
class DynamicArray{

	private:
		unsigned int used;
		unsigned int max_size;
		C* arr;


	public:

		void append(C val);
		unsigned int length(){
			return used;
		}
		C pop();
		DynamicArray(unsigned int size);
		~DynamicArray();
		DynamicArray operator+(const DynamicArray &right);
		bool operator==(const DynamicArray &right);
		C operator[](unsigned int index){
			assert(index >=0 and index < used);
			return arr[index];
		}
	
};

template<class C>
DynamicArray<C>::DynamicArray(unsigned int size){
	
	max_size = size;
	used = 0;
	arr = (C*)malloc(sizeof(C)*max_size);
	
}

template<class C>
DynamicArray<C>::~DynamicArray(){
	free(arr);
}

template<class C>
void DynamicArray<C>::append(C val){

	if (used == max_size){
		arr = (C*)realloc(arr, sizeof(C) * max_size * 2);
		max_size *= 2;
	}
	*(arr+used) = val;
	used++;
	return;
}

template<class C>
C DynamicArray<C>::pop(){

	C ans = *(arr+used-1);
	used--;
	if (used < max_size/4){
		arr = (C*)realloc(arr, sizeof(C) * max_size / 2);
		max_size /= 2;
	}
	return ans;
}

template<class C>
bool DynamicArray<C>::operator==(const DynamicArray<C> &right){

	if (this->used != right.used){
		return false;
	}
	else{
		for (unsigned int iii = 0; iii < this->used; iii++){
			if (this->arr[iii] != right.arr[iii]){
				return false;
			}
		}
	}
	return true;
}

template<class C>
DynamicArray<C> DynamicArray<C>::operator+(const DynamicArray<C> &right){

	unsigned int new_size = this->used + right.used;	
	DynamicArray result = DynamicArray(new_size);
	for (int iii = 0; iii < this->used; iii++){
		result.arr[iii] = this->arr[iii];
	}
	for (int iii = 0; iii < right.used; iii++){
		result.arr[this->used + iii] = right.arr[iii];
	}
	result.used = new_size;
	return result;
}

int main(){

	DynamicArray<int> eka = DynamicArray<int>(3);
	DynamicArray<int> toka = DynamicArray<int>(4);
	
	
	for (int iii = 0; iii < 12; iii++){
		eka.append(iii);
		toka.append(iii);
	}
	
	for (int iii = 0; iii < eka.length(); iii++){
		std::cout << eka[iii] << " vs " << toka[iii] << std::endl;
	}
	
	DynamicArray<int> kolmas = DynamicArray<int>(5);
	
	for (int iii = 0; iii < 10; iii++){
		kolmas.append(iii*15);
	}

	DynamicArray<int> uusi = eka + kolmas;
	
	for (int iii = 0; iii < uusi.length(); iii++){
		std::cout << uusi[iii] << std::endl;
	}

	bool testi1 = eka == toka;
	bool testi2 = eka == kolmas;
	
	std::cout << testi1 << testi2 << std::endl;
	
	std::cout << uusi.pop() << std::endl;
	
	testi1 = eka == toka;
	
	std::cout << eka[6] << std::endl;
	
	return 0;

}


