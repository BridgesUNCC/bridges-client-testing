import bridges.connect.Bridges;
import bridges.data_src_dependent.Tweet;
import bridges.base.AVLTreeElement;

public class avl {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
#if TESTING
		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);
#else
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", 
										"YOUR_API_KEY");
#endif
		bridges.setTitle("AVL Tree Example");
        bridges.setDescription("This AVL tree has six elements. "
                        + "In this example, the balance factor for each element is set manually using the setLabel() function. "
                        + "Users must implement this function as part of the insert/delete operation to maintain a balanced tree. "
                        + "Links between nodes are then set using the setLeft()/setRight() functions. "
                        + "Here the setColor() and setOpacity() functions were used to stylize the root node. "
                        + "Once initialized and styled the AVL root is passed through the BRIDGES visualizer and displayed.");
						
		//create  an  AVL tree elements
		AVLTreeElement<Integer, String> avl_root = new AVLTreeElement<Integer, String>(50,
			"Hello");
		AVLTreeElement<Integer, String> avl_2 = new AVLTreeElement<Integer, String>(30, "This");
		AVLTreeElement<Integer, String> avl_3 = new AVLTreeElement<Integer, String>(70, "is");
		AVLTreeElement<Integer, String> avl_4 = new AVLTreeElement<Integer, String>(20, "an");
		AVLTreeElement<Integer, String> avl_5 = new AVLTreeElement<Integer, String>(40, "AVL");
		AVLTreeElement<Integer, String> avl_6 = new AVLTreeElement<Integer, String>(90, "Tree");
		// put in the balance factors - done manually  here
		// for illustration, but in a real project, the user will
		// implement this as part of the insert/delete
		// operations on the tree to maintain a balanced tree
		avl_root.setLabel("0");
		avl_2.setLabel("0");
		avl_3.setLabel("-1");
		avl_4.setLabel("0");
		avl_5.setLabel("0");
		avl_6.setLabel("0");

		// add the links between nodes
		avl_root.setLeft(avl_2);
		avl_root.setRight(avl_3);
		avl_2.setLeft(avl_4);
		avl_2.setRight(avl_5);
		avl_3.setRight(avl_6);
		// set some attributes
		avl_root.getVisualizer().setColor("magenta");
		avl_root.getVisualizer().setOpacity(0.8f);

		//set visualizer type
		bridges.setDataStructure(avl_root);

		// visualize the list
		bridges.visualize();
	}
}
