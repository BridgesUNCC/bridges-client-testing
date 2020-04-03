import java.io.IOException;

import bridges.connect.Bridges;
import bridges.validation.RateLimitException;
import bridges.base.AudioClip;

public class audio_clip {
	private static void generateSine(AudioClip ac) {
		for (int s = 0; s < ac.getSampleCount(); s++) {
			for (int c = 0; c < ac.getNumChannels(); c++) {
				double val = Math.sin(s / 20.0);
				
				ac.setSample(c, s, (int)(val * Integer.MAX_VALUE));
			}
		}
	}

	public static void main(String[] args) throws IOException, WavFileException, RateLimitException {
		Bridges bridges = new Bridges(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY");

	    bridges.setTitle("Audio Test");
	    
	    AudioClip ac = new AudioClip(44100*5);
	    
	    generateSine(ac);
	    
	    bridges.setServer("clone");
	    bridges.setDataStructure(ac);

	    bridges.visualize();
	}
}
