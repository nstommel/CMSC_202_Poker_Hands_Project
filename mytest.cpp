
/*****************************************
** File:    mytest.cpp
** Project: CMSC 202 Project 2, Fall 2016
** Author:  Nick Stommel
** Date:    03/10/16
** Section: Lab 07 Lecture 06
** E-mail:  stommel1@umbc.edu 
**
** CMSC 202 Computer Science II
** Spring 2016 Project 2
**   
** Tests compare function and whether card ranks are identified correctly
**
***********************************************/

#include <iostream>
#include <string>
#include "pokerhand.h"

using namespace std;

//Constant c-string created for printing divider in output
const char* DIVIDER = "\n====================================================\n";

//Underline function used for printing output headers nicely following DRY principle
//
void underline(const char *word);

//Helper function for printing the sign of the point value after a comparison
//
const char* pointState(int points);

//Test combination function used to test compare function, whether larger hands appropriately trump
//smaller hands, etc.
//
void testCombination(PokerHand smallerHand, PokerHand largerHand, string smallerHandName, string largerHandName);


int main() {
	
	Card aceOfSpades(Card::Spades, 14);
	Card twoOfHearts(Card::Hearts, 2);
	Card fourOfDiamonds(Card::Diamonds, 4);
	Card jackOfHearts(Card::Hearts, 11);
	Card queenOfClubs(Card::Clubs, 12);
	//Testing printing of cards
	aceOfSpades.print();
	twoOfHearts.print();
	fourOfDiamonds.print();
	jackOfHearts.print();
	queenOfClubs.print();
	//Testing member functions of cards
	cout << queenOfClubs.suit() << endl << queenOfClubs.points() << endl;
	
	//Create and print invalid card using default constructor
	Card invalidCard;
	invalidCard.print();
	//Create and print invalid cards using non-default constructor
	Card invalidCard2(Card::Hearts, 32);
	invalidCard2.print();
	Card invalidCard3(Card::Invalid, 4);
	invalidCard3.print();
	Card invalidCard4(Card::Diamonds, 1);
	invalidCard4.print();
	cout << endl;
	
	//Create test poker hand with default constructor
	PokerHand invalidHand;
	invalidHand.printCards();
	cout << endl;
	
	PokerHand invalidHandSame;
	
	//Create test poker hand with non-default constructor
	PokerHand testHand(aceOfSpades, twoOfHearts, fourOfDiamonds, jackOfHearts, queenOfClubs);
	testHand.printCards();
	
	cout << DIVIDER << endl;
	
	
	
	
	
	
	//Some brief directions for interpreting the underlined portions of the output
	underline("KEY");
	cout << "(S) = Sequence" << endl;
	cout << "(A) = All One Suit" << endl;
	cout << "(10) means that lowest card in hand is 10" << endl;
	cout << "(!~) means that the property ~ is not true" << endl;
	
	cout << DIVIDER << endl;
	
	
	
	
	
	//Create Royal Flush
	Card royalFlush0(Card::Diamonds, 10);
	Card royalFlush1(Card::Diamonds, 11);
	Card royalFlush2(Card::Diamonds, 12);
	Card royalFlush3(Card::Diamonds, 13);
	Card royalFlush4(Card::Diamonds, 14);
	
	//Create test poker hand that is a royal flush
	underline("Royal Flush 1-1-1-1-1 (S) (A) (10)");
	PokerHand royalFlush(royalFlush2, royalFlush0, royalFlush1, royalFlush4, royalFlush3);
	royalFlush.printCards();
	royalFlush.printRank();
	cout << endl;
	
	cout << DIVIDER << endl;
	
	
	
	
	
	//Create Straight Flush
	Card straightFlush0(Card::Clubs, 4);
	Card straightFlush1(Card::Clubs, 5);
	Card straightFlush2(Card::Clubs, 6);
	Card straightFlush3(Card::Clubs, 7);
	Card straightFlush4(Card::Clubs, 8);
	
	underline("StraightFlush 1-1-1-1-1 (S) (A) (!10)");
	PokerHand straightFlush(straightFlush0, straightFlush1, straightFlush2, straightFlush3, straightFlush4);
	straightFlush.printCards();
	straightFlush.printRank();
	cout << endl;
	
	cout << DIVIDER << endl;

	
	


	
	//Create four of a kind
	Card fourOfAKind0(Card::Clubs, 4);
	Card fourOfAKind1(Card::Spades, 4);
	Card fourOfAKind2(Card::Diamonds, 4);
	Card fourOfAKind3(Card::Hearts, 4);
	//High card (4-1)
	Card fourOfAKind4(Card::Spades, 7);
	//Low card (1-4)
	Card fourOfAKind5(Card::Spades, 3);
	
	underline("Four of A Kind 4-1");
	PokerHand fourOfAKind4_1(fourOfAKind0, fourOfAKind1, fourOfAKind2, fourOfAKind3, fourOfAKind4);
	fourOfAKind4_1.printCards();
	fourOfAKind4_1.printRank();
	cout << endl;
	
	underline("Four Of A Kind 1-4");
	PokerHand fourOfAKind1_4(fourOfAKind5, fourOfAKind0, fourOfAKind1, fourOfAKind2, fourOfAKind3);
	fourOfAKind1_4.printCards();
	fourOfAKind1_4.printRank();
	cout << endl;
		
	cout << DIVIDER << endl;


	

	
	//Create full house
	//Create three of a kind
	Card fullHouse0(Card::Clubs, 7);
	Card fullHouse1(Card::Hearts, 7);
	Card fullHouse2(Card::Diamonds, 7);
	//Create lower pair
	Card fullHouse3(Card::Spades, 4);
	Card fullHouse4(Card::Clubs, 4);
	//Create higher pair
	Card fullHouse5(Card::Diamonds, 9);
	Card fullHouse6(Card::Hearts, 9);
	
	underline("Full House 3-2");
	PokerHand fullHouse3_2(fullHouse0, fullHouse1, fullHouse2, fullHouse5, fullHouse6);
	fullHouse3_2.printCards();
	fullHouse3_2.printRank();
	cout << endl;
	
	underline("Full House 2-3");
	PokerHand fullHouse2_3(fullHouse3, fullHouse4, fullHouse0, fullHouse1, fullHouse2);
	fullHouse2_3.printCards();
	fullHouse2_3.printRank();
	cout << endl;
	
	
	//Create lower pair
	Card fullHouse7(Card::Spades, 3);
	Card fullHouse8(Card::Hearts, 3);
	//2-3
	//Hand  |3|3|7|7|7|
	//Card# |7|8|0|1|2|
	PokerHand fullHouse78012(fullHouse7, fullHouse8, fullHouse0, fullHouse1, fullHouse2);	
	
	//2-3
	//Hand  |4|4|7|7|7|
	//Card# |3|4|0|1|2|
	PokerHand fullHouse34012(fullHouse3, fullHouse4, fullHouse0, fullHouse1, fullHouse2);
	
	testCombination(fullHouse78012, fullHouse34012, "fullHouse78012", "fullHouse34012");
	
	
	cout << DIVIDER << endl;
	
	
	
	
	
	//Create Flush
	Card flush0(Card::Spades, 3);
	Card flush1(Card::Spades, 7);
	Card flush2(Card::Spades, 9);
	Card flush3(Card::Spades, 11);
	Card flush4(Card::Spades, 13);
	
	underline("Flush 1-1-1-1-1 (!S) (A)");
	PokerHand flush(flush0, flush1, flush2, flush3, flush4);
	flush.printCards();
	flush.printRank();
	cout << endl;
	
	cout << DIVIDER << endl;
	
	
	
	
	
	//Create Straight
	Card straight0(Card::Hearts, 8);
	Card straight1(Card::Spades, 9);
	Card straight2(Card::Clubs, 10);
	Card straight3(Card::Diamonds, 11);
	Card straight4(Card::Spades, 12);
	
	underline("Straight 1-1-1-1-1 (S) (!A)");
	PokerHand straight(straight0, straight1, straight2, straight3, straight4);
	straight.printCards();
	straight.printRank();
	cout << endl;
	
	cout << DIVIDER << endl;
	
	
	
	
	
	//Create three of a kind
	Card threeOfAKind0(Card::Hearts, 5);
	Card threeOfAKind1(Card::Diamonds, 5);
	Card threeOfAKind2(Card::Clubs, 5);
	//Create two higher cards
	Card threeOfAKind3(Card::Spades, 7);
	Card threeOfAKind4(Card::Diamonds, 8);
	//Create two lower cards
	Card threeOfAKind5(Card::Hearts, 4);
	Card threeOfAKind6(Card::Clubs, 3);
	
	underline("Three Of A Kind 3-1-1");
	PokerHand threeOfAKind3_1_1(threeOfAKind0, threeOfAKind1, threeOfAKind2, threeOfAKind3, threeOfAKind4);
	threeOfAKind3_1_1.printCards();
	threeOfAKind3_1_1.printRank();
	cout << endl;
	
	underline("Three Of A Kind 1-3-1");
	PokerHand threeOfAKind1_3_1(threeOfAKind5, threeOfAKind0, threeOfAKind1, threeOfAKind2, threeOfAKind6);
	threeOfAKind1_3_1.printCards();
	threeOfAKind1_3_1.printRank();
	cout << endl;
	
	underline("Three Of A Kind 1-1-3");
	PokerHand threeOfAKind1_1_3(threeOfAKind5, threeOfAKind6, threeOfAKind0, threeOfAKind1, threeOfAKind2);
	threeOfAKind1_1_3.printCards();
	threeOfAKind1_1_3.printRank();
	cout << endl;
	
	
	//1-3-1
	//Hand  |3|5|5|5|7|
	//Card# |6|0|1|2|3|
	PokerHand threeOfAKind60123(threeOfAKind6, threeOfAKind0, threeOfAKind1, threeOfAKind2, threeOfAKind3);
	
	//1-3-1
	//Hand  |4|5|5|5|7|
	//Card# |5|0|1|2|3|
	PokerHand threeOfAKind50123(threeOfAKind5, threeOfAKind0, threeOfAKind1, threeOfAKind2, threeOfAKind3);
	
	testCombination(threeOfAKind60123, threeOfAKind50123, "threeOfAKind60123", "threeOfAKind50123");
	
	
	cout << DIVIDER << endl;
	
	
	
	
	
	//Create two pair cards
	//Create lower pair
	Card twoPair0(Card::Spades, 3);
	Card twoPair1(Card::Hearts, 3);
	//Create higher pair
	Card twoPair2(Card::Diamonds, 5);
	Card twoPair3(Card::Clubs, 5);
	//Create higher card
	Card twoPair4(Card::Spades, 6);
	//Create middle card
	Card twoPair5(Card::Clubs, 4);
	//Create lower card
	Card twoPair6(Card::Clubs, 2);
	
	underline("Two Pair 2-2-1");
	PokerHand twoPair2_2_1(twoPair0, twoPair1, twoPair2, twoPair3, twoPair4);
	twoPair2_2_1.printCards();
	twoPair2_2_1.printRank();
	cout << endl;
	
	underline("Two Pair 2-1-2");
	PokerHand twoPair2_1_2(twoPair0, twoPair1, twoPair5, twoPair2, twoPair3);
	twoPair2_1_2.printCards();
	twoPair2_1_2.printRank();
	cout << endl;
	
	underline("Two Pair 1-2-2");
	PokerHand twoPair1_2_2(twoPair6, twoPair0, twoPair1, twoPair2, twoPair3);
	twoPair1_2_2.printCards();
	twoPair1_2_2.printRank();
	cout << endl;
	
	//Create Higher Pair
	Card twoPair7(Card::Clubs, 8);
	Card twoPair8(Card::Hearts, 8);
	//2-1-2
	//Hand  |3|3|5|8|8|
	//Card# |0|1|3|7|8|
	PokerHand twoPair01378(twoPair0, twoPair1, twoPair3, twoPair7, twoPair8);
	
	//2-1-2
	//Hand  |3|3|6|8|8|
	//Card# |0|1|4|7|8|
	PokerHand twoPair01478(twoPair0, twoPair1, twoPair4, twoPair7, twoPair8);
	
	testCombination(twoPair01378, twoPair01478, "twoPair01378", "twoPair01478");
	
	cout << DIVIDER << endl;
	
	
	
	
	
	//Create one pair cards
	//Create pair
	Card onePair0(Card::Hearts, 7);
	Card onePair1(Card::Spades, 7);
	//Create three lower cards
	Card onePair2(Card::Clubs, 6);
	Card onePair3(Card::Diamonds, 5);
	Card onePair4(Card::Spades, 4);
	//Create three higher cards
	Card onePair5(Card::Spades, 8);
	Card onePair6(Card::Clubs, 9);
	Card onePair7(Card::Hearts, 10);
	
	underline("One Pair 2-1-1-1");
	PokerHand onePair2_1_1_1(onePair0, onePair1, onePair5, onePair6, onePair7);
	onePair2_1_1_1.printCards();
	onePair2_1_1_1.printRank();
	cout << endl;
	
	underline("One Pair 1-2-1-1");
	PokerHand onePair1_2_1_1(onePair2, onePair0, onePair1, onePair5, onePair6);
	onePair1_2_1_1.printCards();
	onePair1_2_1_1.printRank();
	cout << endl;
	
	underline("One Pair 1-1-2-1");
	PokerHand onePair1_1_2_1(onePair2, onePair3, onePair0, onePair1, onePair5);
	onePair1_1_2_1.printCards();
	onePair1_1_2_1.printRank();
	cout << endl;
	
	underline("One Pair 1-1-1-2");
	PokerHand onePair1_1_1_2(onePair2, onePair3, onePair4, onePair0, onePair1);
	onePair1_1_1_2.printCards();
	onePair1_1_1_2.printRank();
	cout << endl;
	
	//1-2-1-1
	//Hand  |4|5|7|7|8|
	//Card# |4|3|0|1|5|
	PokerHand onePair43015(onePair4, onePair3, onePair0, onePair1, onePair5);
	
	//1-2-1-1
	//Hand  |4|5|7|7|9|
	//Card# |4|3|0|1|6|
	PokerHand onePair43016(onePair4, onePair3, onePair0, onePair1, onePair6);
	
	testCombination(onePair43015, onePair43016, "onePair43015", "onePair43016");
	
	//1-2-1-1
	//Hand  |4|6|7|7|8|
	//Card# |4|2|0|1|5|
	PokerHand onePair42015(onePair4, onePair2, onePair0, onePair1, onePair5);
	
	testCombination(onePair43015, onePair42015, "onePair43015", "onePair42015");
	
	//1-2-1-1
	//Hand  |5|6|7|7|8|
	//Card# |3|2|0|1|5|
	PokerHand onePair32015(onePair3, onePair2, onePair0, onePair1, onePair5);
	
	testCombination(onePair42015, onePair32015, "onePair42015", "onePair32015");
	
	cout << DIVIDER << endl;
	
	
	
	
	
	//Create high card cards
	Card highCard0(Card::Diamonds, 6);
	Card highCard1(Card::Hearts,   7);
	Card highCard2(Card::Spades,   8);
	Card highCard3(Card::Clubs,    9);
	Card highCard4(Card::Hearts,   10);
	Card highCard5(Card::Spades,   11);
	Card highCard6(Card::Spades,   12);
	
	underline("High Card 1-1-1-1-1 (!S) (!A)"); 
	
	//(Possible High-Card) Hand
	PokerHand highCard(highCard0, highCard2, highCard4, highCard5, highCard6);
	
	highCard.printCards();
	highCard.printRank();
	cout << endl;
	
	
	//Hand  |6|7|8|9|12|
	//Card# |0|1|2|3|6 |
	//Card4 Same, Card3 Smaller
	PokerHand highCard01236(highCard0, highCard1, highCard2, highCard3, highCard6);
	//Hand  |7|8|9|10|12|
	//Card# |1|2|3|4 |6 |
	//Card4 Same, Card3 Larger
	PokerHand highCard12346(highCard1, highCard2, highCard3, highCard4, highCard6);
	
	testCombination(highCard01236, highCard12346, "highCard01236", "highCard12346");
	
	//Hand  |6|7|8|11|12|
	//Card# |0|1|2|5 |6 |
	//Card4 & Card3 Same, Card2 Smaller
	PokerHand highCard01256(highCard0, highCard1, highCard2, highCard5, highCard6);
	//Hand  |7|8|9|11|12|
	//Card# |1|2|3|5 |6 |
	//Card4 & Card3 Same, Card2 Larger
	PokerHand highCard12356(highCard1, highCard2, highCard3, highCard5,highCard6);
	
	testCombination(highCard01256, highCard12356, "highCard01256", "highCard12356");
	
	//Hand  |6|9|10|11|12|
	//Card# |0|3|4 |5 |6 |
	//Card4 & Card3 & Card2 & Card1 Same, Card0 Smaller
	PokerHand highCard03456(highCard0, highCard3, highCard4, highCard5, highCard6);
	
	//Hand  |7|9|10|11|12|
	//Card# |1|3|4 |5 |6 |
	//Card4 & Card3 & Card2 & Card1 Same, Card0 Larger
	PokerHand highCard13456(highCard1, highCard3, highCard4, highCard5, highCard6);
	
	testCombination(highCard03456, highCard13456, "highCard03456", "highCard13456");
	
	cout << DIVIDER << endl;
	
	
	
	return 0;
}

void underline(const char *word) {
	
	cout << word << endl;
	for(int i = 0; word[i] != '\0'; ++i) {
		cout << '-';
	}
	cout << endl;
}

const char* pointState(int points) {
	if(points > 0) {
		return "Positive";
	} else if (points < 0) {
		return "Negative";
	} else {
		return "Zero";
	}
}

void testCombination(PokerHand smallerHand, PokerHand largerHand, string smallerHandName, string largerHandName) {
	//Should be Positive
	cout << largerHandName << ".cmp(" << smallerHandName << ") = " << largerHand.cmp(smallerHand) << ' ' << pointState(largerHand.cmp(smallerHand));
	if(largerHand.cmp(smallerHand) > 0) {
		// Print Check mark
		cout << " \u2713" << endl;
	} else {
		//Print X-mark
		cout << " \u2717" << endl;
	}
	//Should be Negative
	cout << smallerHandName << ".cmp(" << largerHandName << ") = " << smallerHand.cmp(largerHand) << ' ' << pointState(smallerHand.cmp(largerHand));
	if(smallerHand.cmp(largerHand) < 0) {
		cout << " \u2713" << endl;
	} else {
		cout << " \u2717" << endl;
	}
	//Should be Zero
	cout << smallerHandName << ".cmp(" << smallerHandName << ") = " << pointState(smallerHand.cmp(smallerHand));
	if(smallerHand.cmp(smallerHand) == 0) {
		cout << " \u2713" << endl;
	} else {
		cout << " \u2717" << endl;
	}
	//Should be Zero
	cout << largerHandName << ".cmp(" << largerHandName << ") = " << pointState(largerHand.cmp(largerHand));
	if(largerHand.cmp(largerHand) == 0) {
		cout << " \u2713" << endl;
	} else {
		cout << " \u2717" << endl;
	}
	
	cout << endl;
}