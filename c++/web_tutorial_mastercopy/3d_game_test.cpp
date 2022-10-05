#include "Bridges.h"
#include "DataSource.h"
#include "TerrainMesh.h"
#include "data_src/ElevationData.h"

#include "Scene.h"
#include "Camera.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace bridges;

int main(int argc, char **argv) {

	// create Bridges object
#if TESTING
	// command line args provide credentials and server to test on
	Bridges bridges (atoi(argv[1]), argv[2], argv[3]);

	if (argc > 4)
		bridges.setServer(argv[4]);

	bridges.setTitle("3D Game Engine Test");
#else
	Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");
#endif

	bridges.setServer("clone");

	//create the Bridges object, set credentials

	DataSource ds;
	dataset::ElevationData elev_data;

	// Get a List of Elevation data  records from Bridges
	try {
		elev_data = ds.getElevationData(33.394759, -122.299805, 42.747012, 
										-114.916992, 0.2);
	}
	catch (std::string s) {
		std::cerr << "Exception: " << s << "\n";
	}

	// create a terrain mesh
	
	vector<float> verts;
	for (auto k : elev_data.getData()) 
			verts.push_back (k);
//	TerrainMesh terrain(elev_data.getRows(), elev_data.getCols(), verts); 
	TerrainMesh terrain(15, 15, verts); 




	// specify scene
	float position[] = {0., 0., 0.};
	Scene sc("terrain scene", 90, position);
		sc.add(terrain);

	bridges.setDataStructure (&sc);

	// to print JSON from bridges::visualize() uncomment the following 2 lines
	// but it might crash/burn since the JSON should not be sent to the server
	// as it needs to use the game API; this was done just for testing the JSON

	// bridges.setJSONFlag(true);
	// bridges.visualize();

	// get JSON
	const string scene_json = sc.getDataStructureRepresentation();
//	cout << "scene JSON:  " << scene_json << endl;

	// print the data dimensions  and the firs 10 elevation data values
	cout << "\tWidth: " << elev_data.getCols() << endl
		<< "\tHeight: " << elev_data.getRows() << endl
		<< "\tCell Size: " << elev_data.getCellSize() << endl
		<< "\tLower Left Corner: "  << elev_data.getxll()  << 
				 ", " <<  elev_data.getyll() <<endl;

	cout << "The first 10 elevation values.." << endl;
	for (int k = 0; k < 10; k++)
		cout << elev_data.getVal(0, k) << "  " << endl;
	cout << endl;

	return 0;
}
