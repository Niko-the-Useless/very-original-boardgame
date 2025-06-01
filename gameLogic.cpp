#include "gameLogic.h"
#include <random>
#include <algorithm>
#include <vector>

card::card():id(0), value(0), color(0){}

card::card(short id_, short value_, short color_): id(id_), value(value_), color(color_){}

short card::getId() const {return id;}

short card::getValue() const {return value;}

short card::getColor() const {return color;}

geish::geish():value(0), color(0), favor(0){}

geish::geish(short value_, short color_, short favor_): value(value_), color(color_), favor(favor_){}

short geish::getValue() const {return value;}

short geish::getColor() const {return color;}

short geish::getFavor() const {return favor;}

void geish::setFavor(short player){favor=player;}

void geish::addGift(short player, card gift){
	if (player==P1){
		p1Gifts.push_back(gift);
	} else if (player==P2){
		p2Gifts.push_back(gift);
	}
}

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

void playerHand::action(short action){
	switch (action){
		case SECRET:
			Asecret=1;
		case DISCARD:
			Adiscard=1;
		case TWOPAIR:
			AtwoPairs=1;
		case THREE:
			Athree=1;
	}
}
