from bridges.bridges import *
from bridges.data_src_dependent import *
from bridges.dl_element import *
from bridges.us_map import *

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
    bridges.set_title("Tutorial: Drawing US Map with State Boundaries, and State Counties")
    bridges.set_description("All US States, All Counties")

    #pass no parameters for the whole map
    state_info = get_us_map_county_data()

    my_map = USMap(state_info)


    #visualizes iowa and california with counties
    bridges.set_data_structure(my_map)
    bridges.visualize()




if __name__ == '__main__':
    main()
