# Makefile for EE 450 Lab 1
#
#
#    make main
#	 Makes main executable.  (This is a test driver for your list functions)

# compile options to be used in all compile commands
#     NOTE: $(CXXFLAGS) in the compile commands below will be replaced by the options after the =

CXXFLAGS = -ggdb -Wall -Wno-sign-compare -std=c++11

BellmanFord.o: BellmanFord.cpp BellmanFord.h
	g++ $(CXXFLAGS) -c BellmanFord.cpp

main.o: main.cpp BellmanFord.h 
	g++ $(CXXFLAGS) -c main.cpp

main: main.o BellmanFord.o
	g++ $(CXXFLAGS) -o main main.o BellmanFord.o 


