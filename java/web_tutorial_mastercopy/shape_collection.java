
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

		if (args.length < 2)
			throw new IllegalArgumentException("Need to provide user ID and API key as command-line arguments!");
		// note: you must fill in with your Bridges credentials
#if TESTING
        Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
        bridges.setServer(args[3]);

		bridges.setTitle("Symbol Collection");
		bridges.setDescription("Red square, green circle, magenta horizontal and vertical lines, "
				+	"and a test label with a purple outline.");
				
#else
        Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", 
                                        "YOUR_API_KEY");
#endif

		SymbolCollection sc = new SymbolCollection();
		Rectangle s1 = new Rectangle(-25.0f, 0.0f, 50, 50);
		s1.setFillColor(new Color("red"));
		sc.addSymbol(s1);

		Circle s2 = new Circle(25.0f, 0.0f, 25);
		s2.setFillColor(new Color("green"));
		sc.addSymbol(s2);


		Polyline s3 = new Polyline();
		//	vector<float> pts = {-100.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 100.0, 0.0, 0.0};
		//	s3->setPolygon (pts);

		s3.addPoint(-100, 0);
		s3.addPoint(100, 0);
		s3.addPoint(0, 0);
		s3.addPoint(0, -100);
		s3.addPoint(0, 100);
		s3.addPoint(0, 0);
		s3.setStrokeColor(new Color("magenta"));
		sc.addSymbol(s3);

		Polyline s4 = new Polyline();
			s4.addPoint(-25, -10);
			s4.addPoint(25, -10);
			s4.addPoint(0, 50);
			s4.setStrokeColor(new Color("darkorchid"));
			s4.setStrokeWidth(2.0f);
		sc.addSymbol(s4);

		Label l = new Label();
		l.setLocation(0, 25);
		l.setFontSize(12);
		l.setStrokeWidth(1.0f);
		l.setLabel("test label");
		l.setStrokeColor(new Color("purple"));
		sc.addSymbol(l);


		// set visualizer type

		bridges.setDataStructure(sc);
		// visualize the JSON and Collection
		bridges.visualize();
	}
}

