#include <iostream>
#include "gameLogic.h"

int main (){
	deck mainDeck;
	mainDeck.shuffle();

	playerHand player;
	player.draw(7,mainDeck);

	return 0;
}

void printCard(card& card){
	std::cout<<"id: "<<card.getId()<<" color: "<<card.getColor()<<" value: "<<card.getValue()<<std::endl;
}
