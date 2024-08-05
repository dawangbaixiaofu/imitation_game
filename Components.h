#pragma once
#include "Vec2.h"
#include "SFML/Graphics/CircleShape.hpp"

class CTransform{
public:
    Vec2 pos;
    Vec2 speed;

    CTransform(Vec2 pos, Vec2 speed)
    :pos(pos), speed(speed)
    {}
};

class CShape{
public:
    sf::CircleShape circle;
    CShape(float radius, size_t points, sf::Color fill_color, sf::Color outline_color, float outline_thickness)
    :circle(radius, points){
        circle.setFillColor(fill_color);
        circle.setOrigin(radius, radius);
        circle.setOutlineColor(outline_color);
        circle.setOutlineThickness(outline_thickness);
    }
};

class CInput{
public:
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;

    CInput(){}
};