#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/ActorMovieIMDB.h"
#include "BSTElement.h"
#include "BST.h"


using namespace bridges;


int main(int argc, char **argv) {
	string hilite_color = "orange", 
			def_color = "green",
			end_color = "red";

	if (argc < 3) {
		cout << "Must provide both user id and api key as command line arguments. Terminating.." 
								<< endl;
		exit (-1);
	}	
	Bridges *bridges = new Bridges(10, argv[1], argv[2]);
	if (argc == 4)
		bridges->setServer(argv[3]);
								// read the earth quake  data and build the BST

	bridges->setTitle("BST Example: IMDB Data");
    vector<ActorMovieIMDB> actor_list = DataSource::getActorMovieIMDBData2(10);

	BST<string, string> *bst = new BST<string, string> ();

	cout << "Size:" << actor_list.size() << endl;

					// store actors in a map and store all their movies 
	unordered_map<string, string> act_map; 
	for (int k = 0; k < actor_list.size(); k++) {
		ActorMovieIMDB a = actor_list[k];

		string actor = a.getActor(), movie = a.getMovie();
		if (act_map.find(actor) != act_map.end()) 
			act_map[actor] = act_map[actor] + "\\n" + movie + "  [Rating :" + to_string(a.getMovieRating()) + " ]";
		else 
			act_map[actor] = movie + "  [Rating :" + to_string(a.getMovieRating()) + " ]";  
	}
	for (auto& k : act_map) 
		bst->insert(k.first, k.second);

					// visualize the binary search tree
	bridges->setDataStructure(bst->getRoot());
	bridges->visualize();

	return 0;
}
