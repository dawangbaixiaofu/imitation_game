#include "Game.h"
#include "SFML/Window/Event.hpp"
#include <iostream>

Game::Game()
{
    init();
}

void Game::init()
{
    window.create(sf::VideoMode(800, 600), "test");
    spawn_player();
    window.setFramerateLimit(60);
}

void Game::spawn_player()
{
    auto e = entity_manager.add_entity("player");
    Vec2 pos = {window.getSize().x/2, window.getSize().y/2};
    Vec2 speed = {5.0, 5.0};
    e->c_transform = std::make_shared<CTransform>(pos, speed);
    e->c_input = std::make_shared<CInput>();
    e->c_shape = std::make_shared<CShape>(10, 8, sf::Color::Green, sf::Color::Blue, 2);
    player = e;

}

void Game::user_input()
{
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            running = false;
        }
        if(event.type == sf::Event::KeyPressed){
            switch(event.key.code){
                case sf::Keyboard::W:
                    player->c_input->up = true;
                    std::cout << "w is pressed." << std::endl;
                    break;
                case sf::Keyboard::S:
                    player->c_input->down = true;
                    break;
                case sf::Keyboard::A:
                    player->c_input->left = true;
                    break;
                case sf::Keyboard::D:
                    player->c_input->right = true;
                    break;
            }
        }
        if(event.type == sf::Event::KeyReleased){
            switch(event.key.code){
                case sf::Keyboard::W:
                    player->c_input->up = false;
                    break;
                case sf::Keyboard::S:
                    player->c_input->down = false;
                    break;
                case sf::Keyboard::A:
                    player->c_input->left = false;
                    break;
                case sf::Keyboard::D:
                    player->c_input->right = false;
                    break;
            }
        }
    }

}

void Game::movement()
{
    Vec2 velocity = {0, 0};
    if(player->c_input->up){
        velocity.y -= player->c_transform->speed.y;
    }
    if(player->c_input->down){
        velocity.y += player->c_transform->speed.y;
    }
    if(player->c_input->left){
        velocity.x -= player->c_transform->speed.x;
    }
    if(player->c_input->right){
        velocity.x += player->c_transform->speed.x;
    }
    player->c_transform->pos += velocity;
}

void Game::render()
{
    window.clear();
    player->c_shape->circle.setPosition(player->c_transform->pos.x, player->c_transform->pos.y);
    window.draw(player->c_shape->circle);
    window.display();
}

void Game::run()
{
    while(running){
        entity_manager.update();
        user_input();
        movement();
        render();
    }
}
