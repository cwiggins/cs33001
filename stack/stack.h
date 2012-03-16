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
	Stack():tos(0){};
	Stack(const Stack<T>&);
	~Stack();

	void swap(Stack<T>&);
	Stack& operator=(Stack<T>);
	
	T pop();
	void push(const T&);
	
	bool IsFull()const;
	bool IsEmpty()const{return tos==0;};
	
private:
	Node<T> *tos;
};

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
