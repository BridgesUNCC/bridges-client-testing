
include ../../env_vars.mk

TARGET =  all

# Incude and Library paths


all : 
	cd bst_eq; javac *.java;
	cd bst_gutenberg; javac *.java;
	cd graph_bacon_number; javac *.java;
	cd grid_lyrics; javac *.java;
	cd graph_eq; javac *.java;
	cd grid_square_fill; javac *.java;
	cd bst_games; javac *.java;
	cd bst_shakespeare; javac *.java;

run:

	cd bst_eq; java  bst_eq $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd bst_gutenberg; java  bst_gutenberg $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd graph_bacon_number; java  graph_bacon_number $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd grid_lyrics; java  grid_lyrics $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd graph_eq; java  graph_eq $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd grid_square_fill; java  grid_square_fill $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd bst_games; java  bst_games $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd bst_shakespeare; java  bst_shakespeare $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	

clean:
	cd bst_eq; rm -f *.class;
	cd bst_gutenberg; rm -f *.class;
	cd graph_bacon_number; rm -f *.class;
	cd grid_lyrics; rm -f *.class;
	cd graph_eq; rm -f *.class;
	cd grid_square_fill; rm -f *.class;
	cd bst_games; rm -f *.class;
	cd bst_gutenberg; rm -f *.class;
	

