#include "Bridges.h"
#include "DataSource.h"
#include "Array.h"
#include "SLelement.h"
#include "ColorGrid.h"
#include <sstream>
#include <string>

using namespace bridges;

// This program fragment illustrates how to access and retrieve the song lyrics data 
int main(int argc, char* argv[]) {

	//create the Bridges object, set credentials
#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges(atoi(argv[1]), argv[2], argv[3]);
	if (argc > 4)
		bridges.setServer(argv[4]);
#else
	Bridges bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");
#endif

	// set title
	bridges.setTitle("Accessing Song Data");

	// create data source object
	DataSource ds (&bridges);

	// Get Song data 
	Song s = ds.getSong("Harder Faster Better Stronger", "Daft Punk");

	// print lyrics
	std::cout << "Title: " << s.getSongTitle() << endl 
			<< "Artist: " << s.getArtist() << endl 
			<< "Album Title:" << s.getAlbumTitle() << endl 
			<< "Released Date" << s.getReleaseDate() << endl 
			<< "Lyrics: " << endl << endl
			<< s.getLyrics()<<std::endl;

	return 0;
}
