import java.util.ArrayList;
import java.lang.String;
import bridges.base.Element;
import bridges.base.SLelement;
import bridges.base.GraphAdjListSimple;
import bridges.base.Edge;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.ActorMovieIMDB;

public class graph_al {
	public static void main(String[] args) throws Exception {

		// initialize Bridges
#if TESTING
		
        Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
        bridges.setServer(args[3]);

		// set a title for the visualization
		bridges.setTitle("A Simple Graph (Adjacency List) Example using IMDB Actor/Movie Data");
		bridges.setDescription("Two lists each having an actor as the root node with 15 movies they played in as leaf nodes. "
				+	"Root nodes are both red, Kevin Bacon's leaf nodes are green and Denzel Washington's leaf nodes are neutral.");
				
#else
        Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", 
                                        "YOUR_API_KEY");
#endif

    DataSource ds = bridges.getDataSource();
		ArrayList<ActorMovieIMDB>  actor_movie_data =
			(ArrayList<ActorMovieIMDB>) ds.getActorMovieIMDBData(1813);


		// create an adjacency list based graph
		GraphAdjListSimple<String> g = new GraphAdjListSimple<String>();

		// first create vertices for two actors and add them to the graph
		String a1 = "Kevin_Bacon_(I)", a2 = "Denzel_Washington";
		g.addVertex(a1, "");
		g.addVertex(a2, "");

		// add an edge between the two actors a1 and a2,
		// the third parameter is the edge weight
		g.addEdge(a1, a2);

		// color the two actor nodes
		g.getVertices().get(a1).setColor("red");
		g.getVertices().get(a2).setColor("red");
		// make them a bit bigger
		g.getVertices().get(a1).setSize(20);
		g.getVertices().get(a2).setSize(20);

		// get their nodes
		Element v1 = g.getVertex(a1);
		Element v2 = g.getVertex(a2);

		// we will find the first 15 immediate neighbors of of the two actors
		// and color those links and nodes by followng their adjacency lists
		int cnt1 = 0, cnt2 = 0;
		for (int k = 0; k < actor_movie_data.size(); k++) {
			// from the actor movie data, get an actor-movie pair
			String a = actor_movie_data.get(k).getActor();
			String m = actor_movie_data.get(k).getMovie();

			if (a.equals(a1) && cnt1 < 15) {

				// add vertices for this movie  and an edge for the link
				g.addVertex(m, "");
				g.addEdge(a1, m);
				g.addEdge(m, a1);

				// make the movie node a bit transparent
				g.getVertex(m).setOpacity(0.5f);
				cnt1++;
			}
			else if (a.equals(a2) && cnt2 < 15) {
				// add vertices for this movie  and an edge for the link
				g.addVertex(m, "");
				g.addEdge(a2, m);
				g.addEdge(m, a2);
				// make the movie node a bit transparent
				g.getVertex(m).setOpacity(0.5f);
				cnt2++;
			}
		}

		// Next, we illustrate traversing the adacency list and color the
		// movie nodes adjacent to the Kevin Bacon node.

		// first get the adjacency list for Kevin Bacon
		// traverse the adjacency list
		for (Edge<String, String> edge : g.outgoingEdgeSetOf(a1)) {
			String from = edge.getFrom(), to = edge.getTo();
			if (!to.equals(a2))
				edge.setColor("green");
		}

		// Pass the graph object to BRIDGES
		bridges.setDataStructure(g);

		// Finaly we call the visualize function
		bridges.visualize();
	}
}
