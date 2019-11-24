// Zachary Hayes - zjhayes@dmacc.edu - November 19th, 2019

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>
#include <string>
#include <vector>

class Scene; // Forward declaration.

struct Choice
{
    std::string description = "";
    std::string response = "";
    bool requiresItem = false;
    std::string requiredItem;
    bool dropsLoot = false;
    std::string loot;
    bool changesScenes = false;
    Scene* nextScene;
    bool isExit = false;

};

class Scene
{
private:
    std::string description;
    std::vector<Choice*> choices;
public:
    Scene();
    Scene(std::string);
    std::string getDescription();
    void setDescription(std::string);
    std::vector<Choice*> getChoices();
    void addChoice(Choice*);
    
};

#endif /* Scene_hpp */
