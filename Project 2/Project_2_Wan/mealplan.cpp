//mealplan calculator

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string payment, meal, position, residence; // declaring variables for responses

	cout << "Ticket or BruinCard? "; // asking for type of payment
	getline(cin, payment);
	if (payment != "Ticket" && payment != "BruinCard")
	{
		cout << "The kind value must either be Ticket or BruinCard.";
		return -1;
	}

	cout << "Breakfast, Lunch or Dinner? "; // asking for type of meal
	getline(cin, meal);
	if (meal != "Breakfast" && meal != "Lunch" && meal != "Dinner")
	{
		cout << "The meal value must either be Breakfast, Lunch or Dinner.";
		return -1;
	}

	if (payment == "BruinCard") //
	{
		cout << "Student or Staff? "; // asking for position
		getline(cin, position);
		if (position != "Student" && position != "Staff")
		{
			cout << "The type value must either be Student or Staff.";
			return -1;
		}
		else if (position == "Student")
		{
			cout << "Resident? "; // asking about residence
			getline(cin, residence);
			if (residence != "Yes" and residence != "No")
			{
				cout << "The resident value must either be Yes or No.";
				return -1;
			}
			else if (residence == "Yes") // if this guy is a student living on campus, paying with BruinCard
			{
				if (meal == "Breakfast")
				{
					cout << "Thank you for eating at UCLA today.  Your meal cost is $9.75";
				}
				else if (meal == "Lunch")
				{
					cout << "Thank you for eating at UCLA today.  Your meal cost is $11.25";
				}
				else if (meal == "Dinner")
				{
					cout << "Thank you for eating at UCLA today.  Your meal cost is $12.25";
				}
			}
			else if (residence == "No") // if this student live off campus and pays with BruinCard
			{
				if (meal == "Breakfast")
				{
					cout << "Thank you for eating at UCLA today.  Your meal cost is $10.00";
				}
				else if (meal == "Lunch")
				{
					cout << "Thank you for eating at UCLA today.  Your meal cost is $11.75";
				}
				else if (meal == "Dinner")
				{
					cout << "Thank you for eating at UCLA today.  Your meal cost is $12.75";
				}
			}
		}
		else if (position == "Staff") // if this guy is a stuff paying with BruinCard
		{
			if (meal == "Breakfast")
			{
				cout << "Thank you for eating at UCLA today.  Your meal cost is $11.25";
			}
			else if (meal == "Lunch")
			{
				cout << "Thank you for eating at UCLA today.  Your meal cost is $12.75";
			}
			else if (meal == "Dinner")
			{
				cout << "Thank you for eating at UCLA today.  Your meal cost is $14.75";
			}
		}
	}
	else if (payment == "Ticket") // nobody cares who he is if he pays with ticket
	{
		if (meal == "Breakfast")
		{
			cout << "Thank you for eating at UCLA today.  Your meal cost is $12.50";
		}
		else if (meal == "Lunch")
		{
			cout << "Thank you for eating at UCLA today.  Your meal cost is $14.50";
		}
		else if (meal == "Dinner")
		{
			cout << "Thank you for eating at UCLA today.  Your meal cost is $17.00";
		}
	}

	return 0;
}
