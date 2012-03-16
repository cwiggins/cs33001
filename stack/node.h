/*
 * =====================================================================================
 *
 *       Filename:  node.h
 *
 *    Description:  node class
 *
 *        Version:  1.0
 *        Created:  03/12/2012 12:06:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Curtiss J Wiggins 
 *   Organization:  cs33001
 *
 * =====================================================================================
 */
#ifndef CS33001_NODE_H_
#define CS33001_NODE_H_

template <typename T>
 class Node{
public:
	Node():data(), next(0){};
	Node(T item):data(item), next(0){};
	T data;
	Node<T> *next;
 };

#endif

