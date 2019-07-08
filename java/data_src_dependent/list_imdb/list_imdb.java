import java.util.List;

/* Import Bridges and relevant data source */
import bridges.connect.Bridges;
import bridges.base.SLelement;
import bridges.data_src_dependent.ActorMovieIMDB;

public class list_imdb {

	public static void main(String[] args) throws Exception {

		/* Initialize a Bridges connection with your credentials */
        Bridges bridges = new Bridges (Integer.parseInt(args[0]), args[1], args[2]);
        bridges.setServer (args[3]);

		/* Set an assignment title */
		bridges.setTitle("Linked  List using IMDB Actor/Movie Data");

		/* Get a List of ActorMovieIMDB objects from Bridges */
		List<ActorMovieIMDB> mylist = bridges.getActorMovieIMDBData(Integer.MAX_VALUE);

		/* Set up a prev and head element */
		SLelement<ActorMovieIMDB> prev = new SLelement<ActorMovieIMDB>();
		SLelement<ActorMovieIMDB> head = new SLelement<ActorMovieIMDB>();

		/* Read each actor movie pair and set up a new SLelement for each */
		for(int i = 0; i < mylist.size(); i++) {

			/* Create each new SLelement */
			SLelement<ActorMovieIMDB> element = new SLelement<ActorMovieIMDB>();

			/* Set the element label equal to 'Actor - Movie' for each pair. (print it out for sanity check) */
			element.setLabel(mylist.get(i).getActor() + " - " + mylist.get(i).getMovie());

			/* Add 'next' pointer where appropriate */
			if(i > 0) {
				prev.setNext(element);
			} else {
				/* Set the head pointer */
				head = element;
			}
			/* Update the prev pointer */
			prev = element;
		}

		/* Pass the head of the list to Bridges */
		bridges.setDataStructure(head);

		/* Visualize the list */
		bridges.visualize();
	}
}
