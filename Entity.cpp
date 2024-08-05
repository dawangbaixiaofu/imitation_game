
#include <memory>
#include "Entity.h"
#include <string>


Entity::Entity() = default;

Entity::Entity(const std::string &name, int id):
    name(name), id(id) {}

void Entity::destory()
{
    is_live = false;
}
