/**
 * Created by Kalpathi Subramanian, 1/30/18
 * krs@uncc.edu
 */

#include "Bridges.h"
#include "DataSource.h"
#include "BarChart.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace bridges;


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

	BarChart bar;
	bar.setTitle("Hello World BarChart!");
	bar.setSubTitle("Woah!");
	bar.setBinsLabel("Country");
	bar.setSeriesLabel("Population");
	bar.setBarAlignment("horizontal");
	bar.setTooltipSuffix(" millions");

	vector<string> bins{"africa", "america", "Asia", "Europe"};
	bar.setSeriesBins(bins);

	vector<double> y1{10, 100, 40, 23};
	vector<double> y2{100, 10, 80, 232};
	bar.addDataSeries("year 1", y1);
	bar.addDataSeries("year 2", y2);

	bridges.setDataStructure(bar);
	bridges.visualize();


	return 0;
}
