from bridges.color_grid import *
from bridges.bridges import *
from bridges.color import *
from bridges.data_src_dependent import data_source
import sys
import os

# illustrates retrieving actor-movie data from WikiData

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

    bridges.set_title ("Accessing Wikidata Movie/Actor Data")

    list  = data_source.get_wiki_data_actor_movie(1955, 1955)
    print ("Data Records in 1955: " + str(len(list)) + "\n")
    print ("First 3 records:\n")
    for i in range(3):
        print(str(i) + ")Actor-Movie Data:\n" +  
             "\tMovie: " + list[i].movie_uri + ", " + list[i].movie_name + "\n" +
             "\tActor: " + list[i].actor_uri + ", " + list[i].actor_name + "\n")


if __name__ == "__main__":
    main()
