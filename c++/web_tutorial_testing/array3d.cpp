#include <iostream>
#include <string>
#include "Array.h"
#include "Bridges.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
                        // command line args provide credentials and server to test on
    //Bridges *bridges =  new Bridges(atoi(argv[1]), argv[2], argv[3]);
    Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
    if (argc > 4)
        bridges.setServer(argv[4]);

	bridges.setTitle("Three-Dimensional Array Example");
	bridges.setDescription("A 3D array displaying four rows, four columns, and four slices. " 
						 "This example uses a for loop in which the header specifies slice count as the iteration variable. "
						 "A nested loop then builds a 2D array within that slice. (See Two-Dimensional Array Test) "
						 "After initialization, colors of specific elements are changed manually using the "
						 " setColor() function.");
						

	if (argc == 4)		// Server type provided
		bridges.setServer(argv[3]);
		
	Array<string> arr (4, 4, 4);

	arr.getElement(0, 0, 0).getVisualizer()->setColor(Color("red"));
	arr.getElement(0, 3, 0).getVisualizer()->setColor(Color("green"));
	arr.getElement(3, 0, 0).getVisualizer()->setColor(Color("blue"));
	arr.getElement(3, 3, 0).getVisualizer()->setColor(Color("magenta"));
	arr.getElement(1, 1, 0).getVisualizer()->setColor(Color("cyan"));
	arr.getElement(2, 2, 0).getVisualizer()->setColor(Color("yellow"));

	bridges.setDataStructure(&arr);
	bridges.visualize();

	return 0;
}
