// Name: Devendra Swami
// USC NetID: 1742427505
// EE 450 HW0
// Summer 2019


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to not put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//function headers (aka, function prototypes):
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).

// PRE: all functions are called upon well formed list.
//*************************************************************************


// insert a new key value pair into the linked list
// return false iff this key was already present 
// (and no change made to table)
bool listInsert(ListType &list, const std::string &key, int value);


// returns the address of the value that goes with this key
// or NULL if key is not present in the list.
// Thus, this method can be used to either lookup the value or   
// update the value that goes with this key.
int * listLookup(const ListType &list, const std::string &key);


// remove a pair given its key
// false iff key wasn't present in the list
bool listRemove(ListType &list, const std::string &key);


// print out all the entries in the list, one per line.
// Sample output:
//   zhou 283
//   sam 84
//   babs 99
void listPrintAll(const ListType &list);

int listNumEntries(const ListType &list);      // return number of entries in the list

#endif
