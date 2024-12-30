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
    bridges.set_title("World Map Overlay")

    my_map = WorldMap()
    bridges.set_map(my_map)

    #placeholder for assigning a viz type to BRIDGES
    el0 = DLelement()
    el0.set_location(-80.8431, 35.2271) # Charlotte, NC: 35.2271N, 80.8431W
    el0.size = .5
    
    #visualizes world map
    bridges.set_data_structure(el0)
    bridges.visualize()




if __name__ == '__main__':
    main()
