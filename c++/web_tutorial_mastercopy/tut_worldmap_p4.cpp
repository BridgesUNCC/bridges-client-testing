#include <string>
#include <vector>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "WorldMap.h"

#include "SymbolCollection.h"
#include "Circle.h"
#include "Polyline.h"
#include "Rectangle.h"
#include "Text.h"

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
	bridges.setDescription("This example illustrates overlaying symbols to label cities on a world map overlay");

	// create a data source
	DataSource ds(&bridges);


	// add symbols 
	SymbolCollection sc;

	// plot a bunch of cities
	Circle c(-80.8431, 35.2271, 1.8);
		c.setStrokeColor("red");
		c.setFillColor("cyan");
	sc.addSymbol(c);

	Text l;
		float loc[2] = {-79.8431, 35.2271};
		l.setAnchorLocation(loc);
		l.setFontSize(12.0f);
		l.setStrokeWidth(1.0f);
		l.setText("Charlotte");
		l.setStrokeColor("purple");
		l.setOpacity(1.0f);
    sc.addSymbol(l);

	Circle c2(2.3514, 48.8576, 1.);
		c2.setStrokeColor("red");
		c2.setFillColor("cyan");
	sc.addSymbol(c2);

	Text l2;
		float loc2[2] = {3.3514, 48.8576};
		l2.setAnchorLocation(loc2);
		l2.setFontSize(12.0f);
		l2.setStrokeWidth(1.0f);
		l2.setText("Paris");
		l2.setStrokeColor("purple");
		l2.setOpacity(1.0f);
    sc.addSymbol(l2);

	Circle c3(13.4, 52.52, 1.);
		c3.setStrokeColor("red");
		c3.setFillColor("cyan");
	sc.addSymbol(c3);

	Text l3;
		float loc3[2] = {14.4, 52.52};
		l3.setAnchorLocation(loc3);
		l3.setFontSize(12.0f);
		l3.setStrokeWidth(1.0f);
		l3.setText("Berlin");
		l3.setStrokeColor("purple");
		l2.setOpacity(1.0f);
    sc.addSymbol(l3);
	
	// add the world map
	vector<Country>  wm_data = ds.getWorldMapData();
	WorldMap wm (wm_data);
	bridges.setMap(wm);

	// visualize
	bridges.setDataStructure(sc);
	bridges.visualize();
	
	return 0;
}
