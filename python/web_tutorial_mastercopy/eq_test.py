from bridges.bridges import *
from bridges.data_src_dependent.data_source import *
import sys
import random

def main():

    # create the Bridges object, set credentials
#if TESTING
    args = sys.argv[1:]
    # command line args provide credentials and server to test on
    args = sys.argv[1:]
    bridges = Bridges(int(args[0]), args[1], args[2])
    if len(args) > 3:
        bridges.connector.set_server(args[3])
#else
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")
#endif

    # get 100 earthquake records
    my_list = get_earthquake_usgs_data(100)

    # pick the first one 
    quake1 = my_list[0]

    # print details of quake
    print("Magnitude: " + str(quake1.magnitude))
    print("Date: " + str(quake1.time))
    print("Location:" + str(quake1.location))
    print("Lat/Long:" + str(quake1.latit) + "," + str(quake1.longit))

    # get earthquake records
    my_list = get_earthquake_usgs_data() # this is a different code path

    # pick the first one 
    quake1 = my_list[0]

    # print details of quake
    print("Magnitude: " + str(quake1.magnitude))
    print("Date: " + str(quake1.time))
    print("Location:" + str(quake1.location))
    print("Lat/Long:" + str(quake1.latit) + "," + str(quake1.longit))

    

if __name__ == "__main__":
    main()
