#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include"BoxOffice.h"
#include"Project5Helper.h"

using namespace std;

BoxOffice::BoxOffice() {

}

Ticket BoxOffice::buyTicket(string row, int seat, string event, string venue, Ticket::KIND kind, string daytime) {
	double price = 0;

	Ticket new_ticket(row, seat, event, venue, price, kind, daytime);
	return new_ticket;
}

Ticket BoxOffice::buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime) {
	//a student ticket, price according to the chart
	string venue = "Royce Hall";
	double raw_price = 0;
	raw_price = findRawPrice(row, kind, daytime);

	//calculating the final price
	double price = 0;
	if (raw_price >= 40) {
		price = raw_price - 30;
	}
	else {
		price = raw_price * 0.8;
	}

	//making the ticket
	Ticket this_ticket(row, seat, event, venue, price, kind, daytime);
	return this_ticket;
}

Ticket BoxOffice::buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime) {
	string venue = "Royce Hall";
	double raw_price = 0;
	raw_price = findRawPrice(row, kind, daytime);

	double price = 0;
	if (raw_price >= 40) {
		price = raw_price - 20;
	}
	else {
		price = raw_price * 0.9;
	}

	Ticket this_ticket(row, seat, event, venue, price, kind, daytime);
	return this_ticket;
}

Ticket BoxOffice::buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND kind, string daytime) {
	string venue = "Royce Hall";
	double raw_price = 0;
	raw_price = findRawPrice(row, kind, daytime);

	Ticket this_ticket(row, seat, event, venue, raw_price, kind, daytime);
	return this_ticket;
}


double BoxOffice::findRawPrice(string row, Ticket::KIND kind, string daytime) {
	double price = 0;

	//has it anything to do with PM and Orchestra?
	Project5Helper helper;
	bool is_PM = helper.endsWithPM(daytime);
	bool is_Orchestra = helper.startsWithOrchestra(row);

	switch (kind) {
	case Ticket::ATHLETICGAME:
		price = 75;
		break;
	case Ticket::CONCERT:
		if (is_PM) { 
			price = 65; 
		}
		else { 
			price = 50; 
		}
		break;
	case Ticket::MOVIE:
		price = 12.5;
		break;
	case Ticket::OTHER:
		if (is_PM) {
			price = 55;
		}
		else {
			price = 40;
		}
		break;
	}

	//apply the Orchestra special pricing
	if (is_Orchestra) {
		price = price * 2;
	}

	return price;
}