from bridges.color_grid import *
from bridges.bridges import *
from bridges.color import *
import sys

def main():

    # This tutorial illustrates using the Bridges Color Grid
    # and how to set elements within the grid

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

    # set title
    bridges.set_title("BRIDGES Color Grid Tutorial - Part 1");

    # set description
    bridges.set_description("This is an example of the color grid with height and width of 10 units each");

    red =  Color(col_name="red")
    green = Color(col_name="green")
    blue = Color(col_name="blue")

    # create a 10x10 color grid
    width = 10
    height = 10
    cg = ColorGrid(height, width, Color(col_name="lightgoldenrodyellow"))

    # color a few squares and make a + sign at the center
    cg.set(5, 5, red);
    cg.set(5, 4, blue);
    cg.set(5, 6, blue);
    cg.set(4, 5, green);
    cg.set(6, 5, green);

    # tell Bridges the the color grid object to visualize
    bridges.set_data_structure(cg);

    # visualize
    bridges.visualize();


if __name__ == "__main__":
    main()

