#include <vector>
#define SECRET 1
#define DISCARD 2
#define TWOPAIR 3
#define THREE 4
#define P1 1 
#define P2 2
#define RED 0
#define ORANGE 1
#define YELLOW 2 
#define BLUE 3
#define GREEN 4
#define PURPLE 5

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

class actionData{
private:
	std::vector<card> stack;
	short action;
public:
	actionData();
	actionData(std::vector<card> stack_, short action_);
	std::vector<card> getStack()const;
	short getAction()const;
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
	bool actionTokens[4];
	card secret;
public:
	playerHand();
	std::vector<card> selectCards(std::vector<short> selectedCardIndex);
	void draw(short ammount, deck& deck);
	actionData action(short action, std::vector<card> selectedCards);
	card show(short index);
};

class geisha {
private:
	short value, color, favor;
	std::	vector<card> p1Gifts;
	std:: vector<card> p2Gifts;
public:
	geisha();
	geisha(short value_, short color_, short favor_);
	void setFavor(short);
	short getValue() const;
	short getColor() const;
	short getFavor() const;
	void addGift(short player, card gift);
	void calcFavor();
	std::vector<card> showGifts(short player);
};

class board {
private:
	std::vector<geisha> geishaArr;
public:
	board();
	geisha show(short index);
};
