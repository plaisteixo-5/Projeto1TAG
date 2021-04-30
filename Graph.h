#ifndef GRAPH_H
#define GRAPH_H

#include "iostream"
#include "fstream"
#include "vector"
#include "vector"
#include <algorithm>
#include "Graph.h"

#ifdef _WIN32
    #define clear "cls"
#else
    #define clear "clear"
#endif

using namespace std;

bool verifyRepeatClique(vector<int> R);

bool verifyPAndXEmpty(vector<int> P, vector<int> X, vector<int> R);

double calculaCoeficiente(vector<int> graph[]);

vector<int> Union(vector<int> R, int edge);

vector<int> Intersections(vector<int> adj_vector[], vector<int> vector_of_elements, int edge);

void showGraph(vector<int> graph[]);

void showCliques();

void BronKerbosch(vector<int> R, vector<int> P, vector<int> X, vector<int> graph[]);

void addEdge(vector<int> graph[], int values[]);

#endif