//project3
//six functions for six different parts of a given string

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

bool isValidRowerString(string rowerString);

int totalDistance(string rowerString);
int heartRate(string rowerString);
int strokesPerMinute(string rowerString);
int elapsedMinutes(string rowerString);
int elapsedSeconds(string rowerString);


int process(string rowerString, int index);
int number(string s, int index);//used to turn a string number to a actual number variable. int only.

void test();

int main()
{
	while (true)
	{
		test();
	}
	return 0;
}

void test()
{
	cout.setf(ios::boolalpha); // prints bool values as "true" or "false"
	
	string data;
	getline(cin, data);
	
	cout << "validity: " << isValidRowerString(data) << endl;
	cout << "distance: " << totalDistance(data) << endl;
	cout << "heart rate: " << heartRate(data) << endl;
	cout << "s/m: " << strokesPerMinute(data) << endl;
	cout << "minutes: " << elapsedMinutes(data) << endl;
	cout << "seconds: " << elapsedSeconds(data) << endl << endl << endl;
}

bool isValidRowerString(string rowerString)
{
	int data = process(rowerString, 0);
	if (data == 0)
	{
		return false;
	}
	else if (data == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int totalDistance(string rowerString)
{
	int data = process(rowerString, 4);
	if (data == 0)
	{
		return -1;
	}
	else
	{
		return data;
	}
}

int heartRate(string rowerString)
{
	int data = process(rowerString, 5);
	if (data == 0)
	{
		return -1;
	}
	else
	{
		return data;
	}
}

int strokesPerMinute(string rowerString)
{
	int data = process(rowerString, 3);
	if (data == 0)
	{
		return -1;
	}
	else
	{
		return data;
	}
}

int elapsedMinutes(string rowerString)
{
	int data = process(rowerString, 1);
	if (data == 0)
	{
		return -1;
	}
	else
	{
		return data;
	}
}

int elapsedSeconds(string rowerString)
{
	int data = process(rowerString, 2);
	if (data == 0)
	{
		return -1;
	}
	else
	{
		return data;
	}
}

int process(string rowerString, int index)
{
	size_t length = rowerString.size();
	string minutes = ""; //1
	string seconds = ""; //2
	string sm = ""; //3
	string meters = ""; //4
	string heart_beats = ""; //5

	int values[6];

	bool empty_minutes = false;

	int seq_roll = 1;
	//analyse the input char by char
	for (size_t i = 0; i < length; i++)
	{
		if (rowerString[i] != ' ')
		{
			// if we get ':', it should be right before the seconds value, so seq_roll jumps to 2; 
			//and a bool variable is to mark if the minutes value is inputed
			if (rowerString[i] == ':' && seq_roll == 1)
			{
				seq_roll = 2;
				if (minutes == "")
				{
					empty_minutes = true;
					minutes = "0";
				}
			}
			//if we get a digit, add it to the right string variable		
			else if (isdigit(rowerString[i]))
			{
				switch (seq_roll)

				{
				case 1:
					minutes = minutes + rowerString[i];
					break;
				case 2:
					seconds = seconds + rowerString[i];
					break;
				case 3:
					sm = sm + rowerString[i];
					break;
				case 4:
					meters = meters + rowerString[i];
					break;
				case 5:
					heart_beats = heart_beats + rowerString[i];
					break;
				}
			}
			else
			{
				return 0;
			}
		}
		//when we get a space
		else if (rowerString[i] == ' ')
		{
			string test = "";
			switch (seq_roll)
			{
			case 1:
				if (minutes != "")
				{
					return 0;
				}
				break;
			case 2:
				//if seq_roll points to 2, we know the time section has ended
				seq_roll = 3;
				break;
			case 3:
				//if seq_roll points to 3, 4, or 5, we need to see if this space is separating values or invalid
				test = test + rowerString[i + 1] + rowerString[i + 2] + rowerString[i + 3];
				if (test == "s/m" && sm != "")
				{
					i = i + 3;
					seq_roll = 4;
				}
				else if (test != "s/m" && sm != "")
				{
					return 0;
				}
				break;
			case 4:
				if (rowerString[i + 1] == 'm' && meters != "")
				{
					i++;
					seq_roll++;
				}
				else if (meters != "")
				{
					return 0;
				}
				break;
			case 5:
				if (heart_beats != "")
				{
					return 0;
				}
				break;
			default:
				return 0;
				break;
			}
		}
	}

	//do the variables processed make sense?
	//first they cannot be empty
	if (minutes == "" || seconds == "" || sm == "" || meters == "" || heart_beats == "")
	{
		return 0;
	}
	//second they cannot start with 0
	else if (minutes[0] == '0' || seconds[0] == '0' || sm[0] == '0' || meters[0] == '0' || heart_beats[0] == '0')
	{
		return 0;
	}
	//finally, all values must stay in the valid range
	else
	{
		if (empty_minutes == false)
		{
			values[1] = number(minutes, 0);
		}
		else if (empty_minutes == true)
		{
			values[1] = 0;
		}
		
		values[2] = number(seconds, 0);
		values[3] = number(sm, 0);
		values[4] = number(meters, 0);
		values[5] = number(heart_beats, 0);

		values[0] = 1;

		if (empty_minutes == false && !(values[1] <= 59 && values[1] >= 1)) //make some clever stuff for an empty minutes
		{
			return 0;
		}
		else if (!(values[2] <= 59 && values[2] >= 1))
		{
			return 0;
		}
		else if (!(values[3] <= 999 && values[3] >= 1))
		{
			return 0;
		}
		else if (!(values[4] >= 0))
		{
			return 0;
		}
		else if (!(values[5] <= 999 && values[5] >= 1))
		{
			return 0;
		}
		else
		{
			return values[index];
		}
	}
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