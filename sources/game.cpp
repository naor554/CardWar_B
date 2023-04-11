#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <stdexcept>
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"

using namespace std;
namespace ariel
{
    Game::Game(Player &player1, Player &player2): player1(player1),player2(player2) {
        player1.isplayning = true;
        player2.isplayning = true;
        totalTurns = 0.0;
        numofwars = 0;
        winner = "";
        isover = false;
        initializeDeck();
        shuffleDeck();
        dealCards();
    }

    // Game::~Game() {

    // }

    bool Game::isOver(){
        return isover;
    }


    void Game:: playTurn(){
        if(isover){
            throw invalid_argument("The Game is over!\n");
            return;
        }
        else if(player1.getName() == player2.getName())
        {
            throw invalid_argument("Can't subscribe the same player twice\n");
            return;
        }
        
        int numofcardestaken = 0;
        string turnlog = "";
        while(true)
        {
            Card c1 = player1.drewcard();
            Card c2 = player2.drewcard();
            numofcardestaken += 2;

            if(c1.getvalue() == ACE && c2.getvalue() == TWO)
            {
                player2.cardestaken += numofcardestaken;
                player2.numofwins ++;
                turnlog += (player2.Name + " played " + c2.getinfo() + " " + player1.Name + " played " + c1.getinfo() + ". " + player2.Name + " wins.\n" );
                gamelog.push_back(turnlog);
                totalTurns ++;
                break;

            }

            if(c1.getvalue() == TWO && c2.getvalue() == ACE)
            {
                player1.cardestaken += numofcardestaken;
                player1.numofwins ++;
                turnlog += (player1.Name + " played " + c1.getinfo() + " " + player2.Name + " played " + c2.getinfo() + ". " + player1.Name + " wins.\n" );
                gamelog.push_back(turnlog);
                totalTurns ++;
                break;

            }

            else if(c1.getvalue() > c2.getvalue())
            {
                player1.cardestaken += numofcardestaken;
                player1.numofwins ++;
                turnlog += (player1.Name + " played " + c1.getinfo() + " " + player2.Name + " played " + c2.getinfo() + ". " + player1.Name + " wins.\n" );
                gamelog.push_back(turnlog);
                totalTurns ++;
                break;
            }
            else if(c1.getvalue() < c2.getvalue())
            {
                player2.cardestaken += numofcardestaken;
                player2.numofwins ++;
                turnlog += (player2.Name + " played " + c2.getinfo() + " " + player1.Name + " played " + c1.getinfo() + ". " + player2.Name + " wins.\n" );
                gamelog.push_back(turnlog);
                totalTurns ++;
                break;
            }
            else
            {
                turnlog += (player1.Name + " played " + c1.getinfo() + " " + player2.Name + " played " + c2.getinfo() + "." + " Draw. " );
                Card hiddencard1 = player1.drewcard();
                Card hiddencard2 = player2.drewcard();
                numofcardestaken += 2;
                numofwars ++;
            } 
        }
    
        
    }

    void Game:: playAll(){
        if(!isover){
            while(player1.stacksize() && player2.stacksize()){
                playTurn();
            }
            isover = true;
            return;
        }
    }
    
    void Game:: printLastTurn(){
        cout << gamelog.back();
    }
    
    void Game:: printLog(){
        for (size_t i = 0; i < gamelog.size(); i++){
             cout << gamelog.at(i);
        }
    }
    
    void Game:: printStats(){
        cout << "Player " << player1.getName() << " won " << (player1.numofwins/totalTurns)*100 << "% of turns." << endl;
        cout << "Player " << player2.getName() << " won " << (player2.numofwins/totalTurns)*100 << "% of turns." << endl;
        cout << "There were " << numofwars << " draws in this game." << endl;
        cout << "Player " << player1.getName() << " won " << player1.cardesTaken() << " cards." << endl;
        cout << "Player " << player2.getName() << " won " << player2.cardesTaken() << " cards." << endl;

    }
    
    void Game:: printWiner(){
        if(player1.cardestaken > player2.cardestaken){
                winner = player1.getName();
        }
        else if(player1.cardestaken < player2.cardestaken){
            winner = player2.getName();
        }
        else{
            winner = "No winner, Cardes Taken is equal!";
        }

        cout << "The winner is: " << winner << endl;
    }

    double Game:: drawRate(){
        return numofwars/totalTurns;
    }


    void Game:: initializeDeck(){
        for (int i = 2; i <= 14; ++i) {
            for (int j = 0; j < 4; ++j) {
                deck.emplace_back(static_cast<Value>(i), static_cast<Shape>(j));
            }
        }
    }
    
    void Game::  shuffleDeck(){
        random_device rd;
        mt19937 g(rd());
        shuffle(deck.begin(), deck.end(), g);

    }
    
    void Game::  dealCards(){
        while(deck.size() > 0){
            player1.addCard(deck.back());
            deck.pop_back();
            player2.addCard(deck.back());
            deck.pop_back();
        }
    }

} 
