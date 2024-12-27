#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/USState.h"
#include "data_src/USCounty.h"
#include "USMap.h"

using namespace bridges;

// This tutorial illustrates how to access the data of the US map with state
// boundaries with different colors for states and its boundaries
// It also illustrates how to draw all the counties 
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
	bridges.setTitle("Tutorial: Drawing US Map with State Boundaries, and State Counties");
	bridges.setDescription("All US states, All Counties");

	// create a data source object
	DataSource ds(&bridges);
	
	// get us map data - all states and counties
	vector<bridges::dataset::USState> map_data = ds.getUSMapCountyData (); 

	// create a USMap object with the map data
	USMap us_maps(map_data);

	// set the data structure to the map
	bridges.setDataStructure(&us_maps);

	//visualize
	bridges.visualize();
	
	return 0;
}
