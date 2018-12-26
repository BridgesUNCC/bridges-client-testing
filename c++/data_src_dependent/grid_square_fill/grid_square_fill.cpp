#include <iostream>
#include "Bridges.h"
#include "ColorGrid.h"
#include "Color.h"
#include "ctime"

using namespace bridges;

int main(int  argc, char **argv) {
    Bridges *bridges = new Bridges(305, argv[1], argv[2]);
	bridges->setServer(argv[3]);

    int rows = 100;
    int columns = 100;

    int totalPixels = rows * columns;
    int filledPixels = 0;

    // initializes a value to check if a point is free or not
    int free = 0;

    ColorGrid grid(rows, columns, Color(255, 255, 255, free));
    bridges->setTitle("Square Fill Grid");

    srand((unsigned) time(nullptr));

    // fill grid
    while (filledPixels < totalPixels){
        int originX = rand() % columns;
        int originY = rand() % rows;

        // if grid space isn't free, generate another one
        if (grid.get(originY, originX).getAlpha() != free)
            continue;

        // generate random color for origin
        grid.set(originY, originX, Color(rand()%255,rand()%255, rand()%255));

        filledPixels++;

        bool collision = false;
        int layers = 1;

        // begin adding layers
        while (!collision) {
            // store locations of the bottomLeft and topRight of current layer
            int bottomLeftX = originX - layers;
            int bottomLeftY = originY - layers;
            int topRightX = originX + layers;
            int topRightY = originY + layers;

            // break if out of bounds
            if (bottomLeftX < 0 || bottomLeftY < 0 ||
                        topRightX >= columns || topRightY >= rows) {
                break;
            }

                int sideLength = 1 + layers * 2;

                // collision check pass
                for (int i = 0; i < sideLength; ++i) {
                    int northX = topRightX - i;
                    int eastY = topRightY - i;
                    int southX = bottomLeftX + i;
                    int westY = bottomLeftY + i;

                    if (!(grid.get(topRightY, northX).getAlpha() == free &&
                            grid.get(eastY, topRightX).getAlpha() == free &&
                            grid.get(westY, bottomLeftX ).getAlpha() == free &&
                            grid.get(bottomLeftY, southX).getAlpha() == free)) {
                        collision = true;
                        break;
                    }
                }

                // if collision on current layer, don't draw the layer
                if (collision)
                    continue;

                // else generate a new color and fill the layer
                Color col(rand()%255, rand()%255, rand()%255);

                for (int i = 0; i < sideLength; ++i) {
                    int northX = topRightX - i;
                    int eastY = topRightY - i;
                    int southX = bottomLeftX + i;
                    int westY = bottomLeftY + i;

                    grid.set(topRightY, northX, col);
                    grid.set(eastY, topRightX, col);
                    grid.set(westY, bottomLeftX, col);
                    grid.set(bottomLeftY, southX, col);
                }

                filledPixels += sideLength * 4 - 4;
                layers++;
        }

    }

    bridges->setDataStructure(&grid);
    bridges->visualize();

    return 0;
}
