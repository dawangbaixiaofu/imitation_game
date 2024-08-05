#pragma once

class Vec2{
public:
    float x, y;
    Vec2() = default;
    Vec2(float x, float y):
        x(x),y(y){}
    
    Vec2 operator + (Vec2 other){
        return Vec2(this->x + other.x, this->y+other.y);
    }
    void operator += (Vec2 other){
        this->x += other.x; 
        this->y += other.y;
    }
};