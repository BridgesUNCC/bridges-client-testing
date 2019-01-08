import java.util.List;
import java.util.Random;
import bridges.connect.Bridges;
import bridges.data_src_dependent.GutenbergBook;

public class book_snippet {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
#if TESTING
    Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
    bridges.setServer(args[3]);
#else
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif

		/* Get a List of GutenbergBook objects from Bridges */
		List<GutenbergBook> mylist = bridges.getGutenbergBookMetaData();

		/* Inspect a random GutenbergBook object */
		GutenbergBook book1 = mylist.get((new Random()).nextInt(mylist.size()));
		System.out.println(book1.getTitle());
		System.out.println(book1.getAuthorName());
		System.out.println(book1.getGenres());

	}
}
