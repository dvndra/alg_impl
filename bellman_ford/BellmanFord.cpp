#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <unordered_set>
#include "BellmanFord.h"


using namespace std; 
 

BellmanFord::BellmanFord(vector< vector<int> > adjMatrix){
	adjMat = adjMatrix;
	numNodes= adjMatrix.size();
	shortestDist = new int[numNodes];  // array to store shortest distance of node i from start node
	previousNode = new int[numNodes];  // array to store which previous node yield shortest distance of node i from start node

}


void BellmanFord::allShortestPath(int start){
	
	// Initialising shortest distance to ith node from start node
	for(int i=0; i<numNodes; i++){
		shortestDist[i] = adjMat[start][i];
	}
	for (int i=0; i<numNodes; i++) {
    	previousNode[i] = start;    	// Initialize all elements to start
	}	

	//runs Bellman Ford algorithm (at most numNodes-1 iterations)
	int numItr = runAlgorithm();		

	if(isNegCycle()){						// prints negative cycle reachable from start node (if any)
		return;
	}

	// No negative cycle detected
	printShortestDist();				// to print shortest distance from start Node to all Nodes
	printAllPath(start);      				// to print all shortest path from start Node
	cout << "Iteration:" << numItr << '\n';
}

int BellmanFord::runAlgorithm(){

	bool changeFlag = true;					// tracks whether any of the values in shortestDist gets updated in an iteration
	int itr = 1;							// Iteration number in Bellman Ford
	// Run bellman ford
	for(;itr<numNodes && changeFlag;itr++){  // atmost n-1 iterations

		changeFlag = false;
		for(int i=0;i<numNodes;i++){			// calculating shortest distance to ith node

			for(int j=0;j<numNodes;j++){		// looping over all nodes to find shortest distance for ith node
				
				int edgeValue = adjMat[j][i];
				if(edgeValue!=INT_MAX && shortestDist[j]!=INT_MAX && shortestDist[i] > shortestDist[j] + edgeValue){
					shortestDist[i] = shortestDist[j] + edgeValue;
					changeFlag = true;
					previousNode[i] = j;	// jth node gave shortest distance to node i
				}
			}
		}	
	}
	return itr;
}

bool BellmanFord::isNegCycle(){

	// Check for negative cycle by running for an additional iteration and see if any value changes
	
	for(int i=0;i<numNodes;i++){			// calculating shortest distance to ith node

		for(int j=0;j<numNodes;j++){		// looping over all nodes to find shortest distance for ith node
			
			int edgeValue = adjMat[j][i];
			if(edgeValue!=INT_MAX && shortestDist[i] > shortestDist[j] + edgeValue){  // Found negative loop
				cout << "Output: Negative Loop Detected" << '\n';
				printNegCycle(i);
				return true;
			}
		}
	}	
	return false;
}

void BellmanFord::printNegCycle(int node){

	unordered_set<int> nodeSet;			// stores distinct nodes 
	nodeSet.insert(node);

	// continue storing untill previousNode[node] is already in set -> it is part of neg. cycle
	while(nodeSet.find(previousNode[node])!= nodeSet.end()){
		node = previousNode[node];
		nodeSet.insert(node);
	}

	// Found negative cycle involving previousNode[node]
	// Output this negative cycle 
	int startNode = previousNode[node];
	cout << startNode;
	int currentNode = previousNode[startNode];

	while(currentNode!=startNode){
		cout << "->" << currentNode;
		currentNode = previousNode[currentNode];
	}
	cout << "->" << currentNode << '\n';
}


void BellmanFord::printAllPath(int start){	

	for(int i=0;i<numNodes;i++){

		if (shortestDist[i]==INT_MAX){
			cout << i << ": No path from node " << start;
		}
		else if (i==start){
			cout << i;
		}

		else {

			stack<int> pathStack;    // stack to store all nodes visited to reach node i from startNode
			pathStack.push(i);
			int previous = previousNode[i]; 
			pathStack.push(previous);

			while (previous!=start){			
				previous = previousNode[previous];	
				pathStack.push(previous);		
			}

			// Output all nodes visited to reach node i from startNode
			while (!pathStack.empty()){

				cout << pathStack.top();
				pathStack.pop();
				if(!pathStack.empty()){
					cout << "->";
				}
			}
		}
		cout << "\n";
	}
}

void BellmanFord::printShortestDist(){
	
	for(int i=0;i<numNodes;i++){
			
		if(shortestDist[i]==INT_MAX){
			cout << "inf,"; 
		}
		else {
			cout << shortestDist[i] << ",";
			
		}
	}
	cout << '\n';
}