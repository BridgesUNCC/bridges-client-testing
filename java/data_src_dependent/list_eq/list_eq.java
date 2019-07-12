import java.util.List;

/* Import Bridges and relevant data source */
import bridges.connect.Bridges;
import bridges.connect.DataSource;
import bridges.base.SLelement;
import bridges.data_src_dependent.EarthquakeUSGS;

import java.util.List;

/* Import Bridges and relevant data source */
import bridges.connect.Bridges;
import bridges.base.SLelement;
import bridges.data_src_dependent.EarthquakeUSGS;

public class list_eq{

	/* Given an SLelement with an EarthquakeUSGS value, set various visual properties */
	public static void setProperties(SLelement<EarthquakeUSGS> el) {

		/*
		 * Get the magnitude of the earthquake from the SLelement
		 * (the EarthquakeUSGS object is stored as the value inside the SLelement)
		 */
		double magnitude = el.getValue().getMagnitude();

		/* Prepare color variable */
		String color = "";

		/* Pick the color depending on the magnitude */
		if (magnitude < 1.0) {
			color = "blue";
		} else if (magnitude < 2.0) {
			color = "green";
		} else if (magnitude < 3.0) {
			color = "yellow";
		} else if (magnitude < 4.0) {
			color = "orange";
		} else if (magnitude < 5.0) {
			color = "red";
		} else if (magnitude < 6.0) {
			color = "purple";
		} else {
			color = "black";
		}
		/* Set the color of the Element */
		el.setColor(color);

		/* Set the size of the Element based on the magnitude */
		el.setSize(magnitude * 5);

		/* Set the shape of the Element based on the location */
		if (el.getValue().getLocation().contains("Alaska"))
			el.setShape("diamond");
		else if (el.getValue().getLocation().contains("Hawaii"))
			el.setShape("cross");
	}

	public static void main(String[] args) throws Exception {

		/* Initialize a Bridges connection with your credentials */
        Bridges bridges = new Bridges (Integer.parseInt(args[0]), args[1], args[2]);
        bridges.setServer (args[3]);
	
		/* Set an assignment title */
		bridges.setTitle("List Using USGS Earthquake Data");

		/* Get a List of USGS Earthquake Tweet objects from Bridges */
	DataSource ds = bridges.getDataSource();
		List<EarthquakeUSGS> mylist = ds.getEarthquakeUSGSData(500);

		/* Set up a prev and head element */
		SLelement<EarthquakeUSGS> prev = new SLelement<EarthquakeUSGS>();
		SLelement<EarthquakeUSGS> head = new SLelement<EarthquakeUSGS>();

		/* Read each earthquake and set up a new SLelement for each */
		for (int i = 0; i < mylist.size(); i++) {

			/* Create each new SLelement */
			SLelement<EarthquakeUSGS> element = new SLelement<EarthquakeUSGS>(mylist.get(i));

			/* Set the element label equal to Title (print it out for sanity check) */
			element.setLabel(mylist.get(i).getTitle());

			/* Pass the element to a function to set its visual properties */
			setProperties(element);

			/* Add 'next' pointer where appropriate */
			if (i > 0) {
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
