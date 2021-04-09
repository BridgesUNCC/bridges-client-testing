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

    list  = data_source.get_wiki_data_actor_movie(1955, 1965)
    print("Actor-Movie Data:\n" + 
         "\tMovie: " + list[0].movie_uri + ", " + list[0].movie_name + "\n" +
         "\tActor: " + list[0].actor_uri + ", " + list[0].actor_name + "\n")


if __name__ == "__main__":
    main()
