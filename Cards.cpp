#include <iostream>
#include "apvector.h"
#include "apstring.h"
#include "apstring.cpp"
//#include "Cards.h"
using namespace std;


// Downey Chapter 11: Member functions
struct Card
{
    // instance variables
    int rank, suit;

    Card ();
    Card (int s, int r);
    void print () const;
    bool isGreater (const Card& c2) const;
    apvector<Card> buildDeck ();
    //int find (const Card& card, const apvector<Card>& deck);
};

// constructor
Card::Card ()
{
    suit = 0; rank = 0;
}

// constructor
Card::Card (int s, int r)
{
    suit = s; rank = r;
}

// function: test whether Card A equals Card B
bool equals (const Card& c1, const Card& c2)
{
    return (c1.rank == c2.rank && c1.suit == c2.suit);
}

// function: test whether A is greater than B
bool Card::isGreater (const Card& c2) const
{
    // turn Aces into rank 14
    int rank1 = rank;
    int rank2 = c2.rank;
    if (rank == 1) {
        rank1 = 14;
    }
    if (c2.rank == 1) {
        rank2 = 14;
    }

    // first check the suits
    if (suit > c2.suit) return true;
    if (suit < c2.suit) return false;

    // if the suits are equal, check the ranks
    if (rank1 > rank2) return true;
    if (rank1 < rank2) return false;

    // if the ranks are also equal, return false
    return false;
}

// function: Build a deck of cards
apvector<Card> buildDeck ()
{
    apvector<Card> deck (52);
    int i = 0;
    for (int suit = 0; suit <= 3; suit++) {
        for (int rank = 1; rank <= 13; rank++) {
            deck[i].suit = suit;
            deck[i].rank = rank;
            i++;
        }
    }
    return deck;
}

void printDeck (const apvector<Card>& deck) {
    for (int i = 0; i < deck.length(); i++) {
        deck[i].print ();
    }
}

// function: search for a Card in a deck
int find (const Card& card, const apvector<Card>& deck) {
    for (int i = 0; i < deck.length(); i++) {
        if (equals (deck[i], card)) return i;
    }
    return -1;
}

// function: perform a bisection search
int findBisect (const Card& card, const apvector<Card>& deck, 
        int low, int high) {

    cout << low << ", " << high << endl;

    if (high < low) return -1;

    int mid = (low + high) / 2;

    // if we found the card, return its index
    if (equals (deck[mid], card)) return mid;

    // otherwise, compare the card to the middle card
    if (deck[mid].isGreater (card)) {
        // search the first half of the deck
        return findBisect (card, deck, low, mid-1);
    } else {
        return findBisect (card, deck, mid+1, high);
    }
}

// function: print suit and rank of a given Card
void Card::print () const
{
    apvector<apstring> suits (4);
    suits[0] = "Clubs";
    suits[1] = "Diamonds";
    suits[2] = "Hearts";
    suits[3] = "Spades";

    apvector<apstring> ranks (14);
    ranks[1] = "Ace";
    ranks[2] = "2";
    ranks[3] = "3";
    ranks[4] = "4";
    ranks[5] = "5";
    ranks[6] = "6";
    ranks[7] = "7";
    ranks[8] = "8";
    ranks[9] = "9";
    ranks[10] = "10";
    ranks[11] = "Jack";
    ranks[12] = "Queen";
    ranks[13] = "King";

    cout << ranks[rank] << " of " << suits[suit] << endl;
}

int main ()
{
    Card card (1, 11);
    card.print ();

    Card card1 (2, 1);
    Card card2 (2, 13);
    if (equals (card1, card2)) {
        cout << "Yup, that's the same card." << endl;
    }
    if (card1.isGreater (card2)) {
        card1.print ();
        cout << "is greater than" << endl;
        card2.print ();
    }

    apvector<Card> mydeck = buildDeck();
    // printDeck (mydeck);
    int index = find (mydeck[17], mydeck);
    cout << "I found the card at index = " << index << endl;

    cout << findBisect (mydeck[23], mydeck, 0, 51);
    return 0;
}
