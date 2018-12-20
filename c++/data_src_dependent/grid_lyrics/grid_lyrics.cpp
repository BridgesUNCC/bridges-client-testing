#include "Bridges.h"
#include "DataSource.h"
#include "Array.h"
#include "SLelement.h"
#include "ColorGrid.h"
#include <sstream>
#include <string>

using namespace bridges;

//Tokenize a string into individual word, removing punctuation at the
//end of words
std::vector<std::string> lyrics_tokenize(const std::string& lyrics) {
  std::vector<std::string> ret;

  std::stringstream ss (lyrics);

  std::string line;

  //For each line
  while (getline(ss, line, '\n')) {
    //Skip all like starting with [
    if (line[0] == '[')
      continue;

    std::stringstream ssline (line);
    //For all words
    while (ssline) {
      std::string word;
      ssline>>word;
      if (ssline) {

	//remove punctuation at the end of word
	while (word.length() > 0
	       && std::ispunct(word[word.length()-1])) {
	  word.pop_back();
	}
	ret.push_back(word);
      }
    }
  }
  
  return ret;
}

int main(int argc, char* argv[]) {

	std::string author = "Daft Punk";
	std::string title = "Harder Faster Better Stronger";

	if (argc == 5) {
	  title = argv[1];
	  author = "";
	}
	if (argc > 5) {
	  title = argv[1];
	  author = argv[2];
	}

	int assignment_id = 107;
	if (argc > 3) {
	  assignment_id = atoi(argv[3]);
	}

	//create the Bridges object, set credentials
	Bridges *bridges = new Bridges(203, argv[1], argv[2]);
	bridges->setServer (argv[3]);
	

	//Get Song data
	DataSource *ds = new DataSource;
	Song s = ds->getSong(title, author);

	bridges->setTitle("Song Grid - `"+ title + "'  by " + author);

	
	//print lyrics
	//std::cout<<s.getLyrics()<<std::endl;

	//tokenize lyrics
	auto words = lyrics_tokenize(s.getLyrics());

	//print lyrics one word at a time
//	for (auto w : words) {
//	  std::cout<<w<<std::endl;
//	}

	int wordCount = words.size();

	//Build an empty grid
	ColorGrid grid (wordCount, wordCount);

	Color matchColor (0, 0, 0, 255);
	Color mismatchColor (255, 255, 255, 255);

	//Build repetition matrix
	for (int i=0; i<wordCount; ++i) {
	  for (int j=0; j<wordCount; ++j) {
	    if (words[i].compare(words[j]) == 0)
	      grid.set(i, j, matchColor);
	    else
	      grid.set(i, j, mismatchColor);
	  }
	}
	
	//tell Bridges what data structure to visualize
	bridges->setDataStructure(&grid);

	// visualize the grid
	bridges->visualize();
	
	return 0;
}
