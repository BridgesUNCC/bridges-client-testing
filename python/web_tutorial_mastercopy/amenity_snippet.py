from bridges.bridges import *
from bridges.data_src_dependent import *
import sys
import random

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

    # create the Bridges object, set credentials
    bridges = Bridges(int(args[0]), args[1], args[2])

    bridges.set_title("OpenStreet Map Data Access Example")

    # get the OsmData
    amenitydata = data_source.get_amenity_data("Charlotte, North Carolina", "school")

    meta = amenitydata.meta
    
    print ("Number of Vertices: " + str(meta.count))
    

    print ("Position of first vertex: lat="+str(amenitydata.data[0].lat)+
           " long="+ str(amenitydata.data[0].lon))

    #print ("Cartesian Coordinate of first vertex: "+str(vertices[0].cartesian_coord[0])+ ", "+ str(vertices[0].cartesian_coord[1]))

    
if __name__ == '__main__':
    main()
