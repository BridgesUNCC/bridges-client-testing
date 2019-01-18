from bridges.bridges import *
from bridges.data_src_dependent.data_source import *
from data_src_dependent.bst_eq.BST import *
import sys

def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials

    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    bridges.set_title("Recent Earthquakes(USGIS Data)")

    eqlist = get_earthquake_usgs_data(100)
    bst = BST()
    for i in range(len(eqlist)):
        if eqlist[i].get_magnitude() > 3:
            bst.insert(eqlist[i].get_magnitude(), eqlist[i])
            print(bst.node_count)

    bridges.set_data_structure(bst.get_tree_root())
    bridges.visualize()


if __name__ == '__main__':
    main()