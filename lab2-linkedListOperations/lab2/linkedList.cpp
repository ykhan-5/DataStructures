#include <iostream>
#include <string>
using namespace std;

#include "linkedList.h"

// Extra fxns
int linkedList::listSizeRecursive(node *curr) {
  if (curr == nullptr) {
    return 0;
  }
  return 1 + listSizeRecursive(curr->next);
}

// Insertion
void linkedList::insertNode(int p, string d) { // GOOD
  // if (listSizeRecursive(getHead()) >= p){
  node *temp = new node; // add check for size here
  node *before = head;

  temp->data = d;
  temp->next = nullptr;

  if (head == nullptr && p == 0) {
    head = temp;
    tail = temp;
  } else if (p == 0) {
    temp->next = head;
    head = temp;
  } else {
    if (listSizeRecursive(getHead()) >= p){
    for (int i = 0; i < p - 1; i++) {
      before = before->next;
    }
    temp->next = before->next;
    before->next = temp;
  }
  }
}
//}

void linkedList::insertNode(string p, string d) { // GOOD
  node *temp =
      new node; // add checl for size here, ig for this one may not matter

  temp->data = d;
  temp->next = nullptr;

  if (head == nullptr) {
    head = temp;
    tail = temp;
  } else {
    if (p == "Head") {
      temp->next = head;
      head = temp;
    }
    if (p == "Tail") {
      tail->next = temp;
      tail = temp;
    }
  }
}

// Printing
void linkedList::print(int position, ofstream &out) { // GOOD
  if (listSizeRecursive(getHead()) > position) {
    node *curr = head;

    for (int j = 0; j < position; j++) {
      curr = curr->next;
    }

    //for (int i = position; (i < listSizeRecursive(getHead())); i++) {
      out << curr->data << endl;
    //  curr = curr->next; // traversing
    //}
  }
}

void linkedList::print(string position, ofstream &out) { // GOOD
  if (head != nullptr) {

    if (position == "Head") {
      node *curr = head;
      //while (curr != nullptr) {
        out << curr->data << endl;
      //  curr = curr->next; // traversing
      //}

    } else if (position == "Tail") {
      out << tail->data << endl;
    }
  }
}

// Removals
void linkedList::removeNode(int position) { // Not Written
  if (listSizeRecursive(getHead()) > position) {
    if (position == 0) {
      // Dummy node
      node *before = new node;
      before->next = head;

      for (int j = 0; j < position - 1; j++) { // finds the position
        before = before->next;
      }

      before->next = before->next->next;
      head = before->next;
      if (listSizeRecursive(getHead()) == 1) {
        head = tail;
      }

    } else if (position == listSizeRecursive(getHead()) - 1) {
      node *before = head;
      for (int j = 0; j < position - 1; j++) { // finds the position
        before = before->next;
      }
      before->next = before->next->next;
      tail = before;
    } else {
      node *before = head;
      for (int j = 0; j < position - 1; j++) { // finds the position
        before = before->next;
      }
      before->next = before->next->next;
    }
  }
}

void linkedList::removeNode(string position) { // Not Written
  if (head != nullptr) {
    if (position == "Head") {
      node *del = head;

      head = del->next;
      del->next = nullptr;

      if (listSizeRecursive(getHead()) == 1) {
        head = tail;
      }
    }
    if (position == "Tail") {
      node *del = head;
      for (int j = 0; j < (listSizeRecursive(getHead()) - 2); j++) {
        del = del->next;
      }

      del->next = nullptr;
      tail = del;
    }
  }
}
