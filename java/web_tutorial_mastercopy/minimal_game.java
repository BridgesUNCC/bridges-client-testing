import bridges.games.*;
import bridges.base.*;

class minimal_game extends NonBlockingGame {
	public minimal_game(int assignmentnumber, String username, String apikey) {
		super (assignmentnumber, username,  apikey, 10, 10);
		//this created a game board of 10x10 into assignment 1
	}

	public void initialize() {
		//This function is executed once at the beginning of the game
	}

	public void gameLoop() {
		//This function is executed each frame of the game
	}

	public static void main (String args[]) {
#if TESTING
		minimal_game g = new minimal_game(Integer.parseInt(args[0]), args[1], args[2]);
#else
		minimal_game g = new minimal_game(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
#endif

		g.start();
	}
}
