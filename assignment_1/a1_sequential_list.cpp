#include "a1_sequential_list.hpp"
#include <iostream>

SequentialList::SequentialList(unsigned int cap)
{
	capacity_ = cap;
	data_ = new DataType [capacity_];
}

SequentialList::~SequentialList()
{
	delete(data_);
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::empty() const
{
	if (size_ == 0)
		return true;
	return false;
}

bool SequentialList::full() const
{
	if (size_ == capacity_)
		return true;
	return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if (index >= size_)
		return *(data_ + size_-1);
	return *(data_ + index);
}

unsigned int SequentialList::search(DataType val) const
{
	for (int i = 0; i < size_; i++){
		if (*(data_ + i) == val)
			return i;
	}
}

void SequentialList::print() const
{
	for (int i = 0; i < size_; i++){
		std::cout << *(data_ + i) << ",";
	}
	std::cout << std::endl;
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if (size_ == capacity_)
		return false;
	if (index > size_)
		index = size_;
	Datatype temp;
	size_ += 1;
	*(data_ + index) = val;
}

bool SequentialList::insert_front(DataType val)
{
	if (size_ == capacity_)
		return false;
	
}

bool SequentialList::insert_back(DataType val)
{
	if (size_ == capacity_)
		return false;
	*(data_ + size-1) = val;
	size++;
	return true;
}

bool SequentialList::remove(unsigned int index)
{
	if (size_ < index)
		return false;
}

bool SequentialList::remove_front()
{
	if (size_ == 0)
		return false;
}

bool SequentialList::remove_back()
{
	if (size_ == 0)
		return false;
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	
}
