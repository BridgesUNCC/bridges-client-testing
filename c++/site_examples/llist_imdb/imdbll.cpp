
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

#include "actorList.h"
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/ActorMovieIMDB.h"

using namespace bridges;

int main(int argc, char **argv) {
	string hilite_color = "orange", 
			def_color = "green",
			end_color = "red";

					// track the number of movies by actor
	unordered_map<string, int>  *movie_cnt = new unordered_map<string, int>; 
		
							// BRIDGES initializations
	Bridges *bridges = new Bridges(100, argv[1], argv[2]);
	bridges->set_title("Linked List Example: IMDB Actor-Movie Data");
	bridges->set_description("A linked list example using IMDB actor movie data. Here we see a list of 1813 actors with their movies displayed. Mouseover the node and zoom in using the middle button to see the movies of this actor. The node colors from blue to red are mapped to the number of movies.");


	ActorList<ActorMovieIMDB> *actor_list = new ActorList<ActorMovieIMDB>;

							// get the actor movie data
	DataSource *ds = new DataSource;
	vector<ActorMovieIMDB> actor_data = ds->getActorMovieIMDBData(1813);

							//read and build linked list of actors/movies
	for (int k = 0; k < 1813; k++) {
		actor_list->insertActor(actor_data[k].getActor(), 
					actor_data[k].getMovie(), movie_cnt);
	}
							// color the nodes by movie count
	
	for (SLelement<ActorMovieIMDB> *curr = actor_list->getFront(); curr != nullptr; curr = curr->getNext()) {
		string actor = curr->getValue().getActor();
		int cnt =  (*movie_cnt)[actor];
		if (cnt < 10)
			curr->getVisualizer()->setColor (Color("blue"));
		else if (cnt < 20)
			curr->getVisualizer()->setColor (Color("green"));
		else if (cnt < 30)
			curr->getVisualizer()->setColor (Color("yellow"));
		else if (cnt < 40)
			curr->getVisualizer()->setColor (Color("orange"));
		else if (cnt < 50)
			curr->getVisualizer()->setColor (Color("magenta"));
		else curr->getVisualizer()->setColor (Color("red"));
	}

								// highlight the ends of the lists
	if (actor_list->length())
		actor_list->getFront()->getNext()->getVisualizer()->setColor(end_color);
	if (actor_list->length() > 1)
		actor_list->getEnd()->getVisualizer()->setColor(end_color);
	cout << "List Size:" << actor_list->length() << endl;

	bridges->setDataStructure(actor_list->getFront()->getNext());
	bridges->Bridges::visualize();

/*
		System.out.print(
	"\n\n1(Find Actor)\n\n2(Insert Actor/Movie pair)\n\n4(Quit):\n\n Command: ");
		int ch;
		Scanner  sc = new Scanner(System.in);
		String actor_name, movie_name;
		while ((ch = System.in.read()) != '4') {
			switch (ch) {
				case '1': 
					System.out.print("\tEnter Actor Name:");
					actor_name = sc.next();
					if (actor_list.find_actor(actor_name)) {
						if (actor_list.getCurrent() != null)
							actor_list.getCurrent().getNext()
								.getVisualizer().setColor(COLOR_HIGHLIGHT);
System.out.println("Found " + actor_list.getCurrent().getNext().getValue().getActorName());
						Bridges::visualize();
					}
					break;
				case '2':
					System.out.print("\tEnter Actor/Movie pair:");
					actor_name = sc.next();
					movie_name = sc.next();
					System.out.print("Entered " + actor_name + "," + movie_name);
					actor_list.find_and_insert(actor_name, movie_name);
					actor_list.getCurrent().getNext()
								.getVisualizer().setColor(COLOR_HIGHLIGHT);
					Bridges::visualize();
					break;
				case '4':
					break;
			}
	System.out.print(
	"\n\n1(Find Actor)\n\n2(Insert Actor/Movie pair)\n\n4(Quit):\n\n Command: ");
		}
*/
	return 0;
}
