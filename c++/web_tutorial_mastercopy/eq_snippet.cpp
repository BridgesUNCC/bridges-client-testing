
#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/EarthquakeUSGS.h"


using namespace bridges;

int max_quakes = 100;

int main(int argc, char **argv) {

#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
	if (argc > 4)
		bridges.setServer(argv[4]);
#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");
#endif
	// read the earth quake  data and build the BST
	bridges.setTitle("Accessing USGIS Earthquake Data (USGIS Data)");

	DataSource ds (&bridges);
	vector<EarthquakeUSGS> eq_list = ds.getEarthquakeUSGSData(max_quakes);

	cout << "Earthquake 0:" << endl;
	cout << "\tMagnitude:" << eq_list[0].getMagnitude() << endl
		 << "\tDate:" << eq_list[0].getDateStr() << endl 
		 << "\tLocation: " <<  eq_list[0].getLocation() << endl
		 << "\tLat/Long:"  << eq_list[0].getLatit() << "," << 
		 			eq_list[0].getLongit() << endl;
		

	return 0;
}
