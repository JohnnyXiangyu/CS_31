//using the simpler way to process the characters
//this page will only contain one function

#include <cctype>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int number(string s, int index);

class RowerData
{
public:
	bool validity = true;
	int minutes = 0;
	int seconds = 0;
	int strokes = 0;
	int meters = 0;
	int heart_rate = 0;

	void falsify()
	{
		validity = false;
		minutes = -1;
		seconds = -1;
		strokes = -1;
		meters = -1;
		heart_rate = -1;
	}

	void digitalize(string min, string sec, string sm, string m, string hr)
	{
		minutes = number(min, 0);
		seconds = number(sec, 0);
		strokes = number(sm, 0);
		meters = number(m, 0);
		heart_rate = number(hr, 0);
	}
};

RowerData process(string rowerString);

int main()
{
	while (true)
	{
		string input;
		getline(cin, input);
		RowerData data = process(input);
		cout << data.validity << endl << data.minutes << endl << data.seconds << endl << data.strokes << endl << data.meters << endl << data.heart_rate << endl;
	}
	return 0;
}

RowerData process(string rowerString)
{
	RowerData return_data;
	int pin = 0;
	string values[5] = { "", "", "", "", "" };

	for (size_t i = 0; i < rowerString.size(); i++)
	{
		if (i == 0)
		{
			char current_character = rowerString[i];
			char next_character = rowerString[i + 1];

			if (current_character == ' ')
			{
				i = i;
			}
			else if (isdigit(current_character))
			{
				values[pin] = values[pin] + current_character;
			}
			else if (current_character == ':')
			{
				pin = 1;
			}
			else
			{
				return_data.falsify();
				cerr << 1;
				return return_data;
			}
		}
		else
		{
			//getting the previous, current and next characters
			char prev_character = rowerString[i - 1];
			char current_character = rowerString[i];
			char next_character = rowerString[i + 1];

			if (current_character == ' ')
			{
				if (pin == 0)
				{
					if (!(prev_character == ' ' && values[pin] == ""))
					{
						return_data.falsify();
						cerr << 2;
						return return_data;
					}
				}
				else if (pin == 1 && values[pin] != "")
				{
					pin = 2;
				}
				else if (pin == 2)
				{
					if (prev_character == ' ' && values[pin] == "")
					{
						i = i;
					}
					else if (isdigit(prev_character) && next_character == 's' && values[pin] != "")
					{
						i++;
					}
					else
					{
						return_data.falsify();
						cerr << 3;
						return return_data;
					}
				}
				else if (pin == 3)
				{
					if (values[pin] == "")
					{
						i = i;
					}
					else if (isdigit(prev_character) && next_character == 'm' && values[pin] != "")
					{
						i++;
						pin++;
					}
					else
					{
						return_data.falsify();
						cerr << 4;
						return return_data;
					}
				}
				else if (pin == 4)
				{
					if (values[pin] == "")
					{
						i = i;
					}
					else
					{
						return_data.falsify();
						cerr << 5;
						return return_data;
					}
				}
			}
			else if (current_character == ':')
			{
				if ((isdigit(prev_character) || prev_character == ' ') && pin == 0)
				{
					pin = 1;
				}
				else
				{
					return_data.falsify();
					cerr << 6;
					return return_data;
				}
			}
			else if (current_character == '/')
			{
				if (prev_character == 's' && next_character == 'm' && pin == 2)
				{
					i++;
					pin = 3;
				}
				else
				{
					return_data.falsify();
					cerr << 7;
					return return_data;
				}
			}
			else if (isdigit(current_character))
			{
				if (isdigit(prev_character) || values[pin] == "")
				{
					values[pin] = values[pin] + current_character;
				}
				else
				{
					return_data.falsify();
					cerr << 9;
					return return_data;
				}
			}
			else
			{
				return_data.falsify();
				cerr << 10;
				return return_data;
			}
		}
	}

	return_data.digitalize(values[0], values[1], values[2], values[3], values[4]);
	return return_data;
}

int number(string s, int index)
{
	int result = 0;
	if (s[index] >= '1' && s[index] <= '9')
	{
		while (s[index] >= '0' && s[index] <= '9')
		{
			result = (result * 10) + (s[index] - '0');
			index = index + 1;
		}
	}
	return(result);
}