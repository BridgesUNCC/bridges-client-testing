#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"

using namespace bridges;

int main(int argc, char **argv) {

	// create bridges object
#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
	if (argc > 4)
		bridges.setServer(argv[4]);
#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif

	// set title
	bridges.setTitle("Using World Map overlay");

	DataSource ds(&bridges);

	bridges.setMapOverlay(true);
	bridges.setCoordSystemType("equirectangular");
	bridges.setMap("all");
	
	SLelement<string>  *el0 = new SLelement<string> ("Charlotte", "Go Niners!");
	el0->setLocation(-80.8431, 35.2271); //35.2271N, 80.8431W
	
	
	bridges.setDataStructure(el0);
	bridges.visualize();

	delete el0;
	
	return 0;
}
