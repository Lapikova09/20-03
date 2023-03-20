#include <SFML/Graphics.hpp>
#include <vector>
#include "settings.h"
#include "Player.h"
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(FPS);

    Player player;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        player.update();

       
        window.clear();
        window.draw(player.getSprite());
        window.display();
    }

    return 0;
}