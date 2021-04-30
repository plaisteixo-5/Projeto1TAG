/** 
 *  Author: Felipe Fon
 *  TAG 2020-2 project 1
 *  This file have all functions and variables
 *  to execute the project.
 */

#include "iostream"
#include "Graph.h"
#include "iostream"
#include "fstream"
#include "vector"
#include "algorithm"
#include "Graph.h"

// Global variables
// ====================================================
vector<vector<int>> maximal_clique;                    // -> Variable to put all cliques on graph.
// ====================================================

// Functions
// ====================================================

// QUal fsdiuhus?/


/** 
 *  This function recive the graph to print on terminal
 *  @param graph is a vector of vectors of integers used to represent.
 *  all the graph.
 * 
 *  @return void 
 * **/
void showGraph(vector<int> graph[]){

    for(int i = 1 ; i < 63 ; i++){
        
        cout << i;

        for(auto x : graph[i]) cout << " -> " << x;
    
        cout << endl;
    
    }
}

/** 
 *  This function shows all cliques found on the graph.
 * 
 *  @return void 
 * **/
void showCliques(){

    int flag;
    flag = 0;

    cout << "Cliques: " << endl;

    for(auto value : maximal_clique){

        cout << "Número de vértices: " << value.size() << endl;

        cout << "[";
        for(auto value2 : value){

            flag++;

            if(value.size() == flag) {

                flag = 0;
                cout << value2 << "]" << endl;

            } else cout << value2 << ", ";
        
        }
    }
}

/** 
 *  Function to verify if the edges in R 
 *  is already in the variable maximal_clique.
 *  @param R is a vector of integers with all edges 
 *  that have been visited.
 * 
 * @return bool
 * **/
bool verifyRepeatClique(vector<int> R){

    int cont = 0;
    int sizeClique;

    for(vector<int> cliques : maximal_clique){

        sizeClique = cliques.size();
        
        for(int i : R){
        
            for(int clique : cliques){

                if(clique == i) cont++;
            
            }
        }

        if(cont == sizeClique) return false;
        cont = 0;

    }

    return true;
}

bool verifyVertex(vector<int> graph[], int vertex1, int vertex2){
    for(auto element : graph[vertex1]){
        if(element == vertex2) return true;
    }  

    return false;  
}

/**
 * Function to calculate the coefficient of graph.
 * @param graph is a vector of vectors of integers with all graph.
 * 
 * @return double **/
double calculaCoeficiente(vector<int> graph[]){

    int triangulo = 0;
    double coeficienteAglomeração = 0.0, coeficienteMedio = 0.0;

    for(int i = 1 ; i < 63 ; i++){

        triangulo = 0;
        
        for(auto elementVertex : graph[i]){
            for(auto vertex : graph[elementVertex]){
                if(vertex == i) triangulo++;
            }
        }

        if(graph[i].size() > 1) coeficienteAglomeração += (double) ( 2 * triangulo / ( graph[i].size() * (double) ( graph[i].size() - 1 )));
       
    }
    coeficienteMedio = (double) ( ( 1.0 / 62.0 ) * coeficienteAglomeração )/2;

    return coeficienteMedio;
}

/** 
 *  Function to add a edge in R
 *  @param edge int value of some edge.
 *  @param R vector of integers with all edges that was
 *      visited.
 * 
 * @return vector<int>
 * **/
vector<int> Union(vector<int> R, int edge){

    R.push_back(edge);
    
    return R;
}

/** 
 *  A function to verify all intersections 
 *  between P or X elements and all the 
 *  graph in a specific edge.
 *  @param vector_of_elements vector of integers of X or P elements, 
 *      used as a base to find all same elements in some edge of
 *      all graph.
 *  @param adj_vector vector of vectors of integers that represents 
 *      all the graph.
 *  @param edge int value that represents a edge in the graph.
 * 
 * @return vector<int>
 * **/
vector<int> Intersections(vector<int> adj_vector[], vector<int> vector_of_elements, int edge){

    vector<int> intersection = {};

    for(int edge_graph : vector_of_elements){

        for(int edge_ajd_vector : adj_vector[edge]){

            if(edge_graph == edge_ajd_vector) intersection.push_back(edge_graph);
        }
    }

    return intersection;
}

/** 
 *  The main function, used to calculate all cliques in the graph.
 *  @param R is a vector of integers used to store all possible cliques.
 *  @param P is a vector of integers with all intersection edges.
 *      present in R.
 *  @param X vector of integers with all edges that were already visited.
 *  @param graph vector of vectors of integers that represents all the 
 *      graph.
 *      
 * @return void
 * **/
void BronKerbosch(vector<int> R, vector<int> P, vector<int> X, vector<int> graph[]){
    
    vector<int> p_new, r_new, x_new;

    if(P.empty() && X.empty()){

        if(verifyRepeatClique(R)) maximal_clique.insert(maximal_clique.end(), R);

    } else {
        
        for(auto edge_p : P){

            r_new = Union(R, edge_p);
            p_new = Intersections(graph, P, edge_p);
            x_new = Intersections(graph, X, edge_p);

            BronKerbosch(r_new, p_new, x_new, graph);

            P.erase(remove(P.begin(), P.end(), edge_p), P.end());
            X.push_back(edge_p);
        
        }
    }
}

/** 
 *  Function used to add vertex in the graph.
 *  @param graph is a vector of vectors of integers with all graph.
 *  @param values is a vector of integers with two values. We save
 *      the edges in the graph like this because it's a 
 *      undirected graph.
 *      
 * @return void
 * **/
void addEdge(vector<int> graph[], int values[]){

    graph[values[0]].push_back(values[1]);
    graph[values[1]].push_back(values[0]);

}
// ====================================================