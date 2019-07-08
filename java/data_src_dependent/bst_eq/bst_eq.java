
//
// SimpleDriver.java : Driver to illustrate importing USGS earthquake data
// 
import bridges.connect.Bridges;
import bridges.base.BSTElement;
import bridges.data_src_dependent.EarthquakeUSGS;
import bridges.data_src_dependent.Tweet;
import bridges.data_src_dependent.USGSaccount;
import java.util.List;

public class bst_eq {
	public static final int maxElements = 1000; //number of tweets

	public static void main(String[] args) throws Exception{
	
    							// Instantiate a Bridges object */

		Bridges bridges = new Bridges (Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer (args[3]);
		bridges.setTitle("Recent Earthquakes(USGIS Data)");

								// Retrieve a list of (maxElements) Tweets */	
		List<EarthquakeUSGS> eqlist = Bridges.getEarthquakeUSGSData(maxElements );
		BST<Double, EarthquakeUSGS>  bst = new BST<Double, EarthquakeUSGS>();
		for ( int i = 0; i < eqlist.size(); i++ ){
			if (eqlist.get(i).getMagnitude() > 3.)
				bst.insert(eqlist.get(i).getMagnitude(), eqlist.get(i));

		}
		// To do: use the list of earthquake objects and insert them into
		// a binary search tree (use the BST API); use the magnitude as
		// search key

		// Set each node's element with the various attributes of the 
		// earthquake; in the visualization the mousing over the element will
		// reveal this label

		
		bridges.setDataStructure(bst.getTreeRoot());
//		bridges.setVisualizeJSON(true);
		//* Read each Tweet returned from Bridges
//		System.out.println("\n\n\n------Printing Earthquakes-------\n");
//		for ( int i = 0; i < eqlist.size(); i++ ){
//			System.out.println(eqlist.get(i));
//		}
		bridges.visualize();
    }
}
