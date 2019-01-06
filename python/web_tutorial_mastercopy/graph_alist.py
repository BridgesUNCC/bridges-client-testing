from bridges.data_src_dependent import *
from bridges.graph_adj_list import *
from bridges.bridges import *
import sys


def main():

    args = sys.argv[1:]

    # create the Bridges object, set credentials
    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    # set a title for the visualization
    bridges.set_title("A Simple Graph (Adjacency List) Example Using IMDB Actor/Movie Data")

    actor_movie_data = get_actor_movie_imdb_data(1813)

    # create an adjacency list based graph
    g = GraphAdjList()

    # first create vertices for two actors and add the to the graph
    a1 = "Kevin_Bacon_(I)"
    a2 = "Denzel_Washington"

    g.add_vertex(a1, "")
    g.add_vertex(a2, "")

    # add and edge between the two actors
    g.add_edge(a1, a2, 1)

    # color the two actor nodes
    g.get_vertices().get("Kevin_Bacon_(I)").get_visualizer().set_color(col_name="red")
    g.get_vertices().get("Denzel_Washington").get_visualizer().set_color(col_name="red")
    # make them a bit bigger
    g.get_vertices().get("Kevin_Bacon_(I)").get_visualizer().set_size(20)
    g.get_vertices().get("Denzel_Washington").get_visualizer().set_size(20)

    # get their nodes
    v1 = g.get_vertices().get(a1)
    v2 = g.get_vertices().get(a2)

    cnt1 = 0
    cnt2 = 0

    # we will find the first 15 immediate neighbors of the two actors
    # and color those links and nodes by following their adjacency lists
    for k in range(len(actor_movie_data)):
        # from the actor movie data, get and actor-movie pair
        a = actor_movie_data[k].get_actor()
        m = actor_movie_data[k].get_movie()

        if (a == "Kevin_Bacon_(I)" and cnt1 < 15):
            # add vertices for this movie and an edge for the link
            g.add_vertex(m, "")
            g.add_edge(a1, m, 1)
            g.add_edge(m, a1, 1)
            # make the movie node a bit transparent
            g.get_vertices().get(m).get_visualizer().set_opacity(0.5)
            cnt1 += 1

        elif (a == "Denzel_Washington" and cnt2 < 15):
            # add vertices for this movie and an edge for the link
            g.add_vertex(m, "")
            g.add_edge(a2, m, 1)
            g.add_edge(m, a2, 1)
            # make the movie node a bit transparent
            g.get_vertices().get(m).get_visualizer().set_opacity(0.5)
            cnt2 += 1

    # Next, we illustrate traversing the adjacency list and color the movie
    # nodes adjacent to the Kevin Bacon node

    # first get the adjacency list for Kevin Bacon
    head = g.get_adjacency_list().get("Kevin_Bacon_(I)")

    sle = head
    # traverse the adjacency list
    while(sle is not None):
        # get the terminating vertex
        term_vertex = sle.get_value().get_vertex()
        # find the corresponding element
        el = g.get_vertices().get(term_vertex)
        # set the color of the node except the Denzel W. node
        if(term_vertex != "Denzel Washington"):
            el.get_visualizer().set_color(col_name="green")
        sle = sle.get_next()

    # Pass the graph object to BRIDGES
    bridges.set_data_structure(g)
    # visualize the graph
    bridges.visualize()


if __name__ == "__main__":
    main()

