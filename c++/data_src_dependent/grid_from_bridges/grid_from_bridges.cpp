#include <string>
#include "Bridges.h"
#include "DataSource.h"
#include "ColorGrid.h"


using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	#if TESTING
	                        // command line args provide credentials and server to test on
	    Bridges *bridges =  new Bridges(atoi(argv[1]), argv[2], argv[3]);
	    if (argc > 4)
	        bridges->setServer(argv[4]);
	#else
	    Bridges *bridges =  new Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
	                                "YOUR_API_KEY");
	#endif

	DataSource *ds = new DataSource;
	ColorGrid cg = ds->getColorGridFromAssignment("bridges_testing", 2108);

						// just to be sure this is working, lets change the mid square
						// of pixels to a red colored square

	int *dims = cg.getDimensions();
	cout << "Dims:" << dims[0] << "," << dims[1] << endl;
	for (int k = dims[1]/2 -10; k < dims[1]/2 + 10; k++)
	for (int j = dims[0]/2-10; j < dims[0]/2 + 10; j++)
		cg.set(k, j, Color("red"));
	bridges->setDataStructure(&cg);
	bridges->setServer("clone");
	bridges->visualize();

	return 0;
}
