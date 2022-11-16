#include "memer.h"

sf::Image
Memer::generateMeme(sf::Image base, sf::String topText, sf::String bottomText, int topX, int topY, int bottomX,
                    int bottomY)
{
    sf::Texture texture;
    texture.loadFromImage(base);

    sf::Sprite sprite(texture);

    int width = sprite.getTextureRect().width,
        height = sprite.getTextureRect().height;

    sf::RenderTexture renderTexture;
    renderTexture.clear();
    renderTexture.create(width, height);

    renderTexture.draw(sprite);

    sf::Font font;
    font.loadFromFile("Cave-Story.ttf");

    sf::Text top(topText, font);
    auto topTextBound = top.getLocalBounds();

    float topXPos = ((topX == -1) ? (float) -width/2 : (float) -topX) + topTextBound.width/2,
          topYPos = ((topY == -1) ? (float) -height/3: (float) -topY) + topTextBound.height/2;

    top.setOrigin(topXPos, topYPos);

    top.setFillColor(sf::Color(255, 255, 255));

    renderTexture.draw(top);

    if (!bottomText.isEmpty()) {
        sf::Text bottom(bottomText, font);
        auto bottomTextBound = bottom.getLocalBounds();

        float bottomXPos = ((bottomX == -1) ? (float) -width/2 : (float) -bottomX) + bottomTextBound.width/2,
              bottomYPos = ((bottomY == -1) ? -2 * (float) height/3: (float) -bottomY) + bottomTextBound.height/2;

        bottom.setOrigin(bottomXPos, bottomYPos);

        bottom.setFillColor(sf::Color(255, 255, 255));

        renderTexture.draw(bottom);
    }

    return retrieveImage(renderTexture);
}

sf::Image Memer::retrieveImage(sf::RenderTexture &renderTexture)
{
    sf::Image img = renderTexture.getTexture().copyToImage();
    img.flipVertically();

    return img;
}

void Memer::saveToFile(const sf::Image& base, string filename)
{
    base.saveToFile(filename);
}
