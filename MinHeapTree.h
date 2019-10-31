#pragma once
#include "node.h"
#include <vector>



template <class T>
class minHeapTree
{
	// The root of the tree
	Node<T>* root_ = nullptr;
	// Find the parent of a node. Requires list to be structure so parent's index equals: (i - 1) / 2 
	Node<T>* FindParent(std::vector<Node<T>*>, int);
	// Find parent's index in the list of nodes
	int GetParentIndex(int);
	// Contains all the nodes of the tree
	std::vector<Node<T>*> listOfNodes;
public:

	minHeapTree() = default;
	minHeapTree(int); 
	~minHeapTree() = default;

	// Create Balanced Tree Function
	minHeapTree<T> CreateTree(T*, int);

// Main Functions //
	
	// Sets left and right child for nodes based on how they have been stored in list.
	void ConnectTree(minHeapTree*);

	// Heapify and create initalize nodes. Use when heapifying for first time
	std::vector<Node<T>*> HeapifyElements(T*,  int);

	// Heapify already created nodes
	std::vector<Node<T>*> HeapifyElements();

	// Get the node with minimum value and remove it from list of nodes. List re-adjusts.
	Node<T>* ExrtactMin(minHeapTree<T>*);
	
// Helping Functions

	// Get the nodes of this tree
	std::vector<Node<T>*> GetListOfNodes();
	// Get the root of the tree
	Node<T>* GetRoot();
	// Set a node as the root of the tree
	void SetRoot(Node<T>*);
	// Check if list of nodes contain node
	bool Contains(T);
	// Find a node in the list of nodes
	Node<T>* FindNode(T);
	// Count Function, used for displaying tree
	int CountNodes(Node<T>*);

	

};

// Swap the pointers of two nodes
template <class T>
void SwapNodes(Node<T>*, Node<T>*);