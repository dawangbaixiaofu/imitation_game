#include "EntityManager.h"
#include <memory>


EntityManager::EntityManager() = default;

std::shared_ptr<Entity> EntityManager::add_entity(const std::string &name)
{
    auto entity_ptr = std::shared_ptr<Entity>(new Entity(name, entity_id++));
    to_add.push_back(entity_ptr);
    return entity_ptr;
}

void EntityManager::remove_dead_entity(VecEntity& entities)
{
    VecEntity::iterator cur = entities.begin();
    while(cur != entities.end()){
        if(!cur->get()->is_live){
            cur = entities.erase(cur);
        }
        else{
            cur++;
        }
    }
    
}

void EntityManager::update()
{
    // to add entity to entities
    for(auto e: to_add){
        entities.push_back(e);
    }
    to_add.clear();

    remove_dead_entity(entities);
}
