import java.util.ArrayList;
import java.util.Map;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.USState;
import bridges.data_src_dependent.USCounty;
import bridges.base.SLelement;
import bridges.base.USMap;
import bridges.base.Color;


// This tutorial illustrates how to access the data of the US map with state
// boundaries with different colors for states and its boundaries
// It also illustrates how to draw all the counties 

public class tut_us_map_p2 {
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
		bridges.setTitle("Tutorial: Drawing US Map with State Boundariess, and State Counties");
		bridges.setDescription("All US states, All Counties");

		// get data source object
		DataSource ds = bridges.getDataSource();

		// get us map data - states and boundaries
		ArrayList<USState> map_data = ds.getUSMapCountyData ();

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
