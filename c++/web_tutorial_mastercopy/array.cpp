#include "Bridges.h"
#include "Array.h"

using namespace bridges;

int main(int argc, char **argv) {
	
#if TESTING
						// command line args provide credentials and server to test on
//	Bridges *bridges =  new Bridges(atoi(argv[1]), argv[2], argv[3]);
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
	if (argc > 4)
		bridges.setServer(argv[4]);

	bridges.set_title("One-Dimensional Array Example");
    bridges.set_description("OneD array with colors in order left to right: "
			"red, green, blue, cyan, magenta, yellow, red, green, blue, black.");

#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif

	Array<int> arr (10);

	for (int j = 0; j < 10; j++) {
		arr.getElement(j).setValue(j * j);
		arr.getElement(j).setLabel(to_string(arr.getElement(j).getValue()));
	}

	arr.getElement(0).setColor("red");
	arr.getElement(1).setColor("green");
	arr.getElement(2).setColor("blue");
	arr.getElement(3).setColor("cyan");
	arr.getElement(4).setColor("magenta");
	arr.getElement(5).setColor("yellow");
	arr.getElement(6).setColor("red");
	arr.getElement(7).setColor("green");
	arr.getElement(8).setColor("blue");
	arr.getElement(9).setColor("black");

	bridges.setDataStructure(&arr);
	bridges.visualize();

	return 0;
}
