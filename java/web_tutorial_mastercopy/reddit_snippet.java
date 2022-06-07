import java.util.List;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.Reddit;

// This program fragment illustrates how to access the USGS earthquake data
public class reddit_snippet {
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
		bridges.setTitle("Accessing Reddit Data");

		DataSource ds = bridges.getDataSource();

		// get some data from the  "News" subreddit
		List<EarthquakeUSGS> eq_list = ds.getRedditData("news", -9999);

	}
}
