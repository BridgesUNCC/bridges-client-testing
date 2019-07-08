import java.util.ArrayList;
import java.lang.String;
import bridges.base.Element;
import bridges.base.SLelement;
import bridges.base.GraphAdjListSimple;
import bridges.base.Edge;
import bridges.connect.Bridges;
import bridges.data_src_dependent.ActorMovieIMDB;

public class graph_al {
	public static void main(String[] args) throws Exception {

		// initialize Bridges
		
        Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
        bridges.setServer(args[3]);

		// set a title for the visualization
		bridges.set_title("A Simple Graph (Adjacency List) Example using IMDB Actor/Movie Data");
		bridges.set_description("Two lists each having an actor as the root node with 15 movies they played in as leaf nodes. "
				+	"Root nodes are both red, Kevin Bacon's leaf nodes are green and Denzel Washington's leaf nodes are neutral.");
				

		ArrayList<ActorMovieIMDB>  actor_movie_data =
			(ArrayList<ActorMovieIMDB>) bridges.getActorMovieIMDBData(1813);

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
		g.getVertices().get("Kevin_Bacon_(I)").setColor("red");
		g.getVertices().get("Denzel_Washington").setColor("red");
		// make them a bit bigger
		g.getVertices().get("Kevin_Bacon_(I)").setSize(20);
		g.getVertices().get("Denzel_Washington").setSize(20);

		// get their nodes
		Element v1 = g.getVertices().get(a1);
		Element v2 = g.getVertices().get(a2);

		// we will find the first 15 immediate neighbors of of the two actors
		// and color those links and nodes by followng their adjacency lists
		int cnt1 = 0, cnt2 = 0;
		for (int k = 0; k < actor_movie_data.size(); k++) {
			// from the actor movie data, get an actor-movie pair
			String a = actor_movie_data.get(k).getActor();
			String m = actor_movie_data.get(k).getMovie();

			if (a.equals("Kevin_Bacon_(I)") && cnt1 < 15) {

				// add vertices for this movie  and an edge for the link
				g.addVertex(m, "");
				g.addEdge(a1, m);
				g.addEdge(m, a1);

				// make the movie node a bit transparent
				g.getVertices().get(m).setOpacity(0.5f);
				cnt1++;
			}
			else if (a.equals("Denzel_Washington") && cnt2 < 15) {
				// add vertices for this movie  and an edge for the link
				g.addVertex(m, "");
				g.addEdge(a2, m);
				g.addEdge(m, a2);
				// make the movie node a bit transparent
				g.getVertices().get(m).setOpacity(0.5f);
				cnt2++;
			}
		}

		// Next, we illustrate traversing the adacency list and color the
		// movie nodes adjacent to the Kevin Bacon node.

		// first get the adjacency list for Kevin Bacon
		SLelement<Edge<String, String>>  head = g.getAdjacencyList().get("Kevin_Bacon_(I)");
		// traverse the adjacency list
		for (SLelement<Edge<String, String>> sle = head; sle != null; sle = sle.getNext() ) {
			// get the terminating vertex
			String term_vertex = sle.getValue().getFrom();
			// find the corresponding element
			Element<String> el = g.getVertices().get(term_vertex);
			// set the  color of the node except the Denzel W. node
			if (!term_vertex.equals("Denzel_Washington"))
				el.setColor("green");
		}

		// Pass the graph object to BRIDGES
		bridges.setDataStructure(g);

		// Finaly we call the visualize function
		bridges.visualize();
	}
}
