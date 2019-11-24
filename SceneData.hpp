// Zachary Hayes - zjhayes@dmacc.edu - November 20th, 2019

#ifndef SceneData_h
#define SceneData_h

#include <stdio.h>
#include "SceneData.hpp"
#include "Scene.hpp"
#include <vector>

class SceneData
{
private:
    Scene* firstScene;
public:
    SceneData();
    void initializeScenes();
    Scene* getFirstScene();
    std::string getOpeningText();
};

#endif /* SceneData_h */
