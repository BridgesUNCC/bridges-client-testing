//import java.util.ArrayList;
import java.util.List;
import java.util.Vector;
import java.lang.String;

import bridges.base.Element;
import bridges.base.SLelement;
import bridges.base.GraphAdjList;
import bridges.base.Edge;
import bridges.connect.Bridges;
import bridges.data_src_dependent.ActorMovieIMDB;
import java.util.HashMap;

// 	This BRIDGES project illustrates a graph built using the IMDB Actor-Movie
// 	dataset; the data contains actor-movie pairs, movie rating and genres
// 	In this program, we group the movies by genres and also color code the movies// by rating; this 
//	helps us illustrates the connections between the movies 
// 	and their genres, while also showing their ratings.

public class graph_imdb_by_genre{
	
	public static void main(String[] args) throws Exception {
		
				// initialize Bridges
				// parameters are assignment number, application key, user id

		Bridges bridges = new Bridges (Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer (args[3]);

						// set a title for the visualization
		bridges.set_title("Graph Example(IMDB Data): Movies Grouped by Genre");

		bridges.set_description("Graph of IMDB movies grouped by genres; movies are color coded by ratings");

						// get the actor-movie IMDB data
						// accessible as JSON from 
						// https://bridgesdata.herokuapp.com/api/imdb2
		List<ActorMovieIMDB> actor_movie_data = bridges.getActorMovieIMDBData2();

						// create an adjacency list based graph
		GraphAdjList<String, ActorMovieIMDB, String> g = new GraphAdjList<>();

						// first create vertices for each genre defined in 
						// the data - we cheat and do this manually.
		String[] genres= {"Mystery", "Comedy",
				"Documentary", "Drama", "Romance", "Crime", "Thriller",
				"Biography", "Horror",
				"News", "Action",
				"Adventure", "Animation",
				"Family", "Sci-Fi",
				"Music", "Sport",
				"Short", "Musical",
				"History", "Talk-Show", "Reality-TV", "Game-Show", "Fantasy",
				"War"};

						// create the genre vertices; these will form the 
						// cluster centers
		create_genre_vertices(g, genres);

						// we will group the movies by genre
		group_movies_by_actors(g, actor_movie_data);

		bridges.setDataStructure(g);
		bridges.visualize();
	}

	public static void create_genre_vertices(GraphAdjList<String, ActorMovieIMDB, String> g,  
								String[] genres) {

							// iterate through the genres array 
							// and create a graph vertex for each, using
							// the genres strings as keys, for example
							// g.addVertex(genres[k], "");
							// Color the cluster center in a unique color,
							// set its size, opacity, etc.

		for (int k = 0; k < genres.length; k++) {
							// add vertex for each genre
			g.addVertex(genres[k], new ActorMovieIMDB()); 
							// set attributes (color, opacity, size)
			g.getVertex(genres[k]).setColor("red");
			g.getVertex(genres[k]).setOpacity(0.5f);
			g.getVertex(genres[k]).setSize(50);
		}
	}

	public static void group_movies_by_actors(GraphAdjList<String, ActorMovieIMDB, String> g,
			List<ActorMovieIMDB> actor_movie_data) {

						// this method groups the movies by movie genres;
						// iterate through the actor-movie list(of type
						// ActorMovieIMDB), retrieve its movie (actor 
						// is not used here), rating and genres (using
						// ActorMovieIMDB::getMovie(), getMovieRating(), 
						// getGenres();  create a movie vertex (using its name)
						// next compare the movie's  genres with the 
						// strings in genres representing cluster centers(double
						// loop - yes, its inefficient-:(, but small loops ); 
						// for  every match, add a graph edge from 
						// the cluster center to the movie

		HashMap<String, Element<ActorMovieIMDB>> verts = g.getVertices();
		for (int k = 0; k < actor_movie_data.size(); k++) {
					// from the actor movie data, get an actor-movie pair
					// Using methods from  ActorMovieIMDB class
			String actor = actor_movie_data.get(k).getActor();
			String movie = actor_movie_data.get(k).getMovie();
			Vector<String> m_genre = actor_movie_data.get(k).getGenres();
					// get the movie rating
			double  rating = actor_movie_data.get(k).getMovieRating();

					// add a graph vertex for the actor, if new)
			if (!g.getVertices().containsKey(actor)) {
				g.addVertex(actor, actor_movie_data.get(k));
				verts.get(actor).setColor("green");
				verts.get(actor).setLabel(actor);
            }

			if (!g.getVertices().containsKey(movie)) {
				g.addVertex(movie, actor_movie_data.get(k));
				verts.get(movie).setColor("yellow");
				verts.get(movie).setLabel(movie);
            }
					// add edges between actor and movie
			g.addEdge(actor, movie, 1);
			g.addEdge(movie, actor, 1);

							// adding edge from the genre to the movie
			for (int l = 0; l < m_genre.size(); l++) {
				String genre = m_genre.elementAt(l);
				g.addEdge (movie, genre, 1);

							// need to get the movie rating
							// color code the movie node by rating
				
				rating = ((ActorMovieIMDB) g.getVertex(movie).getValue()).getMovieRating();
				String label = g.getVertex(movie).getLabel() + "( " + String.valueOf(rating) + " )";
				g.getVertex(movie).setLabel(label);
				
				if (rating < 5.0)
					g.getVertex(movie).setColor("blue");
				else if (rating < 6.0) 
					g.getVertex(movie).setColor("green");
				else if (rating < 7.0)
					g.getVertex(movie).setColor("yellow");
				else if (rating < 8.0)
					g.getVertex(movie).setColor("tan");
				else 
					g.getVertex(movie).setColor("gold");
			}
		}
	}
}
