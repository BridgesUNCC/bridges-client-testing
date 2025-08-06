import java.util.ArrayList;
import java.util.Map;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.Country;
import bridges.base.WorldMap;
import bridges.base.Color;
import bridges.base.Rectangle;
import bridges.base.Circle;
import bridges.base.Text;
import bridges.base.SymbolCollection;


// This tutorial illustrates how to access the data of the World map with 
// boundaries; the countries are filled with default color
public class tut_worldmap_p4 {
	public static void main(String[] args) throws Exception {

		// create Bridges object
#if TESTING
		// command line args provide credentials and server type
		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);
#else
		Bridges bridges = new Bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", 
												"YOUR_API_KEY");
#endif
		// set title, description
		bridges.setTitle("Tutorial: Demonstrating overlaying World Map with Cities at their locations");
		bridges.setDescription("Uses symbols to represent city locations");

		// get data source object
		DataSource ds = bridges.getDataSource();


		// use symbols to represent cities
		SymbolCollection sc = new SymbolCollection();

		// circle properties
		Color red = new Color ("red");
		Color blue = new Color ("blue");

		// label properties
		float fsize = 12.f, str = 1.0f; 
		Color scol = new Color("purple");
		


		// charlotte
		Circle  c1 = new Circle(-80.8431f, 35.2271f, 1.f);
			c1.setStrokeColor(red);
			c1.setFillColor (blue);
		sc.addSymbol(c1);

		Text l1 = new Text();
			l1.setAnchorLocation(-79.8431f, 35.2271f);
			l1.setFontSize(fsize);
			l1.setStrokeColor(scol);
			l1.setText("Charlotte");
		sc.addSymbol(l1);

		// paris
		Circle  c2 = new Circle(2.3514f, 48.8576f, 1.f);
			c2.setStrokeColor(red);
			c2.setFillColor (blue);
		sc.addSymbol(c2);
		Text l2 = new Text();
			l2.setAnchorLocation(3.3514f, 48.8576f);
			l2.setFontSize(fsize);
			l2.setStrokeColor(scol);
			l2.setText("Paris");
		sc.addSymbol(l2);

		// berlin
		Circle  c3 = new Circle(13.4f, 52.52f, 1.f);
			c3.setStrokeColor(red);
			c3.setFillColor (blue);
		sc.addSymbol(c3);
		Text l3 = new Text();
			l3.setAnchorLocation(14.4f, 52.52f);
			l3.setFontSize(fsize);
			l3.setStrokeColor(scol);
			l3.setText("Berlin");
		sc.addSymbol(l3);
		// delhi
		Circle  c4 = new Circle(77.208f, 28.614f, 1.f);
			c4.setStrokeColor(red);
			c4.setFillColor (blue);
		sc.addSymbol(c4);
		Text l4 = new Text();
			l4.setAnchorLocation(78.208f, 28.614f);
			l4.setFontSize(fsize);
			l4.setStrokeColor(scol);
			l4.setText("New Delhi");
		sc.addSymbol(l4);

		// get us map data - states and boundaries
		ArrayList<Country> wm_data = ds.getWorldMapData ();

		WorldMap wm = new WorldMap(wm_data);
		bridges.setMap(wm);
		bridges.setElementLabelFlag(true);

		// set data structure
		bridges.setDataStructure(sc);

		// visualize
		bridges.visualize();
	}
}
