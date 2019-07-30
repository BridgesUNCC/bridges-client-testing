#include <NonBlockingGame.h>

using namespace bridges::game;

struct my_game : public NonBlockingGame {
  my_game(int assID, std::string username, std::string apikey)
    : NonBlockingGame (assID, username,  apikey)
  {
  }
  virtual void initialize() override
  {
    //This function is executed once at the beginning of the game
  }
  virtual void gameLoop() override
  {
    //This function is executed each frame of the game
  }
};

int main (int argc, char** argv) {
#if TESTING
  // command line args provide credentials and server to test on
  my_game g (atoi(argv[1]), argv[2], argv[3]);
#else
  my_game g(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
	                             "YOUR_API_KEY");
#endif

  
  g.start();
}
