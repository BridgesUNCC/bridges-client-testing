from bridges.bridges import *
from bridges.data_src_dependent import *
from bridges.dl_element import *
from bridges.world_map import *

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
    bridges.set_description("Draws a set of specified countries")

    countries = ["Brazil", "Argentina", "Germany", "France", "Spain", "United States of America"]

    # with no arguments to the function, gets all countries of the world
    country_data = get_world_map_data(countries)

    #lets change colors of each country
    country_data[0].fill_color = Color("lightgoldenrodyellow")
    country_data[1].fill_color = Color("lightskyblue")
    country_data[2].fill_color = Color("indigo")
    country_data[3].fill_color = Color("orangered")
    country_data[4].fill_color = Color("olive")
    country_data[5].fill_color = Color("springgreen")

    wm = WorldMap(country_data)

    #visualizes world map
    bridges.set_data_structure(wm)
    bridges.visualize()

if __name__ == '__main__':
    main()
