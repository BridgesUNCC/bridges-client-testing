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
		
	Bridges *bridges = new Bridges(201, argv[1], argv[2]);
	bridges->setServer (argv[3]);
								// read the earth quake  data and build the BST

	bridges->setTitle("BST Example: Gutenberg Book Collection");

	DataSource *ds = new DataSource;

    vector<GutenbergBook> book_list = ds->getGutenbergBookData();

	BST<string, GutenbergBook> *bst = new BST<string, GutenbergBook> ();

	for (int k = 0; k < book_list.size(); k++) {
		GutenbergBook b = book_list[k];
		bst->insert(b.getTitle(), b);
	}


					// visualize the binary search tree
	bridges->setDataStructure(bst->getRoot());
	bridges->visualize();

	return 0;
}
