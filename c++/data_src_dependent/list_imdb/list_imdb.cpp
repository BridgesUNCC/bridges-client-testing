#include "Bridges.h"
#include "DataSource.h"
#include "Array.h"
#include "SLelement.h"


using namespace bridges;

int main(int argc, char **argv) {

	//create the Bridges object, set credentials
	Bridges *bridges = new Bridges(309, argv[1], argv[2]);
	bridges->setServer(argv[3]);
	
	bridges->setTitle("List with  IMDB Actor/Movie Data");

	DataSource *ds = new DataSource;
	std::vector< ActorMovieIMDB > ami = ds->getActorMovieIMDBData();

	//building linked list
	SLelement<ActorMovieIMDB>* head = nullptr;

	for (auto im : ami) {
	  SLelement<ActorMovieIMDB>* newone = new SLelement<ActorMovieIMDB> (im,
									     im.getActor() + " - " + im.getMovie());
	  newone->setNext(head);
	  head = newone;
	}
	
	// tell Bridges what data structure to visualize
	bridges->setDataStructure(head);

	// visualize the list
	bridges->visualize();

	//free memory
	while (head != nullptr) {
	  auto next = head->getNext();
	  delete head;
	  head = next;
	}
	
	return 0;
}
