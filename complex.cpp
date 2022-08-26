/*
Implementing the basic properties of complex numbers in a class

*/

#include<iostream>

template<typename T>
class Complex{

	private:
		
		T real;
		T imag;
	
	friend std::ostream& 
		operator<<(std::ostream &os, const Complex &arg){
			
			if (arg.real == 0 and arg.imag == 0){
				return os << 0;
			}
			
			else if (arg.real != 0){
				if (arg.imag < 0){
					return os << arg.real << " - " << -(arg.imag) << "i";
					}
				else if (arg.imag == 0){
					return os << arg.real;
				}
				else{
					return os << arg.real << " + " << arg.imag << "i";
				}
			}
			else{
				return os << arg.imag << "i";
			}
		}
		
	public:
	
		Complex operator+(const Complex &right);
		
		Complex operator*(const Complex &right);
		
		Complex operator*(const double &right);
		
		Complex(T first, T last){
			real = first;
			imag = last;
		}

};

template<typename T>

Complex<T> Complex<T>::operator+(const Complex<T> &right){

	Complex<T> result = Complex(0,0);
	result.real = this->real + right.real;
	result.imag = this->imag + right.imag;								
	return result;
}

template<typename T>

Complex<T> Complex<T>::operator*(const Complex<T> &right){

	Complex<T> result = Complex(0,0);
	result.real = this->real * right.real - this->imag * right.imag;
	result.imag = this->imag * right.real + this->real * right.imag;
	return result;

}

template<typename T>

Complex<T> Complex<T>::operator*(const double &right){

	Complex<T> result = Complex(0,0);
	result.real = this->real * right;
	result.imag = this->imag * right;
	return result;

}

int main(){

	Complex<double> luku = Complex(1.0,2.0);
	Complex<double> toinen = Complex(3.0,-5.5);
	Complex<int> gauss1 = Complex(1,2);
	std::cout << luku + toinen << std::endl;
	std::cout << luku*toinen << std::endl;
	std::cout << gauss1*3 << std::endl;

}
