#include "AudioClip.h"
#include <iostream>
#include <fstream>
#include "Bridges.h"
#include <math.h>

using namespace std;
using namespace bridges;

void generateSine(AudioClip * ac) {
    for (int s = 0; s < ac->getSampleCount(); s++) {
        for (int c = 0; c < ac->getNumChannels(); c++) {
            double val = sin(s / 20.0);
            int minmax32 = (pow(2, 32) / 2.0) - 1.0;

            int amp = (int)(val * minmax32);
            
            ac->setSample(c, s, amp);
        }
    }
}

int main() {
    Bridges bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

    bridges.setTitle("Audio Mixing");
    bridges.setDescription("Mixing two AudioClips together");

    bridges.setServer("clone");

    // Load the clips
    AudioClip clip = AudioClip(44100*5);

    generateSine(&clip);

    bridges.setDataStructure(clip);
    bridges.visualize();

    return 0;
}