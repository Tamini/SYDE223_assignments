#include <iostream>
#include "a3_priority_queue.hpp"

PriorityQueue::PriorityQueue(unsigned int capacity){
    size_=0;
    capacity_=capacity;
    heap_ = new DataType[capacity_ + 1];
}

PriorityQueue::~PriorityQueue(){
    delete[] heap_;
}

unsigned int PriorityQueue::size() const{
    return size_;
}

bool PriorityQueue::empty() const {
    return (size_ == 0);
}

bool PriorityQueue::full() const {
    return (size_ == capacity_);
}

void PriorityQueue::print() const{
    for (int i = 1; i < size_; i++)
        std::cout << heap_[i] << "\n";
}

PriorityQueue::DataType PriorityQueue::max() const{
    if (size_ == 0)
        return NULL;
    return heap_[0];
}

bool PriorityQueue::enqueue(DataType val){
    if (size_ == capacity_)
        return false;
    heap_[size_] = val;
    for (int i = size_ +1; i > 1; i= (i-1) / 2){
        if (heap_[i] > heap_[(i-1) / 2]){
            DataType temp = heap_[(i-1) / 2];
            heap_[(i-1) / 2] = heap_[i];
            heap_[i] = temp;
        }
    }
    size_++;
    return true;
}

bool PriorityQueue::dequeue(){
    if (size_ == capacity_)
        return false;
    size_--;
    heap_[1] = heap_[size_];
    delete (heap_ + size_);
    for (int i = 1; i < size_ / 2; i++){
        if (heap_[i] < heap_[i*2+1]){
            DataType next = heap_[i*2+1];
            heap_[i*2+1] = heap_[i];
            heap_[i] = next;
        }
        else if (heap_[i] < heap_[i*2]){
            DataType next = heap_[i*2];
            heap_[i*2] = heap_[i];
            heap_[i] = next;
        }
        else
            break;
    }
    return true;
}

bool heapify(){
    return true;
}
