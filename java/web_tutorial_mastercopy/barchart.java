import bridges.base.BarChart;
import bridges.connect.Bridges;
import bridges.validation.RateLimitException;

import java.io.IOException;
import java.util.*;

public class barchart {

	public static void main(String[] args) throws IOException, RateLimitException, InterruptedException {
#if TESTING

		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);

		bridges.setTitle("Bar Chart Test");
		bridges.setDescription("Bar Chart Test in Java");

#else
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
#endif

		BarChart bar = new BarChart();
		bar.setTitle("Bar Chart Example");
		bar.setSubTitle ("Example illustrating how to build bar charts in Java");
		bar.setCategoriesLabel("Continent");
		bar.setValueLabel("Population (in millions)");
		bar.setBarOrientation("horizontal");
		bar.setTooltipSuffix(" millions");

		Vector<String> bins = new Vector<String>();
			bins.add("Africa");
			bins.add("America");
			bins.add("Asia");
			bins.add("Europe");

		bar.setCategories(bins);

		double y1[] = new double[] {10, 100, 40, 23};
		double y2[] = new double[] {100, 10, 80, 232};
		bar.addDataSeries("year 1", y1);
		bar.addDataSeries("year 2", y2);

		bridges.setDataStructure(bar);
		bridges.visualize();
	}
}
