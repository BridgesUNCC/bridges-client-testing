from bridges.data_src_dependent import *
from bridges.graph_adj_list import *
from bridges.bridges import *
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
    bridges.set_title("testing edgevalue")
    bridges.set_description("edgevalue test")

    # create an adjacency list based graph
    g = GraphAdjList()

    a = "a"
    b = "b"
    c = "c"
    
    g.add_vertex(a, "")
    g.add_vertex(b, "")
    g.add_vertex(c, "")

    # add  edges
    g.add_edge(a, b, data=12)
    g.add_edge(a, c, data=12)
    
    if g.get_edge_data(a,b) != 12:
        exit (-1);
        
    if g.get_edge_data(a,c) != 12:
        exit (-1);
        
    if g.get_edge_data(b,c) != None:
        exit (-1);    
        

if __name__ == "__main__":
    main()

