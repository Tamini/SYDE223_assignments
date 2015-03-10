#include <iostream>
#include "a2_dynamic_stack.hpp"

typedef DynamicStack::StackItem StackItem; 
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() {
	size_=0;
	capacity_=16;
	init_capacity_=16;
	items_ = new int[init_capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity) {
	size_=0;
	capacity_ = capacity;
	init_capacity_ = capacity;
	items_ = new int[init_capacity_];
}

DynamicStack::~DynamicStack() {
	delete[] (items_);
}

int DynamicStack::size() const {
    return size_;
}

bool DynamicStack::empty() const {
    return (size_==0);
}

void DynamicStack::print() const {
	for (int i = size_-1; i >=0; i--){
		std::cout << *(items_+i) << "\n";
	}
	std::cout << "DONE";
}

StackItem DynamicStack::peek() const {
    if (size_ > 0)
    	return *(items_ + size_ -1);
    return EMPTY_STACK;
}

void DynamicStack::push(StackItem value) {
	if (size_ == capacity_){
		capacity_ *= 2;
		StackItem* newStack = new StackItem[capacity_];
    	for (int i = 0 ; i < size_ ; i++){
    		*(newStack + i) = *(items_ + i);
    	}
    	delete[] items_;
    	items_ = newStack;
	}
	*(items_ + size_) = value;
	size_++;
}

StackItem DynamicStack::pop() {
    if (size_ == 0)
    	return EMPTY_STACK;
    size_--;
    if (size_ <= capacity_ / 4 && size_ / 2 >= init_capacity_){
    	capacity_ = capacity_ / 2;
    	StackItem* newStack = new StackItem[capacity_];
    	for (int i = 0 ; i <= size_ ; i++){
    		*(newStack + i) = *(items_ + i);
    	}
    	delete[] items_;
    	items_ = newStack;
    }
    StackItem temp = *(items_ + size_);
    delete (items_ + size_);
    return temp;
    
}
