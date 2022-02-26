
/*****************************************
** File:    pokerhand.cpp
** Project: CMSC 202 Project 2, Fall 2016
** Author:  Nick Stommel
** Date:    03/10/16
** Section: Lab 07 Lecture 06
** E-mail:  stommel1@umbc.edu 
**
** CMSC 202 Computer Science II
** Spring 2016 Project 2
**   
** Implementation of PokerHand class.
** See pokerhand.h for documentation.
**
***********************************************/


#include <iostream>
#include <sstream>
using namespace std ;

#include "pokerhand.h"

PokerHand::PokerHand ()
	//Initializer list used for maximum efficiency
  :	m_valid(false), m_rank(NoRank), m_lastCardPoints(0), m_firstPairPoints(0), 
	m_secondPairPoints(0), m_tripletPoints(0), m_quadrupletPoints(0)
{/* Empty Constructor Body */}



PokerHand::PokerHand (Card c0, Card c1, Card c2, Card c3, Card c4)
	// Store Cards, (valid and concise extended initializer list in C++11 below)
  :	// m_cards{c0, c1, c2, c3, c4},
	//
	//Initializer list used for maximum efficiency 
	//
	// We have cards.
	// Note: this assumes c0, ..., c4 are valid
	m_valid(true), m_rank(NoRank),
	// Default values for "additional information"
	m_lastCardPoints(0), m_firstPairPoints(0), m_secondPairPoints(0), 
	m_tripletPoints(0), m_quadrupletPoints(0)

{
	//Store Cards (Because there are no extended initializer lists prior to C++11, 
	// the array must be filled in the unsightly way below)
	m_cards[0] = c0;
	m_cards[1] = c1;
	m_cards[2] = c2;
	m_cards[3] = c3;
	m_cards[4] = c4;
	
	// Don't forget to sort
	//
	sort() ;

	// IF YOU WANT THE ALTERNATE CONSTRUCTOR
	// TO DO MORE, PLACE THE CODE AFTER THIS
	// LINE:
	// --------------------------------------
	
	//Initialize m_rank during hand construction by calling getRank() in constructor
	getRank();
	
}

void PokerHand::sort() {
	
	//Bubble Sort cards based on point value
	for (int li = 0; li < FIVE - 1; ++li) {
		
		for (int ri = li + 1; ri < FIVE; ++ri) {
			
			if (m_cards[li].points() > m_cards[ri].points()) {
				
				Card temp = m_cards[li];
				m_cards[li] = m_cards[ri];
				m_cards[ri] = temp;
			}
		}
	}
}

void PokerHand::printCards() {
	
	for(int i = 0; i < FIVE; ++i) {
		
		m_cards[i].print();
	}
}

PokerHand::pRank PokerHand::getRank() {
	
	//If rank has already been obtained, don't recheck hand for rank!
	if(m_rank == NoRank && m_valid) {
		//Check whether hand has rank by calling functions in ascending order of
		//rarity of hand so that less expensive operations are performed on common hands.
		if(isHighCard()) {
			return m_rank;
		} else if(isOnePair()) {
			return m_rank;
		} else if(isTwoPair()) {
			return m_rank;
		} else if(isThreeOfAKind()) {
			return m_rank;
		} else if(isStraight()) {
			return m_rank;
		} else if(isFlush()) {
			return m_rank;
		} else if(isFullHouse()) {
			return m_rank;
		} else if(isFourOfAKind()) {
			return m_rank;
		} else if(isStraightFlush()) {
			return m_rank;
		} else if(isRoyalFlush()) {
			return m_rank;
		//Final case necessary just in case the hand isn't valid
		} else {
			return m_rank;
		}
		
	//If rank has already been calculated, return m_rank
	} else {
		return m_rank;
	}
}

void PokerHand::printRank() {
	
	stringstream ss;
	
	switch(m_rank) {
		
		case HighCard:
			ss << "High Card";
			break;
		case OnePair:
			ss << "One Pair";
			break;
		case TwoPair:
			ss << "Two Pair";
			break;
		case ThreeOfAKind:
			ss << "Three of a Kind";
			break;
		case Straight:
			ss << "Straight";
			break;
		case Flush:
			ss << "Flush";
			break;
		case FullHouse:
			ss << "Full House";
			break;
		case FourOfAKind:
			ss << "Four of a Kind";
			break;
		case StraightFlush:
			ss << "Straight Flush";
			break;
		case RoyalFlush:
			ss << "Royal Flush";
			break;
		default:
			ss << "NoRank";
	}
	
	cout << ss.str() << endl;
}

int PokerHand::cmp(PokerHand &otherHand) {
	
	//If the ranks are different, return the difference in rank
	if(m_rank != otherHand.m_rank) {
		
		return m_rank - otherHand.m_rank;
	
	//Otherwise, if the ranks are the same, test the following:
	} else {
		
		//Arranged in ascending order of rarity for maximum efficiency (that is, less 
		//rare hands are checked for first)
		
		if(isHighCard() || isFlush()) {	
		
			for(int handIndex = FIVE - 1; handIndex > -1; --handIndex) {
				
				if(m_cards[handIndex].points() != otherHand.m_cards[handIndex].points()) {
					
					return m_cards[handIndex].points() - otherHand.m_cards[handIndex].points();
				}
			}
			return 0;
			
		} else if(isOnePair()) {
			
			if(m_firstPairPoints != otherHand.m_firstPairPoints) {
				
				return m_firstPairPoints - otherHand.m_firstPairPoints;
				
			} else {
				
				for(int handIndex = FIVE - 1; handIndex > -1; --handIndex) {
					
					if(m_cards[handIndex].points() != otherHand.m_cards[handIndex].points()
						&& (m_cards[handIndex].points() != m_firstPairPoints)) {
							
						return m_cards[handIndex].points() - otherHand.m_cards[handIndex].points();
					}
				}
				return 0;
			}

		} else if(isTwoPair()) {
			
			if(m_secondPairPoints != otherHand.m_secondPairPoints) {
				
				return m_secondPairPoints - otherHand.m_secondPairPoints;
				
			} else {
				
				if(m_firstPairPoints != otherHand.m_firstPairPoints) {
					
					return m_firstPairPoints - otherHand.m_firstPairPoints;
					
				} else {
					
					if(m_lastCardPoints != otherHand.m_lastCardPoints) {
						
						return m_lastCardPoints - otherHand.m_lastCardPoints;
						
					} else {
						
						return 0;
					}
				}
			}
			
			
		} else if(isThreeOfAKind()) {
			
			if(m_tripletPoints != otherHand.m_tripletPoints) {
				
				return m_tripletPoints - otherHand.m_tripletPoints;
				
			} else {
				
				for(int handIndex = FIVE - 1; handIndex > -1; --handIndex) {
					
					if(m_cards[handIndex].points() != otherHand.m_cards[handIndex].points()
						&& (m_cards[handIndex].points() != m_tripletPoints)) {
							
						return m_cards[handIndex].points() - otherHand.m_cards[handIndex].points();
					}
				}
				return 0;	
			}
			
			
		} else if(isStraight() || isStraightFlush()) {
			
			if(m_cards[4].points() != otherHand.m_cards[4].points()) {
				
				return m_cards[4].points() - otherHand.m_cards[4].points();
				
			} else {
				
				return 0;
			}

			
		} else if(isFullHouse()) {
			
			if(m_tripletPoints != otherHand.m_tripletPoints) {
				
				return m_tripletPoints - otherHand.m_tripletPoints;
				
			} else {
				
				if(m_firstPairPoints != otherHand.m_firstPairPoints) {
					
					return m_firstPairPoints - otherHand.m_firstPairPoints;
					
				} else {
					
					return 0;
				}
			}
			
		} else if(isFourOfAKind()) {
			
			if(m_quadrupletPoints != otherHand.m_quadrupletPoints) {
				
				return m_quadrupletPoints - otherHand.m_quadrupletPoints;
				
			} else {
				
				if(m_lastCardPoints != otherHand.m_lastCardPoints) {
					
					return m_lastCardPoints - otherHand.m_lastCardPoints;
					
				} else {
					
					return 0;
				}
			}	
			
		} else if(isRoyalFlush()) {
			
			return 0;
			
		//Final case necessary just in case hand is invalid, or of rank NoRank.
		} else {
			return 0;
		}
	}	
}

bool PokerHand::isAllOneSuit() {
	
	Card::cSuit firstSuit = m_cards[0].suit();
	
	for(int i = 0; i < FIVE; ++i) {
		
		if(m_cards[i].suit() != firstSuit) {
			
			return false;
		}
	}
	return true;
}

bool PokerHand::isSequence() {
	
	Card::cPoints currPointVal = m_cards[0].points();
	
	for(int i = 1; i < FIVE; ++i) {
		
		if(m_cards[i].points() == currPointVal + 1) {
			
			++currPointVal;
			
		} else {
			
			return false;
		}
	}
	return true;
}

bool PokerHand::isRoyalFlush() {
	
	if(isSequence() && isAllOneSuit() && m_cards[0].points() == 10) {
		
		m_rank = RoyalFlush;
		return true;
		
	} else {
		
		return false;
	}
}

bool PokerHand::isStraightFlush() {
	
	if(isSequence() && isAllOneSuit() && m_cards[0].points() != 10) {
		
		m_rank = StraightFlush;
		return true;
		
	} else {
		
		return false;
	}
}

bool PokerHand::isFlush() {
	
	if(isAllOneSuit() && !isSequence()) {
		
		m_rank = Flush;
		return true;
		
	} else {
		
		return false;
	}
}

bool PokerHand::isStraight() {
	
	if(isSequence() && !isAllOneSuit()) {
		
		m_rank = Straight;
		return true;
		
	} else {
		
		return false;
	}
}

bool PokerHand::isFullHouse() {
	
	//Check 2-3
	if( m_cards[0].points() == m_cards[1].points() &&
		m_cards[1].points() != m_cards[2].points() &&
		m_cards[2].points() == m_cards[3].points() &&
		m_cards[3].points() == m_cards[4].points()) {
		
		m_firstPairPoints = m_cards[0].points();
		m_tripletPoints = m_cards[2].points();
		m_rank = FullHouse;
		return true;
	
	
	//Check 3-2
	} else if ( m_cards[0].points() == m_cards[1].points() &&
				m_cards[1].points() == m_cards[2].points() &&
				m_cards[2].points() != m_cards[3].points() &&
				m_cards[3].points() == m_cards[4].points()) {
		
		m_firstPairPoints = m_cards[3].points();
		m_tripletPoints = m_cards[0].points();
		m_rank = FullHouse;
		return true;
		
	} else {
		
		return false;
	}
}

bool PokerHand::isFourOfAKind() {
	
	//Check 4-1
	if( m_cards[0].points() == m_cards[1].points() && 
		m_cards[1].points() == m_cards[2].points() &&
		m_cards[2].points() == m_cards[3].points() &&
		m_cards[3].points() != m_cards[4].points()) {
		
		m_quadrupletPoints = m_cards[0].points();
		m_lastCardPoints = m_cards[4].points();
		m_rank = FourOfAKind;
		return true;
	
	//Check 1-4
	} else if ( m_cards[0].points() != m_cards[1].points() &&
				m_cards[1].points() == m_cards[2].points() &&
				m_cards[2].points() == m_cards[3].points() &&
				m_cards[3].points() == m_cards[4].points()) {
		
		m_quadrupletPoints = m_cards[1].points();
		m_lastCardPoints = m_cards[0].points();
		m_rank = FourOfAKind;
		return true;
	
	//If not four of a kind, return false
	} else {
		
		return false;
	}
}

bool PokerHand::isThreeOfAKind() {
	
	//Check 3-1-1
	if( m_cards[0].points() == m_cards[1].points() &&
		m_cards[1].points() == m_cards[2].points() &&
		m_cards[2].points() != m_cards[3].points() &&
		m_cards[3].points() != m_cards[4].points()) {
		
		m_tripletPoints = m_cards[0].points();
		m_rank = ThreeOfAKind;
		return true;
	 
	//Check 1-3-1
	} else if (	m_cards[0].points() != m_cards[1].points() &&
				m_cards[1].points() == m_cards[2].points() &&
				m_cards[2].points() == m_cards[3].points() &&
				m_cards[3].points() != m_cards[4].points()) {
		
		m_tripletPoints = m_cards[1].points();
		m_rank = ThreeOfAKind;
		return true;
	
	//Check 1-1-3
	} else if (	m_cards[0].points() != m_cards[1].points() &&
				m_cards[1].points() != m_cards[2].points() &&
				m_cards[2].points() == m_cards[3].points() &&
				m_cards[3].points() == m_cards[4].points()) {
		
		m_tripletPoints = m_cards[2].points();
		m_rank = ThreeOfAKind;
		return true;
	
	//If not three of a kind, return false
	} else {
		
		return false;
	}
}

bool PokerHand::isTwoPair() {
	
	//Check 2-2-1
	if( m_cards[0].points() == m_cards[1].points() &&
		m_cards[1].points() != m_cards[2].points() &&
		m_cards[2].points() == m_cards[3].points() &&
		m_cards[3].points() != m_cards[4].points()) {
		
		m_firstPairPoints = m_cards[0].points();
		m_secondPairPoints = m_cards[2].points();
		m_lastCardPoints = m_cards[4].points();
		m_rank = TwoPair;
		return true;

	//Check 2-1-2
	} else if (	m_cards[0].points() == m_cards[1].points() &&
				m_cards[1].points() != m_cards[2].points() &&
				m_cards[2].points() != m_cards[3].points() &&
				m_cards[3].points() == m_cards[4].points()) {
		
		m_firstPairPoints = m_cards[0].points();
		m_secondPairPoints = m_cards[3].points();
		m_lastCardPoints = m_cards[2].points();
		m_rank = TwoPair;
		return true;
	
	//Check 1-2-2
	} else if (	m_cards[0].points() != m_cards[1].points() &&
				m_cards[1].points() == m_cards[2].points() &&
				m_cards[2].points() != m_cards[3].points() &&
				m_cards[3].points() == m_cards[4].points()) {
		
		m_firstPairPoints = m_cards[1].points();
		m_secondPairPoints = m_cards[3].points();
		m_lastCardPoints = m_cards[0].points();
		m_rank = TwoPair;
		return true;
	
	//If hand is not two pair, return false
	} else {
		
		return false;
	}
}

bool PokerHand::isOnePair() {
	
	//Check 2-1-1-1
	if( m_cards[0].points() == m_cards[1].points() &&
		m_cards[1].points() != m_cards[2].points() &&
		m_cards[2].points() != m_cards[3].points() &&
		m_cards[3].points() != m_cards[4].points()) {
		
		m_firstPairPoints = m_cards[0].points();
		m_rank = OnePair;
		return true;
	
	//Check 1-2-1-1
	} else if (	m_cards[0].points() != m_cards[1].points() &&
				m_cards[1].points() == m_cards[2].points() &&
				m_cards[2].points() != m_cards[3].points() &&
				m_cards[3].points() != m_cards[4].points()) {
		
		m_firstPairPoints = m_cards[1].points();
		m_rank = OnePair;
		return true;
	
	//Check 1-1-2-1
	} else if (	m_cards[0].points() != m_cards[1].points() &&
				m_cards[1].points() != m_cards[2].points() &&
				m_cards[2].points() == m_cards[3].points() &&
				m_cards[3].points() != m_cards[4].points()) {
		
		m_firstPairPoints = m_cards[2].points();
		m_rank = OnePair;
		return true;
	
	//Check 1-1-1-2
	} else if (	m_cards[0].points() != m_cards[1].points() &&
				m_cards[1].points() != m_cards[2].points() &&
				m_cards[2].points() != m_cards[3].points() &&
				m_cards[3].points() == m_cards[4].points()) {
		
		m_firstPairPoints = m_cards[3].points();
		m_rank = OnePair;
		return true;
	
	//Otherwise, if hand is not one pair, return false
	} else {
		
		return false;
	}
}

bool PokerHand::isHighCard() {
	
	if( m_cards[0].points() != m_cards[1].points() &&
		m_cards[1].points() != m_cards[2].points() &&
		m_cards[2].points() != m_cards[3].points() &&
		m_cards[3].points() != m_cards[4].points() &&
		!isSequence() && !isAllOneSuit()) {
			
		m_rank = HighCard;
		return true;
	} else {
		
		return false;
	}
}
