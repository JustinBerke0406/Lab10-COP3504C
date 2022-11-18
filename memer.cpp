#include "memer.h"

sf::Image
Memer::generateMeme(sf::Image base, sf::String topText, sf::String bottomText, int topX, int topY, int bottomX,
                    int bottomY)
{
    // Load texture
    sf::Texture texture;
    texture.loadFromImage(base);

    // Get sprite
    sf::Sprite sprite(texture);

    // Get dimensions
    int width = sprite.getTextureRect().width,
        height = sprite.getTextureRect().height;

    // Create new RenderTexture
    sf::RenderTexture renderTexture;
    renderTexture.clear();
    renderTexture.create(width, height);

    // Draw meme image to the texture
    renderTexture.draw(sprite);

    // New font
    sf::Font font;
    font.loadFromFile("Cave-Story.ttf");

    // New text
    sf::Text top(topText, font);
    auto topTextBound = top.getLocalBounds();

    // Counteract the offset of the text when determining its positions
    float topXPos = ((topX == -1) ? (float) -width/2 : (float) -topX) + topTextBound.width/2,
          topYPos = ((topY == -1) ? (float) -height/3: (float) -topY) + topTextBound.height/2;

    // Set position
    top.setOrigin(topXPos, topYPos);

    // Set text color
    top.setFillColor(sf::Color(255, 255, 255));

    // Draw text to texture
    renderTexture.draw(top);

    // Only do if there is bottom text
    if (!bottomText.isEmpty()) {
        // All of this is the same as what was done with the top text
        sf::Text bottom(bottomText, font);
        auto bottomTextBound = bottom.getLocalBounds();

        float bottomXPos = ((bottomX == -1) ? (float) -width/2 : (float) -bottomX) + bottomTextBound.width/2,
              bottomYPos = ((bottomY == -1) ? -2 * (float) height/3: (float) -bottomY) + bottomTextBound.height/2;

        bottom.setOrigin(bottomXPos, bottomYPos);

        bottom.setFillColor(sf::Color(255, 255, 255));

        renderTexture.draw(bottom);
    }

    // Launch a window
    launchWindow(renderTexture, width, height);

    // Return new meme image
    return retrieveImage(renderTexture);
}

sf::Image Memer::retrieveImage(sf::RenderTexture &renderTexture)
{
    // Get image from renderTexture and flip so its in the right direction
    sf::Image img = renderTexture.getTexture().copyToImage();
    img.flipVertically();

    return img;
}

void Memer::saveToFile(const sf::Image& base, string filename)
{
    base.saveToFile(filename);
}

void Memer::launchWindow(sf::RenderTexture &renderTexture, int width, int height)
{
    // New window
    sf::RenderWindow window(sf::VideoMode(width, height), "Meme Generator");

    // Event needed for windows to work
    sf::Event event;

    // Get sprite from texture and then flip the sprite
    sf::Sprite afterSprite(renderTexture.getTexture());
    afterSprite.setTextureRect(sf::IntRect(0, height, width, -height));

    // For loop to keep window open
    while (window.isOpen())
    {
        // Draw sprite
        window.clear();
        window.draw(afterSprite);
        window.display();

        // Close window if the close event was triggered
        if (window.pollEvent(event) and event.type == sf::Event::Closed)
            window.close();
    }
}
