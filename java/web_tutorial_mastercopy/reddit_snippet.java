import java.util.ArrayList;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.Reddit;


// This program fragment illustrates how to access the reddit data
public class reddit_snippet {
	public static void main(String[] args) throws Exception {

		// create Bridges object
#if TESTING
		// command line args provide credentials and server type
		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);
#else
		Bridges bridges = new Bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif
    
		DataSource ds = bridges.getDataSource();

		ArrayList<String> subreddits = ds.getAvailableSubreddits();

		// get some data from the  "Ask Science" subreddit
		ArrayList<Reddit> reddit_posts = ds.getRedditData("askscience");
		int count = 0;
		for (Reddit r: reddit_posts) {
		    ++count;
		    if (count > 10)
			break;
		    System.out.println("ID: "+r.getID());
		    System.out.println("Title: "+r.getTitle());
		    System.out.println("Author: "+r.getAuthor());
		    System.out.println("Score: "+r.getScore());
		    System.out.println("VoteRatio: "+r.getVoteRatio());
		    System.out.println("CommentCount: "+r.getCommentCount());
		    System.out.println("Subreddit: "+r.getSubreddit());
		    System.out.println("PostTime: "+r.getPostTime());
		    System.out.println("URL: "+r.getURL());
		    System.out.println("Text: "+r.getText());
		    System.out.println("");
		}
		
	}
}
