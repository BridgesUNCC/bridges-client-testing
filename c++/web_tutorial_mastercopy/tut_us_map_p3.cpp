#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/USState.h"
#include "data_src/USCounty.h"
#include "USMap.h"

using namespace bridges;

// This program illustrates how to access the data of the US map with state
// boundaries with different colors for states and its boundaries
// Here we select 3 states and draw them with different attributes with or 
// without counties
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
	bridges.setTitle("Tutorial: Drawing US Map with States and Counties");
	bridges.setDescription("3 US states, with different attributes");

	// create a data source object
	DataSource ds(&bridges);
	
	// specify the states of interest
	vector<string> states = {"Vermont", "Iowa", "North Carolina"};
	
	// get us map data - all states and counties
	// we also retrieve the counties, using the second argument
	vector<bridges::dataset::USState> map_data = ds.getUSMapCountyData (states, true); 

	// we will draw the first state without counties and set fill and boundary 
	// colors - use the viewCounties() flag to ignore counties
	auto& s = map_data[0];
	s.setViewCountiesFlag(true);
	s.setStrokeColor(Color(255,0,0));
	s.setFillColor(Color(0,255,0));
	s.setViewCountiesFlag(false);

	// the second state  we will draw with counties and set their colors
	auto s2 = map_data[1];
	// iterate over the counties
	for (auto& c: s2.accessCounties()) {
		c.second.setStrokeColor(Color(50,250,50));
		c.second.setFillColor(Color(0,0,25));
	}

	// the third state will use default colors

	// create a USMap object with the map data
	USMap us_maps(map_data);

	// pass it to BRIDGES 
	bridges.setMap (us_maps);

	// Plot Charlotte, NC 
	SLelement<string>  *el0 = new SLelement<string> ("Charlotte", "Charlotte, Go Niners!");
	el0->setLocation(-80.8431, 35.2271); //35.2271N, 80.8431W

	// set the data structure
	bridges.setDataStructure(el0);

	//visualize
	bridges.visualize();

	delete el0;
	
	return 0;
}
