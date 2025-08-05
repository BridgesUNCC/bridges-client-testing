import java.util.ArrayList;
import java.util.Map;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.Country;
import bridges.base.WorldMap;


// This tutorial illustrates how to access the data of the World map with 
// boundaries; the countries are filled with default color
public class tut_worldmap_p1 {
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
		bridges.setTitle("Tutorial: Drawing World Map with Country Boundaries");
		bridges.setDescription("All Countries");

		// get data source object
		DataSource ds = bridges.getDataSource();

		// get us map data - states and boundaries

		WorldMap wm = new WorldMap();

		// set data structure
		bridges.setMap(wm);
		bridges.setDataStructure(wm);

		// visualize
		bridges.visualize();
	}
}
