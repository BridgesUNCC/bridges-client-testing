#include <iostream>
#include <string>
#include "Array.h"
#include "Bridges.h"

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	if (argc < 3) {
		cout << "Must provide both user id and api key as command line arguments. Terminating.." 
								<< endl;
		exit (-1);
	}	
	Bridges *bridges = new Bridges(2, argv[1], argv[2]);
	
	if (argc == 4)		// Server type provided
		bridges->setServer(argv[3]);
		
//	Bridges::initialize(2, "YOUR_USER_ID", "YOUR_API_KEY");

	Array<string> *arr = new Array<string>(4, 4, 4);

	arr->getElement(0, 0, 0).getVisualizer()->setColor(Color("red"));
	arr->getElement(0, 3, 0).getVisualizer()->setColor(Color("green"));
	arr->getElement(3, 0, 0).getVisualizer()->setColor(Color("blue"));
	arr->getElement(3, 3, 0).getVisualizer()->setColor(Color("magenta"));
	arr->getElement(1, 1, 0).getVisualizer()->setColor(Color("cyan"));
	arr->getElement(2, 2, 0).getVisualizer()->setColor(Color("yellow"));

	Bridges::setTitle("3D Array Example");
	Bridges::setDataStructure(arr);
	Bridges::visualize();

	return 0;
}
