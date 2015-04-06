//
//  main.cpp
//  BST
//
//  Created by Mousa Khan on 2015-04-04.
//  Copyright (c) 2015 Mousa Khan. All rights reserved.
//

#include <iostream>
#include "a3_binary_search_tree.hpp"

using namespace std;

//HELPER FUNCTIONS


//Helper function to help find a certain node..

BinarySearchTree::Node* findNode(BinarySearchTree::Node *node, BinarySearchTree::DataType data) {


    if (node == NULL) {
        return node;
    }



    if (node->val > data && node->left != NULL) {

        return findNode(node->left, data);

    } else if (node->val < data && node->right != NULL){

        return findNode(node->right, data);
    } else {

        return node;
    }

}


// helper function to see if node exists in tree
bool doesNodeExist(BinarySearchTree::Node *node, BinarySearchTree::DataType data) {

    if (node == NULL) return false;

    if (node->val == data) {

        return true;
    }

    if (node->val > data && node->left != NULL) {

        return doesNodeExist(node->left, data);


    } else if (node->val < data && node->right != NULL){

        return doesNodeExist(node->right, data);

    } else {

        return false;

    }

};

// Recursive delete helper function
void destruct(BinarySearchTree::Node* node) {

    if (node->left != NULL) {
        destruct(node->left);
    }

    if (node->right != NULL) {
        destruct(node->right);
    }

    if (node != NULL) {
        delete(node);
    }


}

//Helper function to find depth..

unsigned int findDepth(BinarySearchTree::Node *node, int &dep) {

    int leftTreeD = dep;
    int rightTreeD = dep;


    if (node->right != NULL) {
        rightTreeD++;
        findDepth(node->right, rightTreeD);
    }

    if (node->left != NULL) {
        leftTreeD++;
        findDepth(node->left, leftTreeD);
    }

    if (rightTreeD > leftTreeD) {
        dep = rightTreeD;
    } else {
        dep = leftTreeD;
    }

    return dep;
}

// Recursive print
void printTree(BinarySearchTree::Node* node) {

    if (node == NULL) {
        return;
    }

    if (node->left != NULL) {
        printTree(node->left);
    }

    if (node->right != NULL) {

        printTree(node->right);
    }


    cout << node->val << "\n";

};

// Remove helper functions

BinarySearchTree::Node* removeTree(BinarySearchTree::Node* node, int val) {


    if (node == NULL) return node;
    if (node->right != NULL && node->right->val == val) {

        return node;

    } else if (node->left != NULL && node->left->val == val ) {

        return node;
    }

    if (node->val > val && node->left != NULL){
        return removeTree(node->left, val);
    } else if (node->val < val && node->right != NULL) {
        return removeTree(node->right, val);
    } else {
        return node;
    }


}

bool noChild(BinarySearchTree::Node* node) {
    return (node->right == NULL && node->left == NULL);
}

bool oneChild(BinarySearchTree::Node* node) {

    int count = 0;

    if (node == NULL) {
        return false;
    }
    if (node->right != NULL) {
        count++;
    }

    if (node->left != NULL) {
        count++;
    }


    return (count == 1);
}

bool twoChildren(BinarySearchTree::Node* node) {

    if (node == NULL) {
        return false;
    }

    return (node->right != NULL && node->left != NULL);
};






BinarySearchTree::Node::Node(DataType newval){
    this->val = newval;
};

// Default constructor to initialize the root.
BinarySearchTree::BinarySearchTree(){
    root_ = NULL;
    size_ = 0;

};

// Destructor of the class BinarySearchTree. It deallocates the memory
// space allocated for the binary search tree.
BinarySearchTree::~BinarySearchTree(){
    if (root_ == NULL) return;
    destruct(root_);
    size_ = 0;
};

// Returns the number of nodes in the tree.
unsigned int BinarySearchTree::size() const{
    return size_;
};

// Returns the maximum value of a node in the tree. You can assume that
// this function will never be called on an empty tree.
BinarySearchTree::DataType BinarySearchTree::max() const{

    Node *node = root_;

    while (node->right != NULL) {
        node = node->right;
    }

    return node->val;
};

// Returns the minimum value of a node in the tree. You can assume that
// this function will never be called on an empty tree.

BinarySearchTree::DataType BinarySearchTree::min() const{

    Node *node = root_;

    while (node->left != NULL) {
        node = node->left;
    }

    return node->val;
};



unsigned int BinarySearchTree::depth() const{

    if (size_ == 1 && root_ != NULL) {
        return 0;
    }

    int depth = 0;

    depth = findDepth(root_, depth);

    return depth;
};



// Returns true if a node with the value val exists in the tree; otherwise,
// it returns false.
bool BinarySearchTree::exists(DataType val) const {

    bool exists = doesNodeExist(root_, val);

    if (exists) return true;

    return false;

};




void BinarySearchTree::print() const {

    printTree(root_);

};



// Inserts the value val into the tree. Returns false if val already exists in
// the tree, and true otherwise.
bool BinarySearchTree::insert(DataType val) {

    if (exists(val)) return false;
    if (root_ == NULL) {
        root_ = new Node(val);
        root_->val = val;
        root_->left = NULL;
        root_-> right = NULL;
        size_++;
        return true;
    }


    Node* newNode = new Node(val);
    newNode->left = NULL;
    newNode->right = NULL;
    Node *currNode = findNode(root_, val);


    if (newNode->val > currNode->val) {
        currNode->right = newNode;
    } else if (newNode->val < currNode->val) {
        currNode->left = newNode;
    }

    size_++;

    return true;
};


// Removes the node with the value val from the tree. Returns true if successful,
// and false otherwise.


bool BinarySearchTree::remove(DataType val) {

    Node* node = removeTree(root_, val);

    if (node == NULL) return false;

    if (root_->val == val) {

        if (noChild(root_)) {
            delete(root_);
        }
        if (oneChild(root_)) {

            if (root_->right != NULL) {
                Node* tmp = root_;
                root_ = root_->right;
                delete(tmp);
                tmp = NULL;
            }

        }

        if(twoChildren(root_)) {
            Node* smallest = root_->right;
            Node *temp = root_;

            //Find smallest value in right sub-tree
            while (smallest->left != NULL) {
                smallest = smallest->left;
            }


            if (temp->left != NULL) {
                smallest->left = root_->left;
            }

            smallest = root_->right;

            root_ = smallest;

            delete(temp);
        }
        size_--;
        return true;
    }

    if (node->right != NULL && node->right->val == val){


        //Case 1: Leaf node
        if (noChild(node->right)) {
            delete(node->right);
            node->right  = NULL;
        }

        //Case 2: One child
        if (oneChild(node->right))   {
            Node* tmp = node->right;
            if (tmp->left != NULL) {
                node->right = tmp->left;
            } else {
                node->right = tmp->right;
            }

            delete (tmp);
            tmp = NULL;
        }

        //Case 3: Two children
        if (twoChildren(node->right)) {

            Node* smallest = node->right;
            Node *temp = node->right;

            //Find smallest value in right sub-tree
            while (smallest->left != NULL) {
                smallest = smallest->left;
            }

            smallest->right = temp->right;
            node->right = smallest;


            delete(temp);

        }
        size_--;
        return true;

    } else if (node->left != NULL && node->left->val == val ) {


        //Case 1: Leaf node
        if (noChild(node->left)) {
            delete (node->left);
            node->left = NULL;
        }

        //Case 2: One child
        if (oneChild(node->left))   {

            Node* tmp = node->left;

            if (tmp->right != NULL) {
                node->left = tmp->right;
            } else {
                node->left = tmp->left;
            }

            delete (tmp);
            tmp = NULL;
        }

        if (twoChildren(node->left)) {

            Node* smallest = node->left;
            Node *temp = node->left;

            //Find smallest value in right sub-tree
            while (smallest->right != NULL) {
                smallest = smallest->right;
            }

            smallest->left = temp->left;
            node->left = smallest;

            delete(temp);
            temp = NULL;



        }

        size_--;
        return true;
    }






    return false;
};



