/*
 * Node.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: smon7958
 */

#include "Node.h"
#include <iostream>
template<class Type>
Node<Type>::Node()
{

	this->pointers = nullptr;
}

template<class Type>
Node<Type>::Node(const Type& value)
{

	this->pointers = nullptr;
}

template<class Type>
Node<Type>::~Node()
{

}

template<class Type>
Type Node<Type>::getValue()
{
	return this->value;
}
template<class Type>
void Node<Type>::setValue(const Type& value)
{
	this->value = value;
}

template<class Type>
Node<Type> * Node<Type>::getPointers()
{
	return this->pointers;
}
