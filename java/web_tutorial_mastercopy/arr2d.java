import bridges.connect.Bridges;
import bridges.base.Array2D;
import bridges.base.Element;

public class arr2d {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
#if TESTING

		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);

		bridges.setTitle("Two-Dimensional Array Example");
		bridges.setDescription("Illustrates a 2D array with visual attributes");

#else
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
#endif
		// title, description
		bridges.setTitle("Two-Dimensional Array Example");
		bridges.setDescription("Illustrates a 2D array with visual attributes");

		//  for 2D array 5x5
		int num_rows = 6, num_cols = 6;
		Array2D<Integer> my_array = new Array2D<Integer> (num_rows, num_cols);

		// load array with its 1D address
		for (int i = 0; i < num_rows; i++)
			for (int j = 0; j < num_cols; j++) {
				my_array.getElement(i, j).setValue(i*num_cols+j);
				System.out.println (i+","+j+": " + my_array.getElement(i, j).getValue());
			}

		// populate the array
		for (int row = 0; row < num_rows; row++) {
			for (int col = 0; col < num_cols; col++) {
				my_array.getElement(row, col).setLabel("El " +
					String.valueOf(my_array.getElement(row, col).getValue()));
				System.out.println (row+","+col+": " + my_array.getElement(row, col).getLabel());
			}
		}

		// color some of the elements
		my_array.getElement(0, 0).setColor("red");
		my_array.getElement(0, 3).setColor("green");
		my_array.getElement(5, 0).setColor("blue");
		my_array.getElement(5, 3).setColor("magenta");
		my_array.getElement(1, 1).setColor("cyan");
		my_array.getElement(2, 2).setColor("yellow");

		//set visualizer type
		bridges.setDataStructure(my_array);

		// visualize the array
		bridges.visualize();
	}
}
