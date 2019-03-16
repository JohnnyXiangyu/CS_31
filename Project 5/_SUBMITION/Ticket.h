#ifndef TICKET_H
#define TICKET_H 1
#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;

class Ticket {
public:
	enum KIND { ATHLETICGAME, CONCERT, MOVIE, OTHER };
	
	Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime);
	
	string getRow();
	int getSeat();
	string getEvent();
	string getVenue();
	double getPrice();
	void setPrice(double price);
	KIND getKind();
	string getDayTime();

private:
	string mRow;
	int mSeat;
	string mEvent;
	string mVenue;
	double mPrice;
	KIND mKind;
	string mDayTime;
};
#endif