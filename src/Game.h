#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Game
{
    private:
        sf::RenderWindow window;
        sf::Font font;
        sf::Text text;
        sf::Music music;

        void processEvents();

        void render();
    public:
        Game();

        void run();
};

#endif // GAME_H
