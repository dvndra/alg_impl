#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>
#include <regex>
#include "BellmanFord.h"

using namespace std;  

vector< vector<int> > readData(string filename);
int processEdge(string word);

int main(int argc, char* argv[]){
	if (argc > 1) {
      string filename = string(argv[1]);  // converts c-string to C++ string
      vector< vector<int> > adjMatrix = readData(filename); // read adjacency matrix
      BellmanFord problem (adjMatrix);
      problem.allShortestPath(0);            // all shortest path from node 0
      
   }
   else {   // no command line args given 
      cout << "Command line argument must supply filename for adjacency matrix" << endl;
      return 1;
   }
}


// Function to read adjacency matrix from input string filename 
// Returns: adjacency matrix for supplied graph 

vector< vector<int> > readData(string filename){
   
   ifstream file (filename);
   vector< vector<int> > adjMatrix;   // adjacency matrix for supplied graph
      
   if (file.is_open()) {  // successfully opens file

      string line;                       // stores a line from file as string                     
      string edgeValue;                  // stores value of an edge from file                        
               
      for (int i = 0; getline(file,line); i++){  // populate adjMatrix
         vector<int> row;    
         stringstream scanner(line);
         while (scanner >> edgeValue){
            row.push_back(processEdge(edgeValue));            
         } 
         if(row.size()>0){    // not a empty row 
            adjMatrix.push_back(row);   
         }              
      }

      file.close();      
   }

   else {
      cout << "Unable to open file " << filename << '\n';
      exit (EXIT_FAILURE);    
   }
   return adjMatrix; 
}


// Function to return integer edge value from a string
// of format 'num' or ['num','num','num']

int processEdge(string word){
   
   if (word == "inf"){
      return INT_MAX;
   }

   regex multiCost("(\\[)(.*)");     // regex to see if multiple cost are provided for an edge
   
   if(!regex_match(word, multiCost)) {    // format 'num'
      return atoi(word.c_str());
   }

   else {
      // removing square brackets
      int i = 0;
      while(i < word.size())
      {
         if(word[i] == '[' || word[i] == ']'){
            word.erase(i,1);
         } 
         else {
            i++;
         }
      }
      
      int value = 0;      // to store numeric edge value       
      stringstream input_word(word);
      string parsed;
      while(getline(input_word, parsed,',')){
         value = value + atoi(parsed.c_str());
      }
      return value; 
   } 
}