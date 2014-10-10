#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

using namespace std;

template<typename T>
class LinkedList {

  public:

	/*
	 * No-parameters constructor, default constructor.
	 */
	LinkedList();

	/*
	 * Copy constructor
	 */
	LinkedList(const LinkedList<T>&);

	/*
	 * Sized constructor
	 */
	LinkedList(int,const T&);

	/*
	 * Destructor
	 */
	~LinkedList();

	void pushFront(const T&);
	void pushBack(const T&);

	const T& back() const;
	const T& front() const;

	void popFront();
	void popBack();

	void clear();

	/*
	 * Indicates whether the list has 0 elements. False if it doesn't.
	 */
	bool isEmpty() const;

	/*
	 * Returns quantity of elements in the list
	 */
	int size() const;

	void merge(const LinkedList<T>&);

	void removeTail();

	void removeBegin();

	/*
	 * True only if both has the same values in all its nodes.
	 */
	bool operator==(const LinkedList<T>&) const;

	T& operator[](int position) const;
	

  private:
	/*
	 * Node implemetation
	 */
	struct Node {
		T value;
		Node* next;

        Node(const T& newValue):value(newValue){}
	};

	int _length;
  	Node* _front;
  	Node* _back;

};

template<class T>
LinkedList<T>::LinkedList(){
	_length = 0;
	_front = NULL;
	_back = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other){
	_length = other._length;
	_front = NULL;

	Node* otherActual = other._front;
	Node* buffer = NULL;

	while(otherActual != NULL){
		Node* newNode = new Node(otherActual->value);

		if(buffer != NULL)
			buffer->next = newNode;
		else
			_front = newNode;

		buffer = newNode;
		otherActual = otherActual->next;
	}

	_back = buffer;
}

template<class T>
LinkedList<T>::LinkedList(int size,const T& defaultValue){
	_length = 0;
	_front = NULL;
	_back = NULL;

	while(size)
		pushBack(defaultValue);
}

template<class T>
LinkedList<T>::~LinkedList(){
	clear();
}

template<class T>
void LinkedList<T>::clear(){
	while(_length)
	 	popBack();
}

template<class T>
const T& LinkedList<T>::front() const{
	return _front->value;
}

template<class T>
const T& LinkedList<T>::back() const{
	return _back->value;
}

template<class T>
void LinkedList<T>::pushFront(const T& newElement){
	Node* newNode = new Node(newElement);

	if(!_length)
		_back = newNode;
	else
		newNode->next = _front;

	_front = newNode;
	_length++;
}

template<class T>
void LinkedList<T>::removeBegin(){
	while(_length - 1)
	 	popFront();
}

template<class T>
void LinkedList<T>::removeTail(){
	while(_length - 1)
	 	popBack();
}

template<class T>
void LinkedList<T>::pushBack(const T& newElement){
	Node* newNode = new Node(newElement);
	newNode->next = NULL;
	
	if(!_length)
		_front = newNode;
	else
		_back->next = newNode;
		
	_back = newNode;
	_length++;
}

template<class T>
void LinkedList<T>::merge(const LinkedList<T>& otherList){
	for (int i = 0; i < otherList._length; i++)	//When iterator implemented, refactor this
		pushBack(otherList[i]);
}

template<class T>
void LinkedList<T>::popFront(){
	Node* exFront = _front;
	_front = _front->next;
	if(_length == 1)
		_back = NULL;

	delete exFront;
	_length--;
}

template<class T>
void LinkedList<T>::popBack(){
	Node* currentNode = _front;
	Node* exBack = _back;

	if(_length == 1){
		_front = NULL;
		_back = NULL;
	}else{
		while(currentNode->next != _back)
			currentNode = currentNode->next;

		_back = currentNode;
		_back->next = NULL;
	}

	delete exBack;
	_length--;
}


template<class T>
bool LinkedList<T>::isEmpty() const{
	return !_length;
}

template<class T>
int LinkedList<T>::size() const{
	return _length;
}

template<class T>
bool LinkedList<T>::operator==(const LinkedList<T>& other) const{
	if(_length != other._length)
		return false;

	Node* otherCurrent = other._front;
	Node* thisCurrent = _front;

	while(otherCurrent != NULL){
		if(otherCurrent->value != thisCurrent->value)
			return false;

		otherCurrent = otherCurrent->next;
		thisCurrent = thisCurrent->next;
	}

	return true;
}

template<class T>
T& LinkedList<T>::operator[](int position) const{
	Node* currentNode = _front;
	for (int i = 0; i < position; i++)
		currentNode = currentNode->next;

	return currentNode->value;
}

#endif //LINKEDLIST_H_
