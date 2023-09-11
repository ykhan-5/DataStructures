#include <iostream>
#include <string>
#include "ArgumentManager.h"
#include <fstream>

using namespace std;

int getSuitIndex(char suit) {
    switch (suit) {
        case 'S': return 0;
        case 'H': return 1;
        case 'C': return 2;
        case 'D': return 3;
        default: return -1; // Invalid suit
    }
}

int getValueIndex(char value, char valueNext) {
    if (value == '1' and valueNext =='0'){ 
        return 9;
    }
    switch (value) {
        case '1': return 0;
        case '2': return 1;
        case '3': return 2;
        case '4': return 3;
        case '5': return 4;
        case '6': return 5;
        case '7': return 6;
        case '8': return 7;
        case '9': return 8;
        // return 9 covered by above (if the number is 10)
        case 'J': return 10;
        case 'Q': return 11;
        case 'K': return 12;
        default: return -1; // Invalid value
    }
}

int main(int argc, char* argv[]) {
    
    ArgumentManager am(argc,argv);
    const string input = am.get("input");
    const string output = am.get("output");

    ifstream inputFile(input);
    ofstream outputFile(output);

    string str;
    getline(inputFile,str);
    
    int ans[4][13] = {0};

    size_t pos = 0;
    
    do {
    pos = str.find(',');
    string card = str.substr(0, pos);
    str.erase(0, pos + 2);

    char value = card[0];
    char valueNext = card[1];
    char suit = card[1];
    
    
    if (getValueIndex(value,valueNext) == 9){
    suit = card[2];
    } 
    

    int col = getSuitIndex(suit);
    int row = getValueIndex(value,valueNext);

    if (col != -1 && row != -1) {
        ans[col][row] = 1;
            }
        } while (pos != string::npos);

    // Print the array to the output file
    for (int row = 0; row < 13; ++row) {
        for (int col = 0; col < 4; ++col) {
            outputFile << ans[col][row] << " ";
        }
        outputFile << endl;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    return 0;
}
