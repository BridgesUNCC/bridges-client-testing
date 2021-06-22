#include <string>
#include "Bridges.h"
#include "DataSource.h"
#include "GraphAdjList.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);

	if (argc > 4)
		bridges.setServer(argv[4]);

	// set a title for the visualization
	bridges.setTitle("A Simple Graph (Adjacency List) Example using IMDB Actor/Movie Data");
	bridges.setDescription("Two lists each having an actor as the root node with 15 movies they played in as leaf nodes. "
		"Root nodes are both red, Kevin Bacon's leaf nodes are green and Denzel Washington's leaf nodes are neutral.");

#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");
#endif

	// create a graph
	GraphAdjList<string, string, int> graph;

	string kevin_bacon = "Kevin_Bacon_(I)", denzel_washington = "Denzel_Washington", noone= "NoOne";

	graph.addVertex(kevin_bacon, "");
	graph.addVertex(denzel_washington, "");
	graph.addVertex(noone, "");

	graph.addEdge(kevin_bacon, denzel_washington, 1);

	


	for (auto& edge : graph.outgoingEdgeSetOf(kevin_bacon)) {
		string from = edge.from(), to = edge.to();
		if (to != "Denzel_Washington")
			graph.getVisualizer(to)->setColor("turquoise");
	}
	for (auto& edge : graph.outgoingEdgeSetOf(denzel_washington)) {
		string from = edge.from(), to = edge.to();
		if (to != kevin_bacon)
			graph.getVisualizer(to)->setColor("orange");
	}
	for (auto& edge : graph.outgoingEdgeSetOf(noone)) {
		string from = edge.from(), to = edge.to();
		if (to != kevin_bacon)
			graph.getVisualizer(to)->setColor("orange");
	}

	
	
	return 0;
}
