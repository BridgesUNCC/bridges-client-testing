
include ../../env_vars.mk

TARGET =  all


all : 
	cd graph_imdb_by_genre;  make;

run:

	cd graph_imdb_by_genre; java graph_imdb_by_genre 1004 $(BRIDGES_PUBLIC_USER_NAME) $(BRIDGES_PUBLIC_API_KEY)  live

clean:
	cd graph_imdb_by_genre; rm *.class
	

