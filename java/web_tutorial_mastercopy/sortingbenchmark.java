import bridges.base.LineChart;
import bridges.base.SortingBenchmark;
import bridges.connect.Bridges;
import bridges.validation.RateLimitException;

import java.io.IOException;
import java.util.*;
import java.util.function.Consumer;

public class sortingbenchmark {
	
	static Consumer <int[]> sort = arr -> {
		int n = arr.length; 
		  
        // One by one move boundary of unsorted subarray 
        for (int i = 0; i < n-1; i++) 
        { 
            // Find the minimum element in unsorted array 
            int min_idx = i; 
            for (int j = i+1; j < n; j++) 
                if (arr[j] < arr[min_idx]) 
                    min_idx = j; 
  
            // Swap the found minimum element with the first 
            // element 
            int temp = arr[min_idx]; 
            arr[min_idx] = arr[i]; 
            arr[i] = temp; 
        } 
	};
	
	static Consumer <int[]> bubbleSort = arr -> {
		int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j] > arr[j+1]) 
                { 
                    int temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
	};

	public static void main(String[] args) throws IOException, RateLimitException, InterruptedException {
#if TESTING

		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);

		bridges.setTitle("Sorting Benchmark");
        bridges.setDescription("Sorting Benchmark test");

#else
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", 
										"YOUR_API_KEY");
#endif
    //bridges.setVisualizeJSON(true);
		
		LineChart plot = new LineChart("Sort Runtime");
		SortingBenchmark bench = new SortingBenchmark(plot);
		bench.run("InsertSort", 500, 10000, sort);
		bench.run("bubblesort", 500, 10000, bubbleSort);
		
		bridges.setDataStructure(plot);
		bridges.visualize();
	}

}
