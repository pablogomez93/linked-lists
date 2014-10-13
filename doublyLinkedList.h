#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

using namespace std;

template<typename T>
class DoublyLinkedList {

  public:

	/*
	 * No-parameters constructor, default constructor.
	 */
	DoublyLinkedList();

	/*
	 * Copy constructor
	 */
	DoublyLinkedList(const DoublyLinkedList<T>&);

	/*
	 * Sized constructor. Generates a list of size = n with all values seted in defaultValues parameter value.	
	 */
	DoublyLinkedList(int n,const T& defaultValues);

	/*
	 * Destructor
	 */
	~DoublyLinkedList();

	/*
	 * Add a element at the front or at the end of the list, respectively. Size increased by one.
	 */
	void pushFront(const T&);
	void pushBack(const T&);

	/*
	 * Return a reference of first and last element of the list, respectively, not modifiable. 
	 */
	const T& front() const;
	const T& back() const;

	/*
	 * Remove first and last element of the list, respectively. Size decreases by 1.
	 */
	void popFront();
	void popBack();

	/*
	 * Indicates whether the list has 0 elements. False if it doesn't.
	 */
	bool isEmpty() const;

	/*
	 * Returns the number of items in the list.
	 */
	int size() const;

	/*
	 * Take a DoublylinkedList (parameter) and copy all its values, in orden, at the end of this list.
	 */
	void merge(const DoublyLinkedList<T>&);

	/*
	 * Remove all elements in the list, except last (this accion makes the last and first elements are the same node).
	 * Size changes to 1.
	 */
	void removeBegin();

	/*
	 * Remove all elements in the list, except first (this accion makes the last and first elements are the same node).
	 * Size changes to 1.
	 */
	void removeTail();

	/*
	 * Remove all elements in the list, but not delete the instance of it.
	 */
	void clear();

	/*
	 * Remove an specific element in the list who are in position i.
	 */
	void erase(int i);

	/*
	 * True only if both has the same values in all its nodes.
	 */
	bool operator==(const DoublyLinkedList<T>&) const;

	/*
	 * Return the value of the position passed by parameter.
	 * This methods allows you to modify the value in requested position because returns a reference of it not const. 
	 */
	T& operator[](int position) const;
	

  private:
	
	//Node implemetation
	struct Node {
		T value;
		Node* next;
		Node* previous;

        Node(const T& newValue){
        	this->value = newValue;
        	this->next = NULL;
        	this->previous = NULL;
        }
	};

	int _length;
  	Node* _front;
  	Node* _back;

};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){
	_length = 0;
	_front = NULL;
	_back = NULL;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other){
	_length = other._length;
	_front = NULL;

	Node* otherCurrent = other._front;
	Node* buffer = NULL;

	while(otherCurrent != NULL){
		Node* newNode = new Node(otherCurrent->value);
		newNode->previous = buffer;

		if(buffer != NULL)
			buffer->next = newNode;
		else
			_front = newNode;

		buffer = newNode;
		otherCurrent = otherCurrent->next;
	}

	_back = buffer;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(int size,const T& defaultValue){
	_length = 0;
	_front = NULL;
	_back = NULL;

	while(size){
		pushBack(defaultValue);
		size--;
	}
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
	clear();
}

template<class T>
void DoublyLinkedList<T>::pushFront(const T& newElement){
	Node* newNode = new Node(newElement);

	if(!_length){
		_back = newNode;
	}else{
		_front->previous = newNode;
		newNode->next = _front;
	}

	_front = newNode;
	_length++;
}

template<class T>
void DoublyLinkedList<T>::pushBack(const T& newElement){
	Node* newNode = new Node(newElement);
	
	if(!_length){
		_front = newNode;
	}else{
		_back->next = newNode;
		newNode->previous = _back;
	}

	_back = newNode;
	_length++;
}

template<class T>
const T& DoublyLinkedList<T>::front() const{
	return _front->value;
}

template<class T>
const T& DoublyLinkedList<T>::back() const{
	return _back->value;
}

template<class T>
void DoublyLinkedList<T>::popFront(){
	Node* exFront = _front;

	if(_length == 1)
		_back = NULL;
	else
		_front->next->previous = NULL;

	_front = _front->next;
	delete exFront;
	_length--;
}

template<class T>
void DoublyLinkedList<T>::popBack(){
	Node* exBack = _back;

	if(_length == 1)
		_front = NULL;
	else
		_back->previous->next = NULL;

	_back = _back->previous;
	delete exBack;
	_length--;
}

template<class T>
bool DoublyLinkedList<T>::isEmpty() const{
	return !_length;
}

template<class T>
int DoublyLinkedList<T>::size() const{
	return _length;
}

template<class T>
void DoublyLinkedList<T>::merge(const DoublyLinkedList<T>& otherList){
	for (int i = 0; i < otherList._length; i++)	//When iterator is implemented, refactor this
		pushBack(otherList[i]);
}

template<class T>
void DoublyLinkedList<T>::removeBegin(){
	while(_length - 1)
	 	popFront();
}

template<class T>
void DoublyLinkedList<T>::removeTail(){
	while(_length - 1)
	 	popBack();
}

template<class T>
void DoublyLinkedList<T>::clear(){
	while(_length)
	 	popBack();
}

template<class T>
void DoublyLinkedList<T>::erase(int i){
	Node* toDeleteNode = _front;
	
	if(_length == 1 && i == 0){
			_front = NULL;
			_back = NULL;

	}else if(i == 0){
			_front->next->previous = NULL;
			_front = _front->next;

	}else{
			if(i <= (_length/2)){	//i is closest to the beginning or the end?
				for(i; i > 0 ; i--)
					toDeleteNode = toDeleteNode->next;

			}else{
				toDeleteNode = _back;
				for (int k = _length-1; k > i; k--)
					toDeleteNode = toDeleteNode->previous;

			}
			
			Node* previousNode 	= toDeleteNode->previous;	//Never NULL
			Node* nextNode		= toDeleteNode->next;		//possibly NULL

			previousNode->next = nextNode;

			if(toDeleteNode == _back)
				_back = previousNode;
			else
				nextNode->previous = previousNode;

	}

	_length--;
	delete toDeleteNode;
}

template<class T>
bool DoublyLinkedList<T>::operator==(const DoublyLinkedList<T>& other) const{
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
T& DoublyLinkedList<T>::operator[](int position) const{
	Node* currentNode;
	if(position <= (_length/2)){	//position is closest to the beginning or the end?

		currentNode = _front;
		for (int i = 0; i < position; i++)
			currentNode = currentNode->next;

	}else{

		currentNode = _back;
		for (int i = _length-1; i > position; i--)
			currentNode = currentNode->previous;
		
	}

	return currentNode->value;
}

#endif //DOUBLYLINKEDLIST_H_
