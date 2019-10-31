#pragma once


template <class T>
class node
{
	
	node<T>* left_;
	node<T>* right_;
	node<T>* parent_;

public:
	T value_;
	node();
	explicit node(T);
	T get_value();
	node<T>* get_left();
	node<T>* get_right();
	void set_left(node<T>*);
	void set_right(node<T>*);
	void set_parent(node<T>*);
	node<T>* get_parent();
};



template <class T>
node<T>::node()
{
	left_ = right_ = nullptr;
}

template <class T>
node<T>::node(T value)
{
	value_ = value;
	left_ = right_ = nullptr;
}

template <class T>
T node<T>::get_value()
{
	return value_;
}

template <class T>
node<T>* node<T>::get_left()
{
	return left_;
}

template <class T>
node<T>* node<T>::get_right()
{
	return right_;
}

template <class T>
void node<T>::set_left(node<T>* node)
{
	left_ = node;
	if (node != nullptr) {
		node->set_parent(this);
	}
}

template <class T>
void node<T>::set_right(node<T>* node)
{
	right_ = node;
	if (node != nullptr) {
		node->set_parent(this);
	}
}
template <class T>
node<T>* node<T>::get_parent()
{
	return parent_;
}
template <class T>
void node<T>::set_parent(node<T>* node)
{
	parent_ = node;
}
