import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.base.WorldMap;
import bridges.data_src_dependent.Country;


import java.util.ArrayList;
import java.lang.String;


public class world_map {
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
		bridges.setTitle("Using World Map");

		DataSource ds = bridges.getDataSource();
		
		// get Country data
		String[] countries = {"Germany", "France"};
		ArrayList<Country> country_data = ds.getWorldMapData();
		
		// create a USMap object with the map data
		WorldMap wm = new WorldMap(country_data);

		// set data structure
		bridges.setDataStructure(wm);

		// visualize
		bridges.visualize();
	}
}
