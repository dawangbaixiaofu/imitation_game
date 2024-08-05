#pragma once
#include "Entity.h"
#include <vector>

typedef std::vector<std::shared_ptr<Entity>> VecEntity;

class EntityManager{
public:
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::shared_ptr<Entity>> to_add;
    int entity_id=0;

    EntityManager();
    std::shared_ptr<Entity> add_entity(const std::string& name);
    void remove_dead_entity(VecEntity& entities);
    void update();
    
};