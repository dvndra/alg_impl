#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include <vector>


// Class to represent a mathematical graph using adjacency Matrix as input

class BellmanFord{
	
	public:

	// Constructor	
	BellmanFord(std::vector< std::vector<int> > adjMat);

	// Method to print shortest distance and shortest path using
	// Bellman Ford Algorithm from start Node to all Nodes in this Graph.
	// Prints negative cycle detected instead if there exist a negative cycle
	// reachable from start Node.
	// @input param start: start Node
	void allShortestPath(int start);

	private:
	// Instance variables; 
	std::vector< std::vector<int> > adjMat;  // 2D vector to store adjacency Matrix
	int numNodes;							 // number of nodes in graph 
	int * shortestDist;  					 // array to store shortest distance of node i from start node
	int * previousNode;  // array to store which previous node yield shortest distance of node i from start node

	// Method to run Bellman Ford algorithm (at most numNodes-1 iterations)
	// Runs from start Node (in allShortestPath)
	// @return: no.of iterations in Bellman Ford
	int runAlgorithm();

	// Method to find if there is a negative cycle reachable from start Node (in allShortestPath)
	// prints negative cycle (if found) by calling printNegCycle
	// @return: true iff there is a negative cycle reachable from start Node
	bool isNegCycle();

	// Method to print negative cycle reachable to node
	// @input param node: negative cycle reachable to this node
	void printNegCycle(int node);  

	// Method to print all shortest distance from start Node 
	// Uses results of Bellman Ford Algorithm run from start Node (in allShortestPath)
	void printShortestDist();

	// Method to print all shortest path from start Node 
	// Uses results of Bellman Ford Algorithm 
	// @input param start: start Node for all paths
	void printAllPath(int start);
};

#endif