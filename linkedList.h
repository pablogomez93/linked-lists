#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

using namespace std;

template<typename T>
class LinkedList {

  public:

	/*
	 * No-parameters constructor, defalast constructor.
	 */
	LinkedList();

	/*
	 * Copy constructor
	 */
	LinkedList(const LinkedList<T>&);

	/*
	 * Destructor
	 */
	// ~LinkedList();

	void agregarAdelante(const T&);
	void agregarAtras(const T& nuevoAdepto);

	const T& last() const;
	const T& first() const;


	/*
	 * Indicates if list has 0 elements. False if it doesn't.
	 */
	bool isEmpty() const;

	/*
	 * Returns quantity of elements in the list
	 */
	int size() const;

	/*
	 * True only if both has the same values in all of its nodes.
	 */
	// bool operator==(const LinkedList<T>&) const;


  private:
	/*
	 * Node implemetation
	 */
	struct Node {
        Node(const T& newValue):value(newValue){}

		T value;
		Node* next;
	};

	int _length;
  	Node* _first;
  	Node* _last;

};

template<class T>
LinkedList<T>::LinkedList(){
	_length = 0;
	_first = NULL;
	_last = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other){
	_length = other._length;
	_first = NULL;

	Node* otherActual = other._first;
	Node* buffer = NULL;

	while(otherActual != NULL){
		Node* newNode = new Node(otherActual->value);

		if(buffer != NULL)
			buffer->next = newNode;

		buffer = newNode;

		otherActual = otherActual->next;
	}

	_last = buffer;
}

// template<class T>
// LinkedList<T>::~LinkedList(){
// 	while(_length > 0){
// 	 	golDeCristiano(adeptoAlabando());
// 	}
// }

template<class T>
const T& LinkedList<T>::first() const{
	return _first->value;
}

template<class T>
const T& LinkedList<T>::last() const{
	return _last->value;
}

template<class T>
void LinkedList<T>::agregarAdelante(const T& newElement){
	Node* newNode = new Node(newElement);

	if(!_length)
		_last = newNode;
	else
		newNode->next = _first;

	_first = newNode;

	_length++;
}

template<class T>
void LinkedList<T>::agregarAtras(const T& newElement){
	Node* newNode = new Node(newElement);
	
	if(!_length)
		_first = newNode;
	else
		_last->next = newNode;
		
	_last = newNode;

	_length++;
}


template<class T>
bool LinkedList<T>::isEmpty() const{
	return !_length;
}

template<class T>
int LinkedList<T>::size() const{
	return _length;
}

// template<class T>
// bool LinkedList<T>::operator==(const LinkedList<T>& otra) const{
//     bool ret = (_length == otra.size()) && (hayElegido() == otra.hayElegido());
//     if(ret && hayElegido()){
//     	ret = _elegido->value == otra.dameElegido();
//     }
//     if(ret && _length != 0){
//     	ret = _alabando->value == otra.adeptoAlabando();
//     }
//     Node* n = _first;
//     Node* m = otra._first;
//     if(ret && _length!=0){
//     	int i = 0;
//     	for(i=0; i<_length && ret;i++){
//     		ret = (n->value == m->value);
//     		n = n->next;
//             m = m->next;
//     	}
//     }
//     return ret;
// }



#endif //LINKEDLIST_H_
