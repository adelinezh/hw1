/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
// WRITE YOUR CODE HERE
//call next pointer of main array
//create temp Node without the first value
//determine if it is odd or even
//add onto either odd or evens
//recurse onto temp node in main array
  if (in == nullptr)
  {
    return;
  }
  Node* nextNode = in -> next;

  if (in -> value % 2 == 0) //even
  {
    in -> next = evens; // add onto evens
    evens = in; 
    split(nextNode, odds, evens -> next);
  }
  else
  {
    in -> next = odds;
    odds = in;
    split(nextNode, odds -> next, evens);
  }
  in = nullptr;
}