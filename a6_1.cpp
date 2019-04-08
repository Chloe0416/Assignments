#include <iostream>
using namespace std;

int lastIndexOf(const char* inString, char target) {
	int lastIndex = -1;
	int i = 0;
	while (inString[i] != '\0') {
		if (inString[i] == target) {
			lastIndex = i;
		}
		i++;
	}
	return lastIndex;
}

void reverse(char* inString) {
	int i = 0, j = strlen(inString) - 1;
	while (i < j) {
		char temp = inString[i];
		inString[i] = inString[j];
		inString[j] = temp;
		i++;
		j--;
	}
}

int replace(char* inString, char target, char replacementChar) {
	int numOfRep = 0;
	int i = 0;
	while (inString[i] != '\0') {
		if (inString[i] == target) {
			inString[i] = replacementChar;
			numOfRep += 1;
		}
		i++;
	}
	return numOfRep;
}
bool isDifferentCase(char a, char b) {
	if (a > b) {
		if (a - 32 == b) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (a + 32 == b) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool isPalindrome(const char* inString) {
	int i = 0, j = strlen(inString) - 1;
	while (i < j) {
		if (inString[i] != inString[j]) {
			if (!isDifferentCase(inString[i], inString[j])) {
				return false;
			}
		}
		i++;
		j--;
	}
	return true;
}

void toupper(char* inString) {
	int i = 0;
	while (inString[i] != '\0') {
		if (inString[i] >= 'a' && inString[i] <= 'z') {
			inString[i] -= 32;
		}
		i++;
	}
}

int numLetters(const char* inString) {
	int i = 0, numOfLetter = 0;
	while (inString[i] != '\0') {
		if (inString[i] >= '0' && inString[i] <= '9') {
			numOfLetter += 1;
		}
		i++;
	}
	return numOfLetter;

}

int main(){

	char str1[] = "Hello hello World";
	char str2[] = "Today is a good day";
	char str3[] = "Today is Monday";
	char str4[] = "abcdefeDcba";
	char str5[] = "Hello World";
	char str6[] = "a1b2c3defg";


	cout << "----- test 1 -----\n";
	// Test of case sensitivity using 'h' and 'H'.
	cout << lastIndexOf(str1, 'h') << endl;
	cout << lastIndexOf(str1, 'H') << endl;
	// Try the target char with more than one index in the string.
	cout << lastIndexOf(str1, 'e') << endl;
	// Try the target char isn't in the string.
	cout << lastIndexOf(str1, 'a') << endl;

	cout << "\n----- test 2 -----\n";
	cout << "The string before reverse is: " << str1 << endl;
	reverse(str1);
	cout << "The string after reverse is: " << str1 << endl;

	cout << "\n----- test 3 -----\n";
	cout << "The string before replacement is: " << str2 << endl;
	// Try replace 'o' in the string with '*'
	cout << "The number of replacing 'o' with '*' is: " << replace(str2, 'o', '*') << endl;
	cout << "The string replacement replacement is: " << str2 << endl;
	cout << "The string before replacement is: " << str3 << endl;
	// Try replace 'z'(which does not) in the string with '*'
	cout << "The number of replacing 'z' with '*' is: " << replace(str3, 'z', '*') << endl;
	cout << "The string replacement replacement is: " << str3 << endl;

	cout << "\n----- test 4 -----\n";
	// Test of a palindrome
	cout << "String < " << str4 << " > is a palindrome?\n";
	if (isPalindrome(str4)) {
		cout << "Yes, it is.\n";
	}
	else {
		cout << "No, it is not.\n";
	}
	// Test of a not palindrome.
	cout << "String < " << str5 << " > is a palindrome?\n";
	if (isPalindrome(str5)) {
		cout << "Yes, it is.\n";
	}
	else {
		cout << "No, it is not.\n";
	}

	cout << "\n----- test 5 -----\n";
	// Test of string with low and upper case chars
	cout << "The test string for test 5 is: " << str5 << endl;
	toupper(str5);
	cout << "After converting to all uppercase is: " << str5 << endl;

	cout << "\n----- test 6 -----\n";
	// Test of string with letters.
	cout << "String < " << str6 << " > has " << numLetters(str6) << " letters in it.\n";
	// Test of string with no letters.
	cout << "String < " << str5 << " > has " << numLetters(str5) << " letters in it.\n";




	return 0;
}

/** OUTPUT:
	----- test 1 -----
	6
	0
	7
	-1

	----- test 2 -----
	The string before reverse is: Hello hello World
	The string after reverse is: dlroW olleh olleH

	----- test 3 -----
	The string before replacement is: Today is a good day
	The number of replacing 'o' with '*' is: 3
	The string after replacement is: T*day is a g**d day
	The string before replacement is: Today is Monday
	The number of replacing 'z' with '*' is: 0
	The string after replacement is: Today is Monday

	----- test 4 ----- 
	String < abcdefDcba > is a palindrome?
	Yes , it is.
	String < Hello World > is a palindrome?
	No, it is not.

	----- test 5 -----
	The test string for test 5 is: Hello World
	After converting to all uppercase is: HELLO WORLD

	----- test 6 -----
	String < a1b2c3defg > has 3 letters in it.
	String < HELLO WORLD > has 0 letters in it.


	**/