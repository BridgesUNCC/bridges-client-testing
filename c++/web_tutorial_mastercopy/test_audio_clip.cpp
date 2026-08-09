#include "AudioClip.h"
#include <iostream>
#include <fstream>
#include "Bridges.h"
#include <math.h>

using namespace std;
using namespace bridges;


int main(int argc, char*argv[]) {

#if TESTING
  // command line args provide credentials and server to test on
  Bridges bridges (atoi(argv[1]), argv[2], argv[3]);

  if (argc > 4)
    bridges.setServer(argv[4]);


#else
  Bridges bridges (YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		   "YOUR_API_KEY");
#endif

  bridges.setTitle("Testing audio clip IO loader");

  try {      
    AudioClip ac2 ("../../data/clap-8bit.wav");
  
    AudioClip ac3 ("../../data/clap-16bit.wav");
    
    AudioClip ac4 ("../../data/clap-24bit.wav");
  
    AudioClip ac5 ("../../data/clap-32bit.wav");
	    
    AudioClip ac6 ("../../data/piano.wav");

    AudioClip ac7 ("../../data/CelloA2Trim.wav"); //This particular file caused infinite loop at some point. This file has a meta data subchunk with an odd length (causing a meta data padding byte)
  } catch(std::string s) {
    std::cout<<s<<"\n";
  }

    
  return 0;
}
