#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <stdexcept>
#include "card.hpp"

using namespace std;

namespace ariel
{
    Card::Card(){
        val = ACE;
        shape = HEARTS;
    }
    
    Card::Card(Value value, Shape shape){
        this->val = value;
        this->shape = shape;
    }

    // Card::~Card(){

    // }

    int Card::getvalue(){
        return val;
    }

    string Card::getinfo(){
        string r = "";
        switch (val) {
            case ACE:
                r = "Ace";
                break;
            case TWO:
                r = "2";
                break;
            case THREE:
                r = "3";
                break;
            case FOUR:
                r = "4";
                break;
            case FIVE:
                r = "5";
                break;
            case SIX:
                r = "6";
                break;
            case SEVEN:
                r = "7";
                break;
            case EIGHT:
                r = "8";
                break;
            case NINE:
                r = "9";
                break;
            case TEN:
                r = "10";
                break;
            case JACK:
                r = "Jack";
                break;
            case QUEEN:
                r = "Queen";
                break;
            case KING:
                r = "King";
                break;
        }

        string s = "";
        switch (shape) {
            case HEARTS:
                s = "Hearts";
                break;
            case DIAMONDS:
                s = "Diamonds";
                break;
            case CLUBS:
                s = "Clubs";
                break;
            case SPADES:
                s = "Spades";
                break;
        }
        return r + " of " + s;
    }

}
