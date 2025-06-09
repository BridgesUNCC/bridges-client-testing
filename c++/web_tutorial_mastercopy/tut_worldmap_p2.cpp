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
	bridges.setDescription("This example illustrates how to draw a world map of a few countries");

	// create a data source
	DataSource ds(&bridges);

	// specify a few countries to draw their maps
	vector<string> countries = {"Brazil", "Argentina", "Germany", "France", "Spain", 
							"United States of America"};
	vector<Country>  wm_data = ds.getWorldMapData({countries});

	// lets change colors of each country
	wm_data[0].setFillColor(Color("lightgoldenrodyellow"));
	wm_data[1].setFillColor(Color("lightskyblue"));
	wm_data[2].setFillColor(Color("indigo"));
	wm_data[3].setFillColor(Color("orangered"));
	wm_data[4].setFillColor(Color("olive"));
	wm_data[5].setFillColor(Color("springgreen"));
	
	WorldMap wm (wm_data);
	
	bridges.setDataStructure(&wm);
	bridges.visualize();
	
	return 0;
}
