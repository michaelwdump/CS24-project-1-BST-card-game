#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "cards.h"
#include "utility.h"
#include "utility.cpp"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  card temp;
  cardBST a;
  cardBST b;
  string word, word2;
  istringstream iss;


  while (getline (cardFile1, line) && (line.length() > 0)){
    //get first string, setsuit
    //second second string, getvalue
    //insert card to alice BST
    //incrment line
    iss.clear();
    iss.str(line);
    while (iss.good()) {
      iss >> word;
      iss >> word2;
      temp.setSuit(word);
      temp.setValue(word2);
      a.insert(temp);
    }
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    iss.clear();
    iss.str(line);
    while (iss.good()) {
      iss >> word;
      iss >> word2;
      temp.setSuit(word);
      temp.setValue(word2);
      b.insert(temp);
    }
  }
  cardFile2.close();
  
  /* TEST CODE
  cout << "Alice's card has: " << endl;
  a.printInOrder();

  cout << "Bob's card has: " << endl; 
  b.printInOrder();
*/
  //end of test code

  bool loopEnd = true;

  while (loopEnd) {
    a.checkInOrder(b);
    b.checkRevInOrder(a);
    if (!a.checkInOrder(b) || !b.checkRevInOrder(a)) loopEnd = false;
  }


  cout << endl;
  cout << "Alice's cards:" << endl;
  a.printInOrder();

  cout << endl;
  cout << "Bob's cards:" << endl; 
  b.printInOrder();


  return 0;
}
