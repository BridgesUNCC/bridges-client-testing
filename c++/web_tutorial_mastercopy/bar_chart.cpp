/**
 * Created by Kalpathi Subramanian, 1/30/18
 * krs@uncc.edu
 */

#include "Bridges.h"
#include "BarChart.h"

using namespace bridges;
using namespace std;


int main (int argc, char **argv) {
	// create Bridges object
#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);

	if (argc > 4)
		bridges.setServer(argv[4]);


#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif
	// set title
	bridges.setTitle("A Bar Chart Example");

	// set  description
	bridges.setDescription("Demonstrates how to  draw a  bar chart using BRIDGES");

	// create the linked list elements with student names
	BarChart bc;
	
	bc.setXLabel ("US States");
	bc.setYLabel ("Population");
	
	vector<double> pop_data{10550000., 19840000., 39240000., 29530000., 10960000.};
	vector<string> bins {"North Carolina", "New York", "California", "Texas",
								"Rhode Island"};
	bc.setSeriesBins(bins);

	bc.addDataSeries ("State Populations", pop_data);

	bridges.setDataStructure(&bc);
	bridges.visualize();
}
