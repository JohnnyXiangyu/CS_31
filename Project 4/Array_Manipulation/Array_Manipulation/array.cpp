#include<iostream>
#include<string>
#include<cctype>
using namespace std;

bool hasDuplicates(const string array[], int size);
int countAllDigits(const string array[], int size);
bool isInDecreasingOrder(const string array[], int size);
int shiftRight(string array[], int size, int amount, string placeholder);
int find(const string array[], int size, string match);
int replaceAllCharacters(string array[], int size, char findLetter, char replaceLetter);

void printArray(const string array[], int size);

void reset(string folks[]);

void testDuplicates(const string array[], int size);
void testAllDigits(const string array[], int size);
void testInDecreasingOrder(const string array[], int size);
void testShiftRight(string array[], int size, int amount, string placeholder);
void testFind(const string array[], int size, string match);
void testReplaceAllCharacters(string array[], int size, char findLetter, char replaceLetter);


int main() {
	string folks[8] = {
		"samwell", "jon", "margaery", "daenerys",
		"tyrion", "sansa", "howard123", "jon"
	};

	string people[5] = {
		"samwell", "jon", "margaery",
		"daenerys", "tyrion"
	};

	string sequence_test[10] = { "zzz", "zz", "z", "aaa", "aa", "Zz", "ZA", "Ba", "B", "A" };

	string empty_test[5] = { " 123", "", "", "", "a123" };

	testDuplicates(folks, 8);
	testDuplicates(people, 5);
	testDuplicates(empty_test, 5);
	testDuplicates(people, -1);
	testAllDigits(folks, 8);
	testAllDigits(people, 5);
	testAllDigits(empty_test, 5);
	testAllDigits(empty_test, -1);
	testInDecreasingOrder(folks, 8);
	testInDecreasingOrder(people, 5);
	testInDecreasingOrder(sequence_test, 10);
	testInDecreasingOrder(empty_test, 5);
	testInDecreasingOrder(people, -1);
	testShiftRight(folks, 8, 5, "foo");
	testShiftRight(folks, 8, 10, "foo");
	testShiftRight(folks, 8, 8, "foo");
	testShiftRight(folks, 0, 0, "foo");
	//testShiftRight(empty_test, 5, 3, "foo");
	testShiftRight(folks, -1, 10, "foo");
	testShiftRight(folks, 8, -1, "foo");
	testFind(folks, 8, "jon");
	testFind(folks, 8, "margaery");
	testFind(folks, 5, "jon");
	//testFind(empty_test, 5, "");
	//testFind(empty_test, 5, " ");
	testFind(folks, -1, "jon");
	testReplaceAllCharacters(folks, 8, 'a', '_');
	testReplaceAllCharacters(folks, 8, 'b', '_');
	testReplaceAllCharacters(folks, 8, 'c', '_');
	testReplaceAllCharacters(folks, 8, 'd', '_');
	testReplaceAllCharacters(folks, 8, 'e', '_');
	//testReplaceAllCharacters(empty_test, 5, ' ', '_');
	testReplaceAllCharacters(folks, -1, 'e', '_');

	cerr << endl << endl << endl << "finished";

	return 0;
}

void printArray(const string array[], int size) {
	for (int i = 0; i < size; i++) {
		cerr << array[i] << ", ";
	}
	cerr << endl;
}

bool hasDuplicates(const string array[], int size) {
	if (size <= 0) { return false; }
	//run the elements from first to last
	for (int i = 0; i < size; i++) {
		string candidate = array[i];
		for (int j = i + 1; j < size; j++) {
			//see if there's any chance one element is duplicated
			if (candidate == array[j]) {
				return true;
			}
		}
	}

	return false;
}

int countAllDigits(const string array[], int size) {
	if (size <= 0) { return -1; }

	//declare a variable to count digits
	int digit_number = 0;
	for (int i = 0; i < size; i++) {
		string now_string = array[i];
		int length = now_string.length();
		for (int j = 0; j < length; j++) {
			//see if this one is a digit
			if (isdigit(now_string[j])) {
				digit_number++;
			}
		}
	}
	return digit_number;
}

bool isInDecreasingOrder(const string array[], int size) {
	if (size < 0) { return false; }
	
	//check if there's an element in the array to break the rule. starting from the second one
	for (int i = 1; i < size; i++) {
		string now_string = array[i];
		string just_now_string = array[i - 1];
		if (!(now_string < just_now_string)) { return false; }
	}
	return true;
}

int shiftRight(string array[], int size, int amount, string placeholder) {
	if (size < 0 || amount < 0) { return -1; }
	
	//when amount is bigger, thw whole array is wiped
	if (size <= amount) {
		for (int i = 0; i < size; i++) {
			array[i] = placeholder;
		}
		return size;
	}
	//when amount is smaller than size
	else if (size > amount) {
		int num_preserved = size - amount;
		for (int i = num_preserved; i > 0; i--) {
			int index = i - 1;
			array[index + amount] = array[index];
		}
		for (int i = 0; i < amount; i++) {
			array[i] = placeholder;
		}
		return amount;
	}
	else { return -1; }
}

int  find(const string array[], int size, string match) {
	if (size <= 0) { return -1; }
	
	int index = 0;
	//startng from the first item in the array
	for (int i = 0; i < size; i++) {
		if (array[i] == match) {
			index = i;
			return index;
		}
	}

	return -1;
}

int  replaceAllCharacters(string array[], int size, char findLetter, char replaceLetter) {
	if (size <= 0) { return -1; }
	
	int times_replaced = 0;
	//from the first item
	for (int i = 0; i < size; i++) {
		//from the first character
		for (unsigned int j = 0; j < array[i].length(); j++) {
			if (array[i][j] == findLetter) {
				array[i][j] = replaceLetter;
				//count times
				times_replaced++;
			}
		}
	}
	return times_replaced;
}

void reset(string folks[]) {
	string folks_prototype[8] = {
	"samwell", "jon", "margaery", "daenerys",
	"tyrion", "sansa", "howard123", "jon"
	};

	for (int i = 0; i < 8; i++) {
		folks[i] = folks_prototype[i];
	}
}

void testDuplicates(const string array[], int size) {
	cerr.setf(ios::boolalpha);
	
	cerr << "input: ";
	printArray(array, size);
	cerr << "hasDuplicates: " << hasDuplicates(array, size) << endl << endl << endl;
}

void testAllDigits(const string array[], int size) {
	cerr.setf(ios::boolalpha);

	cerr << "input: ";
	printArray(array, size);
	cerr << "countAllDigits: " << countAllDigits(array, size) << endl << endl << endl;
}

void testInDecreasingOrder(const string array[], int size) {
	cerr.setf(ios::boolalpha);

	cerr << "input: ";
	printArray(array, size);
	cerr << "isInDecreasingOrder: " << isInDecreasingOrder(array, size) << endl << endl << endl;
}

void testShiftRight(string array[], int size, int amount, string placeholder) {
	cerr.setf(ios::boolalpha);

	cerr << "input: ";
	printArray(array, size);
	cerr << "amount: " << amount << ", placeholder: " << placeholder << endl;
	cerr << "shiftRight: " << shiftRight(array, size, amount, placeholder) << endl;
	cerr << "output: ";
	printArray(array, size);
	cerr << endl << endl;

	reset(array);
}

void testFind(const string array[], int size, string match) {
	cerr.setf(ios::boolalpha);

	cerr << "input: ";
	printArray(array, size);
	cerr << "match: " << match << endl;
	cerr << "find: " << find(array, size, match) << endl << endl << endl;
}

void testReplaceAllCharacters(string array[], int size, char findLetter, char replaceLetter) {
	cerr.setf(ios::boolalpha);

	cerr << "input: ";
	printArray(array, size);
	cerr << "size: " << size << ", findLetter: " << findLetter 
		 << ", replaceLetter: " << replaceLetter << endl;
	cerr << "replaceAllCharacters: "
		 << replaceAllCharacters(array, size, findLetter, replaceLetter) 
		 << endl;
	cerr << "output: ";
	printArray(array, size);
	cerr << endl << endl;

	reset(array);
}