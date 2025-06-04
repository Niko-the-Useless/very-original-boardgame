#include <iostream>
#include "gameLogic.h"

void printCard(card card){
std::cout<<"id: "<<card.getId()<<" color: "<<card.getColor()<<" value: "<<card.getValue()<<std::endl;
}

void printGeisha(geisha geisha){
std::cout<<"favor: "<<geisha.getFavor()<<" color: "<<geisha.getColor()<<" value: "<<geisha.getValue()<<std::endl;
}

int main (){
	deck mainDeck;
	mainDeck.shuffle();
	board Mainboard;
	playerHand player1;
	player1.draw(7,mainDeck);
	playerHand player2;
	player2.draw(7,mainDeck);

	return 0;
}

