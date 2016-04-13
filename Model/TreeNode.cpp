/*
 * TreeNode.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: smon7958
 */

#include "TreeNode.h"

using namespace CTECData;

template<class Type>
TreeNode<Type>::TreeNode() :
				Node<Type>()
{
	this->leftChild = nullptr;
	this->rightChild = nullptr;
	this->parent = nullptr;
}

template<class Type>
TreeNode<Type>::TreeNode(const Type& value) :
				Node<Type>(value)
{
	this->leftChild = nullptr;
	this->rightChild = nullptr;
	this->parent = nullptr;

	this->setValue(value);
}

template<class Type>
TreeNode<Type>::TreeNode(const Type& value, TreeNode<Type> * parent) :
				Node<Type>(value)
{
	this->leftChild = nullptr;
	this->rightChild = nullptr;
	this->parent = parent;
}

