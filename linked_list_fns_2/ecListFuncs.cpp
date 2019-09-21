/*  Name: Devendra Swami
 *  USC NetID: 1742427505
 *  CS 455 Spring 2019
 *
 *  See ecListFuncs.h for specification of each function.
 */


// for NULL
#include <cstdlib>

#include "ecListFuncs.h"

using namespace std;


int lastIndexOf(ListType list, int val) {
   
   int currIndex = 0;         // current index in list
   int valLastIndex = -1;     // last index where passed value is found in list
   
   while(list!=NULL){
      if (list->data==val){
         valLastIndex = currIndex;
      }
      list = list->next;
      currIndex++;
   }
   return valLastIndex;  
}


int longestNondecreasingSequence(ListType list) {
   
   int longestSeq = 0;       // stores value of longest sequence found
   int currSeq = 0;          // stores value of current sequence
   
   while(list!=NULL){
      
      currSeq++; // counts current element by incrementing current Sequence by 1
      
      /* Conditions when current sequence should be considered as candidate for longest sequence
      */
      if (list->next == NULL){  // true if currently at last node in the list 
         if (currSeq>longestSeq){
            longestSeq = currSeq;
         }
      }
      
      else if (list->data > list->next->data){ // true if current element greater than next element (marks end of current sequence)
         if (currSeq>longestSeq){
            longestSeq = currSeq;
         }
         currSeq = 0;
      }
      
      list = list->next; // continue parsing the list
   }   
   return longestSeq;  
}


void removeAdjacentEvens(ListType & list) {
   
   Node* temp = list;  // pointer to traverse list
   
   while(temp!=NULL && temp->next != NULL){ // continue till temp points to second last number & list length > 1

      if (temp->data%2 == 0){   // if current number is even
         
         while (temp->next->data%2 == 0){ // delete numbers until next number is odd
            
            Node* delptr = temp->next; // pointer to reclaim memory of number to be deleted 
            temp->next = temp->next->next;
            delete delptr;
            
            if (temp->next == NULL){ // temp points to last number
               return;
            }
         }
         
         temp = temp->next->next;  // incrementing pointer by two numbers as next element is odd
      }
      
      else {     // current element is odd, parse to next element
         temp = temp->next; 
      }
   } 
}


void mirror(ListType & list) {
   
   if (list == NULL){
      return;
   }
   
   Node* temp = list; // pointer to traverse list
   Node* addList = NULL; // pointer to new mirrored part to be added at the end of passed list
   
   while(temp->next!=NULL){
      insertFront(addList, temp->data);   
      temp = temp->next;
   }
   insertFront(addList, temp->data);
   temp->next = addList;  // mirror image added to original list
}


void rotateLeft(ListType & list, int k) {
   
   if(list == NULL || list->next == NULL || k<=0){
      return;
   }
   
   Node* first = list; // pointer to first number in list
   
   while(k>1){    // performing operations corresponding to k-1 rotation inside loop
      
      list=list->next;  // advancing list ptr to incorporate one rotation
      k--;
      
      if (list->next == NULL){  // k >= list length, points to first node again
         list = first;    
         return;
      }
   }
   
   /* 
   Performing operations corresponding to the last rotation 
   to ensure NULL at end of list(1:k) and list now points to (k+1)th no. where k<n
   */
   Node* temp = list->next;  
   list->next = NULL;        
   list = temp;   
   
   
   // Relinking of two lists from (k+1:n) and (1:k) where k<n
   while(temp->next!=NULL){   // traversing list to nth number
      temp=temp->next;
   }
   
   temp->next = first;  // relinks the first node to end of list
}
