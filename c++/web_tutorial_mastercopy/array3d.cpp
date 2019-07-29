#include <iostream>
#include <string>
#include "Array3D.h"
#include "Bridges.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	// create Bridges object
#if TESTING
                        // command line args provide credentials and server to test on
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
	if (argc > 4)
		bridges.setServer(argv[4]);
#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif
	// title, description
	bridges.setTitle("Three-Dimensional Array Example");
	bridges.setDescription("A 3 dimensional array with visual attributes. The third dimension is illustrated as a sequence of 2D slices");

		
	// create, populate 3D array
	Array3D<int> my_array (4, 4, 4);

	// color some of the elements
	my_array[0, 0, 0].setColor("red");
	my_array[0, 3, 0].setColor("green");
	my_array[3, 0, 0].setColor("blue");
	my_array[3, 3, 0].setColor("magenta");
	my_array[1, 1, 0].setColor("cyan");
	my_array[2, 2, 0].setColor("yellow");

	// visualize
	bridges.setDataStructure(&arr);
	bridges.visualize();

	return 0;
}
