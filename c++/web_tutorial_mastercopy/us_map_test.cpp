#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/State.h"
#include "data_src/County.h"
#include "USMap.h"

using namespace bridges;

// this program illustrates how to access the data of the US state county
// maps and apply attributes to them
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
	bridges.setTitle("Accessing US State County Maps");

	DataSource ds(&bridges);

	cout << "Retrieving US State County Map Data" << endl;


	vector<string> states = {"Vermont", "Iowa"};
	vector<bridges::dataset::State> 
		map_data = ds.getUSStateCountyMapData (states);


	// 
	// now do what needs to be done as part of your assignment
	// 

	// this will prepare the dataset for visualization
	// print info
	for (auto& st : map_data) {
		cout << "State: " << st.getStateName() << "\n";
		unordered_map<string, County> counties = st.getCounties();
		st.setViewCountiesFlag(false);
		int k = 0; 
		for (auto c : counties) {
			c.second.setHideFlag(true);
			if (k++ < 10)
			cout <<  "\t" << c.second.getCountyName() << endl; 
		}
	}
	USMap us_maps(map_data);

	bridges.setDataStructure(&us_maps);
bridges.setJSONFlag(true);
	bridges.visualize();

	return 0;
}
