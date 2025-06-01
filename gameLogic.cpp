#include "gameLogic.h"
#include <random>
#include <algorithm>

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

deck::deck(){
	short index=0;
	while (index<=1){
		stack[index]=card(index,2,0);
		index++;
	}
	while (index<=3){
		stack[index]=card(index,2,1);
		index++;
	}
	while (index<=5){
		stack[index]=card(index,2,2);
		index++;
	}
	while (index<=8){
		stack[index]=card(index,3,3);
		index++;
	}
	while (index<=11){
		stack[index]=card(index,3,4);
		index++;
	}
	while (index<=15){
		stack[index]=card(index,4,5);
		index++;
	}
	while (index<=20){
		stack[index]=card(index,5,6);
		index++;
	}
	index=0;
}
void deck::shuffle(){
	std::random_device rd;
	std::mt19937 rng(rd());
	std::shuffle(stack,stack+21,rng);
}
card deck::draw(){
	index++;
	return stack[index-1];
}

playerHand::playerHand():Asecret(0),Adiscard(0),AtwoPairs(0), Athree(0){};

void playerHand::draw(short ammount, deck& deck){
	for (int i=0;i<ammount;){
		hand[i]=deck.draw();
		i++;
	}
};

card playerHand::show(short index){
	return hand[index];
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
