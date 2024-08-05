#pragma once
#include "EntityManager.h"
#include "SFML/Graphics/RenderWindow.hpp"

class Game{
public:
    sf::RenderWindow window;
    EntityManager entity_manager;
    std::shared_ptr<Entity> player;

    bool running = true;


    Game();
    void init();
    /*
    创建窗口，并初始化
    */
    void spawn_player();
    /*
    添加player
    初始化player的各个组件
    
    */
    void user_input();
    /*
    用户的输入控制player
    */
    void movement();
    /*
    根据用户的输入来设置player的位置
    */
    void render();
    /*
    画出player的新位置
    调整camera view的位置
    */
    void run();
    /*
    entity_manager进行更新
    玩家输入
    玩家移动
    渲染画图
    */


};