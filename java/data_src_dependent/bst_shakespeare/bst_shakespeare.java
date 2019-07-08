
//
// SimpleDriver.java : Driver to illustrate importing USGS earthquake data
// 
import java.util.Scanner;
import bridges.connect.Bridges;
import bridges.base.BSTElement;
import bridges.data_src_dependent.Shakespeare;
import java.util.ArrayList;

public class bst_shakespeare {
	public static final int maxElements = 100; //number of tweets

	public static void main(String[] args) throws Exception{
	
    						// Instantiate a Bridges object 
        Bridges bridges = new Bridges (Integer.parseInt(args[0]), args[1], args[2]);
        bridges.setServer (args[3]);


		bridges.setTitle("Shakespeare Sonnets, Poems, Plays");

							// Retrieve Shakespeare Data 
		ArrayList<Shakespeare> shksp_list = 
				(ArrayList<Shakespeare>) Bridges.getShakespeareData();

		BST<String, Shakespeare>  bst = new BST<String, Shakespeare>();
		for ( int i = 0; i < shksp_list.size(); i++ ){
			bst.insert(shksp_list.get(i).getTitle(), shksp_list.get(i));
		}

							// give BRIDGES handle to tree root
		bridges.setDataStructure(bst.getTreeRoot());
							// visualize the tree
		bridges.visualize();
	}
}
