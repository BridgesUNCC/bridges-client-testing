#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Shakespeare.h"

using namespace bridges;


int main(int argc, char **argv) {
		
	// create Bridges object
#if TESTING
                        // command line args provide credentials and server to test on
    Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
    if (argc > 4)
        bridges.setServer(argv[4]);
#else
    Bridges bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", 
                                "YOUR_API_KEY");
#endif
								// read the earth quake  data and build the BST

	bridges.setTitle("Accessing Shakespeare Plays, Poems, Sonnets Dataset");

						// create a data source object
	DataSource ds (&bridges);

						// get the data
    vector<Shakespeare> shakespeare_data = ds.getShakespeareData();

						// print the first record
	cout << endl << "Shakespeare Data:" <<  endl << 
		"Title: " << shakespeare_data[0].getTitle()  <<  endl << 
		"Type: " << shakespeare_data[0].getType() <<  endl << 
		"Text: " << shakespeare_data[0].getText() << endl;	


	return 0;
}
