#include <iostream>
#include <string>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>

using namespace std;

struct node {
  string data;
  node *next;
};

class linkedList {
private:
  node *head;
  node *tail;

public:
  linkedList() {
    head = nullptr;
    tail = nullptr;
  }

  // Insertion
  void insertNode(int p, string d);    
  void insertNode(string p, string d);

  // Printing
  void print(int position, ofstream& out);
  void print(string position, ofstream& out);

  // Removals
  void removeNode(int position);
  void removeNode(string position);

  node *getHead() { return head; }
  node *getTail() { return tail; }
  int listSizeRecursive(node *curr);
};
