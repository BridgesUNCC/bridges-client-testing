import java.util.ArrayList;
import java.util.Map;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.USState;
import bridges.data_src_dependent.USCounty;
import bridges.base.SLelement;
import bridges.base.USMap;
import bridges.base.Color;
import bridges.base.Rectangle;
import bridges.base.Polyline;
import bridges.base.Circle;
import bridges.base.Text;
import bridges.base.SymbolCollection;


// This program illustrates how to access the data of the US map with state
// boundaries with different colors for states and its boundaries
// Here we select 3 states and draw them with different attributes with or 
// without counties

public class tut_usmap_p4 {
	public static void main(String[] args) throws Exception {

		// create Bridges object
#if TESTING
		// command line args provide credentials and server type
		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);
#else
		Bridges bridges = new Bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif
		// set title, description
		bridges.setTitle("Tutorial: Drawing US Map with Symbols");
		bridges.setDescription("Example demonstrates using symbols overlaid on US Map");

		// get data source object
		DataSource ds = bridges.getDataSource();

		// get us map data - states and boundaries with counties
		// second argument is needed to get the counties
		ArrayList<USState> map_data = ds.getUSMapData ();

		// draw some symbols to indicate two cities
		SymbolCollection sc = new SymbolCollection();

		// create a circle symbol
		Circle c = new Circle(-80.8431f, 35.2271f, 1.f);
			c.setStrokeColor("red");
			c.setFillColor("cyan");
		sc.addSymbol(c);

		Text l = new Text();
			l.setAnchorLocation(-79.8431f, 35.2271f);
			l.setFontSize(18.0f);
			l.setStrokeWidth(1.0f);
			l.setText("Charlotte");
			l.setStrokeColor("purple");
			l.setOpacity(1.0f);
    	sc.addSymbol(l);

		// create a rectangle symbol
		Rectangle r = new Rectangle(-82.998f, 39.96f, 1.f, 1.f);
			r.setStrokeColor("red");
			r.setFillColor("lightgreen");
		sc.addSymbol(r);


		Text l2 = new Text();
			l2.setAnchorLocation(-81.998f, 39.96f);
			l2.setFontSize(18.0f);
			l2.setStrokeWidth(1.0f);
			l2.setText("Columbus");
			l2.setStrokeColor("purple");
			l2.setOpacity(1.0f);
    	sc.addSymbol(l2);
	
		Polyline p3 = new Polyline();
			p3.addPoint(-80, 41);
			p3.addPoint(-85, 41);
			p3.setStrokeColor("magenta");
			p3.setStrokeWidth(0.5f);
			p3.setOpacity(1.0f);
		sc.addSymbol(p3);

		// create a USMap object with the map data
		USMap us_maps = new USMap(map_data);
		bridges.setMap(us_maps);

		// set data structure
		bridges.setDataStructure(sc);

		// visualize
		bridges.visualize();
	}
}
