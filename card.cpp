
/*****************************************
** File:    card.cpp
** Project: CMSC 202 Project 2, Fall 2016
** Author:  Nick Stommel
** Date:    03/10/16
** Section: Lab 07 Lecture 06
** E-mail:  stommel1@umbc.edu 
**
** CMSC 202 Computer Science II
** Spring 2016 Project 2
**   
** Implementation of Card member functions.
** See card.h for documentation.
**
***********************************************/

#include <iostream>
#include <sstream>
#include "card.h"

using namespace std ;


// Default constructor marks card as invalid
//
Card::Card()
  :	m_suit(Invalid), m_points(0)
{/* Empty Constructor Body */}


Card::Card(cSuit s, cPoints p) {

	if (s == Invalid || p < 2 || p > 14) {
		m_suit = Invalid;
		m_points = 0;  
	} else {
		m_suit = s;
		m_points = p;
	}
  
}


Card::cPoints Card::points() {
	
	return m_points;
}

Card::cSuit Card::suit() {
	
	return m_suit;
}


void Card::print() {

	stringstream ss;
	
	switch(m_points) {
		case 11:
			ss << "Jack";
			break;
		case 12:
			ss << "Queen";
			break;
		case 13:
			ss << "King";
			break;
		case 14:
			ss << "Ace";
			break;
		default:
			ss << m_points;
		
	}
	ss << " of ";
	
	switch(m_suit) {
		case Clubs:
			ss << "Clubs";
			break;
		case Diamonds:
			ss << "Diamonds";
			break;
		case Hearts:
			ss << "Hearts";
			break;
		case Spades:
			ss << "Spades";
			break;
		default:
			ss << "Invalid";
		
	}
	//Fetch contents of stringstream using str() function
	cout << ss.str() << endl;

}