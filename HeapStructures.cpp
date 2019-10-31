// HeapStructures.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "visualizer.h"
#include "MinHeapTree.cpp"

// Driver program to test above functions 
int main()
{
	
	int arr[] = { 3,2,15,5,4,45,19,35,12,7 };
	// Get Array size
	const int arr_size = 10;
	// Declare a min heap tree
	minHeapTree<int> tree (arr_size);
	// Create a tree with nodes
	tree = tree.CreateTree(arr, arr_size);	
	
	// Visualize the resulting tree
	cout << endl << endl;
	visualize(tree);
	cout << endl << endl;

	// Extract min
	tree.ExrtactMin(&tree);
	
	// Visualize the resulting tree
	cout << endl << endl;
	visualize(tree);
	cout << endl << endl;

	return 0;
}
