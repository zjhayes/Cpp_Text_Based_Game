// Zachary Hayes - zjhayes@dmacc.edu - November 19th, 2019

#ifndef GameManager_hpp
#define GameManager_hpp

#include <stdio.h>
#include "Scene.hpp"
#include <vector>
#include <iostream>
#include "SceneManager.hpp"
#include "SceneData.hpp"

class GameManager
{
private:
    SceneManager sceneManager = SceneManager();
    SceneData data = SceneData();
public:
    GameManager();
    void runGame();
};

#endif /* GameManager_hpp */
