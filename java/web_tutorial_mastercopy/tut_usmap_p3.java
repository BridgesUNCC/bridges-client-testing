import java.util.ArrayList;
import java.util.Map;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.USState;
import bridges.data_src_dependent.USCounty;
import bridges.base.SLelement;
import bridges.base.USMap;
import bridges.base.Color;


// This program illustrates how to access the data of the US map with state
// boundaries with different colors for states and its boundaries
// Here we select 3 states and draw them with different attributes with or 
// without counties

public class tut_usmap_p3 {
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
		bridges.setTitle("Tutorial: Drawing US Map with States and Counties");
		bridges.setDescription("3 US  states, with or without Counties, with varied coloring");

		// get data source object
		DataSource ds = bridges.getDataSource();

		// get the States
		String[] states = {"Vermont", "Iowa", "North Carolina"};

		// get us map data - states and boundaries with counties
		// second argument is needed to get the counties
		ArrayList<USState> map_data = ds.getUSMapCountyData (states, true);

		// we will draw the first state without counties and set 
		// fill and boundary colors - use the viewCounties() flag to 
		// ignore counties
		USState s = map_data.get(0);
		s.setStrokeColor(new Color(255,0,0));
		s.setFillColor(new Color(0,255,0));
		s.setViewCountiesFlag(false);

		// the second state  we will draw with counties and set their colors
		USState s2 = map_data.get(1);

		// iterate over the counties
		for (Map.Entry<String,USCounty> e: s2.getCounties().entrySet()) {
			USCounty c = e.getValue();
			c.setStrokeColor(new Color(50,250,50));
			c.setFillColor(new Color(0,0,25));
		}

		// create a USMap object with the map data
		USMap us_maps = new USMap(map_data);


		// set data structure
		bridges.setDataStructure(us_maps);

		// visualize
		bridges.visualize();
	}
}
