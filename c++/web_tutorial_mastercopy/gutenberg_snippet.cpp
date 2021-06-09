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
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif


	// set title
	bridges.setTitle("Accessing Gutenberg Book Collection Meta Data");

	// read the Gutenberg book data
	DataSource ds (&bridges);
	GutenbergBook gbook = ds.getGutenbergBookMetaData(2701);

	// print the first book record
	cout << "Guttenberg Book Data:\n"; 
	cout << "\n\tTitle: "  << gbook.getTitle();
	cout << "\n\tId: "  << gbook.getId();

	cout << "\n\tAuthors:";
	for (auto& k: gbook.getAuthors()) 
		cout << "\t" << k << ",";
	cout << "\n\tDate Added: "  << gbook.getDateAdded();
	cout << "\n\tLanguage: " << gbook.getLang();
	cout << "\n\tGenres: \n\t\t";
	for (auto& i : gbook.getGenres())
		cout << i << ",";
	cout << "\n\n";

	cout << "Testing Search by title: Pride and Prejudice"  << endl;
	vector<GutenbergBook> gbook_list = ds.searchGutenbergBookData("Pride and Prejudie", "title");

	cout << "Print the first 3 books of search results\n";
	int n = 0;
	for (auto& b : gbook_list) {
		cout << b.getId() << "\n";
		cout << "\n\tLanguage:" << b.getLang();
		cout << "\n\tAuthors:";
		for (auto& k: b.getAuthors()) 
			cout << k << ",";
		cout << "\n\tTitle: "  << b.getTitle();
		if (++n == 3) break;
	}
	cout << "Testing Search by Language: English"  << endl;
	gbook_list = ds.searchGutenbergBookData("en", "language");
	cout << "Print the first 3 books of search results\n";
	n = 0;
	for (auto& b : gbook_list) {
		cout << b.getId() << "\n";
		cout << "\n\tLanguage:" << b.getLang();
		cout << "\n\tAuthors:";
		for (auto& k: b.getAuthors()) 
			cout << k << ",";
		cout << "\n\tTitle: "  << b.getTitle();
		if (++n == 3) break;
	}
	cout << "Testing search by Date: 2018"  << endl;
	gbook_list = ds.searchGutenbergBookData("2018-01-01", "date");
	cout << "Print the first 3 books of search results\n";
	n = 0;
	for (auto& b : gbook_list) {
		cout << b.getId() << "\n";
		cout << "\n\tLanguage:" << b.getLang();
		cout << "\n\tAuthors:";
		for (auto& k: b.getAuthors()) 
			cout << k << ",";
		cout << "\n\tTitle: "  << b.getTitle();
		if (++n == 3) break;
	}

	cout << "\n";

//	cout << "Testing  Getting Moby Dick text..\n";

//	string moby_dick_str = ds.getGutenbergText(2701);

//	cout << "First 200 chars:" << moby_dick_str.size() << "chars.\n";
//	for (int k = 0; k < 200; k++) 
//		cout << moby_dick_str[k];
//	cout << "\n";
	
	return 0;
}
