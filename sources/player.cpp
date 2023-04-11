#include <iostream>
#include <vector>
#include <string>
#include "player.hpp"
#include "card.hpp"

using namespace std;
namespace ariel
{
  Player::Player(){
    Name = "Bob";
    numofwins = 0.0;
    cardestaken = 0;
    isplayning = false;
  }

  Player::Player(string name){
    Name = name;
    numofwins = 0;
    cardestaken = 0;
    isplayning = false;
  }

  // Player::~Player() {

  // }

  int Player:: stacksize(){ 
    return vec1.size();
  }

  int Player:: cardesTaken(){ 
    return cardestaken;
  }  

  string Player:: getName(){
    return Name;
  }

  bool Player:: isPlayning(){
    return isplayning;
  }

  Card Player:: drewcard(){
    Card c = vec1.back();
    vec1.pop_back();
    return c;
  }

  void Player:: addCard(Card card){
    vec1.push_back(card);
  }

} 



