/**
 * Created by Lucas Estrella on 1/31/2017.
 * lestrell@uncc.edu
 */
import java.util.ArrayList;

import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.ActorMovieWikidata;

// This program fragment illustrates how to access and read the Wikidata actor/movie data

public class wikidata_actor_snippet {

	public static void main(String[] args) throws Exception {

		// note: you must fill in with your Bridges credentials
#if TESTING

		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);
#else
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
#endif
		// set title
		bridges.setTitle("Accessing Wikidata Movie/Actor Data");

		// create data source object
        DataSource ds = bridges.getDataSource();

		// Get a List of Wikidata actor/movie  records from Bridges
		// get the actor movie Wikidata data through the BRIDGES API for 1955.
		// data are available from the early 20th century to now.
		ArrayList<ActorMovieWikidata> list = ds.getWikidataActorMovie(1955, 1955);

		// print out the first record of the dataset
		System.out.println("Actor-Movie Data:\n" +
			"\tMovie: " + list.get(0).getMovieURI()  + " \""  + list.get(0).getMovieName() + "\"\n" +
	     	"\tActor: " +  list.get(0).getActorURI() + " \"" + list.get(0).getActorName() + "\"\n"); 
	}
}
