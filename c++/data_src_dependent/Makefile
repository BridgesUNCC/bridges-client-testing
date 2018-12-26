
include ../../env_vars.mk

TARGET =  all

# Incude and Library paths


all : 
	cd bst_eq; make;
	cd bst_gutenberg; make;
	cd graph_bacon_number; make;
	cd grid_lyrics; make;
	cd graph_eq; make;
	cd grid_square_fill;  make;
	cd bst_games; make;
	cd bst_shakespeare; make;
	cd list_eq; make;
	cd list_imdb; make;

run:

	cd bst_eq; bst_eq $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd bst_gutenberg;   bst_gutenberg $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd graph_bacon_number;   graph_bacon_number $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd grid_lyrics;   grid_lyrics $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd graph_eq;   graph_eq $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd grid_square_fill;   grid_square_fill $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd bst_games; bst_game $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd bst_shakespeare;   bst_shakespeare $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd list_eq;   list_eq $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	cd list_imdb;   list_imdb $(BRIDGES_TESTING_USER_NAME) $(BRIDGES_TESTING_API_KEY)  $(BRIDGES_SERVER)
	

clean:
	cd bst_eq; make clean;
	cd bst_gutenberg; make clean;
	cd graph_bacon_number; make clean;
	cd grid_lyrics;  make clean;
	cd graph_eq; make clean;
	cd grid_square_fill; make clean;
	cd bst_games; make clean;
	cd bst_shakespeare; make clean;
	cd bst_gutenberg; make clean;
	cd list_eq; make clean;
	cd list_imdb; make clean;
	

