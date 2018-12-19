
//
// SimpleDriver.java : Driver to illustrate importing USGS earthquake data
// 
import java.util.Scanner;
import bridges.connect.Bridges;
import bridges.base.BSTElement;
import bridges.data_src_dependent.Game;
import java.util.ArrayList;

public class bst_games {
	public static final int maxElements = 100; //number of tweets

	public static void main(String[] args) throws Exception{
	
    						// Instantiate a Bridges object 
		Bridges bridges = new Bridges (21, args[0], args[1]);
		bridges.setServer (args[2]);
		bridges.setTitle("Binary Search Tree with IGN Game Data");

							// Retrieve Game Data
		ArrayList<Game> game_list = 
				(ArrayList<Game>) Bridges.getGameData();

		BST<String, Game>  bst = new BST<String, Game>();
//		for ( int i = 0; i < game_list.size(); i++ ){
		for ( int i = 0; i < 5000; i++ ){
			bst.insert(game_list.get(i).getTitle(), game_list.get(i));
		}

							// give BRIDGES handle to tree root
		bridges.setDataStructure(bst.getTreeRoot());
							// visualize the tree
		bridges.visualize();
	}
}
