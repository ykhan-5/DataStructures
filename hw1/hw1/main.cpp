#include <iostream>
#include <string>
#include "ArgumentManager.h"
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int findMin(vector<int>& numbers, int position = 0) { // '&' so we can change numbers as we go through
                                                      // 'position=0' so we can know which place we are in
    if (numbers.empty()) {
        return 0; // Base case: If the array is empty, return 0.
        //Even though this won't happen probably good to get in the habit.
    }
    
      //initialize
    int minIndex = 0;
    int minNum = numbers[0];
    int subMin = 0;

    //check if there is a 10, if so --> split into 1 and 0, that is how it should be treated
    int it = find(numbers.begin(), numbers.end(), 10) - numbers.begin();
    if (it < numbers.size()) {
        // If 10 is found, split it into 1 and 0
        numbers.erase(numbers.begin() + it);
        numbers.push_back(1);
        numbers.push_back(0);
    }


    //find min and minIndex --> problem with this is if i find 10, i have to put it last --> if statement?
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] < minNum) {
            minNum = numbers[i];
            minIndex = i;
        }
    }

      // Remove the minimum number from the array
    numbers.erase(numbers.begin() + minIndex);


      // Recursively find the minimum of the remaining numbers
    subMin = findMin(numbers, position + 1);


      //Since the return is after the recursive function call, we know that its gonna run backwards
      //meaning we have found for example (input: 4 8 1 --> we find [1 4 8] in that order)
      //now return after and you will get needed order of [841]


      //How to get the places right? 
      //Using hundreds,tens,ones,etc..

      // Multiply the maximum number by 10 raised to the power of its position
    return minNum * pow(10, position) + subMin;
}

int main(int argc, char* argv[]) {
    
    ArgumentManager am(argc,argv);
    ifstream inputFile(am.get("input"));
    ofstream outputFile(am.get("output"));

    //ifstream inputFile(input);
    //ofstream outputFile(output);

    std::vector<int> numbers;
       int num;

    // Print the array to the output file
    while (inputFile >> num) {
        numbers.push_back(num);
    }
    
    int greatestPermutation = findMin(numbers);

    outputFile << greatestPermutation;
    
    // Close the files
    inputFile.close();
    outputFile.close();

    return 0;
}
