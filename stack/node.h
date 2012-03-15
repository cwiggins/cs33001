// Curtiss J Wiggins
// node.h
// cs33001 
#ifndef _CS33001_NODE_H_
#define _CS33001_NODE_H_

template <typename T>

class Node{
public:
	node():data(), next(0){};
	node(T item): data(item), next(0){};
	T data;
	node<T> *next;
};
#endif


