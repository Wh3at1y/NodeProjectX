/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: smon7958
 */

#include "NodeController.h"
#include "../Model/Timer.h"
#include <iostream>

using namespace std;
using namespace CTECData;

NodeController::NodeController()
{

}

NodeController::~NodeController()
{

}

void NodeController::start()
{
    tryGraphs();
}

void NodeController::sortData()
{
	/*
	 Create a CTECList, CTECArray
	 Fill them with random stuff(numbers)
	 start timer, sort, stop timer, diplay info for list
	 start timer, sort, stop timer, diplay info for array
	 */
	CTECArray<int> randomNumberArray(5000);
	CTECList<int> randomNumberList;
	int myCPlusPlusArray[5000];

	for (int spot = 0; spot < 5000; spot++)
	{
		int myRandom = rand();
		randomNumberArray.set(spot, myRandom);
		randomNumberList.addToEnd(myRandom);
		myCPlusPlusArray[spot] = myRandom;
	}

	Timer sortTimer;
	sortTimer.startTimer();
	randomNumberArray.selectionSort();
	sortTimer.stopTimer();
	sortTimer.displayTimerInformation();

	sortTimer.resetTimer();

	sortTimer.startTimer();
	std::sort(begin(myCPlusPlusArray), end(myCPlusPlusArray));
	sortTimer.stopTimer();
	sortTimer.displayTimerInformation();

	sortTimer.resetTimer();

}

void NodeController::doMergesort()
{
	mergeData = new int[500000];

	for (int spot = 0; spot < 500000; spot++)
	{
		int myRandom = rand();
		mergeData[spot] = myRandom;
	}
	for (int spot = 0; spot < 5000; spot++)
	{
		cout << mergeData[spot] << ", ";
	}

	Timer mergeTimer;
	mergeTimer.startTimer();
	mergesort(mergeData, 500000);
	mergeTimer.stopTimer();
	mergeTimer.displayTimerInformation();

	for (int spot = 0; spot < 5000; spot++)
	{
		cout << mergeData[spot] << ", ";
	}

	delete[] mergeData;
}

void NodeController::tryGraphs()
{
    CTECGraph<int> testGraph;
    testGraph.addVertex(4);
    testGraph.addVertex(13);
    testGraph.addVertex(2);
    testGraph.addVertex(5);
    testGraph.addVertex(8);
    testGraph.addVertex(21);
    testGraph.addVertex(43);
    testGraph.addVertex(1);
    testGraph.addVertex(99);
    testGraph.addVertex(10);
    testGraph.addEdge(0,1);
    testGraph.addEdge(1,2);
    testGraph.addEdge(2,3);
    testGraph.addEdge(3,4);
    testGraph.addEdge(4,5);
    testGraph.addEdge(5,6);
    testGraph.addEdge(6,7);
    testGraph.addEdge(7,8);
    testGraph.addEdge(8,9);
    
    
    testGraph.breadthFirstTraversal(testGraph,0);
    testGraph.depthFirstTraversal(testGraph,0);
    
}
void NodeController::mergesort(int data[], int size)
{
	int sizeOne;
	int sizeTwo;

	if (size > 1)
	{
		sizeOne = size / 2;
		sizeTwo = size - sizeOne;

		mergesort(data, sizeOne);
		mergesort((data + sizeOne), sizeTwo);

		merge(data, sizeOne, sizeTwo);
	}

}

void NodeController::merge(int data[], int sizeOne, int sizeTwo)
{
	int * temp;
	int copied = 0;
	int copied1 = 0;
	int copied2 = 0;

	int index;

	temp = new int[sizeOne + sizeTwo];

	while ((copied1 < sizeOne) && (copied2 < sizeTwo))
	{
		if (data[copied1] < (data + sizeOne)[copied2])
		{
			temp[copied++] = data[copied1++];
		}
		else
		{
			temp[copied++] = (data + sizeOne)[copied2++];
		}
	}

	while (copied1 < sizeOne)
	{
		temp[copied++] = data[copied1++];
	}
	while (copied2 < sizeTwo)
	{
		temp[copied++] = (data + sizeOne)[copied2++];
	}

	for (index = 0; index < sizeOne + sizeTwo; index++)
	{
		data[index] = temp[index];
	}
	delete[] temp;

}

void NodeController::tryTrees()
{
    
    CTECBinaryTree<int> testTree;
    cout<<"this is pre removal" << endl;
    
    testTree.insert(1);
    testTree.insert(5);
    testTree.insert(7);
    testTree.insert(3);
    testTree.insert(2);
    testTree.insert(8);
    testTree.insert(12);
    testTree.inorderTraversal(testTree.getRoot());
    
    
    testTree.remove(1);
    cout<<"this is post removal" << endl;
    testTree.inorderTraversal(testTree.getRoot());
    
    
}
