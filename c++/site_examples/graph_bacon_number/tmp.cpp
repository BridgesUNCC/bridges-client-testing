#include <iostream>
#include <string>
#include "GraphAdjList.h"
#include "SLelement.h"
#include "Edge.h"

using namespace std;

int main() {

GraphAdjList<string, string> gr;

SLelement<Edge>* sle = gr.getAdjacencyList("test");

return 0;
}
