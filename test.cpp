#include <iostream>
#include <assert.h>
#include "linkedList.h"

using namespace std;

int main(){

	LinkedList<int> testList;

	assert(testList.size() == 0);
	testList.clear();
	assert(testList.size() == 0);
	assert(testList.isEmpty());
	
	testList.pushFront(4);
	assert(!testList.isEmpty());
	testList.pushFront(5);
	testList.pushBack(3);
	testList.pushFront(0);

	assert(testList.size() == 4);

	testList.pushFront(0);
	testList.pushBack(-10);

	int aux = testList.back();
	
	assert(aux == -10);
	assert(testList.size() == 6);

	//Testing .back() method don't return a pointer to value;
	aux = 5;
	int aux2 = testList.back();
	assert(aux2 == -10);
	assert(testList.size() == 6);

	int aux3 = testList.front();
	assert(aux3 == 0);
	assert(testList.size() == 6);

	testList.removeTail();
	assert(testList.size() == 1);
	assert(testList.back() == testList.front());
	assert(testList.front() == 0);

	testList.clear();
	assert(testList.isEmpty());
	assert(testList.size() == 0);
	
	int i = 0;
	for (i; i < 100; i++)
		testList.pushFront(i+1);

	LinkedList<int> anotherIncredibleList; //(*shudder*)
	for (i; i < 200; i++)
		anotherIncredibleList.pushFront(i+1-100);
	
	assert(anotherIncredibleList.size() == 100);
	assert(anotherIncredibleList == testList);

	for (i = 99; i >= 0; i--)
		assert(testList[i] == 100 - i);

	anotherIncredibleList.clear();
	for (i = 0; i < 200; i++)
		anotherIncredibleList.pushBack(i);
	
	for (i = 0; i < 200; i++)
		assert(anotherIncredibleList[i] == i);

	assert(anotherIncredibleList.size() == 200);



	//Testing = operator
	LinkedList<int> theMasterOfLists = anotherIncredibleList;
	assert(!theMasterOfLists.isEmpty());
	assert(theMasterOfLists.size() == 200);
	for (i = 0; i < 200; i++)
		assert(theMasterOfLists[i] == i);

	//Testing independence of both lists;
	anotherIncredibleList.clear();
	assert(theMasterOfLists.size() == 200);
	for (i = 0; i < 200; i++)
		assert(theMasterOfLists[i] == i);

	theMasterOfLists.pushFront(4);
	assert(anotherIncredibleList.size() == 0);



	//Copy construtor testing
	LinkedList<int> lastTestList(testList);
	assert(lastTestList.size() == testList.size());

	for (i = 99; i >= 0; i--)
		assert(lastTestList[i] == 100 - i);

	for (i = 99; i >= 0; i--)
		assert(testList[i] == 100 - i);

	//Testing independence of both list after create one by copy constructor.
	testList.clear();
	assert(testList.isEmpty());

	assert(lastTestList.size() == 100);
	for (i = 99; i >= 0; i--)
		assert(lastTestList[i] == 100 - i);

	for (int k = 40000; k < 44000; k++){
		testList.pushFront(k+1);
		testList.pushBack(k-1);
	}

	assert(lastTestList.size() == 100);
	for (i = 99; i >= 0; i--)
		assert(lastTestList[i] == 100 - i);

	return 0;
}
