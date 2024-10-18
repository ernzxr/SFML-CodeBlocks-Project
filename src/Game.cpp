#include "Game.h"

Game::Game()  {
    window.create(sf::VideoMode(800, 600), "UTN FRGP");

    // Cargar la fuente
    if (!font.loadFromFile("resources/fonts/arial.ttf")) {
        std::cerr << "Error al cargar la fuente" << std::endl;
    }

    // Cargar la música
    if (!music.openFromFile("resources/sounds/miau.mp3")) {
        std::cerr << "Error al cargar la música" << std::endl;
    }

    // Reproducir la música
    music.setVolume(5);
    music.setLoop(true);
    music.play();

    // Crear un texto
    text.setFont(font);
    text.setString("Universidad Tecnologica Nacional\nFacultad Regional General Pacheco\nProgramación II");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 200);

    // Obtener el tamaño del texto
    sf::FloatRect textBounds = text.getLocalBounds();

    // Establecer el origen del texto en el centro
    text.setOrigin(textBounds.width / 2, textBounds.height / 2);

    // Centrar en la ventana
    text.setPosition(window.getSize().x / 2, window.getSize().y / 2);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::render() {
    window.clear();
    window.draw(text);  // Dibuja el texto
    window.display();
}
