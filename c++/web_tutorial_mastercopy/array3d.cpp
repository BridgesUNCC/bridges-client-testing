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
	bridges.setDescription("A 3D array displaying four rows, four columns, and four slices. " 
						 "This example uses a for loop in which the header specifies slice count as the iteration variable. "
						 "A nested loop then builds a 2D array within that slice. (See Two-Dimensional Array Test) "
						 "After initialization, colors of specific elements are changed manually using the "
						 " setColor() function.");

		
	// create, populate 3D array
	Array3D<std::string> arr (4, 4, 4);

	arr[0][1][2] = "hi there";
	arr.getElement(0, 1, 2).setLabel(arr[0][1][2]);
	arr.getElement(0, 1, 2).setColor("white");
	
	arr.getElement(0, 0, 0).setColor("red");
	arr.getElement(0, 3, 0).setColor("green");
	arr.getElement(3, 0, 0).setColor("blue");
	arr.getElement(3, 3, 0).setColor("magenta");
	arr.getElement(1, 1, 0).setColor("cyan");
	arr.getElement(2, 2, 0).setColor("yellow");

	// visualize
	bridges.setDataStructure(&arr);
	bridges.visualize();

	return 0;
}
