import java.util.ArrayList;
import java.util.Map;
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.data_src_dependent.Country;
import bridges.base.WorldMap;
import bridges.base.Color;
import bridges.base.GraphAdjListSimple;


// This tutorial illustrates how to access the data of the World map with 
// boundaries; the countries are filled with default color
public class tut_world_map_p3 {
	public static void main(String[] args) throws Exception {

		// create Bridges object
#if TESTING
		// command line args provide credentials and server type
		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);
#else
		Bridges bridges = new Bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", 
												"YOUR_API_KEY");
#endif
		// set title, description
		bridges.setTitle("Tutorial: Demonstrating overlaying World Map with Cities at their locations");
		bridges.setDescription("Uses graph vertices and lat/long coords to locate the cities");

		// get data source object
		DataSource ds = bridges.getDataSource();

		// specify a few countries to change their fill colors
		// get us map data - states and boundaries
		ArrayList<Country> wm_data = ds.getWorldMapData ();

		GraphAdjListSimple<String> gr = new GraphAdjListSimple<String>();

		gr.addVertex("Charlotte", "Charlotte,NC, USA");
			gr.getVertex("Charlotte").setLocation(-80.8431, 35.2271);
			gr.getVertex("Charlotte").setColor(new Color("crimson"));
			gr.getVertex("Charlotte").setSize(2.);
			gr.getVertex("Charlotte").setLabel("Charlotte, NC");
		gr.addVertex("Paris", "Paris, France");
			gr.getVertex("Paris").setLocation(2.3514, 48.8576);
			gr.getVertex("Paris").setColor(new Color("crimson"));
			gr.getVertex("Paris").setSize(2.);
		gr.addVertex("Berlin", "Berlin, Germany");
			gr.getVertex("Berlin").setLocation(13.4, 52.52);
			gr.getVertex("Berlin").setColor(new Color("crimson"));
			gr.getVertex("Berlin").setSize(2.);
		gr.addVertex("New Delhi", "New Delhi, India");
			gr.getVertex("New Delhi").setLocation(77.208, 28.614);
			gr.getVertex("New Delhi").setColor(new Color("crimson"));
			gr.getVertex("New Delhi").setSize(2.);
		gr.addVertex("Buenos Aires", "Buenos Aires, Argenina");
			gr.getVertex("Buenos Aires").setLocation(-58.382, -34.60);
			gr.getVertex("Buenos Aires").setColor(new Color("crimson"));
			gr.getVertex("Buenos Aires").setSize(2.);
		gr.addVertex("Esperanza Station, Antarctica", "Esperanza Station, Antarctica");
			gr.getVertex("Esperanza Station, Antarctica").setLocation(-56.59, -63.24);
			gr.getVertex("Esperanza Station, Antarctica").setColor(new Color("crimson"));
			gr.getVertex("Esperanza Station, Antarctica").setSize(2.);


		WorldMap wm = new WorldMap(wm_data);
		bridges.setMap(wm);
		bridges.setLabelFlag(true);

		// set data structure
		bridges.setDataStructure(gr);

		// visualize
		bridges.visualize();
	}
}
