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

NodeController::NodeController()
{

}

NodeController::~NodeController()
{

}

void NodeController::start()
{
	doMergesort();
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
