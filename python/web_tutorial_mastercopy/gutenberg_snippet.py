from bridges.bridges import *
from bridges.data_src_dependent import data_source
import sys


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



    # Print the first 50 character of the books text
    data = data_source.text_gutenberg(2701)
    print(data[0:50])

    #get and print out the indivdual meta data values
    data = data_source.meta_gutenberg(2701)
    print(f"Id: {data.id}")
    print(f"Title: {data.title}")
    print(f"Date: {data.date}")
    print(f"Author: {data.authors}")
    print(f"Genres: {data.genres}")
    



    
if __name__ == '__main__':
    main()
