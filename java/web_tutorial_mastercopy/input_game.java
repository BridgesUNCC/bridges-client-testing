import bridges.games.*;
import bridges.base.*;

class input_game extends NonBlockingGame {
	public input_game(int assignmentnumber, String username, String apikey) {
		super (assignmentnumber, username,  apikey, 10, 10);
		//this created a game board of 10x10 into assignment 1
	}

	public void initialize() {
		for (int i = 0; i < getBoardHeight(); ++i)
			for (int j = 0; j < getBoardWidth(); ++j)
				setBGColor(i, j, NamedColor.ivory);
	}

	public void gameLoop() {
		//This function is executed each frame of the game

		if (keyUp()) {
			drawSymbol(1, 1, NamedSymbol.H, NamedColor.blue);
			drawSymbol(1, 2, NamedSymbol.E, NamedColor.yellow);
			drawSymbol(1, 3, NamedSymbol.L, NamedColor.black);
			drawSymbol(1, 4, NamedSymbol.L, NamedColor.green);
			drawSymbol(1, 5, NamedSymbol.O, NamedColor.red);
		}
		else {
			drawSymbol(1, 1, NamedSymbol.none, NamedColor.blue);
			drawSymbol(1, 2, NamedSymbol.none, NamedColor.yellow);
			drawSymbol(1, 3, NamedSymbol.none, NamedColor.black);
			drawSymbol(1, 4, NamedSymbol.none, NamedColor.green);
			drawSymbol(1, 5, NamedSymbol.none, NamedColor.red);
		}
	}

	public static void main (String args[]) {
#if TESTING
		input_game g = new input_game(Integer.parseInt(args[0]), args[1], args[2]);
#else
		input_game g = new input_game(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
#endif
		g.start();
	}
}
