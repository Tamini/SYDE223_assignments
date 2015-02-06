#include "a1_doubly_linked_list.hpp"
#include <iostream>

DoublyLinkedList::Node::Node(DataType data)
{
	value = data;
	prev = NULL;
	next = NULL;
}

DoublyLinkedList::DoublyLinkedList()
{
	size_ = 0;
	head_ = NULL;
	tail_ = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
	
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
	return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
	return (size_ == 0);
}

bool DoublyLinkedList::full() const
{
	return (size_ == CAPACITY);
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	Node* temp = head_;
	if (index >= size_)
		return NULL;
	for (int i = 0; i < index; i++)
	{
		temp = temp -> next;
	}
	return temp -> value;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	Node* current = head_;
	for (int i = 0; i < size_; i++)
	{
		if (current -> value == value)
			return i;
		current = current -> next;
	}	
	return size_;
}

void DoublyLinkedList::print() const
{
	Node* current = head_;
	do{
		std::cout << current -> value << ",";
		current = current -> next;
	}while (current -> next != head_);
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	Node* current = head_;
	for (int i = 0; i < index; i++)
	{
		current = current -> next;
	}
	return current;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	Node* newNode = new Node(value);
	size_ ++;
	if (size_ == 1) {
		head_ = newNode;
		tail_ = newNode;
		return true;
	}
	if (size_ == 2) {
		if (index != 0)
			tail_ = newNode;
		else {
			tail_ = head_;
			head_ = newNode;
		}
		head_ -> next = tail_;
		head_ -> prev = NULL;
		tail_ -> prev = head_;
		tail_ -> next = NULL;
		return true;
	}
	if (index == 0) {
		newNode -> next = head_;
		head_ -> prev = newNode;
		newNode -> prev = NULL;
		head_ = newNode;
		return true;
	}
	if (index == size_ - 1){
		newNode -> next = NULL;
		tail_ -> next = newNode;
		newNode -> prev = tail_;
		tail_ = newNode;
		return true;
	}
	Node* previous;
	previous = getNode(index - 1);
	Node* nextNode = previous -> next;
	previous -> next = newNode;
	newNode -> prev = previous;
	newNode -> next = nextNode;
	nextNode -> prev = newNode;	
	return true;
}

bool DoublyLinkedList::insert_front(DataType value)
{
	return insert(value, 0);
}

bool DoublyLinkedList::insert_back(DataType value)
{
	return insert(value, size_);
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if (index >= size_ || index < 0)
		return false;
	Node* previous = head_;
	for (int i = 0; i < index - 1; i++)
	{
		previous = previous -> next;
	}
	Node* next = previous -> next -> next;
	delete(previous -> next);
	previous -> next = next;
	next -> prev = previous;
	return true;
}

bool DoublyLinkedList::remove_front()
{
	if (size_ == 0)
		return false;
	head_ = head_ -> next;
	delete(head_ -> prev);
	head_ -> prev = NULL;
	return true;
}

bool DoublyLinkedList::remove_back()
{
	if (size_ == 0)
		return false;
	tail_ = tail_ -> prev;
	delete(tail_ -> next);
	tail_ -> next = NULL;
	return true;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	if (index >= size_ || index < 0)
		return false;
	Node* curr = head_;
	for (int i = 0; i < index; i++)
	{
		curr = curr -> next;
	}
	curr -> value = value;
	return true;
}
