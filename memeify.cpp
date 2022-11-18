#include <string>
#include <SFML/Graphics.hpp>
#include "memer.h"

using namespace std;

int main(int argc, char** argv)
{
    string filename = argv[1];

    // Get image from filename
    auto img = sf::Image();
    img.loadFromFile(filename);

    // Read the bottom message if the argument list is long enough
    string bottomMsg = (argc > 3) ? argv[3] : "";

    // Get the top coordinates if the argument list is long enough
    int topX = (argc > 4) ? stoi(argv[4]) : -1;
    int topY = (argc > 5) ? stoi(argv[5]) : -1;

    // Get the bottom coordinate if the argument list is long enough
    int bottomX = (argc > 6) ? stoi(argv[6]) : -1;
    int bottomY = (argc > 7) ? stoi(argv[7]) : -1;

    // Generate meme
    auto meme = Memer::generateMeme(img, argv[2], bottomMsg, topX, topY, bottomX, bottomY);

    // Create new file with modified name and same extension
    int index = filename.find('.');
    string ext = filename.substr(index);

    string modifiedName = filename.substr(0, index) + "-meme" + ext;

    // Save the meme to the file
    Memer::saveToFile(meme, modifiedName);

    return 0;
}
