#include<iostream>
#include<string>
#include<cctype>
#include<assert.h>

#include"Ticket.h"
#include"BoxOffice.h"

using namespace std;

void priceTest();
void contentTest();

int main() {
	priceTest();
	contentTest();

	return 0;
}

void priceTest() {
	const string kBAL = "Balcony Row U";
	const string kORC = "Orchestra Row Y";

	const Ticket::KIND kATH = Ticket::ATHLETICGAME;
	const Ticket::KIND kCON = Ticket::CONCERT;
	const Ticket::KIND kMOV = Ticket::MOVIE;
	const Ticket::KIND kOTH = Ticket::OTHER;


	const string kAM = "August 1, 7:30 AM";
	const string kPM = "August 1, 7:30 PM";

	BoxOffice b;

	Ticket t0 = b.buyTicket(kBAL, 45, "Dodgers vs. Brewers", "HAHAHA", kATH, kAM);
	assert(t0.getPrice() == 0);
	
	Ticket t1 = b.buyRoyceHallTicket(kBAL, 45, "Dodgers vs. Brewers", kATH, kAM);
	assert(t1.getPrice() == 75);

	Ticket t2 = b.buyRoyceHallTicket(kBAL, 45, "Dodgers vs. Brewers", kATH, kPM);
	assert(t2.getPrice() == 75);

	Ticket t3 = b.buyRoyceHallTicket(kBAL, 45, "Dodgers vs. Brewers", kCON, kAM);
	assert(t3.getPrice() == 50);

	Ticket t4 = b.buyRoyceHallTicket(kBAL, 45, "Dodgers vs. Brewers", kCON, kPM);
	assert(t4.getPrice() == 65);

	Ticket t5 = b.buyRoyceHallTicket(kBAL, 45, "Dodgers vs. Brewers", kMOV, kAM);
	assert(t5.getPrice() == 12.5);

	Ticket t6 = b.buyRoyceHallTicket(kBAL, 45, "Dodgers vs. Brewers", kMOV, kPM);
	assert(t6.getPrice() == 12.5);

	Ticket t7 = b.buyRoyceHallTicket(kBAL, 45, "Dodgers vs. Brewers", kOTH, kAM);
	assert(t7.getPrice() == 40);

	Ticket t8 = b.buyRoyceHallTicket(kBAL, 45, "Dodgers vs. Brewers", kOTH, kPM);
	assert(t8.getPrice() == 55);

	Ticket t11 = b.buyRoyceHallTicket(kORC, 45, "Dodgers vs. Brewers", kATH, kAM);
	assert(t11.getPrice() == 150);

	Ticket t12 = b.buyRoyceHallTicket(kORC, 45, "Dodgers vs. Brewers", kATH, kPM);
	assert(t12.getPrice() == 150);

	Ticket t13 = b.buyRoyceHallTicket(kORC, 45, "Dodgers vs. Brewers", kCON, kAM);
	assert(t13.getPrice() == 100);

	Ticket t14 = b.buyRoyceHallTicket(kORC, 45, "Dodgers vs. Brewers", kCON, kPM);
	assert(t14.getPrice() == 130);

	Ticket t15 = b.buyRoyceHallTicket(kORC, 45, "Dodgers vs. Brewers", kMOV, kAM);
	assert(t15.getPrice() == 25);

	Ticket t16 = b.buyRoyceHallTicket(kORC, 45, "Dodgers vs. Brewers", kMOV, kPM);
	assert(t16.getPrice() == 25);

	Ticket t17 = b.buyRoyceHallTicket(kORC, 45, "Dodgers vs. Brewers", kOTH, kAM);
	assert(t17.getPrice() == 80);

	Ticket t18 = b.buyRoyceHallTicket(kORC, 45, "Dodgers vs. Brewers", kOTH, kPM);
	assert(t18.getPrice() == 110);

	Ticket t21 = b.buyRoyceHallStudentTicket(kBAL, 45, "Dodgers vs. Brewers", kMOV, kAM);
	assert(t21.getPrice() == 12.5*0.8);

	Ticket t22 = b.buyRoyceHallStudentTicket(kORC, 45, "Dodgers vs. Brewers", kOTH, kAM);
	assert(t22.getPrice() == 80 - 30);

	Ticket t31 = b.buyRoyceHallStaffTicket(kBAL, 45, "Dodgers vs. Brewers", kMOV, kAM);
	assert(t31.getPrice() == 12.5*0.9);

	Ticket t32 = b.buyRoyceHallStaffTicket(kORC, 45, "Dodgers vs. Brewers", kOTH, kAM);
	assert(t32.getPrice() == 80 - 20);

	cerr << "alles gute fur prices" << endl;
}

void contentTest() {
	const string kBAL = "Balcony Row U";
	const string kORC = "Orchestra Row Y";

	const Ticket::KIND kATH = Ticket::ATHLETICGAME;


	const string kAM = "August 1, 7:30 AM";
	const string kPM = "August 1, 7:30 PM";

	BoxOffice b;

	Ticket t0 = b.buyTicket(kBAL, 45, "Dodgers vs. Brewers", "Drake Stadum", kATH, kAM);
	assert(t0.getPrice() == 0);
	assert(t0.getRow() == "Balcony Row U");
	assert(t0.getEvent() == "Dodgers vs. Brewers");
	assert(t0.getVenue() == "Drake Stadum");
	assert(t0.getDayTime() == "August 1, 7:30 AM");
	assert(t0.getKind() == kATH);

	Ticket t1 = b.buyRoyceHallTicket(kBAL, 45, "Dodgers vs. Brewers", kATH, kAM);
	assert(t1.getPrice() == 75);
	assert(t1.getRow() == kBAL);
	assert(t1.getSeat() == 45);
	assert(t1.getEvent() == "Dodgers vs. Brewers");
	assert(t1.getVenue() == "Royce Hall");
	assert(t1.getDayTime() == "August 1, 7:30 AM");
	assert(t1.getKind() == kATH);

	Ticket t2 = b.buyRoyceHallStudentTicket(kBAL, 45, "Dodgers vs. Brewers", kATH, kAM);
	assert(t2.getPrice() == 75 - 30);
	assert(t2.getRow() == kBAL);
	assert(t2.getSeat() == 45);
	assert(t2.getEvent() == "Dodgers vs. Brewers");
	assert(t2.getVenue() == "Royce Hall");
	assert(t2.getDayTime() == "August 1, 7:30 AM");
	assert(t2.getKind() == kATH);

	Ticket t4 = b.buyRoyceHallStaffTicket(kBAL, 45, "Dodgers vs. Brewers", kATH, kAM);
	assert(t4.getPrice() == 75 - 20);
	assert(t4.getRow() == kBAL);
	assert(t4.getSeat() == 45);
	assert(t4.getEvent() == "Dodgers vs. Brewers");
	assert(t4.getVenue() == "Royce Hall");
	assert(t4.getDayTime() == "August 1, 7:30 AM");
	assert(t4.getKind() == kATH);

	cerr << "alles gute fur contents" << endl;
}