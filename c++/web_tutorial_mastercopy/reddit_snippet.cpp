
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Reddit.h"

using namespace bridges;

// This program fragment illustrates how to access and read the Reddit Post data 
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

	// set title
	bridges.setTitle("Accessing Reddit Data");

	// create data source object
	DataSource ds (&bridges);


	ds.setSourceType("local");
	
	vector<Reddit> reddit_list = ds.getRedditData("news", -9999);
	std::cout<<""<<reddit_list.size()<<" post returned"<<"\n";
	for (auto post : reddit_list) {
	  std::cout<<"Title: "<<post.getTitle()<<"\n";
	}
	
	
	return 0;
}

