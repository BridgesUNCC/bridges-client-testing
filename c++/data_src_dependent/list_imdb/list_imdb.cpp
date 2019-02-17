#include "Bridges.h"
#include "DataSource.h"
#include "Array.h"
#include "SLelement.h"


using namespace bridges;

int main(int argc, char **argv) {

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
	
	bridges.setTitle("List with  IMDB Actor/Movie Data");

	DataSource ds (&bridges);
	std::vector< ActorMovieIMDB > ami = ds.getActorMovieIMDBData();

	//building linked list
	SLelement<ActorMovieIMDB>* head = nullptr;

	for (auto im : ami) {
	  SLelement<ActorMovieIMDB>* newone = new SLelement<ActorMovieIMDB> (im,
									     im.getActor() + " - " + im.getMovie());
	  newone->setNext(head);
	  head = newone;
	}
	
	// tell Bridges what data structure to visualize
	bridges.setDataStructure(head);

	// visualize the list
	bridges.visualize();

	//free memory
	while (head != nullptr) {
	  auto next = head->getNext();
	  delete head;
	  head = next;
	}
	
	return 0;
}
