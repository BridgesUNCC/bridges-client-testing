#include <string>
#include "Bridges.h"
#include "Array.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {

#if TESTING
                        // command line args provide credentials and server to test on
    //Bridges *bridges =  new Bridges(atoi(argv[1]), argv[2], argv[3]);
    Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
    if (argc > 4)
        bridges.setServer(argv[4]);

	bridges.setTitle("Two-Dimensional Array Example");
	bridges.setDescription("A TwoD array with four rows and four columns. "
						 "Row one left to right: red, neutral, neutral, blue. "
						 "Row two left to right: neutral, cyan, neutral, neutral. "
						 "Row three left to right: neutral, neutral, yellow, neutral. "
						 "Row four left to right: green, neutral, neutral, magenta.");

#else
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
                                "YOUR_API_KEY");
#endif

	int dims[3] = {4, 4, 1};
	Array<string> arr(4, 4);

	for (int i = 0; i < dims[0]; i++)
		for (int j = 0; j < dims[1]; j++)
			arr.getElement(i, j).setLabel("El " + to_string(i * dims[1] + j));

	arr.getElement(0, 0).setColor(Color("red"));
	arr.getElement(0, 3).setColor(Color("green"));
	arr.getElement(3, 0).setColor(Color("blue"));
	arr.getElement(3, 3).setColor(Color("magenta"));
	arr.getElement(1, 1).setColor(Color("cyan"));
	arr.getElement(2, 2).setColor(Color("yellow"));

	bridges.setDataStructure(&arr);
	bridges.visualize();

	return 0;
}
