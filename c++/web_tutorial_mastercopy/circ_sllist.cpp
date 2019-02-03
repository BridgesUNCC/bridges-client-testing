/**
 * Created by Kalpathi Subramanian, 1/30/18
 * krs@uncc.edu
 */

#include "Bridges.h"
#include "CircSLelement.h"
#include "StudentInfo.h"

using namespace bridges;

int main (int argc, char **argv) {
#if TESTING
                        // command line args provide credentials and server to test on
    //Bridges *bridges =  new Bridges(atoi(argv[1]), argv[2], argv[3]);
    Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
    
    if (argc > 4)
        bridges.setServer(argv[4]);

	bridges.setTitle("A Circle Singly Linked List Example");
	bridges.setDescription("This example shows five nodes. Each node is linked only to its child node. "
				"Colors are: A green node with a yellow link size 12, a blue node with a magenta link size 9, "
				"a magenta node with a blue link size 9, a red node with a magenta link size 11, and a yellow node with "
				"a red link size 15.");
			
#else
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
                                "YOUR_API_KEY");
#endif

	// create the linked list elements with
	// student data
	CircSLelement<StudentInfo> *students[] = {
		new CircSLelement<StudentInfo>(
			StudentInfo(
				"00000000000",
				"Gretel Chaney",
				"CS",
				"g.chaney@generated.com",
				"magenta",
				"blue",
				9.0
			), ""),
		new CircSLelement<StudentInfo>(
			StudentInfo(
				"00000000001",
				"Karol Soderman",
				"SIS",
				"k.soderman@generated.com",
				"magenta",
				"red",
				11.0
			), ""),
		new CircSLelement<StudentInfo>(
			StudentInfo(
				"00000000002",
				"Lamont Kyler",
				"BIO",
				"l.kyler@generated.com",
				"yellow",
				"green",
				12.0
			), ""),
		new CircSLelement<StudentInfo>(
			StudentInfo(
				"00000000003",
				"Gladys Serino",
				"CS",
				"g.serino@generated.com",
				"green",
				"magenta",
				9.0
			), ""),
		new CircSLelement<StudentInfo>(
			StudentInfo(
				"00000000004",
				"Starr Mcginn",
				"CS",
				"s.mcginn@generated.com",
				"red",
				"cyan",
				15.0
			), "")
	};

	CircSLelement<StudentInfo> *head =  students[0];
	CircSLelement<StudentInfo> *current =  head;

	int num_students = 5;
	for (int i = 1; i < num_students; i++) {
		current->setNext(students[i]);
		current = current->getNext();
	}
	//  point the last element to the first element,
	current->setNext(head);

	//  add visual attributes
	current = head;
	do {
		current->setLabel(current->getValue().getStudentLabel());
		current->getVisualizer()->setColor(current->getValue().getFavoriteColor());

		current->getLinkVisualizer(current->getNext())->setColor(current->getValue().getDislikeColor());
		current->getLinkVisualizer(current->getNext())->setThickness(current->getValue().getStudentCreditHours() * 0.5);

		current = current->getNext();
	}   while (current != head);


	// set data structure to point to head
	bridges.setDataStructure(head);
	// visualize the circular list
	bridges.visualize();
}
