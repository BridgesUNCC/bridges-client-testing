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


    reddit_obj = data_source.reddit_data("askscience")
    
    for i in range(0, 3):
        print(f"Title: {reddit_obj[i].title}")
        print(f"Author: {reddit_obj[i].author}")
        print(f"Score: {reddit_obj[i].score}")
        print(f"Vote Ratio: {reddit_obj[i].vote_ratio}")
        print(f"Comment Count: {reddit_obj[i].comment_count}")
        print(f"Subreddit: {reddit_obj[i].subreddit}")
        print(f"PostTime: {reddit_obj[i].post_time}")
        print(f"URL: {reddit_obj[i].url}")
        print(f"Text: {reddit_obj[i].text}")
        print("")


if __name__ == "__main__":
    main()
