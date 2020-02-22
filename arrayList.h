/*
 * arrayList.h
 *
 *  Created on: Mar 8, 2019
 *      Author: smohammed730
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

template <class elemType>
class arrayList{
public:
	arrayList();
	arrayList(int size);
	arrayList(const arrayList<elemType>&);
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print();
	bool isItemAtEqual(int position, const arrayList<elemType> object);
	void insertAt(int position, const arrayList<elemType>& newObject);
	void insertEnd(const arrayList<elemType>& object);
	void removeAt(int position);
	int retrieveAt(int position);
	void replaceAt(int position, const arrayList<elemType>& object);
	elemType getMin(int size, int m, int list);
	void clearList();
	arrayList<elemType>& operator=(elemType object);
	virtual ~arrayList();
private:
	int length;
	int maxSize;
	elemType *list;


};


#endif /* ARRAYLIST_H_ */

//default constructor
template <class elemType>
arrayList<elemType>::arrayList(): length(0), maxSize(0), list(0)
{

}

//constructor for objects
template <class elemType>
arrayList<elemType>::arrayList(int size)
{
	maxSize = size;
	length = 0;
	list = new elemType[maxSize];
}


//is empty
template <class elemType>
bool arrayList<elemType>::isEmpty() const
{
	return (length == 0);
}

//is full
template <class elemType>
bool arrayList<elemType>::isFull() const
{
	return (length == maxSize);
}

//list size
template <class elemType>
int arrayList<elemType>::listSize() const
{
	return length;
}

//max list size
template <class elemType>
int arrayList<elemType>::maxListSize() const
{
	return maxSize;
}

//print
template <class elemType>
void arrayList<elemType>::print()
{
	for(int i = 0; i < maxSize; i++){
		cout << list[i] << " " << endl;
	}
}

//is item at equal
template <class elemType>
bool arrayList<elemType>::isItemAtEqual(int position, const arrayList<elemType> object)
{
	if((position < 0) || (maxSize < position)){
		cout << position << "is an invalid position" <<endl;
	}else{
		return list[position] == object;
	}
}

//insert at
template <class elemType>
void arrayList<elemType>::insertAt(int position, const arrayList<elemType>& newObject)
{
	if(position < 0){
		cout << position << "is an invalid position" <<endl;
	}else if(position > maxSize){
		arrayList <int> newList(maxSize * 2);
		delete [] list;
		maxSize = newList.maxSize;
		list = newList.length;
		for(int i = 0; i < length; i++){
			list[i] = newList.list[i];
		}
	for(int j = length + 1; j > position; j--){
		list[j] = list[j-1];
	}
	list[position] = newObject;
	length++;
	}
}

//insert end
template <class elemType>
void arrayList<elemType>::insertEnd(const arrayList<elemType>& object)
{
	if(length > maxSize)
		arrayList <int> list2(maxSize);
		delete [] list;
		list2.maxSize = maxSize * 2;
		list = new elemType[list2.maxSize];
		list2.length = length;
		for(int i = 0; i < length; i++){
			list2.list[i] = list[i];
		}
	list[length++] = object;

}


//remove at
template <class elemType>
void arrayList<elemType>::removeAt(int position)
{
	if((position < 0) || (MAX_SIZE < position)){
		cout << position << "is an invalid position" <<endl;
	}else{
		list[position] = 0;
		--length;
	}
}

//retrieve at
template <class elemType>
int arrayList<elemType>::retrieveAt(int position)
{
	if((position < 0) || (MAX_SIZE < position)){
		cout << position << "is an invalid position" <<endl;
	}else{
		cout << "Object at " << position << " is " << list[position] <<endl;
	}
}

//replace at
template <class elemType>
void arrayList<elemType>::replaceAt(int position, const arrayList<elemType>& object)
{
	if((position < 0) || (MAX_SIZE < position)){
		cout << position << "is an invalid position" <<endl;
	}else{
		list[position] = object;
	}
}

//clear list
template <class elemType>
void arrayList<elemType>::clearList()
{
	length = 0;
}

//operator= overload
template <class elemType>
arrayList<elemType>& arrayList<elemType>::operator=(elemType object)
{
	delete [] list;
	maxSize = object.maxSize;
	list = new elemType[maxSize];
	length = object.length;
	for(int i = 0; i < length; i++){
		list[i] = object.list[i];
	}
	return this;
}

//destructor
template <class elemType>
arrayList<elemType>::~arrayList()
{
	delete [] list;
}

//get min
template <class elemType>
elemType getMin(int size, elemType m, elemType list){
	if(m == 1){
		return list[0];
	}else if(m > *list[size - 1]){
		m = list[size - 1];
	}return getMin(m, size - 1);
}



