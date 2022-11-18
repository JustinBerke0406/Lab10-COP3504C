#pragma once

#include <SFML/Graphics.hpp>

using namespace std;

class Memer
{
private:
    static sf::Image retrieveImage(sf::RenderTexture& renderTexture);                   // Get an image from a RenderTexture
    static void launchWindow(sf::RenderTexture& renderTexture, int width, int height);  // Open a window with the meme on it
public:
    static sf::Image generateMeme(sf::Image base, sf::String topText, sf::String bottomText = "",  // Generate a meme image
                           int topX = -1, int topY = -1, int bottomX = -1, int bottomY = -1);

    static void saveToFile(const sf::Image& base, std::string filename);        // Save an image to a file
};