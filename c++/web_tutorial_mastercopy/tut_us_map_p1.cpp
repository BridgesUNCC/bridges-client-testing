#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/USState.h"
#include "data_src/USCounty.h"
#include "USMap.h"

using namespace bridges;

// this program illustrates how to access the data of the US map with state
// boundaries with different colors for states and its boundaries
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
	bridges.setTitle("Tutorial: Drawing US Map with State Boundariess");
	bridges.setDescription("All US states, No Counties");

	// create a data source object
	DataSource ds(&bridges);
	
	// get us map data - states and boundaries
	vector<bridges::dataset::USState> map_data = ds.getUSMapData (); 

	// create a USMap object with the map data
	USMap us_maps(map_data);

	// pass it to BRIDGES 
	bridges.setMap (us_maps);

	// Plot Charlotte, NC 
	SLelement<string>  *el0 = new SLelement<string> ("Charlotte", "Go Niners!");
	el0->setLocation(-80.8431, 35.2271); //35.2271N, 80.8431W

	// set the data structure
	bridges.setDataStructure(el0);

	//visualize
	bridges.visualize();

	delete el0;
	
	return 0;
}
