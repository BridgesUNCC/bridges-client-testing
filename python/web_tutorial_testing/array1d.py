from Bridges.Bridges import *
from Bridges.Array import *
import sys

class Array1d():
    args = sys.argv[1:]

    # create the Bridges object, set credentials

    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])

    #set array dimensions, allocate array fo elements
    arraySize = 10

    arr = Array(num_elements = arraySize)

    #populate the array with squares of indicies
    for i in range(arr.get_size()):
        arr.get_element(i).set_label(i*i)

    #color the array elements
    arr.get_element(0).get_visualizer().set_color("red")
    arr.get_element(1).get_visualizer().set_color("green")
    arr.get_element(2).get_visualizer().set_color("blue")
    arr.get_element(3).get_visualizer().set_color("cyan")
    arr.get_element(4).get_visualizer().set_color("magenta")
    arr.get_element(5).get_visualizer().set_color("yellow")
    arr.get_element(6).get_visualizer().set_color("red")
    arr.get_element(7).get_visualizer().set_color("green")
    arr.get_element(8).get_visualizer().set_color("blue")
    arr.get_element(9).get_visualizer().set_color("black")

    # tell Bridges what data structure to visualize
    bridges.set_data_structure(arr)

    # visualize the list
    bridges.visualize()
