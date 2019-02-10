from bridges.bridges import *
from bridges.data_src_dependent.data_source import *
from data_src_dependent.bst_games.BST import *
import sys

def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials

    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    bridges.set_title("Binary Search Tree with IGN Game Data")

    game_list = get_game_data()

    bst = BST()
    for i in range(5000):
        bst.insert(game_list[i].get_title(), game_list[i])

    bridges.set_data_structure(bst.get_tree_root())
    bridges.visualize()

if __name__ == '__main__':
    main()