#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/State.h"
#include "data_src/County.h"
#include "USMap.h"

using namespace bridges;

// this program illustrates how to access the data of the US state county
// maps and apply attributes to them
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
	bridges.setTitle("Accessing US State County Maps");

	DataSource ds(&bridges);

	cout << "Retrieving US State County Map Data" << endl;


	// vector<string> states = {"Vermont", "Iowa", "North Carolina"};
	vector<string> states = {"all"};
	vector<bridges::dataset::State> map_data = ds.getUSStateCountyMapData (states);
	{
	  auto& s = map_data[0];
	  s.setViewCountiesFlag(true);
	  s.setStrokeColor(Color(255,0,0));
	  s.setFillColor(Color(0,255,0));
	  s.setViewCountiesFlag(false);
	}
	{
	  auto& s = map_data[1];

	  for (auto& c: s.accessCounties()) {
	    c.second.setStrokeColor(Color(50,250,50));
	    c.second.setFillColor(Color(0,0,25));
	  }
	}
	USMap us_maps(map_data);
	bridges.setMap(us_maps);
	
	SLelement<string>  *el0 = new SLelement<string> ("Charlotte", "Go Niners!");
	el0->setLocation(-80.8431, 35.2271); //35.2271N, 80.8431W
	
	
	bridges.setDataStructure(el0);
	bridges.visualize();

	return 0;
}
