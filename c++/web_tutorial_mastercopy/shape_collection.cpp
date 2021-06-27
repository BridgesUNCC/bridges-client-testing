#include "Bridges.h"
#include "SymbolCollection.h"
#include "SymbolGroup.h"
#include "Rectangle.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Circle.h"
#include "Text.h"

using namespace bridges;

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

	// title, description
	bridges.setTitle("Symbol Collection");
	bridges.setDescription("Red square, green circle, magenta horizontal and vertical lines, "
		"and a test label with a purple outline.");


	// create some symbols and add to symbol collection
	SymbolCollection sc;

	// draw a rectangle
	Rectangle s1(-50, 0, 25, 25);
	s1.setFillColor(Color("red"));
	s1.setOpacity(0.1f);
//	sc.addSymbol(&s1);

	
	// and a circle next to it
	Circle s2(50, 0, 25);
	s2.setFillColor(Color("green"));
	s2.setOpacity(1.0f);
//	sc.addSymbol(&s2);

	// draw a triangle above
	SymbolGroup g;
		g.translate(3., 10.);
		g.addSymbol(&s1);
		g.addSymbol(&s2);

	SymbolCollection sc2;
		sc2.addSymbol (&g);

	Polygon s3;
	s3.addPoint(-25, -10);
	s3.addPoint(25, -10);
	s3.addPoint(0, 50);
	s3.setStrokeColor("darkorchid");
	s3.setStrokeWidth(2.0f);
	s3.setOpacity(1.0f);
	sc.addSymbol(&s3);

	// draw axes
	Polyline s4;
	s4.addPoint(-100, 0);
	s4.addPoint(100, 0);
	s4.setStrokeColor("magenta");
	s4.setStrokeWidth(2.0f);
	s4.setOpacity(1.0f);
	sc.addSymbol(&s4);

	Polyline s5;
	s5.addPoint(0, -100);
	s5.addPoint(0, 100);
	s5.setStrokeWidth(2.0f);
	s5.setOpacity(1.0f);
	sc.addSymbol(&s5);

	Polygon s6;
	s6.addPoint (-30.0f, 40.0f);
	s6.addPoint (30.0f, 40.0f);
	s6.addPoint (0.0f, 80.0f);
	s6.setStrokeColor("cyan");
	s6.setFillColor("yellow");
	s6.setStrokeWidth(3.0f);
	s6.setOpacity(1.0f);
	sc.addSymbol(&s6);



	Text l;
	float loc[2] = {0, 25};
	l.setAnchorLocation(loc);
	l.setFontSize(50.0f);
	l.setStrokeWidth(1.0f);
	l.setLabel("test label");
	l.setStrokeColor("purple");
	l.setRotationAngle(90.);
	l.setOpacity(1.0f);
	sc.addSymbol(&l);

	sc.addSymbol(&g);

	// set visualizer type
	bridges.setDataStructure(sc);

	bridges.setVisualizeJSONFlag(true);

	// visualize the JSON and Collection
	bridges.visualize();

	return 0;
}
