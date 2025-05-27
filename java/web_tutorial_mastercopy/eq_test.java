import java.util.List;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.EarthquakeUSGS;

// This program fragment illustrates how to access the USGS earthquake data
public class eq_test {
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
		bridges.setTitle("Accessing USGIS Earthquake Data (USGS Data)");

		DataSource ds = bridges.getDataSource();

		// get 10 most recent earthquake records
		List<EarthquakeUSGS> eq_list = ds.getEarthquakeUSGSData(10);

		// print the first record
		System.out.println("Earthquake 0:");
		System.out.println ("\tMagnitude:"  + eq_list.get(0).getMagnitude() + "\n"
			+ "\tDate:" + eq_list.get(0).getTime() + "\n"
			+ "\tLocation: " +  eq_list.get(0).getLocation() + "\n"
			+ "\tLat/Long:"  + eq_list.get(0).getLatit() + "," +
			eq_list.get(0).getLongit());


		//get all earthquakes
		eq_list = ds.getEarthquakeUSGSData();

		// print the first record
		System.out.println("Earthquake 0:");
		System.out.println ("\tMagnitude:"  + eq_list.get(0).getMagnitude() + "\n"
			+ "\tDate:" + eq_list.get(0).getTime() + "\n"
			+ "\tLocation: " +  eq_list.get(0).getLocation() + "\n"
			+ "\tLat/Long:"  + eq_list.get(0).getLatit() + "," +
			eq_list.get(0).getLongit());
	}
}
