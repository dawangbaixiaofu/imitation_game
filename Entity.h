#pragma once
#include <memory>
#include "Components.h"
#include <string>
#include "Vec2.h"


class Entity{
public:
    Vec2 pos;
    Vec2 speed;
    std::string name;
    int id;
    bool is_live = true;

    std::shared_ptr<CTransform> c_transform;
    std::shared_ptr<CInput> c_input;
    std::shared_ptr<CShape> c_shape;    

    Entity();
    Entity(const std::string& name, int id);
    void destory();

};