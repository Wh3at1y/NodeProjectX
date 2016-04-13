/*
 * CTECBinaryTree.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: smon7958
 */

#include "CTECBinaryTree.h"
using namespace CTECData;
using namespace std;

namespace CTECData
{
    template<class Type>
    CTECBinaryTree<Type> ::CTECBinaryTree()
    {
        root = nullptr;
        size = 0;
        height = 0;
        balanced = true;
    }
    
    template<class Type>
    int CTECBinaryTree<Type> :: getSize()
    {
        size = 0;
        size = calculateSize(root);
        return size;
    }
    
    template<class Type>
    int CTECBinaryTree<Type> :: calculatedSize(TreeNode<Type> * currentNode)
    {
        if(currentNode != nullptr)
        {
            calculatedSize(currentNode->getLeftChild());
            calculatedSize(currentNode->getRightChild());
            size++;
        }
    }
    
    template<class Type>
    TreeNode<Type> * CTECBinaryTree<Type> :: getRoot()
    {
        return root;
    }
    
    template<class Type>
    void CTECBinaryTree<Type>::preorderTraversal(TreeNode<Type> * currentNode)
    {
        if(currentNode != nullptr)
        {
            cout << currentNode->getValue() << " ";
            preorderTraversal(currentNode -> getLeftChild());
            preorderTraversal(currentNode-> getRightChild());
        }
    }
    
    template<class Type>
    void CTECBinaryTree<Type>::inorderTraversal(TreeNode<Type> * currentNode)
    {
        if(currentNode != nullptr)
        {
            preorderTraversal(currentNode -> getLeftChild());
            cout << currentNode->getValue() << " ";
            preorderTraversal(currentNode-> getRightChild());
        }
    }
    
    template<class Type>
    void CTECBinaryTree<Type>::postorderTraversal(TreeNode<Type> * currentNode)
    {
        if(currentNode != nullptr)
        {
            preorderTraversal(currentNode -> getLeftChild());
            preorderTraversal(currentNode-> getRightChild());
            cout << currentNode->getValue() << " ";
        }
    }
    
    template<class Type>
    bool CTECBinaryTree<Type>::contains(Type value)
    {
        bool isInTree = false;
        if(root != nullptr)
        {
            isInTree = true;
        }
        else
        {
            if(value< root->getValue())
            {
                isInTree = contains(value, root->getLeftChild());
            }
            else
            {
                isInTree = contains(value, root->getRightChild());
            }
        }
        return isInTree;
    }
    
    template<class Type>
    bool CTECBinaryTree<Type>::contains(Type value, CTECBinaryTree<Type> * currentTree)
    {
        bool isInTree = false;
        if(currentTree->getRoot()->getValue() == value)
        {
            isInTree = true;
        }
        else
        {
            if(value< currentTree->getRoot()->getValue())
            {
                isInTree = contains(value, currentTree->getRoot()->getLeftChild());
            }
            else
            {
                isInTree = contains(value, currentTree->getRoot()->getRightChild());
            }
        }
        return isInTree;
    }
}
