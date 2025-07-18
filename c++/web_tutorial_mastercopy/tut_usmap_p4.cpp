#include <string>
#include <vector>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/USState.h"
#include "data_src/USCounty.h"
#include "SymbolCollection.h"
#include "Circle.h"
#include "Rectangle.h"
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
	bridges.setTitle("Accessing US State County Maps Example with Symbols");

	DataSource ds(&bridges);

	cout << "Retrieving US State County Map Data" << endl;

	vector<bridges::dataset::USState> map_data = ds.getUSMapData (); 
	USMap us_maps(map_data);
	bridges.setMap(us_maps);
	
	// use a circle symbol
	SymbolCollection sc;
		Circle c(-80.8431, 35.2271, 15.);
		c.setStrokeColor("red");
		c.setFillColor("cyan");
	sc.addSymbol(c);
		Rectangle r(-82.998, 39.96, 25., 25.);
		r.setStrokeColor("red");
		r.setFillColor("lightgreen");
	sc.addSymbol(r);
		
	bridges.setDataStructure(sc);

	bridges.visualize();

	return 0;
}
