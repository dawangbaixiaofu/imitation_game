#pragma once
#include <memory>
#include "Component.h"


class Vec2{
public:
    float x, y;
    Vec2(float x, float y):
        x(x),y(y){}
    
    Vec2 operator + (Vec2 other){
        return Vec2(this->x + other.x, this->y+other.y);
    }
};


class Entity{
public:
    Vec2 pos;
    Vec2 speed;
    std::shared_ptr<CTransform> c_transform;    

    Entity();
    

};