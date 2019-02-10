from bridges.bridges import *
from bridges.data_src_dependent.data_source import *
from bridges.graph_adj_list import *
import math
import sys

def calc_distance(la1, lo1, la2, lo2):
    radius = 6371

    la_distance = math.radians(la2 - la1)
    lo_distance = math.radians(lo2 - lo1)
    a = math.sin(la_distance / 2) * math.sin(la_distance / 2) + math.cos(math.radians(la1)) * math.cos(math.radians(la2)) * math.sin(lo_distance / 2) * math.sin(lo_distance / 2)
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))

    distance = radius * c
    return distance

def sorting(e):
    return e.magnitude

def main():
    args = sys.argv[1:]

    # create the Bridges object, set credentials

    bridges = Bridges(int(args[0]), args[1], args[2])

    if len(args) > 3:
        bridges.connector.set_server(args[3])
        
    bridges.set_title("Bacon Number: IMDB Actor-Movie Data")

    graph = GraphAdjList()

    eqlist = get_earthquake_usgs_data(5000)

    eqlist.sort(key=sorting, reverse=True)

    for eq in eqlist:
        if len(graph.get_adjacency_list()) > 99:
            break
        graph.add_vertex(eq.get_title(), eq.get_title())
        vis = graph.get_visualizer(eq.get_title())
        vis.set_location(eq.get_longit(), eq.get_latit())
        vis.set_size(eq.get_magnitude())

        red = ((eq.get_longit()/180.0)*255)
        if red > 0:
            red = red
        else: red = 0

        blue = ((eq.get_longit() / 180.0) * 255)
        if blue < 0:
            blue = blue * -1
        else: blue = 0

        green = ((eq.get_latit() / 90.0) * 255)
        if green < 0:
            green = green * -1
        else: green = green

        vis.set_color(red,green,blue,1.0)

    bridges.set_coord_system_type("equirectangular")
    bridges.set_data_structure(graph)
    bridges.set_map_overlay(True)
    bridges.set_title("Earthquake Map")
    bridges.visualize()

    for i in range(99):
        eq = eqlist[i]

        for j in range(99):
            if i == j:
                continue

            ua = eqlist[j]
            distance = calc_distance(eq.get_latit(), eq.get_longit(), ua.get_latit(), ua.get_longit())

            if distance < 500:
                graph.add_edge(eq.get_title(), ua.get_title())
                graph.get_link_visualizer(eq.get_title(), ua.get_title()).set_label("%s.2f KM" % distance)

    bridges.visualize()

    for i in range(99):
        eq = eqlist[i]
        vis = graph.get_visualizer(eq.get_title())

        vis.set_location(float('inf'), float('inf'))
        vis.set_size(eq.get_magnitude() * 5)

    bridges.set_map_overlay(False)
    bridges.visualize()

if __name__ == '__main__':
    main()
