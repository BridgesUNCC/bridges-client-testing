#include <iostream>
#include <algorithm>
#include <SortingBenchmark.h>
#include <Bridges.h>

using namespace bridges;
using namespace bridges::datastructure;

void myfirstsort (int* arr, int n) {
  // ...
}

void bubblesort (int *arr, int n) {
	for (int i = 0; i < n-1; ++i) {
    	for (int j = 0; j < n-1; ++j) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
          	}
		}
	}
}
void standardsort (int* arr, int n) {
  std::sort(arr, arr + n);
}

int main (int argc, char **argv) {
      // create Bridges object
#if TESTING
    // command line args provide credentials and server to test on
    Bridges bridges (atoi(argv[1]), argv[2], argv[3]);
    if (argc > 4)
        bridges.setServer(argv[4]);
#else
    Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif
	bridges.setTitle("Sorting Benchmark Test");

  LineChart plot;

  bridges::benchmark::SortingBenchmark sb(plot);

  sb.geometricRange (100, 100000, 2.0);

  sb.run("bubblesort", bubblesort);
  sb.run("std::sort", standardsort);

  bridges.setDataStructure (&plot);
  bridges.visualize();

  return 0;
}
