/**
 * Created by Kalpathi Subramanian
 * Date : 7/17/2018.
 *
 * krs@uncc.edu
 */
import java.lang.String;
import bridges.connect.Bridges;
import bridges.base.SLelement;
import bridges.base.Color;
import bridges.base.ColorGrid;

/**
 *  This example illustrates the use of the Grid type and its subclass, a ColorGrid.
 *  The example builds  a checkerboard with two different colors
 *
 */

public class color_grid_rle_edgecase {

	public static void main(String[] args) throws Exception {

		// This example illustrates using the Bridges color grid
		// We will build a checker grid using two different colors

		// initialize BRIDGES
#if TESTING

		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);

		// set title for visualization
		bridges.setTitle("A CheckerBoard Example Using Grid Type");
		bridges.setDescription("This is an example of the color grid with height and width 10. "
			+   "This example alternates between blue and red starting with red at the top left corner of the grid.");

#else
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
#endif

    /// This test tries to trigger a very specific bug in colorgrid.
    /// It happens whenever the RLE buffer is exactly full in the last
    /// buffer it sends, causing a potential edge case.
    
    int width = 128;
int height = 128;

		Color blue = new Color("blue");
		Color red = new Color("red");

		ColorGrid cg  = new ColorGrid(width, height, red);

		for (int row = 0; row < height; row++)
		    for (int column = 0; column < width; column++)
			cg.set(row, column, blue);

		bridges.setDataStructure(cg);

		bridges.visualize();
	}
}
