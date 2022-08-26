#include<iostream>
#include<string>

template<class T>
class Node{
		
	private:
	
		T value;
		Node* prev;
		Node* next;
	
	public:
		Node(T val, Node* pr = NULL, Node* nxt = NULL);
		~Node();
		T get();

};

template<class T>		
	Node<T>::Node(T val, Node* pr = NULL, Node* nxt = NULL){
		value = val;
		prev = pr;
		next = nxt;
	}
	
template<class T>
	T Node<T>::get(){
		return value;
	}

template<class T>
class Deque{

	private:
		
		unsigned long long int size;
		Node<T> *head;
		Node<T> *tail;

	public:
	
		Deque();
		~Deque();
		T pop();
		T popleft();
		void append(T* val);
		void appendleft(T* val);
		unsigned long long int getsize();
		
};

template<class T>
	Deque<T>::Deque(){
		
		size = 0;
		Node<T> *head = ;
		Node<T> *tail;
	
}

template<class T>
	unsigned long long int Deque<T>::getsize(){
		return size;
	}

int main(){

	Deque<int> *cont;


	return EXIT_SUCCESS;
}
