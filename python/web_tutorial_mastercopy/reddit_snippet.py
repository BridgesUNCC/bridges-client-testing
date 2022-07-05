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

    reddit_obj = data_source.reddit_data("news")
   
    print(f"Title: {reddit_obj[10].title}")
    print(f"Author: {reddit_obj[10].author}")
    print(f"Score: {reddit_obj[10].score}")
    print(f"Comment Count: {reddit_obj[10].comment_count}")
    print(f"Subreddit: {reddit_obj[10].subreddit}")

    for i in range(0, 10):
        print(f"Title: {reddit_obj[i].title}")


if __name__ == "__main__":
    main()
