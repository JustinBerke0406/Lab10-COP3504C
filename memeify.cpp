#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "memer.h"

using namespace std;

int main(int argc, char** argv)
{
    string filename = argv[1];

    auto img = sf::Image();
    img.loadFromFile(filename);

    string bottomMsg = (argc > 3) ? argv[3] : "";

    int topX = (argc > 4) ? stoi(argv[4]) : -1;
    int topY = (argc > 5) ? stoi(argv[5]) : -1;

    int bottomX = (argc > 6) ? stoi(argv[6]) : -1;
    int bottomY = (argc > 7) ? stoi(argv[7]) : -1;

    auto meme = Memer::generateMeme(img, argv[2], bottomMsg, topX, topY, bottomX, bottomY);

    int index = filename.find('.');
    string ext = filename.substr(index);

    string modifiedName = filename.substr(0, index) + "-meme" + ext;

    Memer::saveToFile(meme, modifiedName);

    return 0;
}
