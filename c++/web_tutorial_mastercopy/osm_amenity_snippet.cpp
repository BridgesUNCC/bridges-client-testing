#include "Bridges.h"
#include "DataSource.h"
#include <iostream>
#include <string>
#include "data_src/Amenity.h"

// An example illustrating how to extract amenity attributes from OpenStreetMap datasets
 
using namespace std;
using namespace bridges;

int main(int argc, char **argv) {

	// create Bridges object
#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);

	if (argc > 4)
		bridges.setServer(argv[4]);

	bridges.setTitle("An Amenity Data  Extraction from OpenStreet Map Example");
	bridges.setDescription("Extracting food amenities from Charlotte.");

#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif

	DataSource ds(bridges);
	vector<Amenity> amenities = ds.getAmenityData(38.77657, -77.20918, 39.03198, -76.8999, "food");
//	AmenityData amenity_data = ds.getAmenityData("Charlotte, North Carolina", "food");

	cout << "Total Amenities: " <<  amenities.size() << "\n";

	cout << "The first 5 amenities:\n";

	for (int k = 0; k < 5; k++) {
		cout << "[" << k <<  "]:\n";
		cout << "\tName: " <<  amenities[k].getName() << "\n";
		cout << "\tId: " <<  amenities[k].getId() << "\n";
		cout << "\tName: " <<  amenities[k].getName() << "\n";
		cout << "\tLatitude: " <<  amenities[k].getLat() << "\n";
		cout << "\tLongitude: " <<  amenities[k].getLon() << "\n";
	}
	
	return 0;
}
