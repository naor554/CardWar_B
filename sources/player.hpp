#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"


#pragma once
#ifndef EX1_CPP_A_PLAYER_H
#define EX1_CPP_A_PLAYER_H

#endif //EX1_CPP_A_PLAYER_H

namespace ariel{
    using namespace std;

    class Player
    {
    public:

        string Name;
        vector<Card> vec1;
        int cardestaken;
        float numofwins;
        bool isplayning;

        Player();
        Player(string name);
        //~Player();
        int stacksize();
        int cardesTaken();
        bool isPlayning();
        string getName();
        Card drewcard();
        void addCard(Card card);
    };
    

}

