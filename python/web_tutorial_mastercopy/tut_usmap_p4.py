from bridges.bridges import *
from bridges.data_src_dependent import *
from bridges.dl_element import *
from bridges.us_map import *
from bridges.symbol_collection import *
from bridges.circle import *
from bridges.rectangle import *
from bridges.polyline import *
from bridges.text import *

# This program illustrates how to access the data of the US map with state
# boundaries with 2 cities represented as symbols overlaid

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
    bridges.set_title("Tutorial: Drawing US Map with  Symbols Overlaid")
    bridges.set_description("All US states, with 2 Cities located")


	# draw some symbols to indicate two cities
    sc = SymbolCollection()

    # create a circle symbol
    c = Circle(locx=-80.8431, locy=35.2271, r=1.)
    c.stroke_color = "red"
    c.fill_color = "cyan"
    sc.add_symbol(c)

    # create a label
    l = Text()
    l.set_anchor_location(-79.8431, 35.2271)
    l.font_size = 18.0
    l.stroke_width = 1.0
    l.text = "Charlotte"
    l.stroke_color = "purple"
    l.opacity = 1.0
    sc.add_symbol(l)

    # create a rectangle symbol
    r = Rectangle(locx=-82.998, locy=39.96, w=1., h=1.)
    r.stroke_color = "red"
    r.fill_color = "lightgreen"
    sc.add_symbol(r)

    # create a label
    l2 = Text()
    l2.set_anchor_location(-81.998, 39.96)
    l2.font_size = 18.0
    l2.stroke_width = 1.0
    l2.text = "Columbus"
    l2.stroke_color = "purple"
    l2.opacity = 1.0
    sc.add_symbol(l2)
	
    p3 = Polyline()
    p3.add_point(-80, 41)
    p3.add_point(-85, 41)
    p3.stroke_color = "magenta"
    p3.stroke_width = 0.5
    p3.opacity = 1.
    sc.add_symbol(p3)

    # create a USMap object with the map data

    #pass no parameters for the whole map
    state_info = get_us_map_data()
    map_data = USMap(state_info)

    bridges.set_map(map_data)

    # set data structure, visualize
    bridges.set_data_structure(sc)
    bridges.visualize()


if __name__ == '__main__':
    main()
