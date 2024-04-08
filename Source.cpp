/*
Program name: Palindrome.cpp
Programmer: Tyler Davies
Date: 11-24-21
Version: 1.0
Description: This program contains a boolean function called testPalindrome that uses recursion to
             determine if a string argument is a palindrome; it returns true if the argument reads
             the same forward and backward. Two other functions have been added to increase the
             productivity of the testPalindrome function, which now allows for testing of true
             palindromes. True palindromes ignore spaces, punctuation, and case.
*/

#include<iostream>
#include<string>
using namespace std;

//Function Prototypes
void isPalindrome(string&);
string formatString(string);
bool testPalindrome(string&);

//The main function acts as a driver program. It prompts the user for a string, and calls the
//isPalindrome function.
int main()
{
    string userString;

    cout << "Enter a string to test if it is a palindrome:\n";
    getline(cin, userString);

    isPalindrome(userString);

    exit(0);
}

//The isPalindrome function passes the user's string to the formatString function, then to the
//testPalindrome function. It prints a message based on the testPalindome's return value.
void isPalindrome(string& userString)
{
    bool test;

    userString = formatString(userString);
    test = testPalindrome(userString);

    if (test)
        cout << "\nThe string entered is a palindrome!\n";
    else
        cout << "\nThe string entered is not a palindrome!\n";
}

//The formatString function removes all spaces and punctuation from the user's string. This is
//because palindromes ignore spaces and punctuation.
string formatString(string userString)
{
    string returnString = "";

    for (unsigned int i = 0; i < userString.size(); i++)
    {
        if ((userString[i] != ' ') && (!ispunct(userString[i])))
            returnString.push_back(userString[i]);
    }

    return returnString;
}

/*
The testPalindrome function is a recursive function. Its base case tests whether the string is a
single character or an empty string; which are by definition still palindromes. If not, it checks
whether the first and last character are the same, using the tolower() function to convert
uppercase characters to lowercase, allowing for the test to ignore case.
*/
bool testPalindrome(string& userString)
{
    string subString;
    bool test;

    if (userString.size() <= 1)
        test = true;
    else if (tolower(userString[0]) != tolower(userString[userString.size() - 1]))
        test = false;
    else
    {
        subString = userString.substr(1, userString.size() - 2);
        test = testPalindrome(subString);
    }

    return test;
}