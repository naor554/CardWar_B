#include <iostream>
#include <vector>
#pragma once

#ifndef EX1_CPP_A_CARD_H
#define EX1_CPP_A_CARD_H

#endif //EX1_CPP_A_CARD_H


using namespace std;

namespace ariel{

    enum Value {
        TWO = 2,
        THREE = 3,
        FOUR = 4,
        FIVE = 5,
        SIX = 6,
        SEVEN = 7,
        EIGHT = 8,
        NINE = 9,
        TEN = 10,
        JACK = 11,
        QUEEN = 12,
        KING = 13,
        ACE = 14
    };

    enum Shape {
        HEARTS,
        DIAMONDS,
        CLUBS,
        SPADES
    };

    class Card {
        Value val;
        Shape shape;

        public:
            Card();
            Card(Value value, Shape shape);
            //~Card();
            int getvalue();
            string getinfo();

            
    };
}
   
