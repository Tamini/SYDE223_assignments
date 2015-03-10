#include <iostream>
#include "a2_circular_queue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
    capacity_ = 16;
    head_ = 0;
    tail_ = 0;
    size_ = 0;
    items_ = new int[capacity_];
}

CircularQueue::CircularQueue(unsigned int capacity) {
    capacity_ = capacity;
    head_ = 0;
    tail_ = 0;
    size_ = 0;
    items_ = new int[capacity_];
}

CircularQueue::~CircularQueue() {
    delete[] items_;
}

int CircularQueue::size() const {
    return size_;
}

bool CircularQueue::empty() const {
    return (size_ == 0);
}

bool CircularQueue::full() const {
    return (size_ == capacity_);
}

void CircularQueue::print() const {
    if (size_ == 0)
        return;
    for (int i=head_; i != tail_; i++){
        if(i == capacity_)
            i = 0;
        std::cout << *(items_ + i) << "\n";
    }
}

QueueItem CircularQueue::peek() const {
    if (size_ == 0)
        return EMPTY_QUEUE;
    return *(items_ + head_);
}

bool CircularQueue::enqueue(QueueItem value) {
    if (size_ == capacity_)
        return false;
    size_++;
    *(items_ + tail_) = value;
    tail_ = (tail_ + 1) % capacity_;
    return true;
}

QueueItem CircularQueue::dequeue() {
    if (size_ == 0)
        return EMPTY_QUEUE;
    QueueItem temp = *(items_ + head_);
    head_++;
    size_--;
    if (size_ < 0)
        size_ = 0;
    if (head_ == capacity_)
        head_ = 0;
    return temp;
}
