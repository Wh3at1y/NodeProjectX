//
//  CTECHashTable.cpp
//  NodeProjectX
//
//  Created by Montoya, Samuel on 5/9/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECHashTable.hpp"
#include <cmath>
template<class Type>

CTECHashTable<Type> ::CTECHashTable()

{
    
    this->size = 0;
    
    this->capacity = 101;
    
    this->efficiencyPercentage = .667;
    
    this->internalStorage = new HashNode<Type>[capacity];
    
}



template <class Type>

CTECHashTable<Type> :: ~CTECHashTable()

{
    
    delete [] internalStorage;
    
}



template <class Type>

int CTECHashTable<Type> :: getSize()

{
    
    return this->size;
    
}



template <class Type>

void CTECHashTable<Type> :: add(HashNode<Type> currentNode)

{
    
    if (!constains(currentNode)) 
        
    {
        
        if(size/capacity >= this->efficiencyPercentage)
            
        {
            
            updateSize();
            
        }
        
        int insertionIndex = findPosition(currentNode);
        
        
        
        if(internalStorage[insertionIndex] != nullptr)
            
        {
            
            while(internalStorage[insertionIndex] != nullptr)
                
            {
                
                insertionIndex = insertionIndex + 1 % capacity;
                
            }
            
        }
        
        
        
        internalStorage[insertionIndex] = currentNode;
        
    }
}


template<class Type>
int CTECHashTable<Type> :: findPosition(HashNode<Type> currentNode)
{
    int position = 0;
    position = currentNode.getKey() % capacity;
    return position;
}

template <class Type>
int CTECHashTable<Type>:: getNextPrime()
{
    int nextPrime = capacity;
    nextPrime *= 2;
    nextPrime++;
    
    while (!isPrime(nextPrime)) 
    {
        nextPrime += 2;
    }
    return nextPrime;
}

template <class Type>
bool CTECHashTable<Type>::isPrime(int candidateNumber)
{
    bool isPrime = true;
    
    if(candidateNumber <= 1)
        isPrime= false;
    
    else if(candidateNumber ==2 || candidateNumber == 3)
        isPrime = true;
    
    else if(candidateNumber % 2 == 0)
        isPrime = false;
    
    else
        for(int spot = 3; spot < sqrt(candidateNumber) + 1; spot++)
            if(candidateNumber % spot == 0)
            {
                isPrime = false;
                break;
            }
    
    return isPrime;
}

template<class Type>
void CTECHashTable<Type>::updateCapacity()
{
    int updatedCapacity = getNextPrime();
    int oldCapacity = capacity;
    capacity = updatedCapacity;
    
    HashNode<Type> * largerStorage = new HashNode<Type>[capacity];
    
    for(int index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updatedIndex = findPosition(internalStorage[index]);
            largerStorage[updatedIndex] = internalStorage[index];
        }
    }
    
    internalStorage = largerStorage;
}