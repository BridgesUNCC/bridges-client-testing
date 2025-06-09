from bridges.bridges import *
from bridges.data_src_dependent import *
from bridges.dl_element import *
from bridges.world_map import *
from bridges.graph_adj_list import *

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
    bridges.set_title("World Map Using BRIDGES")
    bridges.set_description("Draws all countries and their boundaries in a default color")

    # with no arguments to the function, gets all countries of the world
    country_data = get_world_map_data()
    wm = WorldMap(country_data)

	# lets add  a points to the map to illustrate how to identify cities 
    # we will use graph vertices for this

    gr = GraphAdjList()
    gr.add_vertex("Charlotte", "Charlotte,NC")
    gr.get_vertex("Charlotte").set_location(-80.8431, 35.2271)
    gr.get_vertex("Charlotte").color = "crimson"
    gr.get_vertex("Charlotte").size = 2.

    gr.add_vertex("Paris", "Paris, France")
    gr.get_vertex("Paris").set_location(2.3514, 48.8576)
    gr.get_vertex("Paris").color = "crimson"
    gr.get_vertex("Paris").size = 2.

    gr.add_vertex("Berlin", "Berlin, Germany")
    gr.get_vertex("Berlin").set_location(13.4, 52.52)
    gr.get_vertex("Berlin").color = "crimson"
    gr.get_vertex("Berlin").size = 2.

    gr.add_vertex("New Delhi", "New Delhi, India")
    gr.get_vertex("New Delhi").set_location(77.208, 28.614)
    gr.get_vertex("New Delhi").color = "crimson"
    gr.get_vertex("New Delhi").size = 2.

    gr.add_vertex("Buenos Aires", "Buenos Aires, Argenina")
    gr.get_vertex("Buenos Aires").set_location(-58.382, -34.60)
    gr.get_vertex("Buenos Aires").color = "crimson"
    gr.get_vertex("Buenos Aires").size = 2.

    gr.add_vertex("Esperanza Station, Antarctica", "Esperanza Station, Antarctica")
    gr.get_vertex("Esperanza Station, Antarctica").set_location(-56.59, -63.24)
    gr.get_vertex("Esperanza Station, Antarctica").color = "crimson"
    gr.get_vertex("Esperanza Station, Antarctica").size = 2.

	# add the map overlay
    bridges.set_map(wm)

    #visualizes world map
    bridges.set_data_structure(gr)
    bridges.visualize()

if __name__ == '__main__':
    main()
