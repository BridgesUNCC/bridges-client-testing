
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
		
	Bridges *bridges = new Bridges(101, argv[1], argv[2]);

								// read the earth quake  data and build the BST
	bridges->setTitle("Recent Earthquakes (USGIS Data)");

	DataSource *ds = new DataSource;
    vector<EarthquakeUSGS> eq_list = ds->getEarthquakeUSGSData(max_quakes);

	BST<float, EarthquakeUSGS> *bst = new BST<float, EarthquakeUSGS> ();

	for (int k = 0; k < max_quakes; k++) {
		EarthquakeUSGS eq = eq_list[k];
		if (eq.getMagnitude() > 3.)
			bst->insert(eq.getMagnitude(), eq);
	}
	bst->setProperties(bst->getRoot());

					// visualize the binary search tree
	bridges->setDataStructure(bst->getRoot());
	bridges->visualize();

	return 0;
}
