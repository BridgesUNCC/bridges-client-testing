#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/State.h"
#include "data_src/County.h"

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

	DataSource ds (&bridges);

	cout << "Retrieving US State County Map Data" << endl;


	vector<string> states = {"North Carolina","Georgia"};
	vector<State> state_info = ds.getUSStateCountyData (states);

	// print info
	for (auto st : state_info) {
		cout << "State: " << st.getStateName() << "\n";
		vector<County> counties = st.getCounties();
		int k = 0; 
		for (auto c : counties) {
			if (k++ < 10)
			cout <<  "\t" << c.getCountyName() << endl; 
		}
	}

	return 0;
}
