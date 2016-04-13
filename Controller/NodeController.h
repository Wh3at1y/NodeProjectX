/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: smon7958
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_
#include <string>
#include "../Model/Node.cpp"
#include "../Model/ArrayNode.cpp"
#include "../Model/CTECArray.cpp"
#include "../Model/CTECList.cpp"

using namespace std;

class NodeController
{
	private:
		CTECArray<int> * notHipsterInts;

		void testLists();
		void searchLists();
		int * mergeData;
		void doMergesort();
		void mergesort(int data[], int size);
		void merge(int data[], int sizeOne, int sizeTwo);
		void swap(int first, int second);
		void quicksort(int first, int last);
		int parttion(int first, int last);
		void doQuick();
		void sortData();

	public:
		NodeController();
		virtual ~NodeController();
		void start();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
