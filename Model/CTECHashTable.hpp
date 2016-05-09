//
//  CTECHashTable.hpp
//  NodeProjectX
//
//  Created by Montoya, Samuel on 5/9/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECHashTable_hpp
#define CTECHashTable_hpp

#include "HashNode.cpp"

template <class Type>

class CTECHashTable

{
    
private:    
    int size;
    int capacity;
    HashNode<Type> * internalStorage;
    double efficiencyPercentage;
    int findPosition(HashNode<Type> currentNode);
    int handleCollision(HashNode<Type> currentNode);
    void updateSize();
    int getNextPrime();
    bool isPrime(int candidateNumber);
    void updateCapacity();
    
public:
    CTECHashTable();
    ~CTECHashTable();
    void add(HashNode<Type> currentNode);
    bool remove(HashNode<Type> currentNode);
    bool contains(HashNode<Type> currentNode);
    int getSize();
};

#endif /* CTECHashTable_hpp */
