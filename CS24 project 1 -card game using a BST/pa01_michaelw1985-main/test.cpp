#include "utility.h"
#include "utility.cpp"
#include "cards.h"
#include <iostream>
/*
 suit: c, d, h, s
 value: a, 2->10, j, q, k
*/

using namespace std;

int main() {
    cardBST BST;
    card a = {"c", "a"};
    card b = {"h", "9"};
    card c = {"s", "q"};
    card d = {"s", "k"};
    card e = {"d", "2"};
    card f = {};
    BST.insert(a);
    BST.insert(b);
    BST.insert(c);
    BST.insert(d);
    BST.insert(e);
    BST.insert(f);

    BST.printInOrder();
    return 0;
}