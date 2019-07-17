#include "Bridges.h"
#include "Array1D.h"

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
	bridges.setTitle("One-Dimensional Array Example");
    bridges.setDescription("OneD array with colors in order left to right: "
			"red, green, blue, cyan, magenta, yellow, red, green, blue, black.");

	// create, populate the array
	Array1D<int> arr (10);

	for (int j = 0; j < 10; j++) {
		arr.getElement(j).setValue(j * j);
		arr.getElement(j).setLabel(to_string(arr.getElement(j).getValue()));
	}

	// set visual attributes
	arr[0].setColor("red");
	arr[1].setColor("green");
	arr[2].setColor("blue");
	arr[3].setColor("cyan");
	arr[4].setColor("magenta");
	arr[5].setColor("yellow");
	arr[6].setColor("red");
	arr[7].setColor("green");
	arr[8].setColor("blue");
	arr[9].setColor("black");

	// visualize
	bridges.setDataStructure(&arr);
	bridges.visualize();

	return 0;
}
