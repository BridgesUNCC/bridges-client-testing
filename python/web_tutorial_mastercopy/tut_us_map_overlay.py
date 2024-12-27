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
    state_info = get_us_map_county_data(['Vermont', 'Iowa', 'North Carolina'])
    for s in state_info:
        if s.state_name == "North Carolina":
            for c in s.counties:
                if c.geoid == "37119": #access by FIPS code
                    c.fill_color = Color(0,255,0)
                

    my_map = USMap(state_info)
    bridges.set_map(my_map)

    #placeholder for assigning a viz type to BRIDGES
    el0 = DLelement()
    el0.set_location(-80.8431, 35.2271) # Charlotte, NC: 35.2271N, 80.8431W
    el0.size = .5
    
    #visualizes iowa and california with counties
    bridges.set_data_structure(el0)
    bridges.visualize()




if __name__ == '__main__':
    main()
