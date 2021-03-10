import bridges.connect.Bridges;
import bridges.base.SymbolCollection;
import bridges.base.Rectangle;
import bridges.base.Circle;
import bridges.base.Label;
import bridges.base.Polyline;
import bridges.base.Polygon;
import bridges.base.Color;


public class shape_collection {

	public static void main(String[] args) throws Exception {

		//create Bridges object
#if TESTING
		if (args.length < 2)
			throw new IllegalArgumentException("Need to provide user ID and API key as command-line arguments!");
		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);

#else
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
#endif
		// title, description
		bridges.setTitle("Symbol Collection");
		bridges.setDescription("Red square, green circle, magenta horizontal and vertical lines, "
			+	"and a test label with a purple outline.");

		// create some symbols and add to symbol collection
		SymbolCollection sc = new SymbolCollection();

		// draw a rectangle
		Rectangle s1 = new Rectangle(-25.0f, 0.0f, 50.0f, 50.0f);
		s1.setFillColor("red");
		sc.addSymbol(s1);

		// and a circle next to it
		Circle s2 = new Circle(25.0f, 0.0f, 25.0f);
		s2.setFillColor("green");
		sc.addSymbol(s2);

		// draw a triangle above
		Polygon s3 = new Polygon();
		s3.addPoint(-25.0f, -10.0f);
		s3.addPoint(25.0f, -10.0f);
		s3.addPoint(0.0f, 50.0f);
		s3.setStrokeColor("darkorchid");
		s3.setStrokeWidth(2.0f);
		sc.addSymbol(s3);

		// draw axes
		Polyline s4 = new Polyline();
		s4.addPoint(-100.0f, 0.0f);
		s4.addPoint(100.0f, 0.0f);
		s4.setStrokeColor("magenta");
		s4.setStrokeWidth(2.0f);
		sc.addSymbol(s4);

		Polyline s5 = new Polyline();
		s5.addPoint(0.0f, -100.0f);
		s5.addPoint(0.0f, 100.0f);
		s5.setStrokeWidth(2.0f);
		sc.addSymbol(s5);

		Polygon s6 = new Polygon();
		s6.addPoint (-30.0f, 40.0f);
		s6.addPoint (30.0f, 40.0f);
		s6.addPoint (0.0f, 80.0f);
		s6.setStrokeColor("cyan");
		s6.setFillColor("yellow");
		s6.setStrokeWidth(3.0f);
		sc.addSymbol(s6);



		Label l = new Label();
		l.setLocation(0.0f, 25.0f);
		l.setFontSize(12.0f);
		l.setStrokeWidth(1.0f);
		l.setLabel("test label");
		l.setStrokeColor("purple");
		l.setRotationAngle(90.0f);
		sc.addSymbol(l);

		// set visualizer type
		bridges.setDataStructure(sc);

		// visualize the JSON and Collection
		bridges.visualize();
	}
}

