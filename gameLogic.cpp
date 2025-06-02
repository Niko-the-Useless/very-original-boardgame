#include "gameLogic.h"
#include <random>
#include <algorithm>
#include <vector>
//-------------card--------------
card::card():id(0), value(0), color(0){}
card::card(short id_, short value_, short color_): id(id_), value(value_), color(color_){}
short card::getId() const {return id;}
short card::getValue() const {return value;}
short card::getColor() const {return color;}

//-------------deck--------------

deck::deck(){
	short index=0;
	while (index<=1){
		stack.push_back(card(index,2,0));
		index++;
	}
	while (index<=3){
		stack.push_back(card(index,2,1));
		index++;
	}
	while (index<=5){
		stack.push_back(card(index,2,2));
		index++;
	}
	while (index<=8){
		stack.push_back(card(index,3,3));
		index++;
	}
	while (index<=11){
		stack.push_back(card(index,3,4));
		index++;
	}
	while (index<=15){
		stack.push_back(card(index,4,5));
		index++;
	}
	while (index<=20){
		stack.push_back(card(index,5,6));
		index++;
	}
}

void deck::shuffle(){
	std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(stack.begin(),stack.end(),g);
}

card deck::draw(){
	card c=stack.back();
	stack.pop_back();
	return c;
}

//-------------hand--------------
playerHand::playerHand():Asecret(0),Adiscard(0),AtwoPairs(0), Athree(0){};
void playerHand::draw(short ammount, deck& deck){
	for (int i=0;i<ammount;){
		hand.push_back(deck.draw());
		i++;
	}
};

card playerHand::show(short index){
	return hand.at(index);
}

std::vector<card> playerHand::selectCards(std::vector<short> selectedCardIndex){
	std::vector<card> selectedCards;
	while (selectedCardIndex.size()>0){
		selectedCards.push_back(hand.at(selectedCardIndex.back()));
		selectedCardIndex.pop_back();
	}
	return selectedCards;
}

void playerHand::action(short action, std::vector<card> selectedCards){
	switch (action){
		case SECRET:
		Asecret=1;
		secret=selectedCards.back();
		selectedCards.pop_back();
		case DISCARD:
		Adiscard=1;
		case TWOPAIR:
		AtwoPairs=1;
		case THREE:
		Athree=1;
	}
}

//-------------------geisha--------------
geisha::geisha():value(0), color(0), favor(0){}
geisha::geisha(short value_, short color_, short favor_): value(value_), color(color_), favor(favor_){}
short geisha::getValue() const {return value;}
short geisha::getColor() const {return color;}
short geisha::getFavor() const {return favor;}
void geisha::setFavor(short player){favor=player;}

void geisha::addGift(short player, card gift){
	if (player==P1){
		p1Gifts.push_back(gift);
	} else if (player==P2){
		p2Gifts.push_back(gift);
	}
}

void geisha::calcFavor(){
	short p1Favor=0, p2Favor=0;
	while (p1Gifts.empty()!=true){
		p1Favor=p1Favor+p1Gifts.back().getValue();
		p1Gifts.pop_back();
	}
	while (p2Gifts.empty()!=true){
		p2Favor=p2Favor+p2Gifts.back().getValue();
		p2Gifts.pop_back();
	}
	if (p1Favor>p2Favor){favor=P1;}
	else if (p1Favor<p2Favor){favor=P2;}
}

std::vector<card> geisha::showGifts(short player){
	if (player==P1){return p1Gifts;}
	else {return p2Gifts;}
}
