// Name: Devendra Swami
// USC NetID: 1742427505
// CSCI 455 PA5
// Spring 2019


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}

//*************************************************************************
// Function definitions for the list functions below:

bool listInsert(ListType &list, const std::string &theKey, int theValue){
   
   // Special case: empty list
   if (list==NULL){
      list = new Node(theKey,theValue);
      return true;
   }
   
   Node * p = list;
   
   // Checking if theKey is already present while traversing to last node
   while(p->next!=NULL){
      if (p->key == theKey){
         return false;  // theKey already present
      }
      p = p->next;
   }
   
   // Checking if theKey present at the last node
   if (p->key == theKey){  
      return false;
   }
   
   // Inserting new entry at the last node
   p->next = new Node(theKey,theValue);
   
   return true; // successfully inserted
}   


int * listLookup(const ListType &list, const std::string &theKey){
   
   Node * p = list;
   
   // Traversing list to check if theKey is present
   while(p!=NULL){
      if (p->key == theKey){
         return &(p->value);  // returned pointer to value associated with theKey
      }
      p = p->next;
   }
   
   return NULL; // unable to retrieve theKey
}


bool listRemove(ListType &list, const std::string &theKey){
   
   // Special case: empty list
   if (list == NULL){
      return false;
   }
   
   // Using two temp pointers for traversal
   Node * p = list;
   Node * ahead = list->next;
   
   // Unable to check first element in general case in while loop below (Considering separately here)
   if (list->key == theKey){
      
      if (list->next == NULL){   // 1 element list
         delete list;
         list = NULL;
      }
      else {                    // >1 element list
         list->next = ahead->next;
         delete ahead;
      }
      
      return true;   
   }
   
   // General case
   while(ahead!=NULL){
      
      if(ahead->key == theKey){ // check theKey in Node pointed by ahead pointer
         
         p->next = ahead->next;
         delete ahead;
         return true;
      }
      
      p = p->next;
      ahead = ahead->next;
   }
   
   return false; // unable to find theKey even after complete list traversal    
}


void listPrintAll(const ListType &list){
   
   Node * p = list;
   
   while(p!=NULL){
      cout << p->key << " " << p->value << endl;
      p = p->next;
   }
}


int listNumEntries(const ListType &list){
   
   int size = 0; // compute size of list
   Node *p = list;
   
   while(p!=NULL){
      size+=1; // incrementing size
      p=p->next;
   }
   
   return size;
}
