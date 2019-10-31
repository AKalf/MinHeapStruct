#pragma once
#include "node.h"
#include <vector>

template <class T>
class minHeapTree
{
	node<T>* root_ = nullptr;

	// Remove Helper Functions

	node<T>* FindParent(std::vector<node<T>*>, int);

	std::vector<node<T>*> listOfNodes;
public:

	minHeapTree() = default;
	minHeapTree(int); 
	~minHeapTree() = default;

	// Create Balanced Tree Function
	minHeapTree<T> CreateTree(T*, int);

	// Main Functions
	node<T>* GetRoot();
	void SetRoot(node<T>*);
	bool Contains(T);
	node<T>* FindNode(T);
	void ConnectTree(minHeapTree*,  int);
	
	std::vector<node<T>*> HeapifyElements(T*,  int);
	std::vector<node<T>*> HeapifyElements();
	node<T>* ExrtactMin(minHeapTree<T>*);
	std::vector<node<T>*> GetListOfNodes();
	
	// Count Function
	int count_nodes(node<T>*);
	
};


using namespace std;

template <class T>
minHeapTree<T>::minHeapTree(int array_size) {
	 listOfNodes = std::vector<node<T>*>(array_size);
}


int GetParentIndex(int i) {
	return (i - 1) / 2;
}

////// Create MinHeap Tree Function //////
template <class T>
void SwapNodes(node<T> *x, node<T> *y)
{
	node<T> temp = *x;
	*x = *y;
	*y = temp;
	std::cout << " swapping: "<<x->get_value() << " with: " << y->get_value() << "\n";
}
template <class T>
minHeapTree<T> minHeapTree<T>::CreateTree(T* values, int array_size)
{
	// Place elements in order where root = min
	minHeapTree<T> balanced_tree (array_size);
	// Main loop for structuring tree. Creates a node for each value and placec them in order where root = min
	
	listOfNodes = balanced_tree.HeapifyElements(values, array_size);
	// Set as root the element with smallest value
	balanced_tree.SetRoot(listOfNodes.at(0));
	cout << "Array size: " << array_size << "\n";
	// Main loop for building tree

	ConnectTree(&balanced_tree, array_size);
	return balanced_tree;
}


// Main loop for structuring tree. Creates a node for each value and placec them in order where root = element with min value.
// Elements are structured like that:
// 2 * iterator + 1 = left child's index of node at index "iterator"
// 2 * iterator + 2 = the right child's index of node at index "iterator"
template <class T>
std::vector<node<T>*> minHeapTree<T>::HeapifyElements(T* values,  int array_size) {
	
	int currentSize = 0;
	for (int i = 0; i != array_size; i++) {
		currentSize++;
		int lastIndex = currentSize - 1;
		listOfNodes.at(lastIndex) = new node<T>(values[i]);
		cout << "New key: " << values[i] << " inserted at end\n";
		cout << "last index " << lastIndex << " parent index " << GetParentIndex(lastIndex) << "\n";
		if (i > 0) {
			// Fix the min heap property if it is violated 
			while (lastIndex != 0 && listOfNodes.at(GetParentIndex(lastIndex))->get_value() > listOfNodes.at(lastIndex)->get_value())
			{
				SwapNodes(listOfNodes.at(lastIndex), listOfNodes.at(GetParentIndex(lastIndex)));
				lastIndex = GetParentIndex(lastIndex);
			}
		}
		cout << "Key: " << values[i] << " inserted at position: " << lastIndex << "\n";
	}
	return listOfNodes;

}
template <class T>
std::vector<node<T>*> minHeapTree<T>::HeapifyElements() {

	int currentSize = 0;
	for (int i = 0; i != listOfNodes.size(); i++) {
		currentSize++;
		int lastIndex = currentSize - 1;
		
		//cout << "New key: " << listOfNodes.at(i).get_Value() << " inserted at end\n";
		cout << "\nCurrent node value: " << listOfNodes.at(lastIndex)->get_value() << "\n";
		cout << " parent node value: " << listOfNodes.at(GetParentIndex(lastIndex))->get_value() << "\n";
		cout << " current index: " << lastIndex << " parent index: " << GetParentIndex(lastIndex) << "\n";
		
		if (i > 0) {
			// Fix the min heap property if it is violated 
			while (lastIndex != 0 && listOfNodes.at(GetParentIndex(lastIndex))->get_value() > listOfNodes.at(lastIndex)->get_value())
			{
				SwapNodes(listOfNodes.at(lastIndex), listOfNodes.at(GetParentIndex(lastIndex)));
				lastIndex = GetParentIndex(lastIndex);
			}
		}
		//cout << "Key: " << listOfNodes[i].get_Value() << " inserted at position: " << lastIndex << "\n";
	}
	return listOfNodes;

}
template <class T>
void minHeapTree<T>::ConnectTree(minHeapTree* balanced_tree,  int array_size)
{
	// Create a node tree
	int iterator = 0;
	while (iterator != array_size) {
		cout << "\nProcessing node with value : " << listOfNodes.at(iterator)->get_value() << "\n";
		cout << "iterator: " << iterator << " || left kid iterator: " << 2 * iterator + 1 << " ||  right kid iterator:: " << 2 * iterator + 2 << " \n";
		// if there is a left child node
		if (2 * iterator + 1 < array_size) {
			cout << "Added node with value: " << listOfNodes.at(2 * iterator + 1)->get_value() << " as left child and added for processing\n ";
			// set newly created node as left child of currently processing node
			listOfNodes.at(iterator)->set_left(listOfNodes.at(2 * iterator + 1));
		}
		else {
			listOfNodes.at(iterator)->set_left(nullptr);
		}
		// if there is a right child node
		if (2 * iterator + 2 < array_size) {
			cout << "Added node with value: " << listOfNodes.at(2 * iterator + 2)->get_value() << " as right child and added for processing\n";
			// set newly created node as right child of currently processing node
			listOfNodes.at(iterator)->set_right(listOfNodes.at(2 * iterator + 2));
		}
		else {
			listOfNodes.at(iterator)->set_right(nullptr);
		}


		if (listOfNodes.at(iterator)->get_left() == nullptr) {
			cout << "Node: " << listOfNodes.at(iterator)->get_value() << " \nleft node: nullptr\n";
		}
		else {
			cout << "Node: " << listOfNodes.at(iterator)->get_value() << " \nleft node: " << listOfNodes.at(iterator)->get_left()->get_value() << "\n";
		}
		if (listOfNodes.at(iterator)->get_right() == nullptr) {
			cout << "Node: " << listOfNodes.at(iterator)->get_value() << " \nright node: nullptr\n";
		}
		else {
			cout << "Node: " << listOfNodes.at(iterator)->get_value() << " \nleft node: " << listOfNodes.at(iterator)->get_right()->get_value() << "\n";
		}
		iterator++;
	}
}




template <class T>
node<T>* minHeapTree<T>::FindParent(std::vector<node<T>*> listOfNodes, int index)
{
	return listOfNodes[GetParentIndex(index)];
}


////// Main Functions //////

template <class T>
node<T>* minHeapTree<T>::GetRoot()
{
	return root_;
}

template <class T>
void minHeapTree<T>::SetRoot(node<T>* root)
{
	root_ = root;
	cout << "root set to " << root_->value_ << "\n";
}

template <class T>
bool minHeapTree<T>::Contains(T value)
{
	node<T>* temp = FindNode(value);
	return (temp != nullptr);
}

template <class T>
node<T>* minHeapTree<T>::FindNode(T value)
{
	node<T>* temp = root_;

	while (temp != nullptr && temp->get_value() != value)
		if (temp->get_value() > value)
			temp = temp->get_left();
		else
			temp = temp->get_right();

	return temp;
}

template <class T>
node<T>* minHeapTree<T>::ExrtactMin(minHeapTree<T>* tree) {
	std::cout << "Erasing..." << GetRoot()->get_value() << "\n";
	node<T>* oldRoot = GetRoot();	
	cout << "first element: " << listOfNodes[0]->get_value() << "\n";
	listOfNodes.erase(listOfNodes.begin());
	cout << " size of list: " << listOfNodes.size() << "\n";
	cout << "first element erased\n";
	SetRoot(listOfNodes.front());
	//std::cout << "Node with value: " << oldRoot->get_value() << " has been extracted\n";
	HeapifyElements();
	tree->ConnectTree(tree, listOfNodes.size());
	return oldRoot;
}


template <class T>
std::vector<node<T>*> minHeapTree<T>::GetListOfNodes() {
	return listOfNodes;
}







////// Count Function //////

template <class T>
int minHeapTree<T>::count_nodes(node<T>* start)
{
	if (start == nullptr) return 0;

	auto counter = 1;
	if (start->get_left() != nullptr) counter += count_nodes(start->get_left());
	if (start->get_right() != nullptr) counter += count_nodes(start->get_right());

	return counter;
}