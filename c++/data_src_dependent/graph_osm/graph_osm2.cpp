#include "Bridges.h"
#include "DataSource.h"
#include "GraphAdjList.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

using namespace bridges;

double degree_to_rad(double d) {
	return d*M_PI/180.;
}

				
void latlongToCartesianCoords (double lat, double longit, double *cartesian_coords) {

	double R = 6378; // Radius of the earth in KM

	double lat_rad  = degree_to_rad(lat);
	double longit_rad  = degree_to_rad(longit);
	cartesian_coords[0] = R * cos(lat_rad) * cos (longit_rad);
	cartesian_coords[1] = R * cos(lat_rad) * sin (longit_rad);
//	cartesian_coords[1] = R * sin(lat_rad);
}

const int num_vertices = 1885;
const int num_edges = 2647;
string vertex_filename = "vertices.txt";
string edges_filename = "edges.txt";

int main(int argc, char **argv) {

	//create the Bridges object, set credentials
    Bridges *bridges =  new Bridges(12, "kalpathi60", "486749122386");

	
	bridges->setTitle("Graph : OpenStreet Map Example");

						// create graph object
	GraphAdjList<int, int> graph;

					// read and create  the vertices
	ifstream vert_file(vertex_filename.c_str());
	long vert_id;
	double lat, longit;
	unordered_map<long, int> vert_map;
	double lat_range[] = {10000., -10000.}, 
			longit_range[] = {10000., -10000.};
	double cartesian_coords[2];
	cout << "long is " << sizeof(long) << " bytes.."  << endl;
	for (int k = 0; k < num_vertices; k++) {
		vert_file >> vert_id >> lat >> longit; 	

		cartesian_coords[0] = lat; cartesian_coords[1] = longit;
								// convert to cartesian coords
		latlongToCartesianCoords (lat, longit, cartesian_coords);
		
								// remap vertex ids to 0..maxVertices
		vert_map[vert_id] = k;
								// compute lat/long range
		lat_range[0]  = std::fmin(cartesian_coords[0], lat_range[0]); 
		lat_range[1]  = std::fmax(cartesian_coords[0], lat_range[1]); 
		longit_range[0]  = std::fmin(cartesian_coords[1], longit_range[0]); 
		longit_range[1]  = std::fmax(cartesian_coords[1], longit_range[1]);
								// add vertext to graph
		graph.addVertex(k, 0);
								// set its location
		graph.getVertex(k)->getVisualizer()->setLocation(cartesian_coords[0], cartesian_coords[1]);
//		graph.getVertex(k)->getVisualizer()->setSize(1.0f);
		graph.getVertex(k)->getVisualizer()->setColor(Color("green"));
	}
	cout << "Range: Lat: " << lat_range[0] << "," << lat_range[1] << endl;
	cout << "Range: Longit: " << longit_range[0] << "," << longit_range[1] << endl;

								// compute center of bounding box
	double center_x = lat_range[0] + (lat_range[1]-lat_range[0])/2.;
	double center_y = longit_range[0] + (longit_range[1]-longit_range[0])/2.;

	double y_range[] = {1000000., -10000000.};
	for (int k = 0; k < num_vertices; k++) {
		cartesian_coords[0] = graph.getVertex(k)->getVisualizer()->getLocationX();
		cartesian_coords[1] = graph.getVertex(k)->getVisualizer()->getLocationY();
						// translate by the center and scale up
		double loc_x = (cartesian_coords[0] - center_x)*1000;
		double loc_y = (cartesian_coords[1] - center_y)*1000;
		y_range[0] = std::fmin(loc_y, y_range[0]);
		y_range[1] = std::fmax(loc_y, y_range[1]);
		graph.getVertex(k)->getVisualizer()->setLocation(cartesian_coords[0], cartesian_coords[1]);
	}
	for (int k = 0; k < num_vertices; k++) {
	 	double loc_x = graph.getVertex(k)->getVisualizer()->getLocationX();
	 	double loc_y = graph.getVertex(k)->getVisualizer()->getLocationY();
		graph.getVertex(k)->getVisualizer()->setLocation(loc_x, y_range[1]-loc_y);
	}
								// now get to the edges
								// visualize 
	bridges->setDataStructure(&graph);

								// visualize the graph
	ifstream edges_file(edges_filename.c_str());
	long v1, v2; 
	double dist;

	for (int k = 0; k < num_edges; k++) {
		edges_file >> v1 >> v2 >> dist;
				// check if vertices exist
		if (vert_map.find(v1) == vert_map.end() || vert_map.find(v2) == vert_map.end()) {
			cout << "Vertex not found!! Exiting.." << endl;
			exit(0);
		}
		int v1a = vert_map[v1], v2a = vert_map[v2];
		graph.addEdge (v1a, v2a, int(dist));
		graph.getLinkVisualizer(v1a, v2a)->setColor(Color("orange"));	
		graph.getLinkVisualizer(v1a, v2a)->setThickness(5.0f);	
	}

	bridges->setServer("clone");
	bridges->setCoordSystemType("window");
//	bridges->setWindow(lat_range[0], longit_range[0], lat_range[1], longit_range[1]);
	bridges->setWindow(longit_range[0], lat_range[0], longit_range[1], lat_range[1]);
	bridges->setVisualizeJSONFlag(true);
	bridges->visualize();
	
	return 0;
}
