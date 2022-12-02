import bridges.connect.Bridges;
import bridges.base.Array1D;
import bridges.base.Element;

public class purposefully_breaking2 {
  public static void main(String[] args) throws Exception {


      //create the Bridges object, set credentials
#if TESTING
	  Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
      bridges.setServer(args[3]);
#else
	  Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
					"YOUR_API_KEY");
#endif

    /* Set an assignment title */
    bridges.setTitle("Bridges Setup Introduction");
    bridges.setDescription("Visualize a simple Array with Bridges.");

    /* Set up the array dimensions, allocate an Array of Elements */
    int arraySize = 5*1000;
    Array1D<Integer> arr = new Array1D<Integer> (arraySize);

    String junk = "xxxxxxx";
    for (int i=0; i< 10; ++i)
	junk += junk;
    
    /* Populate the array with integers */
    for (int k = 0; k < arraySize; k++) {
      arr.getElement(k).setValue(k * k);
      arr.getElement(k).setLabel(String.valueOf(k * k)+junk);
    }

    /* Tell BRIDGES which data structure to visualize */
    bridges.setDataStructure(arr);

    /* Visualize the Array */
    bridges.visualize();
  }
}
