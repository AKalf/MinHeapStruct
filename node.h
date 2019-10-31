#pragma once


template <class T>
class Node
{
	Node<T>* left_;
	Node<T>* right_;
	Node<T>* parent_;

public:
	T value_;
	Node();
	explicit Node(T);
	T GetPriorityValue();
	Node<T>* GetLeftChild();
	Node<T>* GetRightChild();
	void SetLeftChild(Node<T>*);
	void SetRightChild(Node<T>*);
	void SetParentNode(Node<T>*);
	Node<T>* GetParentNode();
};


// A node with a left, a right child and a priority value
template <class T>
Node<T>::Node()
{
	left_ = right_ = nullptr;
}
// A node with a left, a right child and a priority value
template <class T>
Node<T>::Node(T value)
{
	value_ = value;
	left_ = right_ = nullptr;
}
// Get the priority value of this node
template <class T>
T Node<T>::GetPriorityValue()
{
	return value_;
}
// Clear
template <class T>
Node<T>* Node<T>::GetLeftChild()
{
	return left_;
}
// Clear
template <class T>
Node<T>* Node<T>::GetRightChild()
{
	return right_;
}
// Clear
template <class T>
void Node<T>::SetLeftChild(Node<T>* node)
{
	left_ = node;
	if (node != nullptr) {
		node->SetParentNode(this);
	}
}
// Clear
template <class T>
void Node<T>::SetRightChild(Node<T>* node)
{
	right_ = node;
	if (node != nullptr) {
		node->SetParentNode(this);
	}
}
// Clear
template <class T>
Node<T>* Node<T>::GetParentNode()
{
	return parent_;
}
// Clear
template <class T>
void Node<T>::SetParentNode(Node<T>* node)
{
	parent_ = node;
}
