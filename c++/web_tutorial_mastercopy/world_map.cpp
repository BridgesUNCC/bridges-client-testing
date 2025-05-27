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
	bridges.setTitle("Using World Map overlay");

	DataSource ds(&bridges);
	 vector<string> countries = {"Australia", "Germany", "France", "Spain", "United States of America"};
	vector<Country>  wm_data = ds.getWorldMapData({countries});
//	vector<Country>  wm_data = ds.getWorldMapData();

	for (auto k = 0; k < wm_data.size(); k++) {
		wm_data[k].setFillColor(Color("lightblue"));
		wm_data[k].setStrokeColor(Color("green"));
		wm_data[k].setStrokeWidth(1.);
	}
	
	WorldMap wm (wm_data);
	
	bridges.setDataStructure(&wm);
	bridges.visualize();
	
	return 0;
}
