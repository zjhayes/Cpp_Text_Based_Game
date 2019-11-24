// Zachary Hayes - zjhayes@dmacc.edu - November 19th, 2019

#include "Scene.hpp"

Scene::Scene(){}

Scene::Scene(std::string _description)
{
    description = _description;
}

std::string Scene::getDescription()
{
    return description;
}

void Scene::setDescription(std::string _description)
{
    description = _description;
}

std::vector<Choice*> Scene::getChoices()
{
    return choices;
}

void Scene::addChoice(Choice* _choice)
{
    choices.push_back(_choice);
}
