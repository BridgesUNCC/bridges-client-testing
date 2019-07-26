#include <string>

using namespace std;

#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"

using namespace bridges;

// This example illustrates using the Bridges color grid
// We will build a checker grid using two different colors

int main(int argc, char **argv) {
	// create Bridges object
#if TESTING
                        // command line args provide credentials and server to test on
    Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
    
    if (argc > 4)
        bridges.setServer(argv[4]);
		
#else
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
                                "YOUR_API_KEY");
#endif

	// set title, description 
	bridges.setTitle("A CheckerBoard Example Using Grid Type");
	bridges.setDescription("This is an example of the color grid with height and width 10. "
		   "This example alternates between blue and red starting with red at the top left corner of the grid.");
	int width = 200, height = 200;

	ColorGrid *cg  = new ColorGrid(width, height, Color("red"));

	// create a checkerboard pattern
	// 10 x 10 grid
	const int num_squares_x = 10;
	const int num_squares_y = 10;

	// compute square dimensions
	const int sq_width = width / num_squares_x, sq_height = width / num_squares_y;

	for (int j = 0; j < num_squares_y;  j++)
		for (int k = 0; k < num_squares_x;  k++) {
			// use even/odd of pixel to figure out the color of the square
			bool x_even = (k % 2) == 0;
			bool y_even = (j % 2) == 0;

			string col;
			if (y_even)
				col = (x_even) ? "red" : "blue";
			else
				col = (x_even) ? "blue" : "red";

			// find the address of the square
			int origin_x = k * sq_width;
			int origin_y = j * sq_height;

			// color the square
			for (int row = origin_y; row < origin_y + sq_height; row++)
				for (int column = origin_x; column < origin_x + sq_width; column++)
					cg->set(row, column, Color(col));
		}

	bridges.setDataStructure(cg);

	bridges.visualize();

	return 0;
}
