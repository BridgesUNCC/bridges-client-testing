import java.util.Vector;
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
		bridges.setDescription("3 US states, with/without counties");
		String[] states = {"Vermont", "Iowa", "North Carolina"};
		Vector<State> map_data = ds.getUSMapCountyData (states, true);

		State s = map_data.get(0);
		s.setViewCountiesFlag(true);
		s.setStrokeColor(new Color(255,0,0));
		s.setFillColor(new Color(0,255,0));
		s.setViewCountiesFlag(false);

/*
		{
			State s = map_data.get(1);

			for (County c: s.accessCounties()) {
				c.second.setStrokeColor(Color(50,250,50));
				c.second.setFillColor(Color(0,0,25));
			}
		}
*/

		USMap us_maps = new USMap(map_data);
		bridges.setMap(us_maps);
    
		SLelement<String>  el0 = new SLelement<String>("Charlotte", "Go Niners!");
		el0.setLocation(-80.8431, 35.2271); //35.2271N, 80.8431W
		bridges.setDataStructure(el0);
		bridges.setJSONFlag(true);

//		bridges.visualize();
	}
}
