#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
#include "ArgumentManager.h"
using namespace std;

#include "linkedList.h"

int main(int argc, char *argv[]){

    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));
    
    string inStr = "";
    string cmndStr = "";
    string indxStr = "";
    string valStr = "";
    int val = 0;

    linkedList t;

    while(getline(input, inStr)){

        inStr.erase(remove(inStr.begin(), inStr.end(), '\n'), inStr.end());
        inStr.erase(remove(inStr.begin(), inStr.end(), '\r'), inStr.end());
        
        if(inStr.empty()){
            continue;
        }

        stringstream ss(inStr);

        ss >> cmndStr;

        if(cmndStr == "Insert"){
            ss >> indxStr;
            if(indxStr != "Head" && indxStr != "Tail"){
                val = stoi(indxStr);
            }
            ss >> valStr;
            //val is a number
            //cout << cmndStr << " " << indxStr << " " << valStr << endl;

            if (cmndStr == "Insert" && (indxStr == "Head" || indxStr == "Tail")){
              t.insertNode(indxStr,valStr);
            }
            if (cmndStr == "Insert" && (indxStr != "Head" && indxStr != "Tail")){
              t.insertNode(val,valStr);
            }
        }
        else if(cmndStr == "Remove"){
            ss >> indxStr;
            if(indxStr != "Head" && indxStr != "Tail"){ 
                val = stoi(indxStr);
            }
            //cout << cmndStr << " " << indxStr << endl;
            if (cmndStr == "Remove" && (indxStr == "Head" || indxStr == "Tail")){
              t.removeNode(indxStr);
            }
            if (cmndStr == "Remove" && (indxStr != "Head" && indxStr != "Tail")){
              t.removeNode(val);
            }

        }
        else if(cmndStr == "Print"){
            ss >> indxStr;
            indxStr.erase(remove(indxStr.begin(), indxStr.end(), '['), indxStr.end());
            indxStr.erase(remove(indxStr.begin(), indxStr.end(), ']'), indxStr.end());
            if(indxStr != "Head" && indxStr != "Tail"){
                val = stoi(indxStr);
            }
            //cout << cmndStr << " " << indxStr << endl;
            if (cmndStr == "Print" && (indxStr == "Head" || indxStr == "Tail")){
              t.print(indxStr, output);
            }
            if (cmndStr == "Print" && (indxStr != "Head" && indxStr != "Tail")){
              t.print(val, output);
            }
            
        }
    }

    return 0;
}