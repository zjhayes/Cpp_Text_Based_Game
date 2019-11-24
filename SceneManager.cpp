// Zachary Hayes - zjhayes@dmacc.edu - November 19th, 2019

#include "SceneManager.hpp"

SceneManager::SceneManager(){}

// Returns true if user exits game.
bool SceneManager::runScene()
{
    // Only print description when Scene is first entered.
    if(!skipDescription)
    {
        std::cout << currentScene->getDescription() << std::endl << std::endl;
        skipDescription = true;
    }
    
    // Get user decision.
    Choice* choice = makeChoice(currentScene);
    std::cout << choice->response << std::endl << std::endl;
    
    if(choice->dropsLoot)                       // Check choice properties, and apply.
    {
        addItemToInventory(choice->loot);
    }
    
    if(choice->changesScenes)
    {
        // This choice is a path into another scene.
        setScene(choice->nextScene);
        skipDescription = false;
    }
    
    if(choice->isExit)
    {
        // Game will be ended.
        return true;
    }
    
    return false;
}

void SceneManager::setScene(Scene *nextScene)
{
    currentScene = nextScene;
}

Choice* SceneManager::makeChoice(Scene* _scene)
{
    int choiceIndex;
    std::vector<Choice*> choices = _scene->getChoices();
    std::vector<Choice*> validChoices;
    
    // If choice requires an item that's not in inventory, it is not valid.
    for(Choice* choice : choices)
    {
        if(!choice->requiresItem || (choice->requiresItem && itemInInventory(choice->requiredItem)))
        {
            validChoices.push_back(choice);
        }
    }
    
    printChoices(validChoices);
    
    choiceIndex = takeUserInput(choices.size()) - 1; // 1 less than printed index.
    
    return validChoices[choiceIndex];
}

void SceneManager::printChoices(std::vector<Choice*> _choices)
{
    // Print each choice.
    int index = 1;
    for(Choice* choice : _choices)
    {
        std:: cout << index++ << ". ";
        std::cout << choice->description << std::endl;
    }
}

// Take input and validate that choice is legal.
int SceneManager::takeUserInput(unsigned long numberOfChoices)
{
    int userInput;
    std::cout << "Choose your next action: ";
    std::cin >> userInput;
    std::cin.clear();
    std::cin.ignore(INT_MAX,'\n');
    
    if(userInput > 0 && userInput <= numberOfChoices)
    {
        std::cout << std::endl;
        return userInput;
    }
    {
        std::cout << "Invalid choice, try again. ";
        return takeUserInput(numberOfChoices);
    }
}

bool SceneManager::itemInInventory(std::string itemToCheck)
{
    for(std::string inventoryItem : inventory)
    {
        if(inventoryItem.compare(itemToCheck) == 0)
        {
            return true;
        }
    }
    return false;
}

void SceneManager::addItemToInventory(std::string newItem)
{
    if(!itemInInventory(newItem))
    {
        std::cout << newItem << " added to inventory." << std::endl << std::endl;
        inventory.push_back(newItem);
    }
}

void SceneManager::printText(std::string text)
{
    std::cout << text << std::endl;
}
