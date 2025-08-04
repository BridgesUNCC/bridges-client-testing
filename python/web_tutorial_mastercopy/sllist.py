from bridges.bridges import *
from bridges.sl_element import *
import sys


def main():


    # create the Bridges object, set credentials
#if TESTING
    # command line args provide credentials and server to test on
    args = sys.argv[1:]
    bridges = Bridges(int(args[0]), args[1], args[2])
    if len(args) > 3:
        bridges.connector.set_server(args[3])
#else
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")
#endif

    # set title, description
    bridges.set_title("A Single Linked List Example")
    bridges.set_description("A singly linked list of node with student names, where each node is linked only to the next node in the list. Illustrates Node and link coloring, node size, link thickness and opacity")

	# create the list elements
    el0 = SLelement(e="Gretel Chaney", label="Gretel Chaney")
    el1 = SLelement(e="Lamont Kyler", label="Lamont Kyler")
    el2 = SLelement(e="Gladys Serino", label="Gladys Serino")
    el3 = SLelement(e="Karol Soderman", label="Karol Soderman")
    el4 = SLelement(e="Starr McGinn", label="Starr McGinn")

    # link the elements
    el0.next = el1
    el1.next = el2
    el2.next = el3
    el3.next = el4

    el0.color = "red"
    el2.color = "aliceblue"

    # color the links - must specify a valid terminating element
    el0.get_link_visualizer(el1).color = "green"
    el3.get_link_visualizer(el4).color = "magenta"

    # set link label
    el2.get_link_visualizer(el3).set_label("Gladys->Karol")

	# turn on element and link labels
    bridges.element_label_flag = True
    bridges.link_label_flag = True

    # visualize
    bridges.set_data_structure(el0)
    bridges.visualize()


if __name__ == "__main__":
    main()

