#include "utility.h"

#include <iostream>
using std::cout;

// Daryon Roshanzaer 5701388
// Michael Wong 6209282


card cardBST::failCard() const {
        card a;
        return a;
    }



bool cardBST::checkInOrder(cardBST& other) {
    Node* min;
    Node* temp = root;
    while (temp->left) {
        temp = temp->left;
    }
    min = temp;
    return checkInOrder(min, other);
    

}

bool cardBST::checkInOrder(Node* n, cardBST& other) {
    while (n) {
        
        if (other.contains(n->info)) {
            cout << "Alice picked matching card " << (n->info).getSuit() << " " << (n->info).getValue() << endl;
            other.remove(n->info);
            remove(n->info);
            return true;
        }
        
        n = getSuccessorNode(n->info);
    }
    return false;


    /*
    if (!n) return false;
    //int ogCount = count();

    n->print();
    if (checkInOrder(n->left, other)) return true;

    cout << "passed the first true" << endl;
    if (other.contains(n->info)) {

        cout << "Alice picked matching card " << (n->info).getSuit() << " " << (n->info).getValue() << endl;
        other.remove(n->info); //why should other.remove() be done first?
        remove(n->info); 
        cout << "alice's card removed" << endl;
        cout << "both cards removed" << endl;
        return true;
    }
    */
    //int newCount = count();
    //if (ogCount != newCount) return;
}



bool cardBST::checkRevInOrder(cardBST& other) {
  Node* max;
  Node* temp = root;
  while (temp->right) {
    temp = temp->right;
  }
  max = temp;
  return checkRevInOrder(max, other);
}

bool cardBST::checkRevInOrder(Node* n, cardBST& other) {
    while (n) {
    if (other.contains(n->info)) {
        cout << "Bob picked matching card " << (n->info).getSuit() << " " << (n->info).getValue() << endl;
        other.remove(n->info);
        remove(n->info);
        return true;
    }
    n = getPredecessorNode(n->info);
    }
    return false;

    /*if (!n) return false;

    n->print();
    if (checkRevInOrder(n->right, other)) return true;

    if (other.contains(n->info)) {

        cout << "Bob picked matching card " << (n->info).getSuit() << " " << (n->info).getValue() << endl;
        other.remove(n->info); //why should other.remove() be done first?
        remove(n->info); 
        cout << "bob's card removed" << endl;
        cout << "both cards removed" << endl;
        return true;
    }

    if (checkRevInOrder(n->left, other)) return true;
    else return false;
    */
   
}




// constructor sets up empty tree
cardBST::cardBST() { 
    root = nullptr;
}

// destructor deletes all nodes
cardBST::~cardBST() {
    clear(root);
    root = nullptr;
}

// recursive helper for destructor
void cardBST::clear(Node *n) {
    if (!n) return;
    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value in tree; return false if duplicate
bool cardBST::insert(card value) {

	if (!root) {
        Node *temp = new Node {value};
        root = temp;
        return true;
    }
    else {
        return insert(value, root);
    }
}


// recursive helper for insert (assumes n is never 0)
bool cardBST::insert(card value, Node *n) {
    if (value > n->info) {
        if (!n->right) {
            Node *temp = new Node {value};
	    temp->parent = n;
            n->right = temp;
            return true;
        } else{
            return insert(value, n->right);
        }
    }
    else if ( value < n->info) {
        if (!n->left) {
            Node *temp = new Node {value};
	    temp->parent = n;
            n->left = temp;
            return true;
        } else{
           return insert(value, n->left);
        }
    }
    else { // is equal
        return false;
    }
}

// print tree data pre-order
void cardBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void cardBST::printPreOrder(Node *n) const {
    if (!n) {
        return;
    }
    n->print();
    printPreOrder(n->left);
    printPreOrder(n->right);
}

// print tree data in-order, with helper
void cardBST::printInOrder() const {
    printInOrder(root);
}

void cardBST::printInOrder(Node *n) const {
    if (!n) {
        return;
    }
    printInOrder(n->left);
    n->print();
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void cardBST::printPostOrder() const {
    printPostOrder(root);
}

void cardBST::printPostOrder(Node *n) const {
    if (!n) {
        return;
    }
    printPostOrder(n->left);
    printPostOrder(n->right);
    n->print();
}



// return count of values
int cardBST::count() const {
    return count(root);
}

// recursive helper for count
int cardBST::count(Node *n) const {
    if (!n) { return 0; }
    return (1 + count(n->left) + count(n->right));
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
cardBST:: Node* cardBST::getNodeFor(card value, Node* n) const{
    if (!n) {
        return nullptr;
    }
    if (value > n->info) {
	if (!n->right) {
		return nullptr;
	} else {
        	return  getNodeFor(value, n->right);
	}
    }
    else if ( value < n->info) {
    	if (!n->left) {
		return nullptr;
	} else {
		return getNodeFor(value, n->left);
	}
    }
    else {
        return n; //this returns address right
    }
}

// returns true if value is in the tree; false if not

// FIX 
bool cardBST::contains(card value) const {
    if (getNodeFor(value, root)) return true;
    else return false;
}

// returns the Node containing the predecessor of the given value
cardBST::Node* cardBST::getPredecessorNode(card value) const{
    if (!root) return nullptr;
    Node *currNode = getNodeFor(value, root);
    if (!currNode) return nullptr;
    if (!currNode->left) {
        if (!currNode->parent) return nullptr;
        else {
            while (currNode->parent) {
                if (currNode->parent->info < value) {
                    return currNode->parent;
                }
                currNode = currNode->parent;
            }
            if (!currNode->parent) return nullptr;
        }
    } else {
        currNode = currNode->left;
        while (currNode->right) {
            currNode = currNode->right;
        }
    }
    return currNode;
}


// returns the predecessor value of the given value or 0 if there is none
card cardBST::getPredecessor(card value) const{

    if (!root) return failCard();
    Node *currNode = getNodeFor(value, root);
    if (!currNode) return failCard();
    if (!currNode->left) {
        if (!currNode->parent) return failCard();
        else {
            while (currNode->parent) {
                if (currNode->parent->info < value) {
                    return currNode->parent->info;
                }
                currNode = currNode->parent;
            }
            if (!currNode->parent) return failCard();
        }
    } else {
        currNode = currNode->left;
        while (currNode->right) {
            currNode = currNode->right;
        }
    }
    return currNode->info;
}


// returns the Node containing the successor of the given value
cardBST::Node* cardBST::getSuccessorNode(card value) const{
    if (!root) return nullptr;
    Node *currNode = getNodeFor(value, root);
    if (!currNode) return nullptr;
    if (!currNode->right) {
        if (!currNode->parent) return nullptr;
        else {
            while (currNode->parent) {
                if (currNode->parent->info > value) {
                    return currNode->parent;
                }
                currNode = currNode->parent;
            }
            if (!currNode->parent) return nullptr;
        }
    } 
    else {
        currNode = currNode->right;
        while (currNode->left) {
            currNode = currNode->left;
        }
    }
    return currNode;
}


// returns the successor value of the given value or 0 if there is none
card cardBST::getSuccessor(card value) const{

    if (!root) return failCard();
    Node *currNode = getNodeFor(value, root);
    if (!currNode) return failCard();
    if (!currNode->right) {
        if (!currNode->parent) return failCard();
        else {
            while (currNode->parent) {
                if (currNode->parent->info > value) {
                    return currNode->parent->info;
                }
                currNode = currNode->parent;
            }
            if (!currNode->parent) return failCard();
        }
    } 
    else {
        currNode = currNode->right;
        while (currNode->left) {
            currNode = currNode->left;
        }
    }
    return currNode->info;
}


// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool cardBST::remove(card value){
    Node *currNode = getNodeFor(value, root);
    if (!currNode) return false;
    if (currNode == root && !root->left && !root->right) {
        delete currNode;
        root = nullptr;
        return true;
    }
    else {
        if (!currNode->left && !currNode->right) { // no children
            if (currNode->parent->right == currNode) {
            	currNode->parent->right = nullptr;
            	delete currNode;
            	return true;
            } 
	    else {
            	currNode->parent->left = nullptr;
            	delete currNode;
            	return true;
            }
        } 
	else if (currNode->left && currNode->right) { // two children
		Node* newNode = getSuccessorNode(value);
		card newData = newNode->info;
		remove(newNode->info); 
		currNode->info = newData;
		return true;
        } 
	else { // only has one child
		if (!currNode->parent) { // checking if the currNode is a root node
			if (currNode->left) {
				currNode->left->parent = nullptr;
				root = currNode->left;
				delete currNode;
				return true;
			}
			else {
				currNode->right->parent = nullptr;
				root = currNode->right;
				delete currNode;
				return true;
			}
		}
		else if (currNode->left) { // only has left child which is left
                	currNode->left->parent = currNode->parent;
                	if (currNode->parent->info > value) {
				currNode->parent->left = currNode->left;
               		} 
			else {
				currNode->parent->right = currNode->left;
                	}
                	delete currNode;
                	return true;
            	}
		else { // only has right child
                	currNode->right->parent = currNode->parent;
                	if (currNode->parent->info > value) {
        	            	currNode->parent->left = currNode->right;
                	} 
			else {
	                    	currNode->parent->right = currNode->right;
               		}
                	delete currNode;
                	return true;
           		}
        	}
    	}
}
