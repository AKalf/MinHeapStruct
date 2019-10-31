// HeapStructures.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "visualizer.h"
#include "bst.h"

// Driver program to test above functions 
int main()
{
	
	int arr[] = { 3,2,15,5,4,45,19,35,12,7 };
	// Get Array size
	const int arr_size = 10;
	minHeapTree<int> tree (arr_size);
	//Create a tree with nodes
	tree = tree.CreateTree(arr, arr_size);
	// Visualize the resulting tree
	const visualizer<int> v(tree);
	cout << endl << endl;
	v.visualize();
	cout << endl << endl;
	std::cout << "Starting extracting min\n";
	tree.ExrtactMin(&tree);
	const visualizer<int> v2(tree);
	cout << endl << endl;
	v2.visualize();
	cout << endl << endl;
	for (int i = 0; i != tree.GetListOfNodes().size(); i++) {
		cout << "Printing nodes values as structured: " << tree.GetListOfNodes()[i]->get_value() << "\n";
	}
	
	return 0;
}
