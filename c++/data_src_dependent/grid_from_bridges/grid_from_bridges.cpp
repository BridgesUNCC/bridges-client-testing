#include <string>
#include "Bridges.h"
#include "DataSource.h"
#include "ColorGrid.h"


using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges(atoi(argv[1]), argv[2], argv[3]);
	if (argc > 4)
		bridges.setServer(argv[4]);
#else
	Bridges bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");
#endif

	//First make a ColorGrid
	int sizeI = 25, sizeJ = 35;
	ColorGrid cg1 (sizeI, sizeJ);
	for (int i = 0; i < sizeI; ++i)
		for (int j = 0; j < sizeJ; ++j) {
			if ((i + j) % 2 == 0) {
				cg1.set(i, j, Color(0, 0, 0));
			}
			else {
				cg1.set(i, j, Color(255, 255, 255));
			}
		}
	bridges.setDataStructure(&cg1);
	bridges.visualize();

	try {
		DataSource ds(&bridges);
		ColorGrid cg = ds.getColorGridFromAssignment(bridges.getUserName(), bridges.getAssignment());

		// just to be sure this is working, lets change the mid square
		// of pixels to a red colored square

		int h = cg.getHeight();
		int w = cg.getWidth();
		cout << "Height, Width:" << h << "," << w << endl;
		for (int k = h/2 - 5; k < h/2 + 5; k++)
				for (int j = w/2 - 5; j < w/2 + 5; j++)
					cg.set(k, j, Color("red"));
				bridges.setDataStructure(&cg);
				bridges.visualize();

		}
catch (char const * s) {
		std::cerr << "exception caught: " << s << std::endl;
		return -1;
	}
	catch (rapidjson_exception re) {
		std::cerr << "rapidjson_exception: " << (std::string)re << std::endl;
	}

	return 0;
}
