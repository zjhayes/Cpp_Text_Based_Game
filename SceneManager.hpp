// Zachary Hayes - zjhayes@dmacc.edu - November 19th, 2019

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <stdio.h>
#include <iostream>
#include "Scene.hpp"
#include <string>
#include <vector>

class SceneManager
{
private:
    Scene* currentScene;
    std::vector<std::string> inventory;
    Choice* makeChoice(Scene*);
    void printChoices(std::vector<Choice*>);
    bool itemInInventory(std::string);
    void addItemToInventory(std::string);
    int takeUserInput(unsigned long);
    bool skipDescription = false;
public:
    SceneManager();
    bool runScene();
    void setScene(Scene*);
    void printText(std::string);
};

#endif /* SceneManager_hpp */
