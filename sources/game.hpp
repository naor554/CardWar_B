#include <iostream>
#include <stdexcept>
#include "player.hpp"
#include "card.hpp"

#ifndef EX1_CPP_A_GAME_H
#define EX1_CPP_A_GAME_H
#pragma once
#endif //EX1_CPP_A_GAME_H

namespace ariel{

    class Game
    {

    Player& player1;
    Player& player2;
    vector<Card> deck;
    vector<string> gamelog;
    float totalTurns;
    int numofwars;
    bool isover;
    string winner;

    private:
        void initializeDeck();
        void shuffleDeck();
        void dealCards();

    public:
        Game(Player &player1, Player &player2); 
        //~Game();
        int getNumCardsInDeck();
        int getNumTurns();
        double drawRate();
        bool isOver();
        string getWinner();
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        
    };

}


