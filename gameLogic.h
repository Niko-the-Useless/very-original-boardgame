
#define SECRET 1
#define DISCARD 2
#define TWOPAIR 3
#define THREE 4

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
public:
	short index=0;
	card stack[21];
	deck();
	card draw();
	void shuffle();
};


class playerHand {
private:
	card hand[7];
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
class geish {
private:
	short value, color, favor;
public:
	geish();
	geish(short value_, short color_, short favor_);
	short getValue() const;
	short getColor()const;
	short getFavor()const;
	void setFavor(short);
};
