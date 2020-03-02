from bridges.color_grid import *
from bridges.bridges import *
from bridges.color import *
from bridges.data_src_dependent import data_source
import sys
import os

def main():

#if TESTING
    # command line args provide credentials and server to test on
    args = sys.argv[1:]
    bridges = Bridges(int(args[0]), args[1], args[2])
    if len(args) > 3:
        bridges.connector.set_server(args[3])
#else
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")
#endif


    ele_obj = data_source.get_elevation_data([-98.02593749997456, 41.03133177632377, -96.94531249997696, 42.508577297430456])
    print("width: "+str(ele_obj.cols))
    print("height: "+str(ele_obj.rows))
    print(ele_obj._xll)
    print(ele_obj._yll)
    print("spatial resolution: " + ele_obj.cellsize)

    print("first 10 elevations:")
    for i in range(0, 10):
        print(ele_obj.data[0][i])
    

    

if __name__ == "__main__":
    main()
