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

	for (int k = 0; k < 3; k++) {
		cout << "State:" << map_data[k].getStateName() << endl;
		auto& s = map_data[k];
		if (map_data[k].getStateName() == "Iowa") {
			s.setStrokeColor(Color(255,0,0,100));
			s.setFillColor(Color(0,255,0));
			s.setViewCountiesFlag(false);
		}
		else if (map_data[k].getStateName() == "North Carolina") {
			auto& s = map_data[k];
			// iterate over the counties
			for (auto& c: s.accessCounties()) {
				c.second.setStrokeColor(Color(50,250,50));
				c.second.setFillColor(Color(0,0,255, 100));
			}
		}
		else {
			;
			// the third state will use default colors
		}
	}

	// create a USMap object with the map data
	USMap us_maps(map_data);

	// set the data structure
	bridges.setDataStructure(&us_maps);

	//visualize
	bridges.visualize();
	
	return 0;
}
