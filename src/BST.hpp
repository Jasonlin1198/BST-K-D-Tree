//
// BST.hpp
// CSE 100 Project 1
//
// Last modified by Heitor Schueroff on 01/10/2019
//

#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <algorithm>

#include "BSTIterator.hpp"
#include "BSTNode.hpp"

using namespace std;

template <typename Data>
class BST {
protected:
    // Pointer to the root of this BST, or 0 if the BST is empty.
    BSTNode<Data> *root;

    // Number of elements stored in this BST.
    unsigned int isize;

    // Height of this BST.
    unsigned int iheight;

public:
    // Define iterator as an aliased typename for BSTIterator<Data>.
    typedef BSTIterator<Data> iterator;

    /** 
     * Default constructor. Initializes an empty BST.
     */
    BST() : root(0), isize(0), iheight(0) {}

    /** 
     * Default destructor. Frees all memory allocated by this BST.
     */
    // TODO
    virtual ~BST() {
	deleteAll(root);
    }

    /** 
     * Inserts the given item into this BST.
     *
     * This function should use only the '<' operator when comparing
     * Data items. (do not use ==, >, <=, >=). For the reasoning
     * behind this, see the assignment writeup.
     *
     * Parameters:
     *     item Data item to insert into this BST
     *
     * Returns:
     *     true if the item was inserted as a consequence of calling
     *     this function, false otherwise (e.g. item is a duplicate).
     */
    // TODO
    virtual bool insert(const Data &item){
	
	int currHeight = 1;
	
	/* if empty tree */
	if(!root){
	    root = new BSTNode<Data> (item);
	    isize++;
	    iheight = 1;
	    return true;
	}    	
	BSTNode<Data> * current = root;
	BSTNode<Data> * prev = nullptr;

	/* sets prev ptr to last comparison node */
	while(current){
	    if(item < current->data){
	    	prev = current;
		current = current->left;
	    }
	    else if( current->data < item){
	    	prev = current;
		current = current->right;
	    }
	    else{
	    	return false;
	    }
	    currHeight++;

	}

	/* compares data to parent of node to be inserted */
	if( item < prev->data){
	    prev->left = new BSTNode<Data> (item);
	    prev->left->parent = prev; 
	}
	else{
	    prev->right = new BSTNode<Data> (item);
	    prev->right->parent = prev;
	}

	/* sets new height of tree */
	if(iheight < currHeight){
	    iheight = currHeight;  
	}

	isize++;
	return true; 
    }

    /**
     * Searches for the given item in this BST.
     *
     * This function should use only the '<' operator when comparing
     * Data items. (should not use ==, >, <=, >=). For the reasoning
     * behind this, see the assignment writeup.
     *
     * Parameters:
     *     item Data item to search for in this BST.
     *
     * Returns:
     *     An iterator pointing to the item if found, or pointing 
     *     past the last node in this BST if item is not found.
     */
    // TODO
    virtual iterator find(const Data &item) const {

	if(!root){
	    return typename BST<Data>:: iterator(0);
	}
	
	BSTNode<Data> * current = root;
	while(current){
	    if(item < current->data){
		current = current->left;
	    }
	    else if( current->data < item){
		current = current->right;
	    }
	    else{
	    	return typename BST<Data>:: iterator(current);

	    }
	}

	return typename BST<Data>:: iterator(0);
    
    }		
    /** 
     * Returns the number of items currently in the BST.
     */
    // TODO
    unsigned int size() const {
	return isize;
    }

    /** 
     * Returns the height of this BST.
     */
    // TODO
    unsigned int height() const {
	if(empty()){
	    return 0;
	}
	return iheight;
    }

    /** 
     * Returns true if this BST is empty, false otherwise.
     */
    // TODO
    bool empty() const {
	if(!root){
	    return true;
	}
	return false;
    }

    /** 
     * Returns an iterator pointing to the first item in the BST (not the root).
     */
    // TODO
    iterator begin() const {

	BSTNode<Data>* curr = first(root);
	return typename BST<Data>::iterator(curr);

    }

    /** 
     * Returns an iterator pointing past the last item in the BST.
     */
    iterator end() const { 
        return typename BST<Data>::iterator(0); 
    }

    /** 
     * Prints the elements in this BST in ascending order.
     */
    void inorder() const { 
        inorder(root); 
    }

private:
    /*
     * Find the first node in the given subtree with root curr.
     */
    static BSTNode<Data>* first(BSTNode<Data> *curr) {
        if (!curr) return 0;
        while (curr->left) {
            curr = curr->left;
        }
        return curr;
    }

    /* 
     * Do an inorder traversal, printing the data in ascending order.
     *
     * You can achieve an inorder traversal recursively by following 
     * the order below.
     *
     *     recurse left - print node data - recurse right
     */
    // TODO
    static void inorder(BSTNode<Data> *n) {
	if(!n){
	    return;
	}
	
	inorder(n->left);
	cout << n->data << endl; 
	inorder(n->right);
    }

    /* 
     * Do a postorder traversal, deleting nodes.
     *
     * You can achieve a postorder traversal recursively by following 
     * the order below.
     *
     *     recurse left - recurse right - delete node
     */
    // TODO
    static void deleteAll(BSTNode<Data> *n) {
	if(!n){
	    return; 
	}
	deleteAll(n->left);
	deleteAll(n->right);
    
	delete n;
	return;
	}

};
#endif  // BST_HPP
