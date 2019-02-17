#include "Bridges.h"
#include "Array.h"

using namespace bridges;

int main(int argc, char **argv) {
	
						// command line args provide credentials and server to test on
//	Bridges *bridges =  new Bridges(atoi(argv[1]), argv[2], argv[3]);
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
	if (argc > 4)
		bridges.setServer(argv[4]);

	bridges.setTitle("One-Dimensional Array Example");
    bridges.setDescription("OneD array with colors in order left to right: "
			"red, green, blue, cyan, magenta, yellow, red, green, blue, black.");


	Array<int> arr (10);

	for (int j = 0; j < 10; j++) {
		arr.getElement(j).setValue(j * j);
		arr.getElement(j).setLabel(to_string(arr.getElement(j).getValue()));
	}

	arr.getElement(0).getVisualizer()->setColor(Color("red"));
	arr.getElement(1).getVisualizer()->setColor(Color("green"));
	arr.getElement(2).getVisualizer()->setColor(Color("blue"));
	arr.getElement(3).getVisualizer()->setColor(Color("cyan"));
	arr.getElement(4).getVisualizer()->setColor(Color("magenta"));
	arr.getElement(5).getVisualizer()->setColor(Color("yellow"));
	arr.getElement(6).getVisualizer()->setColor(Color("red"));
	arr.getElement(7).getVisualizer()->setColor(Color("green"));
	arr.getElement(8).getVisualizer()->setColor(Color("blue"));
	arr.getElement(9).getVisualizer()->setColor(Color("black"));

	bridges.setDataStructure(&arr);
	bridges.visualize();

	return 0;
}
