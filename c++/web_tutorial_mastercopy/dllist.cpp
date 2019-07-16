
#include "Bridges.h"
#include "DLelement.h"
#include <string>

using namespace bridges;
using std::string;

// helper function

DLelement<string> *insertFront(DLelement<string> *front, 
					DLelement<string> *new_el);

int main(int argc, char **argv) {
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
	bridges.setTitle("A doubly Linked List Example");

	// set description
	bridges.setDescription("This list has five nodes all linked to the nodes before and after them and illustrates visual attributes. ");


	// create some elements
	DLelement<string>  *el0 = new DLelement<string> ("Gretel Chaney", "Gretel Chaney");
    DLelement<string>  *el1 = new DLelement<string> ("Lamont Kyler", "Lamont Kyler");
    DLelement<string>  *el2 = new DLelement<string> ("Gladys Serino", "Gladys Serino");
    DLelement<string>  *el3 = new DLelement<string> ("Karol Soderman", "Karol Soderman");
    DLelement<string>  *el4 = new DLelement<string> ("Starr McGinn", "Starr McGinn");
	
	// insert the students into the  front of the list
	DLelement<string> *head = nullptr;
	head = insertFront(head, el0);
	head = insertFront(head, el1);
	head = insertFront(head, el2);
	head = insertFront(head, el3);
	head = insertFront(head, el4);

	// add  element colors
	// set colors for list elements - see the Color class for supported colors
    el0->setColor("red");
    el2->setColor("aliceblue");

    // color the links - must specify a valid terminating element
    el0->getLinkVisualizer(el1)->setColor("green");
	// color the reverse link
    el1->getLinkVisualizer(el0)->setColor("magenta");

    // adjust link thickness
    el3->getLinkVisualizer(el4)->setThickness(3.0f);
    el4->getLinkVisualizer(el1)->setThickness(3.0f);

    // set node transparency
    el4->setOpacity (0.5f);

    // set node size
    el0->setSize (20);

	bridges.setDataStructure(head);
	bridges.visualize();

	return 0;
}

DLelement<string> *insertFront(DLelement<string> *front,
	DLelement<string> *new_el) {
	if (front == nullptr)
		return new_el;

	new_el->setNext(front);
	front->setPrev(new_el);

	return new_el;
}
