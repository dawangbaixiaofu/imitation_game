#include "SFML/Graphics/View.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/CircleShape.hpp"


int main(){
    sf::RenderWindow window(sf::VideoMode(1000, 800), "coordinate");

    sf::CircleShape circle(40.0);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(sf::Vector2f(500, 400));


    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
                break;
            }
        }

        window.clear();
        window.draw(circle);
        window.display();

        
    }
}