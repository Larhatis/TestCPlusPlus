#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

int main() {
    // smoke la windows
    sf::RenderWindow window(sf::VideoMode(400, 400), "Grille");

    // le pion
    sf::CircleShape circle(10);
    circle.setFillColor(sf::Color::Blue);

    // position de base du pion
    int x = 10;
    int y = 10;

    // Boucle principale du programme
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    // déplacer le pion vers la gauche
                    if (x > 0) {
                        x--;
                    }
                } else if (event.key.code == sf::Keyboard::Right) {
                    // déplacer le pion vers la droite
                    if (x < 19) {
                        x++;
                    }
                } else if (event.key.code == sf::Keyboard::Up) {
                    // déplacer le pion vers le haut
                    if (y > 0) {
                        y--;
                    }
                } else if (event.key.code == sf::Keyboard::Down) {
                    // déplacer le pion vers le bas
                    if (y < 19) {
                        y++;
                    }
                }
            }
        }

        // clear de la window
        window.clear(sf::Color(192, 192, 192));

        // grille
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                // cases grises
                if ((i + j) % 2 == 0) {
                    sf::RectangleShape rectangle(sf::Vector2f(20, 20));
                    rectangle.setFillColor(sf::Color(128, 128, 128));
                    rectangle.setPosition(i * 20, j * 20);
                    window.draw(rectangle);
                }
            }
        }
        // dessiner les lignes et les colonnes grises
        for (int i = 0; i <= 20; i++) {
            // dessiner une ligne horizontale
            sf::RectangleShape line(sf::Vector2f(400, 1));
            line.setFillColor(sf::Color(128, 128, 128));
            line.setPosition(0, i * 20);
            window.draw(line);

            // dessiner une ligne verticale
            sf::RectangleShape column(sf::Vector2f(1, 400));
            column.setFillColor(sf::Color(128, 128, 128));
            column.setPosition(i * 20, 0);
            window.draw(column);
        }

        // dessiner le pion
        circle.setPosition(x * 20, y * 20);
        window.draw(circle);

        // afficher la fenêtre
        window.display();
    }

    return 0;
}
