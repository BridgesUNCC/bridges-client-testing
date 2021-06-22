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

    # get a song
    song = get_song("Harder Faster Better Stronger", "Daft Punk")

    # print its lyrics
    print(song.song_title)
    print(song.artist)
    print(song.album_title)
    print(song.release_date)
    print(song.lyrics)


if __name__ == "__main__":
    main()
