#include <vector>
#define SECRET 1
#define DISCARD 2
#define TWOPAIR 3
#define THREE 4
#define P1 1 
#define P2 2

class card {
private: 
	short id, value, color;
public:
	card();
	card(short id_, short value_, short color_);
	short getId() const;
	short getValue() const;
	short getColor() const;
};

class deck {
private:
	std::vector<card> stack;
public:
	deck();
	card draw();
	void shuffle();
};

class playerHand {
private:
	std::vector<card> hand;
	bool Asecret;
	bool Adiscard;
	bool AtwoPairs;
	bool Athree;
public:
	playerHand();
	void draw(short ammount, deck& deck);
	void action(short action);
	card show(short index);
};

class geisha {
private:
	short value, color, favor;
	std::	vector<card> p1Gifts;
	std::vector<card> p2Gifts;
public:
	geisha();
	geisha(short value_, short color_, short favor_);
	void setFavor(short);
	short getValue() const;
	short getColor() const;
	short getFavor() const;
	void addGift(short player, card gift);
	void calcFavor();
};
