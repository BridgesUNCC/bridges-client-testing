#include "Bridges.h"
#include "DataSource.h"
#include "GraphAdjList.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include "data_src/OSMData.h"
#include "data_src/OSMVertex.h"
#include "data_src/OSMEdge.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {

#if TESTING
                        // command line args provide credentials and server to test on
    Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
    
    if (argc > 4)
        bridges.setServer(argv[4]);

    bridges.set_title("An Open Street Map Example");
    bridges.set_description("Illustrates the road map of the UNC Charlotte Campus.");
            
#else
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif

	//create the Bridges object, set credentials

	bridges.setServer("clone");

	DataSource  *ds = new DataSource;
/*
	OSMData osm_data = ds->getOSMData("uncc_campus");
*/
	OSMData osm_data = ds->getOSMData("charlotte");
/*
	OSMData osm_data = ds->getOSMData("washington_dc");
	OSMData osm_data = ds->getOSMData("saint_paul");
	OSMData osm_data = ds->getOSMData("new_york");
	OSMData osm_data = ds->getOSMData("los_angeles");
	OSMData osm_data = ds->getOSMData("san_francisco");
	OSMData osm_data = ds->getOSMData("miami");
	OSMData osm_data = ds->getOSMData("minneapolis");
	OSMData osm_data = ds->getOSMData("dallas");
*/

/*
				// Dont work - data too large
	OSMData osm_data = ds->getOSMData("houston");
	OSMData osm_data = ds->getOSMData("chicago");
*/

	vector<OSMVertex> vertices = osm_data.getVertices(); 
	vector<OSMEdge> edges = osm_data.getEdges(); 

	GraphAdjList<int, int>  *gr = new GraphAdjList<int, int>;
	double coords[2];

	for (int k = 0; k < vertices.size(); k++) {
		gr->addVertex(k);
		vertices[k].getCartesianCoords(coords);
		gr->getVertex(k)->setLocation(coords[0], coords[1]);
		gr->getVertex(k)->setColor(Color("green"));
    }
    for (int k = 0; k < edges.size(); k++) {
      gr->addEdge(edges[k].getSourceVertex(), edges[k].getDestinationVertex(), 
                 edges[k].getEdgeLength() );
      gr->getLinkVisualizer(edges[k].getSourceVertex(), edges[k].getDestinationVertex())->setColor(Color("red")); 
		
    }

	bridges.setDataStructure(gr);
	bridges.visualize();

						// create graph object
	
	return 0;
}
