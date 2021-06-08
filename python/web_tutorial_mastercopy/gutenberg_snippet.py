from bridges.bridges import *
from bridges.data_src_dependent import data_source
import sys


def main():
    # if TESTING
    # command line args provide credentials and server to test on
    args = sys.argv[1:]
    bridges = Bridges(int(args[0]), args[1], args[2])
    if len(args) > 3:
        bridges.connector.set_server(args[3])
    # else
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")
    # endif

    #you can search the gutenberg database by supplying a search parameter you would like
    #i.e Home for books containing "home", and the type of search being: id, title, language, date, author, genre, loc
    #which searches for that parameter in that metadata type
    data = data_source.search_gutenberg("home", "title")
    print(len(data)) #here 9 books are returned that contain "home" in the title
    print(data[1].title) #this is the title of book 2
    print(data[1].id) #this is the id of book 2

    #If you already have the ID of a book you want, you can do two retrievals
    #This is a text retieval given the ID of a book
    #Print the characters between 100-200 of the book's text given its ID
    text = data_source.text_gutenberg(data[1].id)
    print(text[100:200])

    #The second retirval is getting the book's metadata given the ID
    #This gets and prints out the indivdual meta data values
    meta = data_source.meta_gutenberg(data[1].id)
    print(f"Id: {meta.id}")
    print(f"Title: {meta.title}")
    print(f"Date: {meta.date}")
    print(f"Author: {meta.authors}")
    print(f"Genres: {meta.genres}")
    print(f"language: {meta.lang}")
    print(f"library of congress: {meta.loc}")


if __name__ == '__main__':
    main()