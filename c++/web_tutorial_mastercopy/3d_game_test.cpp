#include "Bridges.h"
#include "DataSource.h"
#include "TerrainMesh.h"
#include "data_src/ElevationData.h"
#include "NonBlockingGame3D.h"

#include "Scene.h"
#include "Camera.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace bridges;
using namespace bridges::game;

struct test: public NonBlockingGame3D {
    int frame;
    bool flag;
    double iTime;
    
    test(int assID, string username, string apikey): NonBlockingGame3D(0, username, apikey){
        frame = 0;
        flag = true;
        iTime = 0.0;
    }
    
    virtual void initialize() override {
        DataSource ds;
        dataset::ElevationData elev_data;
        elev_data = ds.getElevationData(33.394759, -122.299805, 42.747012,
                                        -114.916992, 0.2);
        vector<float> verts;
        for (auto k : elev_data.getData())
                verts.push_back (k);
        TerrainMesh terrain('terr', elev_data.getRows(), elev_data.getCols(), verts);
        float position[] = {0., 0., 0.};
        scene.add(terrain);
    }
    
    virtual void gameLoop() override {
        iTime += 1;
        for(int i = 0; i < scene.get('terr').getRows(); i++){
            for(int j = 0; j < scene.get('terr').getCols(); j++){
                scene.get('terr').vertices[i][j] = sin(iTime + i + j) * 100;
                scene.get('terr').colors[i][j] = [sin(iTime + i), sin(iTime + i+ j), sin(iTime + j)]
            }
        }
    }
};

int main() {
    test game(600, "USERNAME", "ID");
    game.start();
}

