from bridges.bridges import *
from bridges.tree_element import *
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

    # title, description
    bridges.set_title("A General Tree Example")
    bridges.set_description("A basic tree with seven nodes. Three on one side and three on the other. The root node is set to red with 0.3 opacity. The other six nodes are neutral color.")

    # create tree nodes
    t0 = TreeElement(e="Hello", label="Hello")
    t2 = TreeElement(e="this", label="this")
    t3 = TreeElement(e="is", label='is')
    t4 = TreeElement(e="a", label='a')
    t5 = TreeElement(e="generic", label="generic")
    t6 = TreeElement(e="tree", label='tree')
    t7 = TreeElement(e="representation", label="representation")

    # add links to children
    t0.add_child(t2)
    t0.add_child(t3)
    t0.add_child(t4)
    t2.add_child(t5)
    t2.add_child(t6)
    t3.add_child(t7)

    # set visualizer type
    bridges.set_data_structure(t0)

    # visualize the tree
    bridges.visualize()


if __name__ == "__main__":
    main()

