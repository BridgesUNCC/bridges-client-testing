import random
from bridges import AudioClip
from bridges import Bridges
import math
import sys


class AudioTest(AudioClip):
                
    def generate_sine(self, bit_depth: int) -> None:
        for s in range(self.sample_count):
            for c in range(self.num_channels):
                val = math.sin(s / 20)
                self.set_sample(c, s, val * ((2 ** bit_depth / 2.0) - 1.0))

def main():

#if TESTING
    # command line args provide credentials and server to test on
    args = sys.argv[1:]
    bridges = Bridges(int(args[0]), args[1], args[2])
    if len(args) > 3:
        bridges.connector.set_server(args[3])
#else
    bridges = Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")
#endif

    clip = AudioTest(sample_count=int(44100*.25), num_channels=2)

    clip.generate_sine(32)

    bridges.set_data_structure(clip)
    bridges.visualize()

    
    # Bit Depth Testing, was unsure where to put this since it requires a new clip
    
    clip = AudioTest(sample_count=int(44100*.25), num_channels=1, sample_bits=8, sample_rate=44100)
    clip.generate_sine(8)

    bridges.set_data_structure(clip)
    bridges.visualize()
    
    clip = AudioTest(filepath="../../data/clap-8bit.wav")

    bridges.set_data_structure(clip)
    bridges.visualize()

    clip = AudioTest(filepath="../../data/clap-16bit.wav")

    bridges.set_data_structure(clip)
    bridges.visualize()

    clip = AudioTest(filepath="../../data/clap-24bit.wav")

    bridges.set_data_structure(clip)
    bridges.visualize()

    clip = AudioTest(filepath="../../data/clap-32bit.wav")

    bridges.set_data_structure(clip)
    bridges.visualize()

    clip = AudioTest(filepath="../../data/piano.wav")

    bridges.set_data_structure(clip)
    bridges.visualize()




if __name__ == "__main__":
    main()
