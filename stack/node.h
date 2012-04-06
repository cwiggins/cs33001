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

/*  The Node type is used in conjunction with other types like a stack, queues,
 *  and lists. It links data of Type T with a pointer of Type T called next.
 *  Initially next has a value of zero. The pointer if a node object itself.
 *  next is always used to point at the next value in a stack or queue. */
template <typename T>
 class Node{
public:
	
	/*  Default Constructor: Initializes data of type T using the types  default
	 *  constructor. This means that data has to have a default constructor that
	 *  *is built properly. It then initializes a Node of type T with a value of
	 *  *zero.*/
	Node():data(), next(0){};
	
	/*  non-default constructor that uses an item off Type T as an argument. It
	 *  then uses the item of type T to initialize Data of Type T using one of
	 *  its non-default, whatever those constructors maybe. The constructor for
	 *  data just has to be built properly. It then initializes a Node pointer
	 *  of Type T called next to a value of zero. */
	Node(T item):data(item), next(0){};
	
	T data;//must have properly built constructors or the node object won't work.
	Node<T> *next;
 };

#endif

