#pragma once
#include "MinHeapTree.h"


// Initialize min heap tree
template <class T>
minHeapTree<T>::minHeapTree(int array_size) {
	listOfNodes = std::vector<Node<T>*>(array_size);
}


//// Main functions ////


// Sets left and right child for nodes based on how they have been stored in vector.
template <class T>
minHeapTree<T> minHeapTree<T>::CreateTree(T* values, int array_size)
{
	// Place elements in order where root = min
	minHeapTree<T> balanced_tree(array_size);
	// Main loop for structuring list of nodes. Creates a node for each value and placec them in order such as: root = min
	listOfNodes = balanced_tree.HeapifyElements(values, array_size);
	// Set as root the element with smallest value
	balanced_tree.SetRoot(listOfNodes.at(0));
	std::cout << "\n ----Array size: " << array_size << "\n";
	// Main loop for building tree
	ConnectTree(&balanced_tree);
	return balanced_tree;
}

// Main loop for structuring tree. Creates a node for each value and placec them in order where root = element with min value.
// Heapify and create initalize nodes. Use when heapifying tree for first time.
// Elements are structured like that:
// 2 * iterator + 1 = left child's index of node at index "iterator"
// 2 * iterator + 2 = the right child's index of node at index "iterator"
template <class T>
std::vector<Node<T>*> minHeapTree<T>::HeapifyElements(T* values, int array_size) {

	
	int currentSize = 0; // how many elements actually exist in list
	for (int value = 0; value != array_size; value++) {
		currentSize++;
		int index = currentSize - 1; // Find the index for the next unused slot in list
		listOfNodes.at(index) = new Node<T>(values[value]); // Store a new node at the unused list slot
		//std::cout << " Current index: " << index << ". Parent's index " << GetParentIndex(index) << "\n";
		if (value > 0) {
			// Fix the min heap property if it is violated
			// While parent's value is bigger than current node's value
			while (index != 0 && listOfNodes.at(GetParentIndex(index))->GetPriorityValue() > listOfNodes.at(index)->GetPriorityValue())
			{
				// Swap the pointers of current node and parent node
				SwapNodes(listOfNodes.at(index), listOfNodes.at(GetParentIndex(index)));
				// Procced higher at tree
				index = GetParentIndex(index);
			}
		}
		std::cout << "New node with value: " << values[value] << " inserted at position: " << index << "\n";
	}
	return listOfNodes;

}

// Heapify already created nodes
template <class T>
std::vector<Node<T>*> minHeapTree<T>::HeapifyElements() {

	int currentSize = 0; //how many elements actually exist in list
	// for each node in node list
	for (int node = 0; node != listOfNodes.size(); node++) {
		currentSize++;
		int index = currentSize - 1;
		//cout << "New key: " << listOfNodes.at(i).get_Value() << " inserted at end\n";
		std::cout << "\nCurrent node value: " << listOfNodes.at(index)->GetPriorityValue() << "\n";
		std::cout << " Parent node value: " << listOfNodes.at(GetParentIndex(index))->GetPriorityValue() << "\n";
		//std::cout << " Current index: " << index << ". Parent's index " << GetParentIndex(index) << "\n";
		if (node > 0) {
			// Fix the min heap property if it is violated 
			// While parent's value is bigger than current node's value
			while (index != 0 && listOfNodes.at(GetParentIndex(index))->GetPriorityValue() > listOfNodes.at(index)->GetPriorityValue())
			{
				// Swap the pointers of current node and parent node
				SwapNodes(listOfNodes.at(index), listOfNodes.at(GetParentIndex(index)));
				// Procced higher at tree
				index = GetParentIndex(index);
			}
		}
		//cout << "Key: " << listOfNodes[i].get_Value() << " inserted at position: " << lastIndex << "\n";
	}
	return listOfNodes;

}

// Sets left and right child for nodes based on how they have been stored in list.
template <class T>
void minHeapTree<T>::ConnectTree(minHeapTree* balanced_tree)
{

	int iterator = 0;

	while (iterator != listOfNodes.size()) {
		std::cout << "\nProcessing node with value : " << listOfNodes.at(iterator)->GetPriorityValue() << "\n";
		std::cout << " Current iterator: " << iterator << " || left kid iterator: " << 2 * iterator + 1 << " ||  right kid iterator:: " << 2 * iterator + 2 << " \n";
		// if there is a left child node
		if (2 * iterator + 1 < listOfNodes.size()) {
			std::cout << "  Added node with value: " << listOfNodes.at(2 * iterator + 1)->GetPriorityValue() << " as left child and added for processing\n ";
			// set newly created node as left child of currently processing node
			listOfNodes.at(iterator)->SetLeftChild(listOfNodes.at(2 * iterator + 1));
		}
		else {
			listOfNodes.at(iterator)->SetLeftChild(nullptr);
		}
		// if there is a right child node
		if (2 * iterator + 2 < listOfNodes.size()) {
			std::cout << " Added node with value: " << listOfNodes.at(2 * iterator + 2)->GetPriorityValue() << " as right child and added for processing\n";
			// set newly created node as right child of currently processing node
			listOfNodes.at(iterator)->SetRightChild(listOfNodes.at(2 * iterator + 2));
		}
		else {
			listOfNodes.at(iterator)->SetRightChild(nullptr);
		}

		// Debugging messages if left or right node equals null
		if (listOfNodes.at(iterator)->GetLeftChild() == nullptr) {
			std::cout <<  " left node: nullptr\n";
		}
		
		if (listOfNodes.at(iterator)->GetRightChild() == nullptr) {
			std::cout  << " right node: nullptr\n";
		}
		

		iterator++;
	}
}

// Get the node with minimum value and remove it from list of nodes. List re-adjusts.
template <class T>
Node<T>* minHeapTree<T>::ExrtactMin(minHeapTree<T>* tree) {
	std::cout << "Extracting node with value: " << GetRoot()->GetPriorityValue() << "\n";
	Node<T>* oldRoot = GetRoot(); // store the old root
	listOfNodes.erase(listOfNodes.begin()); // remove root node from node list
	SetRoot(listOfNodes.front()); // Set as root the node at index 0
	HeapifyElements(); // Heapify node list
	tree->ConnectTree(tree); // Reconnect tree based on changed node list
	return oldRoot;
}





////// Helping Functions //////


// Swap two pointers of two nodes
template <class T>
void SwapNodes(Node<T> *x, Node<T> *y)
{
	Node<T> temp = *x;
	*x = *y;
	*y = temp;
	std::cout << " Swapping: " << x->GetPriorityValue() << " with: " << y->GetPriorityValue() << "\n";
}

// Get the root of the tree
template <class T>
Node<T>* minHeapTree<T>::GetRoot()
{
	return root_;
}

// Set a node as the root of the tree
template <class T>
void minHeapTree<T>::SetRoot(Node<T>* root)
{
	root_ = root;
	//std::cout << "root set to " << root_->value_ << "\n";
}

// Get parent's index in the list of nodes
template <class T>
int minHeapTree<T>::GetParentIndex(int i) {
	return ((i - 1) / 2);
}

// Find the parent of a node. Requires list to be structure so parent's index equals: (i - 1) / 2 
template <class T>
Node<T>* minHeapTree<T>::FindParent(std::vector<Node<T>*> listOfNodes, int index)
{
	return listOfNodes[GetParentIndex(index)];
}

// Check if node is already in the list of nodes
template <class T>
bool minHeapTree<T>::Contains(T value)
{
	Node<T>* temp = FindNode(value);
	return (temp != nullptr);
}

// Find node based on value
template <class T>
Node<T>* minHeapTree<T>::FindNode(T value)
{
	Node<T>* temp = root_;

	while (temp != nullptr && temp->GetPriorityValue() != value)
		if (temp->GetPriorityValue() > value)
			temp = temp->GetLeftChild();
		else
			temp = temp->GetRightChild();

	return temp;
}

// Get the nodes of this tree
template <class T>
std::vector<Node<T>*> minHeapTree<T>::GetListOfNodes() {
	return listOfNodes;
}

////// Count Function ////// used for visualazation
template <class T>
int minHeapTree<T>::CountNodes(Node<T>* start)
{
	if (start == nullptr) return 0;

	auto counter = 1;
	if (start->GetLeftChild() != nullptr) counter += CountNodes(start->GetLeftChild());
	if (start->GetRightChild() != nullptr) counter += CountNodes(start->GetRightChild());

	return counter;
}