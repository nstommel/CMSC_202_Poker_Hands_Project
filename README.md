# CMSC_202_Poker_Hands_Project
This project implements two classes: Card and Pokerhand, and includes hand rank and comparison functions.
Enumerated types are used for suit, card value, and poker hand type.

Bubble sorting is used to sort cards based on their point value.

Poker hand types including one pair, two pair, flush, royal flush, straight, straight flush, full house, four of a kind, three of a kind, and high card are found and hand scores can be directly compared against one another.
This project implements the backbone of a full poker game.

The play5.cpp test file illustrates a simple case of comparing a five card hand with another five card hand.

The play7.cpp test file uses the Card and PokerHand classes to pick the best five cards to keep at the end of game of Seven Card Stud.

The mytest.cpp file is used to test ranked hand creation and verify that comparison works properly.

# Assignment Prompt

For this project, you will implement member functions of two C++ classes that can be used to play the game of poker. In object-oriented design, the classes should model things in the problem domain. In this situation, the two classes that you will work with are Card (which models a single playing card) and PokerHand (which models a five-card poker hand).

Card is the simpler class. It has just two data members. One stores the suit of the playing card and another stores the point value. Besides the constructors, the Card class only has accessors and a member function to print the card to standard output.

The PokerHand class is more complicated. First, it has an array of five Card objects. There is a member function to print a PokerHand and a member function to get the rank of a PokerHand. There is also a member function that compares two PokerHand objects and figures out which one is better according to the rules of poker. (If you are not familiar with poker, please see the list of poker hands.) There are several more member functions of PokerHand that you will have to implement. (See below.)

C++ class definitions include data members and member functions. They can also include type definitions and constants. For example, in the definition of the Card class, we have:
   typedef enum {Invalid, Clubs, Diamonds, Hearts, Spades} cSuit ; 

This defines a new type called cSuit. Variables of type cSuit can be assigned a constant value like Clubs. (Please see the section on enumeration types in your textbook.) For example, the data member in Card that holds the suit of a card is declared as:
   cSuit m_suit ; 

Note that within the class definition or within the body of a member function, you may use cSuit, Invalid, Clubs, Diamonds, ... without any qualification. Outside the class definition and the body of a member function, you must use Card::cSuit, Card::Clubs... For example, even in the implementation of the Card class, the return value of accessor function for m_suit, must be declared as:
   Card::cSuit Card::suit() { 
      ...
   }

Similarly, there is a type definition for the point value of a card. These are stored as an unsigned int.
   typedef unsigned int cPoints ;
The purpose of having such a type definition is that if we were to make a change from unsigned int to unsigned char, we would not have to scan through hundreds of lines of code to determine which unsigned int refers to the points of a playing card and should be changed to unsigned char and which unsigned int are unsigned integers for another reason. Defining the cPoints type also helps the readability of your program. The purpose of a variable with type cPoints is much clearer than if the variable were defined as an int.

In the PokerHand class, we also have a type definition for an enumeration type:
   typedef enum { NoRank, HighCard, OnePair, TwoPair, ThreeOfAKind,
      Straight, Flush, FullHouse, FourOfAKind, StraightFlush,
      RoyalFlush } pRank ;

Again, within the PokerHand class definition and within the body of PokerHand member functions, variables that store the rank of a poker hand should be declared using pRank. Outside, PokerHand::pRank should be used. Note that pRank variables hold int values and may be compared. For example,
   PokerHand::FullHouse < PokerHand::RoyalFlush
evaluates to true. You may rely on the enumeration and assume that better poker hands have ranks with bigger int values.

In the PokerHand class, we also have the constant:
   static const int FIVE = 5 ;
This is a bit pedantic, but it allows us to avoid the use of magic numbers. If we see PokerHand::FIVE anywhere in our code, we know that the 5 is there because there are five cards in a poker hand and not for some other reason. 
