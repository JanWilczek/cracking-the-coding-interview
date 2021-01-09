class Deck {
public:
	Deck(int jokerCount = 2); // Fills the deck with 13 numbers and 4 colors
	
	Card getTop();
	Card getCard(Color c, Number n);
	Card getTopWithColor(Color c);
	Card getTopWithNumber(Number n);
	Card getBottom();

	void putTop(Card c);
	void putBottom(Card c);

private:
	std::deque<Card> cards;
};

enum class Color { spades, clubs, diamonds, hearts };
enum class Number { joker = 0, ace = 1, two, three, four, six, seven, eight, nine, ten, jack, queen, king };

class Card {
public:
	Card(Color c, Number n);
	Color color() const noexcept;
	Number number() const noexcept;
};

class Croupier {
public:
	void shuffle(Deck& deck);
};

class Hand {
public:
	Hand(const std::vector<Card>& cards);
	const std::vector<Card>& view() const;
	void insert(Card c);

private:
	std::vector<Card> cards;
};

class Player {
public:
	Player();
	Player(Hand h);

private:
	Hand hand;
};
