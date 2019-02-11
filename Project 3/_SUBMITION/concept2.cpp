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

void test(string data);
void auto_test();

int main()
{
	auto_test();
	cout << endl << endl << endl;
	string string;
	getline(cin, string);
	test(string);
	return 0;
}

void test(string data)
{
	cout.setf(ios::boolalpha); // prints bool values as "true" or "false"

	cout << "input: " << data << endl;

	cout << "isValidRowerString: " << isValidRowerString(data) << endl;
	cout << "elapsedMinutes: " << elapsedMinutes(data) << endl;
	cout << "elapsedSeconds: " << elapsedSeconds(data) << endl;
	cout << "strokesPerMinute: " << strokesPerMinute(data) << endl;
	cout << "totalDistance: " << totalDistance(data) << endl;
	cout << "heartRate: " << heartRate(data) << endl << endl << endl;
}
	

void auto_test()
{
	int index = 106 - 1; //plz always keep index == test[]'s length -1
	string all[106] = {
		":14    28 s/m     42 m    110",
		"        :14         28 s/m         42 m      110",
		"1:14    28 s/m     42 m    110",
		"59:14     28 s/m     42 m    110",
		"59:59    28 s/m     42 m    110",
		"59:59    999 s/m     42 m    110",
		"59:09    999 s/m     42 m    999",
		"59:59  999 s/m   42 m    999",
		":00   1 s/m   42 m   1",
		"    20:20   200 s/m   42 m   120",
		" 1:01 20 s/m  42 m  20",
		" 59:00  10 s/m  42 m         1",
		"FALSE FALSE FALSE FALSE FALSE FALSE FALSE FALSE FALSE FALSE FALSE FALSE FALSE",
		"14:14",
		"14:14  14 s/m  ",
		"14:14   14 s/m   14 m",
		"59:59    09 s/m     42 m    110",
		"59:9    999 s/m     2 m    110",
		"59:59    999 s/m     42 m    010",
		"09:59    999 s/m     42 m    110",
		"asdf:14    28 s/m     42 m    110",
		":14    28 s/m     42 m    110 asdf",
		":14     28       s/m    42 m    110",
		"0:14    28 s/m     42 m    110",
		"0000:14    00028 s/m     00042 m   000110",
		":-14 - 28 s/m - 42 m - 110",
		"555 : 14    28 s/m    42 m   110",
		":555      28 s/m      42 m  110",
		":14    99123 s/m    42 m   110",
		":14    0 s/m            42 m   110",
		":14    28 s/m         42 m   99123",
		":14    28 s/m         42 m   0",
		": 14    28 s/m         42 m   0",
		"59 :59    999 s/m     42 m    110",
		"59 : 59    999 s/m     42 m    110",
		"59:59    999 s/m     42 m    999   ",
		"59:59    999 s/m     42 m    999AAA",
		" 00 1 42 m 210",//missing ':' and s/m
		" 2323 23 s/m 42 m  100", //missing ':'
		" 23:23 23 s/  42 m  100", //missing 'm'
		" 23:23  23 /m 42 m  100", //missing 's'
		" 0:00 1 s/m   42 m 210", //initial '0'
		" 23:23  0 s/m  42 m  210", //0 s/m
		" 23:23  1 s/m  42 m  0", //0 heart rate
		" 59:60  23 s/m  42 m  120",//out of bound sec number
		" 60:59  23 s/m  42 m  120",//out of bound min number
		" 23:23  1001 s/m  42 m  120",//out of bound s/m
		" 23:23  23 s/m  42 m  1001",//out of bound heart rate
		" 23:23  23 s / m 42 m  100",//separated s/m
		" 23 :23  23 s/m  42 m  100",//separated num:num
		" 23: 23  23 s/m  42 m  100",//same as the last one
		" 2 3:23  23 s/m  42 m  100",//separated num
		" 23:2 3  23 s/m  42 m  100",//separated num
		" 23:23  2 3 s/m  42 m  100",//separated num
		" 23:23  23 s/m  4 2 m  101",//separated num
		" 23:23  23 s/m  42 m  1 01",//separated num
		" 23:23  23 s/m  42 m  1 1",//separated num
		" 2 23:23  23 s/m  42 m   100",//separated num
		" 23:23 3 23 s/m  42 m  100",//separated num
		" 23:23 0 23 s/m  42 m  100",//separated num
		" 23:23  23 s/m  0 42 m  100",//separated num
		" 23:23  23 s/m  42 m  ",//missing heartrate
		" 23:23  023 s/m  42 m  100",//unexpected '0'
		" 23:23  23 s/m  042 m  100",//unexpected '0'
		" 23:23  23 s/m  42 m  099",//unexpected '0'
		" 23:2323 s/m 42 m 100",//no spaces between
		" 23:23 23 s/m42 m 100",//no spaces between
		" 23:23 23s/m 42m100",//no spaces between
		" 23:230 23 s/m  42 m 100",//out of digit limit
		" 23:23  23 s/m  100000000000 m  100",//crazy distance
		" 00 1 42 m 210",//missing ':' and s/m
" 2323 23 s/m 42 m  100", //missing ':'
" 23:23 23 s/  42 m  100", //missing 'm'
" 23:23  23 /m 42 m  100", //missing 's'
" 0:00 1 s/m   42 m 210", //initial '0'
" 23:23  0 s/m  42 m  210", //0 s/m
" 23:23  1 s/m  42 m  0", //0 heart rate
" 59:60  23 s/m  42 m  120",//out of bound sec number
" 60:59  23 s/m  42 m  120",//out of bound min number
" 23:23  1001 s/m  42 m  120",//out of bound s/m
" 23:23  23 s/m  42 m  1001",//out of bound heart rate
" 23:3  23 s/m  42 m  120",//incorrect sec digit
" 23:23  23 s / m 42 m  100",//separated s/m
" 23 :23  23 s/m  42 m  100",//separated num:num
" 23: 23  23 s/m  42 m  100",//same as the last one
" 2 3:23  23 s/m  42 m  100",//separated num
" 23:2 3  23 s/m  42 m  100",//separated num
" 23:23  2 3 s/m  42 m  100",//separated num
" 23:23  23 s/m  4 2 m  101",//separated num
" 23:23  23 s/m  42 m  1 01",//separated num
" 23:23  23 s/m  42 m  1 1",//separated num
" 2 23:23  23 s/m  42 m   100",//separated num
" 23:23 3 23 s/m  42 m  100",//separated num
" 23:23 0 23 s/m  42 m  100",//separated num
" 23:23  23 s/m  0 42 m  100",//separated num
" 23:23  23 s/m  42 m  ",//missing heartrate
" 23:23  023 s/m  42 m  100",//unexpected '0'
" 23:23  23 s/m  042 m  100",//unexpected '0'
" 23:23  23 s/m  42 m  099",//unexpected '0'
" 23:2323 s/m 42 m 100",//no spaces between
" 23:23 23 s/m42 m 100",//no spaces between
" 23:23 23 s/m 42 m100",//no spaces between
" 23:23  23 s/m  42m  100",//no spaces between
" 23:23  23s/m  42 m  100",//no spaces between
" 23:23  23 s/m  42 m  100 ",//spaces at the end
		" 23:230 23 s/m  42 m 100",//out of digit limit
	};

	for (int i = 0; i <= index; i++)
	{
		string data = all[i];
		test(data);
	}
}

bool isValidRowerString(string rowerString)
{
	int data = process(rowerString, 0);
	if (data == -1)
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
	/* if (data == -1)
	{
		return -1;
	}
	else
	{
		return data;
	}
	*/
	return data;
}

int heartRate(string rowerString)
{
	int data = process(rowerString, 5);
	return data;
}

int strokesPerMinute(string rowerString)
{
	int data = process(rowerString, 3);
	return data;
}

int elapsedMinutes(string rowerString)
{
	int data = process(rowerString, 1);
	return data;
}

int elapsedSeconds(string rowerString)
{
	int data = process(rowerString, 2);
	return data;
}

int process(string rowerString, int index)
{
	string values_string[6] = { "", "", "", "", "", "" };
	size_t length = rowerString.size();
	int values[6] = { 0, 0, 0, 0, 0, 0 };
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
				if (values_string[1] == "")
				{
					empty_minutes = true;
				}
			}
			//if we get a digit, add it to the right string variable		
			else if (isdigit(rowerString[i]))
			{
				values_string[seq_roll] += rowerString[i];
			}
			else
			{
				return -1;
			}
		}
		//when we get a space
		else if (rowerString[i] == ' ')
		{
			string test = "";
			switch (seq_roll)
			{
			case 1:
				if (values_string[1] != "")
				{
					return -1;
				}
				break;
			case 2:
				//if seq_roll points to 2, we know the time section has ended
				seq_roll = 3;
				break;
			case 3:
				//if seq_roll points to 3, 4, or 5, we need to see if this space is separating values or invalid
				if ((length - 1) < (i + 4))
				{
					return -1;
				}
				test = test + rowerString[i + 1] + rowerString[i + 2] + rowerString[i + 3] + rowerString[i + 4];
				if (test == "s/m " && values_string[seq_roll] != "")
				{
					i = i + 4;
					seq_roll++;
				}
				else if (test != "s/m " && values_string[seq_roll] != "")
				{
					return -1;
				}
				break;
			case 4:
				if ((length - 1) < (i + 1))
				{
					return -1;
				}
				if (rowerString[i + 1] == 'm' && rowerString[i + 2] == ' ' && values_string[seq_roll] != "")
				{
					i = i + 2;
					seq_roll++;
				}
				else if (values_string[seq_roll] != "")
				{
					return -1;
				}
				break;
			case 5:
				if (values_string[seq_roll] != "")
				{
					return -1;
				}
				break;
			default:
				return -1;
				break;
			}
		}
	}

	//do the variables processed make sense?
	//first they cannot be empty
	//second they cannot start with 0
	
	if (empty_minutes == true && values_string[1] == "")
	{
		values[1] = 0;
	}
	else if (empty_minutes == false && values_string[1] != "")
	{
		if (values_string[1][0] != '0')
		{
			values[1] = number(values_string[1], 0);
		}
		else
		{
			return -1;
		}
	}
	else { return -1; }
	
	if (values_string[2].length() == 2)
	{
		values[2] = number(values_string[2], 0);
	}
	else { return -1; }

	for (int i = 3; i <= 5; i++)
	{
		if (values_string[i][0] != '0')
		{
			values[i] = number(values_string[i], 0);
		}
		else { return -1; }
	}
	
	//finally, all values must stay in the valid range	
	values[0] = 1;

	if (empty_minutes == false && !(values[1] <= 59 && values[1] >= 1)) //make some clever stuff for an empty minutes
	{
		return -1;
	}
	else if (empty_minutes == true && values[1] != 0)
	{
		return -1;
	}
	else if (!(values[2] <= 59 && values[2] >= 0))
	{
		return -1;
	}
	else if (!(values[3] <= 999 && values[3] >= 1))
	{
		return -1;
	}
	else if (!(values[4] >= 0))
	{
		return -1;
	}
	else if (!(values[5] <= 999 && values[5] >= 1))
	{
		return -1;
	}
	else
	{
		return values[index];
	}
}

int number(string s, int index)
{
	int result = 0;
	if (s[index] >= '0' && s[index] <= '9')
	{
		while (s[index] >= '0' && s[index] <= '9')
		{
			result = (result * 10) + (s[index] - '0');
			index = index + 1;
		}
	}
	return(result);
}