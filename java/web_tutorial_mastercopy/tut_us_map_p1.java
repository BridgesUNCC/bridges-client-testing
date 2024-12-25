import java.util.Vector;
import java.util.Map;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.State;
import bridges.data_src_dependent.County;
import bridges.base.SLelement;
import bridges.base.USMap;
import bridges.base.Color;


// This tutorial illustrates how to access the data of the US map with state
// boundaries with different colors for states and its boundaries
public class tut_us_map_p1 {
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
		bridges.setTitle("Tutorial: Drawing US Map with State Boundariess");
		bridges.setDescription("All US states, No Counties");

		// get data source object
		DataSource ds = bridges.getDataSource();

		// get us map data - states and boundaries
		Vector<State> map_data = ds.getUSMapData ();

		// create a USMap object with the map data
		USMap us_maps = new USMap(map_data);

		// pass it to BRIDGES
		bridges.setMap(us_maps);
    
		// Plot Charlotte, NC 
		SLelement<String>  el0 = new SLelement<String>("Charlotte", "Go Niners!");
		el0.setLocation(-80.8431, 35.2271); //35.2271N, 80.8431W

		// set data structure
		bridges.setDataStructure(el0);

		// visualize
		bridges.visualize();
	}
}
