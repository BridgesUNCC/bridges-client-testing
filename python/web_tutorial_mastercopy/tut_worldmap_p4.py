from bridges.bridges import *
from bridges.data_src_dependent import *
from bridges.dl_element import *
from bridges.world_map import *
from bridges.graph_adj_list import *
from bridges.rectangle import *
from bridges.circle import *
from bridges.text import *
from bridges.symbol_collection import *

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
    bridges.set_title("World Map Drawing Using BRIDGES")
    bridges.set_description("Labels a few cities using BRIDGES Symbols")

    # with no arguments to the function, gets all countries of the world
    country_data = get_world_map_data()
    wm = WorldMap(country_data)

	# lets add  a points to the map to illustrate how to identify cities 
    # we will use symbols for this

    scol = "red"
    fcol = "blue"
    fsize = 12.
    str_size = 1.

    sc = SymbolCollection()

    c1 = Circle(locx=-80.8431, locy=35.2271, r=1.)
    c1.stroke_color = scol
    c1.fillcolor = fcol
    c1.strok_size = str;
    sc.add_symbol(c1);

    l1 = Text()
    l1.set_anchor_location(-79.8431, 35.2271)
    l1.font_size = fsize
    l1.text = "Charlotte"
    sc.add_symbol(l1);

    c2 = Circle(locx=2.3514, locy=48.8576, r=1.)
    c2.stroke_color = scol
    c2.fillcolor = fcol
    c2.font_size = fsize
    c2.strok_size = str;
    sc.add_symbol(c2);

    l2 = Text()
    l2.set_anchor_location(3.3514,48.8576)
    l2.font_size = fsize
    l2.text = "Paris"
    sc.add_symbol(l2);

    c3 = Circle(locx=13.4, locy=52.52, r=1.)
    c3.stroke_color = scol
    c3.fillcolor = fcol
    c3.font_size = fsize
    c3.strok_size = str;
    sc.add_symbol(c3);

    l3 = Text()
    l3.set_anchor_location(14.4, 52.52)
    l3.font_size = fsize
    l3.text = "Charlotte"
    sc.add_symbol(l3);

    c4 = Circle(locx=77.208, locy=28.614, r=1.)
    c4.stroke_color = scol
    c4.fillcolor = fcol
    c4.font_size = fsize
    c4.strok_size = str;
    sc.add_symbol(c4);

    l4 = Text()
    l4.set_anchor_location(78.208, 28.614)
    l4.font_size = fsize
    l4.text = "New Delhi"
    sc.add_symbol(l4);


	# add the map overlay
    bridges.set_map(wm)

    #visualizes world map
    bridges.set_data_structure(sc)
    bridges.visualize()

if __name__ == '__main__':
    main()
