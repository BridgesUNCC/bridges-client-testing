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
    bridges.set_title("Tutorial: Drawing US Map with States and Counties")
    bridges.set_description("3 US  states, with or without Counties, with varied coloring")

    #pass no parameters for the whole map
    #state_info = get_us_map_county_data(['Vermont', 'Iowa', 'North Carolina'], True)
    state_info = get_us_map_county_data(['Vermont', 'Iowa', 'North Carolina'], False)

    # we will draw the first state without counties and set 
    # fill and boundary colors - use the viewCounties() flag to 
    # ignore counties
    state_info[0].view_counties = False
    state_info[0].stroke_color = Color(255,0,0)
    state_info[0].fill_color = Color(0,255,0)

    # the second state  we will draw with counties and set their colors
    for c in state_info[1].counties:
        c.stroke_color = Color(50, 250, 50)
        c.fill_color = Color(0,0,170)

    # the third state will use default colors
    
        
    my_map = USMap(state_info)
    
    #visualizes iowa and california with counties
    bridges.set_data_structure(my_map)
    bridges.visualize()


if __name__ == '__main__':
    main()
