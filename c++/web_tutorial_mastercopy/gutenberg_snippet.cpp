#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/GutenbergBook.h"

using namespace bridges;


// this program illustrates how to access the Gutenberg book meta data
int main(int argc, char **argv) {

	// create bridges object
#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
	if (argc > 4)
		bridges.setServer(argv[4]);
#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");
#endif


	// set title
	bridges.setTitle("Accessing Gutenberg Book Collection Meta Data");

	// read the Gutenberg book data
	DataSource ds (&bridges);
	GutenbergBook gbook = ds.getGutenbergBookMetaData(2701);

	// print the first book record
	cout << "Guttenberg Book Data:\n\n"; 
	cout << "\n\tTitle: "  << gbook.getTitle();
	cout << "\n\tId: "  << gbook.getId();

	cout << "\tAuthors:\n";
	for (auto& k: gbook.getAuthors()) 
		cout << "\t\t" << k << ",";
	cout << "\n\tDate Added: "  << gbook.getDateAdded();
	cout << "\n\tLanguage: ";
	for (auto& i : gbook.getLang())
		cout << "\t\t" << i << ",";
	cout << "\n\tGenres: \n\t\t";
	for (auto& i : gbook.getGenres())
		cout << i << ",";

	cout << "testing search function.."  << endl;
	vector<GutenbergBook> gbook_list = ds.searchGutenbergBookData("Pride and Prejudie", "title");

	for (auto & b : gbook_list) {
		cout << b.getId() << "\n";
	}
	


	return 0;
}
