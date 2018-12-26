#ifndef ACTOR_LIST_H

#define ACTOR_LIST_H

#include "data_src/ActorMovieIMDB.h"
#include "SLelement.h"
#include "llist.h"
#include <unordered_map>

using namespace bridges;

template<typename E> class ActorList: public LList<E> {
	
	private:
		int nodesTraversed;

	public: 
		bool findActor(string actor_name) { 
			SLelement<ActorMovieIMDB> *tcurr = this->getFront();
	
			while (tcurr->getNext() != NULL) {
								// compare actor names
				ActorMovieIMDB a = (ActorMovieIMDB) tcurr->getNext()->getValue();
				if (actor_name == a.getActor() ){ // found actor
									// unhilite old current node
					this->getCurrent()->getNext()->getVisualizer()->setColor(Color("green"));
										// hilite the new current node
					tcurr->getNext()->getVisualizer()->setColor(Color("orange"));
					return true;
				}
				tcurr = tcurr->getNext();
			}
			return false;
		}
	
		void insertActor(string actor_name, string movie_name, 
						unordered_map<string, int> *movie_cnt) { 
			this->moveToStart();
			SLelement<E>* curr = this->getCurrent();
			bool found = false;
			ActorMovieIMDB a(actor_name, movie_name);

			(*movie_cnt)[actor_name]++;
			if (this->length()) { // non empty list
				while ((curr->getNext() != this->getEnd()) && !found) {
											// compare actor names
					ActorMovieIMDB a = (ActorMovieIMDB) curr->getNext()->getValue();
					int comparison_result = actor_name.compare(a.getActor());
					if (comparison_result == 0 ){ // found it
						found = true;
												// must modify the node
					
						string movies = a.getMovie() + "\n  " + movie_name;  
						curr->getNext()->setValue(ActorMovieIMDB(a.getActor(), 
											movies) );
											// update label
						curr->getNext()->setLabel(a.getActor() + "\n  " + 
								a.getMovie());
											// update movie count
					}
					else if (comparison_result < 0) {// found insertion point, insert
						found = true;
						this->insert(ActorMovieIMDB(actor_name, movie_name));
						curr->getNext()->setLabel(actor_name + "\n  " + movie_name + " ");
					}
					else { 
						this->next();
						curr = curr->getNext();
					}
				}
			}
			if (!found)	{// empty list or insertion point at end of list
				this->insert(ActorMovieIMDB(actor_name, movie_name));
				this->getCurrent()->getNext()->setLabel(actor_name + ":\n  " + movie_name);
			}
		}
};
#endif
