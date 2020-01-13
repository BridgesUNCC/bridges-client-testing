from bridges.bridges import *
from bridges.data_src_dependent.data_source import *
import sys
import random

def main():
    args = sys.argv[1:]

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

    # get the guttenberg book meta data
    book_list = get_gutenberg_book_data()

    # get the first book
    book1 = book_list[random.randrange(len(book_list))]

    # print details to console
    print(book1.title)
    print(book1.name)
    print(book1.genre)

    if __name__ == '__main__':
        main()
