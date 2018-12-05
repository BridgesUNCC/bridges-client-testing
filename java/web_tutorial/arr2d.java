import bridges.connect.Bridges;
import bridges.base.Array;
import bridges.base.Element;

public class arr2d {
	public static void main(String[] args) throws Exception {

		if (args.length < 2)
			throw new IllegalArgumentException("Need to provide user id and api key as command-line arguments!");
		//create the Bridges object
		Bridges bridges = new Bridges(1, args[0], args[1]);

		if (args.length == 3)	// If user provides server
			bridges.setServer(args[2]);
		
		//  for 2D array 5x5
		int num_rows = 4, num_cols = 4;
		Array<Integer> my_array = new Array<Integer> (num_rows, num_cols);

		// populate the array
		for (int row = 0; row < num_rows; row++) {
			for (int col = 0; col < num_cols; col++) {
				my_array.getElement(row, col).setLabel("El " +
					String.valueOf(row * num_cols + col));
			}
		}

		// color some of the elements

		my_array.getElement(0, 0).getVisualizer().setColor("red");
		my_array.getElement(0, 3).getVisualizer().setColor("green");
		my_array.getElement(3, 0).getVisualizer().setColor("blue");
		my_array.getElement(3, 3).getVisualizer().setColor("magenta");
		my_array.getElement(1, 1).getVisualizer().setColor("cyan");
		my_array.getElement(2, 2).getVisualizer().setColor("yellow");

		//set visualizer type
		bridges.setDataStructure(my_array);

		// visualize the array
		bridges.visualize();
	}
}
