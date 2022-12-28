// cards.h
// Author: Michael P Wong

#ifndef CARDS_H
#define CARDS_H


#include <iostream>
#include <string>
using namespace std;

class card {
private:
    string suit; // c, d, h, s
    string value; //a, 2->10, j, q, k


public:
    card(string s = "none", string v = "none") {
        suit = s;
        value = v;
    }

    void setSuit(string input) {
        suit = input;
    }
    void setValue(string input) {
        value = input;
    }

    string getSuit() {
        return suit;
    }

    string getValue() {
        return value;
    }

    //OL < and > for the card class
    int numerize(string input) {
        //suit
        if (input == "c") return 1;
        else if (input == "d") return 2;
        else if (input == "h") return 4;
        else if (input == "s") return 3;

        //value
        else if (input == "a") return 5;
        else if (input == "2") return 6;
        else if (input == "3") return 7;
        else if (input == "4") return 8;
        else if (input == "5") return 9;
        else if (input == "6") return 10;
        else if (input == "7") return 11;
        else if (input == "8") return 12;
        else if (input == "9") return 13;
        else if (input == "10") return 14;
        else if (input == "j") return 15;
        else if (input == "q") return 16;
        else if (input == "k") return 17;
        else return -1;
    }

    //overloaded comparison operators
    bool operator<(const card &other) {
        if (numerize(suit) < numerize(other.suit)) return true;
        else if (numerize(suit) == numerize(other.suit)){
           if (numerize(value) < numerize(other.value)) return true;
           else return false;
        }
        else return false;
    }

    bool operator>(const card &other) {
        if (numerize(suit) > numerize(other.suit)) return true;
        else if (numerize(suit) == numerize(other.suit)){
            if (numerize(value) > numerize(other.value)) return true;
            else return false;
        }
        else return false;
    }
    bool operator==(const card &other) {
        if (numerize(suit) == numerize(other.suit) && numerize(value) == numerize(other.value)) return true;
        else return false;
    }
    void print() {
        cout << suit << " " << value << endl;
    }
};



#endif 
