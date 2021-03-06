#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Game.h"
#include "BSTElement.h"
#include "BST.h"


using namespace bridges;


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
		
	bridges.setTitle("BST Example: IGN Game Data");
								// read the data and build the BST

	DataSource ds (&bridges);
    vector<Game> game_list = ds.getGameData();

    BST<string, Game> bst;

	for (int k = 0; k < 1000;k++) {
		Game g = game_list[k];
		bst.insert(g.getTitle(), g);
	}
					// visualize the binary search tree
	bridges.setDataStructure(bst.getRoot());
	bridges.visualize();

	return 0;
}
