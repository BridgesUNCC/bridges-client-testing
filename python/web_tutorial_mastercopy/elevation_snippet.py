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


    ele_obj = data_source.get_elevation_data([-98.02593749997456, 41.03133177632377, -98.02593749997456, 42.508577297430456, -96.94531249997696])
    print("Width: "+str(ele_obj.cols))
    print("Height: "+str(ele_obj.rows))
    print("Coordinate of lower left corner: "+str(ele_obj.xll)+", "+str(ele_obj.yll))
    print("Spatial resolution: " + str(ele_obj.cellsize))

    print("First 10 elevations:")
    for i in range(0, 10):
        print(str(ele_obj.data[0][i]))
    

    

if __name__ == "__main__":
    main()
