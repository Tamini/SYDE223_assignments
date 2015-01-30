#include "a1_doubly_linked_list.hpp"

DoublyLinkedList::Node::Node(DataType data)
{
	value = data;
}

DoublyLinkedList::DoublyLinkedList()
{
	size_ = 0;
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
}

unsigned int DoublyLinkedList::search(DataType value) const
{
}

void DoublyLinkedList::print() const
{
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
}

bool DoublyLinkedList::insert_front(DataType value)
{
}

bool DoublyLinkedList::insert_back(DataType value)
{
}

bool DoublyLinkedList::remove(unsigned int index)
{
}

bool DoublyLinkedList::remove_front()
{
}

bool DoublyLinkedList::remove_back()
{
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
}
