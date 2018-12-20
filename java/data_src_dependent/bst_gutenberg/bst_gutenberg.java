
//
// Testing the gutenberg books data with a binary search tree
// 
import java.util.Scanner;
import bridges.connect.Bridges;
import bridges.base.BSTElement;
import bridges.data_src_dependent.GutenbergBook;
import java.util.ArrayList;

public class bst_gutenberg {
	public static final int maxElements = 100; //number of tweets

	public static void main(String[] args) throws Exception{
	
    						// Instantiate a Bridges object 
		Bridges bridges = new Bridges (101, args[0], args[1]);
		bridges.setServer (args[2]);

		bridges.setTitle("GutenBerg Book Collection(Meta Data Only)");


							// Retrieve Gutenberg Book Data 
		ArrayList<GutenbergBook> book_list = 
				(ArrayList<GutenbergBook>) Bridges.getGutenbergBookMetaData();

		BST<String, GutenbergBook>  bst = new BST<String, GutenbergBook>();
		for ( int i = 0; i < book_list.size(); i++ ){
			bst.insert(book_list.get(i).getTitle(), book_list.get(i));
		}

							// give BRIDGES handle to tree root
		bridges.setDataStructure(bst.getTreeRoot());
							// visualize the tree
		bridges.visualize();
	}
}
