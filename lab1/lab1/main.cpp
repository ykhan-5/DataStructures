#include <iostream>
#include <string>
#include "ArgumentManager.h"
#include <fstream>
#include <cctype> //for isalnum function
#include <iomanip> //to write true/false to the output file 
using namespace std;

bool isPalindrome(string str, int beg, int end) { //overloaded function
    //1-Base Case
    if (beg >= end) { //base case to stop the recursion
        return true;  
    }
    
    //2-Check 
    while (beg < end && !isalnum(str[beg])) { // Skip non-letter characters from beginning
        beg++;
    }
    while (beg < end && !isalnum(str[end])) { // Skip non-letter characters at end
        end--;
    }
    char char1 = tolower(str[beg]); //Convert to lowercase
    char char2 = tolower(str[end]); //...

    if (char1 != char2) { //check if chars match
        return false; 
    }
    
    //3-Changing inputs
    return isPalindrome(str, beg + 1, end - 1); // Recur for the inner substring
}

bool isPalindrome(string str) { //take in one string as input, simplify main code
    return isPalindrome(str, 0, str.length() - 1);
}

int main(int argc, char* argv[]) {
    
    //read in inputs
    ArgumentManager am(argc,argv);
    const string input = am.get("input");
    const string output = am.get("output");

    ifstream inputFile(input);
    ofstream outputFile(output);

    string str;
    getline(inputFile,str);

    outputFile << boolalpha << isPalindrome(str) << endl;

    // Close the files
    inputFile.close();
    outputFile.close();

    return 0;

}