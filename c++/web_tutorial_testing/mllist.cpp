
#include "Bridges.h"
#include "MLelement.h"

using namespace bridges;

int main(int argc, char **argv)  {
                        // command line args provide credentials and server to test on
    //Bridges *bridges =  new Bridges(atoi(argv[1]), argv[2], argv[3]);
    Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
    
    if (argc > 4)
        bridges.setServer(argv[4]);

	bridges.setTitle("A Multilist Example");
	bridges.setDescription("The multilist example should have one large red node, three small square red nodes, "
				"and eight neutral nodes. The larger red node is connected via a red link to a neutral node. The next "
				"link from the neutral node is blue followed by a cyan link between two of the small square red nodes.");


	//create  a linked list

	MLelement<int> *el0 = new MLelement<int>("0");
	MLelement<int> *el1 = new MLelement<int>("1");
	MLelement<int> *el2 = new MLelement<int>("2");
	MLelement<int> *el3 = new MLelement<int>("3");
	MLelement<int> *el4 = new MLelement<int>("4");

	el0->setNext(el1);
	el1->setNext(el2);
	el2->setNext(el3);
	el3->setNext(el4);
	// create a sublist from 2
	MLelement<int> *el5 = new MLelement<int>("5");
	MLelement<int> *el6 = new MLelement<int>("6");
	MLelement<int> *el7 = new MLelement<int>("7");

	el5->setNext(el6);
	el6->setNext(el7);

	el2->setSubList(el5);

	MLelement<int> *el8 = new MLelement<int>("8");
	MLelement<int> *el9 = new MLelement<int>("9");

	// create a second sublist from 3
	el8->setNext(el9);
	el3->setSubList(el8);

	// create a sublist from 5
	MLelement<int> *el10 = new MLelement<int>("10");
	MLelement<int> *el11 = new MLelement<int>("11");
	el10->setNext(el11);
	el6->setSubList(el10);

	el0->setSize (40);
	el0->getLinkVisualizer(el1)->setColor("red");
	el0->getLinkVisualizer(el1)->setThickness(3);
	el1->getLinkVisualizer(el2)->setColor("blue");
	el1->getLinkVisualizer(el2)->setThickness(3);
	el2->getLinkVisualizer(el3)->setColor("cyan");
	el2->getLinkVisualizer(el3)->setThickness(3);

	el0->setColor(Color("red"));
    
	//set visualizer type
	bridges.setDataStructure(el0);

	// visualize the list
	bridges.visualize();
}
