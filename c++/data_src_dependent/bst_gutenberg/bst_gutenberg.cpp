#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/GutenbergBook.h"
#include "BSTElement.h"
#include "BST.h"

#define LOCAL_SERVER 0

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

								// read the earth quake  data and build the BST

	bridges.setTitle("BST Example: Gutenberg Book Collection");

	DataSource ds (&bridges);

    vector<GutenbergBook> book_list = ds.getGutenbergBookData();

    BST<string, GutenbergBook> bst;

	for (int k = 0; k < book_list.size(); k++) {
		GutenbergBook b = book_list[k];
		bst.insert(b.getTitle(), b);
	}


					// visualize the binary search tree
	bridges.setDataStructure(bst.getRoot());
	bridges.visualize();

	return 0;
}
