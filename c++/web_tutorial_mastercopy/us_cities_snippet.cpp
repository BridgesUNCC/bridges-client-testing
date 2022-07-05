#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/USCities.h"

using namespace bridges;

// this program illustrates how to access the data of the US and World 
//	city data
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
	bridges.setTitle("Accessing US City data");

	// read the Gutenberg book data
	DataSource ds (&bridges);

	cout << "Retrieving a set of US cities" << endl;

	// parameters to the query are through an unordered map

	// return 100 cities in the US
	unordered_map<string, string> city_params {
		{"limit","10"}
	};
try{	
	vector<USCities>  us_cities = ds.getUSCities(city_params);// Moby Dick
	cout << "US Cities:\n";
	for (auto c : us_cities)
		cout << "\n" << c.getCity() << "\n";

	}
	catch (string s) {

	cout << s;
}
	return 0;
}
