 /*
 *       Filename:  stack.h
 *
 *    Description:  stack class
 *
 *        Version:  1.0
 *        Created:  03/12/2012 12:12:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Curtiss J Wiggins 
 *   Organization:  cs33001
 *
 * =====================================================================================
 */
#ifndef CS33001_STACK_H_
#define CS33001_STACK_H_

#include <cassert>
#include <new>
#include "node.h"

template <typename T>
class Stack{
public:
	Stack():tos(0){};//default constructor: sets tos to zero.
	Stack(const Stack<T>&);//copy constructor: makes a copy of stacks for use in call value functions
	~Stack();//destructor: deallocates memory used by a stack

	void swap(Stack<T>&);//swaps two stacks: ex) stack a, stack b a.swap(b), a now has b values and b has a values 
	Stack& operator=(Stack<T>);//assignment operator: assigns *this the value of the stack on right hand side of =.
	
	T pop();//removes an element from the stack and returns its value. removes the last element put on the stack.
	void push(const T&);//puts an element on the top of the stack.
	
	bool IsFull()const;//checks to see if the stack is full
	bool IsEmpty()const{return tos==0;};//checks to see if the stack is empty.
	
private:
	Node<T> *tos;
};

//precondition: That stack of Type T is able to be deallocated.
//postcondition: deallocates the memory that Stack of Type T was using for use
//by this program again or by another program.
template <typename T>
Stack<T>::~Stack(){
	
	while(tos!=0){
		Node<T> *temp = tos;
		tos = tos -> next;
		delete temp;
	}
}

template <typename T>
Stack<T>::Stack(const Stack<T>& actual){
	
	Node<T> *bottom, *ttos, *temp;
	tos = 0;
	ttos = actual.tos;
	
	while(ttos!=0){
		temp = new Node<T> (ttos -> data);
		if(tos==0){
			tos = temp;
			bottom = temp;
		}else{
			bottom -> next = temp;
			bottom = temp;
		}
		ttos = ttos -> next;
	}
}

template <typename T>
void Stack<T>::swap(Stack& rhs){
	Node<T> *temp = tos;
	tos = rhs.tos;
	rhs.tos = temp;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> rhs){
	swap(rhs);
	return *this;
}

template <typename T>
T Stack<T>::pop(){
	assert(tos!=0);
	
	Node<T> *temp = tos;
	T result = tos -> data;
	tos = tos -> next;
	delete temp;

	return result;
}

template <typename T>
void Stack<T>::push(const T& item){
	assert(!IsFull());
	
	Node<T> *temp = new Node<T> (item);
	
	temp -> next = tos;
	
	tos = temp;
}

template <typename T>
bool Stack<T>::IsFull()const{
	Node<T> *temp = new (std::nothrow) Node<T> ();
	
	if(temp==0)
		return true;
	
	delete temp;
	
	return false;
}

#endif
