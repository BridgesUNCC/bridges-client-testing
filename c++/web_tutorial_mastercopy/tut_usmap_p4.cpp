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
#include "Text.h"
#include "USMap.h"


#include "Polyline.h"
#include "Polygon.h"

using namespace bridges;

// this program illustrates how to access the data of the US state county
// maps and also draw symbols using the Bridges shape collection 
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
	bridges.setDescription("Example illustrates map data working with Bridges shape collection symbols");

	DataSource ds(&bridges);

	cout << "Retrieving US State County Map Data" << endl;

	vector<bridges::dataset::USState> map_data = ds.getUSMapData (); 
	USMap us_maps(map_data);
	bridges.setMap(us_maps);
	
	// create a circle symbol
	SymbolCollection sc;
		Circle c(-80.8431, 35.2271, 1.);
		c.setStrokeColor("red");
		c.setFillColor("cyan");

	Text l;
		float loc[2] = {-79.8431, 35.2271};
		l.setAnchorLocation(loc);
		l.setFontSize(18.0f);
		l.setStrokeWidth(1.0f);
		l.setText("Charlotte");
		l.setStrokeColor("purple");
		l.setOpacity(1.0f);
    sc.addSymbol(l);


	// create a rectangle symbol
	sc.addSymbol(c);
		Rectangle r(-82.998, 39.96, 1., 1.);
		r.setStrokeColor("red");
		r.setFillColor("lightgreen");
	sc.addSymbol(r);


	Text l2;
		float loc2[2] = {-81.998, 39.96};
		l2.setAnchorLocation(loc2);
		l2.setFontSize(18.0f);
		l2.setStrokeWidth(1.0f);
		l2.setText("Columbus");
		l2.setStrokeColor("purple");
		l2.setOpacity(1.0f);
    sc.addSymbol(l2);
	
	Polyline p3;
		p3.addPoint(-80, 41);
		p3.addPoint(-85, 41);
		p3.setStrokeColor("magenta");
		p3.setStrokeWidth(0.5f);
		p3.setOpacity(1.0f);
	sc.addSymbol(p3);

	// set data structure, visualize
	bridges.setDataStructure(sc);
	bridges.visualize();

	return 0;
}
