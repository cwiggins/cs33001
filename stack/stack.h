// Curtiss J Wiggins
// stack.h
// cs33001 
#include "node.h"
#ifndef CS33001_STACK_H_
#define CS33001_STACK_H_

template <typename T>

class Stack{

public:
	Stack():tos(0){};
	Stack (const Stack<T>&);
	~Stack();
	
	void swap(Stack<T>&);
	Stack<T>& operator=(Stack<T>);
	
	bool IsFull()const:
	bool IsEmpty()const{return tos==0;};

	T pop();
	void push(const T&)

private:
	node T *tos;
};

template <typename t>
T Stack<T>::pop()
{
	assert(tos!=0);

	node<T> *temp = tos;
	T result = tos->data;
	tos = tos -> next;
	delete temp;

	return result;
}

void Stack<T>::push(const T& item)
{
	assert(!IsFull());

	node<T> *temp=new node
