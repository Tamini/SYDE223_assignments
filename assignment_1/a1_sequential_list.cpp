#include "a1_sequential_list.hpp"
#include <iostream>

// Tristan Amini - 20517967
// Keren Chandren - 20516240

SequentialList::SequentialList(unsigned int cap)
{
	capacity_ = cap;
	data_ = new DataType [capacity_];
	size_ = 0;
}

SequentialList::~SequentialList()
{
	delete[] data_;
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
	return size_;
}

void SequentialList::print() const
{
	for (int i = 0; i < size_ - 1; i++){
		std::cout << *(data_ + i) << ", ";
	}
	std::cout << *(data_ + size_-1);
	std::cout << std::endl;
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if (size_ == capacity_)
		return false;
	if (index > size_)
		index = size_;
	DataType oldVal = *(data_ + index);
	DataType newVal = val;
	for (int i = index; i < size_; i++){
		oldVal = *(data_ + i);
		*(data_ + i) = newVal;
		newVal = oldVal;
	}
	*(data_ + size_) = newVal;
	size_ += 1;
	return true;
}

bool SequentialList::insert_front(DataType val)
{
	if (size_ == capacity_)
		return false;
	for (int i = size_; i > 0; i--){
		*(data_ + i) = *(data_ + i - 1);
	}
	*(data_) = val;
	size_ += 1;
	return true;
	
}

bool SequentialList::insert_back(DataType val)
{
	if (size_ == capacity_)
		return false;
	*(data_ + size_) = val;
	size_++;
	return true;
}

bool SequentialList::remove(unsigned int index)
{
	if (size_ < index)
		return false;
	
	DataType *data2 = new DataType [size_ - index - 1];
	for (int i = index + 1; i < size_; i++)
		*(data2 + i - index) = *(data_ + i);
	size_ -= 1;
	for (int i = index; i < size_; i++)
		*(data_ + i) = *(data2 + i - index);
	return true;
}

bool SequentialList::remove_front()
{
	if (size_ == 0)
		return false;
	return remove(0);
}

bool SequentialList::remove_back()
{
	if (size_ == 0)
		return false;
	delete(data_ + size_ - 1);
	return true;
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if (index >= size_)
		return false;
	*(data_ + index) = val;
	return true;
}
