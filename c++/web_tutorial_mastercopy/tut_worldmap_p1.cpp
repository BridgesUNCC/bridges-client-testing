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
	bridges.setDescription("This example illustrates how to draw a world map of all countries");

	// create a data source
	DataSource ds(&bridges);

	// the following call without arguments will get the data for all countries. Alternately
	// you can specify that with an argument such {"all"}.
	// This construct allow for styling the countries
	// vector<Country>  wm_data = ds.getWorldMapData();

	// declare the world map object with the map data	
	WorldMap wm;

	bridges.setMap(wm);
	
	// visualize
	bridges.setDataStructure(&wm);
	bridges.visualize();
	
	return 0;
}
