import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.Amenities;
import bridges.data_src_dependent.*;
import java.util.*;



public class gutenberg_snippet {
	public static void main(String[] args) throws Exception {

		//create the Bridges object
#if TESTING
		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);
#else
		Bridges bridges = new Bridges(0, "YOUR_USER_ID", "YOUR_API_KEY");
#endif

		//create a bridges datasource object to use and
		//retrieve the gutenberg books
		DataSource ds = bridges.getDataSource();

		//Get Meta data for a book
		List<GutenbergMeta> data = ds.searchGutenbergMeta("home", "title");
		System.out.println(data[1].getTitle());

		// System.out.println(data.getId());
		// System.out.println(data.getTitle());
		// System.out.println(data.getLanguage());
		// System.out.println(data.getDate());

		// for (String gen : data.getGenres()){
		//     System.out.println(gen);
		// }

		// //Get book text
		// String text = ds.getGutenbergText(2701);

		// text = text.substring(0,40);
		// System.out.println(text);
	}
}
