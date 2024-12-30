import bridges.connect.Bridges;
import bridges.base.SLelement;
import bridges.base.WorldMap;


public class world_overlay {
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
		bridges.setTitle("Using World Overlay");
		
		// create a USMap object with the map data
		WorldMap wm = new WorldMap();

		// pass it to BRIDGES
		bridges.setMap(wm);
    
		// Plot Charlotte, NC 
		SLelement<String>  el0 = new SLelement<String>("Charlotte", "Go Niners!");
		el0.setLocation(-80.8431, 35.2271); //35.2271N, 80.8431W

		// set data structure
		bridges.setDataStructure(el0);

		// visualize
		bridges.visualize();
	}
}
