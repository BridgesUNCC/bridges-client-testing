#include "Bridges.h"
#include "LineChart.h"


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
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
                                "YOUR_API_KEY");
#endif

	bridges.setTitle("Sorting Benchmark");
	bridges.setDescription("Sorting Benchmark test");

	LineChart plot;
	plot.setTitle("linechart plot");

	vector<double> x1 = {1, 3, 5, 20};
	vector<double> y1 = {2, 3, 5, 20};
	plot.setDataSeries("1", x1, y1);
	bridges.setDataStructure(plot);
	bridges.visualize();

	vector<double> x2 = {2, 15.2,  40};
	vector<double> y2 = {4, 30.5, 400.99};
	plot.setDataSeries("2", x2, y2);
	bridges.visualize();


	plot.toggleLogarithmicX(true);

	bridges.visualize();

	plot.toggleMouseTrack(true);
	plot.toggleLogarithmicY(true);

	bridges.setVisualizeJSONFlag(true);
	
	bridges.visualize();
}
