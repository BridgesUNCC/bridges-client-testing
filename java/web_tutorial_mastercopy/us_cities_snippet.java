import java.util.List;
import java.util.HashMap;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.USCities;

// This program fragment illustrates how to access the USGS earthquake data
public class us_cities_snippet {
	public static void main(String[] args) throws Exception {

		// create Bridges object
#if TESTING
		// command line args provide credentials and server type
		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);
#else
		Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif
		// read the earth quake  data and build the BST
		bridges.setTitle("Accessing US City Data)");

		DataSource ds = bridges.getDataSource();

		// limit to at most  25 cities and population above 2M
		// - parameters are passed through a map
		HashMap<String, String> map = new HashMap<String, String>();
			map.put ("limit", "10");
			map.put ("population", "2000000");

		// get the cities
		List<USCities> cities = ds.getUSCitiesData(map);

		// print the records
		System.out.println("US Cities Retrieved");
		for (int k = 0; k < cities.size(); k++)
			System.out.println ("\t" + cities.get(k).getCity() + 
				", " + cities.get(k).getState() + 
				":  Population: " + cities.get(k).getPopulation() + 
				", Elevation: " + cities.get(k).getElevation());
	}
}
