#ifndef A1_TESTS_HPP
#define A1_TESTS_HPP

#include "a1_doubly_linked_list.hpp"
#include "a1_sequential_list.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class SequentialListTest
{
public:
    bool test1()
    {
        unsigned int capacity = 5;
        SequentialList list(capacity);
        
        ASSERT_TRUE(list.size() == 0)
        ASSERT_TRUE(list.capacity() == capacity)
        ASSERT_TRUE(list.empty() == true)
        ASSERT_TRUE(list.full() == false)
        return true;
    }
    
    bool test2()
    {
        unsigned int capacity = 5;
        SequentialList list1(capacity);
        SequentialList list2(capacity);
        ASSERT_TRUE(list1.insert_front(100))
        ASSERT_TRUE(list2.insert_back(100))
        
        ASSERT_TRUE(list1.size() == list2.size() && list1.size() == 1)
        ASSERT_TRUE(list1.data_ != NULL)
        ASSERT_TRUE(list2.data_ != NULL)
        ASSERT_TRUE(list1.select(0) == list2.select(0) && list1.select(0) == 100)
        return true;
    }
    
    bool test3()
    {
        unsigned int capacity = 5;
        SequentialList list(capacity);
        for (int i = 0; i < capacity; i++) {
            ASSERT_TRUE(list.insert_back(i*100))
        }
        
        unsigned int idx = 3;
        ASSERT_TRUE(list.search(list.select(idx)) == idx)
        ASSERT_TRUE(list.select(capacity + 1) == list.select(capacity))
        ASSERT_TRUE(list.search(1000) == list.size())
        
        for (int i = 0; i < capacity; i++) {
            ASSERT_TRUE(list.select(i) == i*100 && list.data_[i] == i*100)
        }
        return true;
    }
    
    bool test4(){
        unsigned int capacity = 5;
        SequentialList list(capacity);
        for (int i = 0; i < capacity; i++) {
            ASSERT_TRUE(list.insert_back(i*100))
        }
        
        ASSERT_TRUE(list.remove(3));
        ASSERT_TRUE(list.insert(1000,3));
        ASSERT_TRUE(list.remove_front());
        ASSERT_TRUE(list.insert_front(2000));
        ASSERT_TRUE(list.remove_back());
        ASSERT_TRUE(list.insert_back(3000));
        ASSERT_TRUE(list.replace(2,5000));
        list.print(); //2000 100 5000 1000 3000
        std::cout << list.search(200); //5
        std::cout<<std::endl;
        return true;
    }
    
};

class DoublyLinkedListTest
{
public:
    bool test1()
    {
        DoublyLinkedList list;
        ASSERT_TRUE(list.size() == 0)
        ASSERT_TRUE(list.empty() == true)
        ASSERT_TRUE(list.full() == false)
        ASSERT_TRUE(list.head_ == NULL)
        ASSERT_TRUE(list.tail_ == NULL)
        return true;
    }
    
    bool test2()
    {
        DoublyLinkedList list1, list2;
        list1.insert_front(100);
        list2.insert_back(100);
        
        ASSERT_TRUE(list1.size() == list2.size() && list1.size() == 1)
        ASSERT_TRUE(list1.head_ != NULL && list1.head_ == list1.tail_)
        ASSERT_TRUE(list2.head_ != NULL && list2.head_ == list2.tail_)
        ASSERT_TRUE(list1.head_->prev == NULL && list1.tail_->next == NULL)
        ASSERT_TRUE(list2.head_->prev == NULL && list2.tail_->next == NULL)
        ASSERT_TRUE(list1.select(0) == list2.select(0) && list1.select(0) == 100)
        return true;
    }
    
    bool test3()
    {
        DoublyLinkedList list;
        const int num_elems = 5;
        for (int i = 0; i < num_elems; i++) {
            ASSERT_TRUE(list.insert(i*100, i))
        }
        unsigned int idx = 3;
        ASSERT_TRUE(list.search(list.select(idx)) == idx)
        ASSERT_TRUE(list.select(num_elems + 1) == 400)
        ASSERT_TRUE(list.search(1000) == list.size())
        
        for (int i = 0; i < num_elems; i++) {
            ASSERT_TRUE(list.select(i) == i*100)
        }
        
        ASSERT_TRUE(list.head_->prev == NULL && list.tail_->next == NULL)
        return true;
    }
    
    bool test4()
    {
        DoublyLinkedList list;
        const int num_elems = 5;
        for (int i = 0; i < num_elems; i++) {
            ASSERT_TRUE(list.insert(i*100, i))
        }
        list.print();
        list.insert(600, 2);
        ASSERT_TRUE(list.select(2) == 600);
        list.insert_front(1000);
        list.insert_back(7000);
        list.remove(1);
        
        std::cout<<"INSERT 1000 and 7000 (front back respectively) and remove index 1 element";
        std::cout<<std::endl;
        
        list.print();
        list.replace(3,9000);
        list.remove_front();
        list.remove_back();
        std::cout<<"Replaced element 4 with 9000 and removed first and last element";
        std::cout<<std::endl;
        list.print();
        return true;
    }
    
    
};


#endif
