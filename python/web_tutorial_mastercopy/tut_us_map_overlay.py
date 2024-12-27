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
    bridges.set_title("Test of US Map with State Boundaries")

    #pass no parameters for the whole map
    state_info = get_map(['iowa', 'california', 'north carolina'])

    my_map = USMap(state_info)
    bridges.set_map(my_map)

    #placeholder for assigning a viz type to BRIDGES
    el0 = DLelement()
    el0.set_location(-80.8431, 35.2271) # Charlotte, NC: 35.2271N, 80.8431W

    #visualizes iowa and california with counties
    bridges.set_data_structure(el0)
    bridges.visualize()




if __name__ == '__main__':
    main()
