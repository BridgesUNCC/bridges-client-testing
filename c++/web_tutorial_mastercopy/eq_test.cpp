
#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/EarthquakeUSGS.h"


using namespace bridges;


// This program fragment illustrates how to access the USGS earthquake data
int main(int argc, char **argv) {

	// create Bridges object
#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
	if (argc > 4)
		bridges.setServer(argv[4]);
#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");
#endif
	// set title
	bridges.setTitle("Accessing USGIS Earthquake Data (USGIS Data)");

	// read the earth quake  data
	DataSource ds (&bridges);
	int max_quakes = 100;
	vector<EarthquakeUSGS> eq_list = ds.getEarthquakeUSGSData(max_quakes);

	// print the first quake record
	for (int k = 0; k < 3; k++) {
		cout << "Earthquake " << k << ": \n";
		cout << "\tMagnitude:" << eq_list[0].getMagnitude() << endl
		<< "\tDate:" << eq_list[0].getDateStr() << endl
		<< "\tLocation: " <<  eq_list[0].getLocation() << endl
		<< "\tLat/Long:"  << eq_list[0].getLatit() << "," <<
		eq_list[0].getLongit() << endl;
	}

	eq_list = ds.getEarthquakeUSGSData(); //This is a different code path

	// print the first quake record
	for (int k = 0; k < 3; k++) {
		cout << "Earthquake " << k << ": \n";
		cout << "\tMagnitude:" << eq_list[0].getMagnitude() << endl
		<< "\tDate:" << eq_list[0].getDateStr() << endl
		<< "\tLocation: " <<  eq_list[0].getLocation() << endl
		<< "\tLat/Long:"  << eq_list[0].getLatit() << "," <<
		eq_list[0].getLongit() << endl;
	}

	

	return 0;
}
