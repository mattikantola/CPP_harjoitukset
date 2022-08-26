/*
Trying to implement the abstract data type Deque. I chose to do that with a
doubly linked list and a template: every node has a value which has a type
that can be changed with the template.

Author: Matti Kantola

*/

#include<iostream>
#include<cstddef>

template<class C>

class Deque{

	class Node{

		public:
		C val;
		Node* prev;
		Node* next;
		
		C get(){
			return val;
		}
		Node(C value, Node* pred = NULL, Node* succ = NULL){
			val = value;
			prev = pred;
			next = succ;
		}

	};

	private:
	
	/*
	This data structure keeps record of both tail and head in order to
	achieve O(1) running time for adding elements (append and appendleft)
	and for removing elements (pop and popleft). Also, initialization 
	function has to exist. Pointers are used in order to help with
	initialization (done with NULL pointers) and memory management.
	
	*/
		unsigned long long int size;
		Node* head;
		Node* tail;

	public:
	
		void append(C val);
		bool is_empty();
		C pop();
		void appendleft(C val);
		C popleft();
		unsigned long long int getsize();
		Deque();
		~Deque();
};

template<class C>
Deque<C>::~Deque(){

	Node* start = head;
	while (start != tail){
		Node* temp = start;
		start = start->next;
		delete temp;
	}
	delete tail;
}

template<class C>
Deque<C>::Deque(){

	/*
	This makes an empty deque, whose size is obviously zero and head
	and tail are NULL pointers. This variable is used to append more things. 
	*/

	size = 0; 
	head = NULL;
	tail = NULL;

}

template<class C>
unsigned long long int Deque<C>::getsize(){
	return size;
}

template<class C>
void Deque<C>::append(C val){

	/*
	We need to append an object, so we create a new node. Then it is added
	as the rightmost element in the list: as head if there are no current
	elements in the deque. Pointers and deque size are adjusted accordingly:
	the old tail and new element are linked to each other and the tail is
	updated to the new element. Method appendleft does the same thing to the
	head of the deque.
	*/
	
	Node* new_element = new Node(val);

	if (size == 0){
		head = new_element;
	}
	else{
		tail->next = new_element;
		new_element->prev = tail;
	}
	size++;
	tail = new_element;
}

template<class C>
C Deque<C>::pop(){
	
	/*
	The value of the tail node is extracted, the tail updated to its 
	predecessor and the old tail is deleted. Size is adjusted and the
	deque is restored to initial settings if it turns empty. The method 
	'popleft' does exactly the same thing with the head.
	*/
	
	Node* temp = tail;
	tail = tail->prev;
	C ans = temp->val;
	delete temp;
	size--;
	if (size == 0){
		head = NULL;
		tail = NULL;
	}
	return ans;
}

template<class C>
void Deque<C>::appendleft(C val){

	Node* new_element = new Node(val);
	
	if (size == 0){
		head = new_element;
	}
	else{
		head->prev = new_element;
		new_element->next = head;
	}
	size++;
	head = new_element;
}

template<class C>
C Deque<C>::popleft(){
	
	Node* temp = head;
	head = head->next;
	C ans = temp->val;
	delete temp;
	size--;
	if (size == 0){
		head = NULL;
		tail = NULL;
	}
	return ans;	

}
	
int main(){

	/*
	Testing the appends, appendlefts, pops and poplefts.
	*/


	Deque<int> *pinkka = new Deque<int>();
	for (int iii = 0; iii < 200; iii++){
		pinkka->append(iii);
		pinkka->appendleft(400-iii);
	}
	while (true){
		if (pinkka->getsize() == 0) break;
		else std::cout << pinkka->pop() << " ";
		if (pinkka->getsize() == 0) break;
		else std::cout << pinkka->popleft() << std::endl;
	}
	pinkka->append(123);
	std::cout << pinkka->pop() << std::endl;
	
	delete pinkka;
	
	Deque<int> lista;
	
	for (int iii = 0; iii < 10; iii++){
		lista.append(iii);	
	}
	while (lista.getsize() > 5){
		std::cout << lista.popleft() << std::endl;
	}
	for (int iii = 20; iii < 30; iii++){
		lista.appendleft(iii);
	}
	while (lista.getsize() > 2) {
		std::cout << lista.pop() << std::endl;
	}
	
	Deque<int> *jono = new Deque<int>();
	for (int iii = 0; iii < 1000000000; iii++){
		jono->append(iii);
	}
	std::cout << "jee" << std::endl;
	delete jono;
	
	return 0;
}
