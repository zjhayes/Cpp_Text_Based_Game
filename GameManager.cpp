// Zachary Hayes - zjhayes@dmacc.edu - November 19th, 2019

#include "GameManager.hpp"

GameManager::GameManager()
{
    sceneManager.setScene(data.getFirstScene());
}

// Run game until exited.
void GameManager::runGame()
{
    bool exit;
        
    sceneManager.printText(data.getOpeningText());
    
    do
    {
        exit = sceneManager.runScene();
        
    }while(!exit);
}
