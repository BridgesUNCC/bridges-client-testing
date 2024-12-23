import java.util.Vector;
import java.util.Map;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.State;
import bridges.data_src_dependent.County;
import bridges.base.SLelement;
import bridges.base.USMap;
import bridges.base.Color;


// This program fragment illustrates how to access the US Cities  data
public class us_map_test {
	public static void main(String[] args) throws Exception {

		// create Bridges object
#if TESTING
		// command line args provide credentials and server type
		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);
#else
		Bridges bridges = new Bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif
		// read the earth quake  data and build the BST
		bridges.setTitle("Accessing US State County Maps)");

		DataSource ds = bridges.getDataSource();

		// case 1 : map and counties  of  a few states
		bridges.setDescription("3 US states, with and without counties");
		String[] states = {"Vermont", "Iowa", "North Carolina"};
		Vector<State> map_data = ds.getUSMapCountyData (states, true);

		State s = map_data.get(0);
		s.setViewCountiesFlag(true);
		s.setStrokeColor(new Color(255,0,0));
		s.setFillColor(new Color(0,255,0));
		s.setViewCountiesFlag(false);

		{
			s = map_data.get(1);

			for (Map.Entry<String,County> e: s.accessCounties().entrySet()) {
				County c = e.getValue();
				c.setStrokeColor(new Color(50,250,50));
				c.setFillColor(new Color(0,0,25));
			}
		}

		USMap us_maps = new USMap(map_data);
		bridges.setMap(us_maps);
    
		SLelement<String>  el0 = new SLelement<String>("Charlotte", "Go Niners!");
		el0.setLocation(-80.8431, 35.2271); //35.2271N, 80.8431W
		bridges.setDataStructure(el0);
		bridges.visualize();

		// case 2:  all states, no counties
		bridges.setDescription("All US states, No Counties");
		map_data = ds.getUSMapData(); // all states, no counties
		us_maps.setStateData(map_data);
		bridges.setMap(us_maps);
		bridges.visualize();

		// case 3:  all states, all counties
		bridges.setDescription("All US states, All Counties");
		map_data = ds.getUSMapCountyData (); // all states, no counties
		us_maps.setStateData(map_data);
		bridges.setMap (us_maps);
		bridges.visualize();
	}
}
