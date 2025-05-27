#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "WorldMap.h"

using namespace bridges;

int main(int argc, char **argv) {

	// create bridges object
#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
	if (argc > 4)
		bridges.setServer(argv[4]);
#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif

	// set title
	bridges.setTitle("Drawing a World Map");

	// set description
	bridges.setDescription("This example illustrates overlaying a data structure with a world map overlay");

	// create a data source
	DataSource ds(&bridges);


	// add a Graph object with nodes to represent cities in a few countries
	GraphAdjList<string> gr;
	gr.addVertex("Charlotte", "Charlotte,NC");
		gr.getVertex("Charlotte")->setLocation(-80.8431, 35.2271);
		gr.getVertex("Charlotte")->setColor("crimson");
		gr.getVertex("Charlotte")->setSize(2.);
	gr.addVertex("Paris", "Paris, France");
		gr.getVertex("Paris")->setLocation(2.3514, 48.8576);
		gr.getVertex("Paris")->setColor("crimson");
		gr.getVertex("Paris")->setSize(2.);
	gr.addVertex("Berlin", "Paris, France");
		gr.getVertex("Berlin")->setLocation(13.4, 52.52);
		gr.getVertex("Berlin")->setColor("crimson");
		gr.getVertex("Berlin")->setSize(2.);
	gr.addVertex("New Delhi", "New Delhi, India");
		gr.getVertex("New Delhi")->setLocation(77.208, 28.614);
		gr.getVertex("New Delhi")->setColor("crimson");
		gr.getVertex("New Delhi")->setSize(2.);
	gr.addVertex("Buenos Aires", "Buenos Aires, Argenina");
		gr.getVertex("Buenos Aires")->setLocation(-58.382, -34.60);
		gr.getVertex("Buenos Aires")->setColor("crimson");
		gr.getVertex("Buenos Aires")->setSize(2.);
	gr.addVertex("Esperanza Station, Antarctica", "Esperanza Station, Antarctica");
		gr.getVertex("Esperanza Station, Antarctica")->setLocation(-56.59, -63.24);
		gr.getVertex("Esperanza Station, Antarctica")->setColor("crimson");
		gr.getVertex("Esperanza Station, Antarctica")->setSize(2.);

	// add the world map
	vector<Country>  wm_data = ds.getWorldMapData();
	WorldMap wm (wm_data);
	bridges.setMap(wm);

	// visualize
	bridges.setDataStructure(&gr);
	bridges.visualize();
	
	return 0;
}
