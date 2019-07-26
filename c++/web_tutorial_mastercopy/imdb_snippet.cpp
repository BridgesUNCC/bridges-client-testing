
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/ActorMovieIMDB.h"

using namespace bridges;

// This program fragment illustrates how to access and read the IMDB actor/movie data
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
	bridges.setTitle("Accessing IMDB Data");

	// create data source object
	DataSource ds (&bridges);

	// get the actor movie IMDB data through the BRIDGES API
	vector<ActorMovieIMDB> actor_list = ds.getActorMovieIMDBData(1814);

	// print out the first record of the dataset
	cout << "Actor-Movie Data:" << endl 
		<< "\tActor: " << actor_list[0].getActor() << endl 
		<< "\tMovie: " << actor_list[0].getMovie() << endl;

	return 0;
}

