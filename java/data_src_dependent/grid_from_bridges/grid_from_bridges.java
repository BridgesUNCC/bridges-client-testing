import bridges.base.Color;
import bridges.base.ColorGrid;
import bridges.connect.Bridges;

import java.util.ArrayList;
import java.util.Arrays;

public class grid_from_bridges {


    public static void main(String[] args) throws Exception {
        Bridges bridges = new Bridges (Integer.parseInt(args[0]), args[1], args[2]);
        bridges.setServer (args[3]);


	int sizeI=25, sizeJ=35;
	ColorGrid cg1 = new ColorGrid(sizeI, sizeJ);
	
	for (int i = 0; i < sizeI; ++i)
	    for (int j = 0; j < sizeJ; ++j) {
		if ((i + j) % 2 == 0) {
		    cg1.set(i, j, new Color(0, 0, 0));
		}
		else {
		    cg1.set(i, j, new Color(255, 255, 255));
		}
	    }
	bridges.setDataStructure(cg1);
	bridges.visualize();

	ColorGrid cg= bridges.getColorGridFromAssignment(bridges.getUserName(), bridges.getAssignmentID(), 0);

	int[] dims = cg.getDimensions();
	for (int k = dims[1] / 2 - 5; k < dims[1] / 2 + 5; k++)
	    for (int j = dims[0] / 2 - 5; j < dims[0] / 2 + 5; j++)
		cg.set(k, j, new Color("red"));

	bridges.setDataStructure(cg);
	bridges.visualize();
	
	
    }
}
