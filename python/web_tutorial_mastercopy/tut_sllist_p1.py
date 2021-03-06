from bridges.bridges import *
from bridges.sl_element import *
import sys

#
# This tutorial creates a set of singly linked list elements, links them 
# and displays them
#
# Reference: SLelement, Bridges classes
#

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
    bridges.set_title("A Singly Linked List Example")
    bridges.set_description("A singly linked list of 4 nodes with names; the nodes in this example use string as the generic type")

	# create the list elements
    st0 = SLelement(e="Gretel Chaney")
    st1 = SLelement(e="Lamont Kyler")
    st2 = SLelement(e="Gladys Serino")
    st3 = SLelement(e="Karol Soderman")
    st4 = SLelement(e="Starr McGinn")

    # link the elements
    st0.next = st1
    st1.next = st2
    st2.next = st3
    st3.next = st4

    # we want to see these names in the visualization so we will 
    #set them as the nodes' labels. We will retrieve the nodes' 
    #generic data for the label
    st0.label = st0.value
    st1.label = st1.value
    st2.label = st2.value
    st3.label = st3.value
    st4.label = st4.value

    # tell Bridges the head of the list
    bridges.set_data_structure(st0)

    # visualize
    bridges.visualize()


if __name__ == "__main__":
    main()

