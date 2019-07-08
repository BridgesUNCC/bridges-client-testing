
#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/EarthquakeUSGS.h"
#include "book.h"
#include "BSTElement.h"
#include "BST.h"


using namespace bridges;

int max_quakes = 1000;

int main(int argc, char **argv) {
	string hilite_color = "orange",
		   def_color = "green",
		   end_color = "red";

#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
	if (argc > 4)
		bridges.setServer(argv[4]);
#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");
#endif
	// read the earth quake  data and build the BST
	bridges.set_title("Recent Earthquakes (USGIS Data)");

	DataSource ds (&bridges);
	vector<EarthquakeUSGS> eq_list = ds.getEarthquakeUSGSData(max_quakes);

	BST<float, EarthquakeUSGS> bst;

	for (int k = 0; k < max_quakes; k++) {
		EarthquakeUSGS eq = eq_list[k];
		bst.insert(eq.getMagnitude(), eq);
	}

	// visualize the binary search tree
	bridges.setDataStructure(bst.getRoot());
	bridges.visualize();

	return 0;
}
