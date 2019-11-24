// Zachary Hayes - zjhayes@dmacc.edu - November 20th, 2019

#include "SceneData.hpp"

SceneData::SceneData()
{
    initializeScenes();
}

std::string SceneData::getOpeningText()
{
    return "You’ve entered a strange house. ";
}

void SceneData::initializeScenes()
{
    Scene* sceneA = new Scene("There’s a winding staircase to the second floor. A doorway appears to lead to the kitchen, and another to the den. You could always leave if you’re too scared."); // Foyer
    Scene* sceneB = new Scene("A ghost guards the upstairs hallway and will not let you pass. \"I will haunt these halls until my murder is solved.\""); // Upstairs hallways
    Scene* sceneC = new Scene("A chef is cutting carrots, she pays you no attention."); // Kitchen
    Scene* sceneD = new Scene("This must be someone's office. You get goosebumps the moment you enter. It's lit by a single candle sitting on the antique desk. How long has that candle been burning? The dusty bookshelf looks like it hasn't been touched in ages. There's a stain in the wood floor where carpet had been torn up. Blood?"); // Den;
    Scene* sceneE = new Scene(""); // Upstairs hallway 2
    Scene* sceneF = new Scene("The desk is an antique. A stack of newspaper clippings date back fifty years."); // Desk
    Scene* sceneG = new Scene("Hundreds of old books line the bookshelf, where does one even begin?"); // Bookshelf
    Scene* sceneH = new Scene("The hidden room is like a dungeon. It's empty, other than a pedestal in the middle of the room holding an enormous diamond, your instincts tell you not to touch it. A skeleton lays beneath the pedestal clutching a journal."); // Hidden room
    Scene* sceneI;
    Scene* sceneJ;
    Scene* sceneK;
    Scene* sceneL;
    
    firstScene = sceneA;
    
    //SCENE A - FOYER
    Choice* choiceA1 = new Choice();
    choiceA1->description = "Go up the stairs.";
    choiceA1->response = "The stairs creek as you ascend.";
    choiceA1->changesScenes = true;
    choiceA1->nextScene = sceneB;
    sceneA->addChoice(choiceA1);
    
    Choice* choiceA2 = new Choice();
    choiceA2->description = "See what's in the kitchen.";
    choiceA2->response = "As you approach the kitchen, you hear the tapping of a knife.";
    choiceA2->changesScenes = true;
    choiceA2->nextScene = sceneC;
    sceneA->addChoice(choiceA2);
    
    Choice* choiceA3 = new Choice();
    choiceA3->description = "Investigate the den.";
    choiceA3->response = "You cautiously move towards the den, the floorboards creek beneath your feet.";
    choiceA3->changesScenes = true;
    choiceA3->nextScene = sceneD;
    sceneA->addChoice(choiceA3);
    
    Choice* choiceA4 = new Choice();
    choiceA4->description = "Leave the house, never to return.";
    choiceA4->response = "You exit the house, immediately it feels like it was all just a dream.";
    choiceA4->isExit = true;
    sceneA->addChoice(choiceA4);
    
    // SCENE B - UPSTAIRS HALLWAY
    Choice* choiceB1 = new Choice();
    choiceB1->description = "Show the ghost his killer's journal.";
    choiceB1->response = "The ghost weeps, \"Finally, I can rest in peace.\"";
    choiceB1->requiresItem = true;
    choiceB1->requiredItem = "journal";
    choiceB1->changesScenes = true;
    choiceB1->nextScene = sceneE;
    sceneB->addChoice(choiceB1);
    
    Choice* choiceB2 = new Choice();
    choiceB2->description = "Ask the ghost how he died.";
    choiceB2->response = "The ghost ponders your question for a moment, \"I only remember being in the den.\"";
    sceneB->addChoice(choiceB2);
    
    Choice* choiceB3 = new Choice();
    choiceB3->description = "Go back downstairs.";
    choiceB3->response = "You leave the ghost, not so quick as to offend the already weeping apparition. As you descend the stairs you almost trip over a copy of 'Harry Potter and the Chamber of Secrets.' Close call.";
    choiceB3->dropsLoot = true;
    choiceB3->loot = "book";
    choiceB3->changesScenes = true;
    choiceB3->nextScene = sceneA;
    sceneB->addChoice(choiceB3);
    
    // SCENE C - KITCHEN
    Choice* choiceC1 = new Choice();
    choiceC1->description = "*ahem* \"I need that knife.\"";
    choiceC1->response = "The chef gasps, \"Of course Master Chef.\" She hands over her cutting knife, then unsheaths another knife from her belt and continues chopping carrots.";
    choiceC1->requiresItem = true;
    choiceC1->requiredItem = "master chef's hat";
    choiceC1->dropsLoot = true;
    choiceC1->loot = "knife";
    sceneC->addChoice(choiceC1);
    
    Choice* choiceC2 = new Choice();
    choiceC2->description = "Take an apple.";
    choiceC2->response = "You sneak an apple, the chef doesn't notice or doesn't care.";
    choiceC2->dropsLoot = true;
    choiceC2->loot = "apple";
    sceneC->addChoice(choiceC2);
    
    Choice* choiceC3 = new Choice();
    choiceC3->description = "Return to foyer.";
    choiceC3->response = "You leave the kitchen, the sound of chopping fades to deadened echo.";
    choiceC3->changesScenes = true;
    choiceC3->nextScene = sceneA;
    sceneC->addChoice(choiceC3);
    
    // SCENE D - DEN
    Choice* choiceD1 = new Choice();
    choiceD1->description = "Search the desk.";
    choiceD1->response = "You get a chilling feeling, like something terrible happened here.";
    choiceD1->changesScenes = true;
    choiceD1->nextScene = sceneF;
    sceneD->addChoice(choiceD1);
    
    Choice* choiceD2 = new Choice();
    choiceD2->description = "Peruse the bookshelf.";
    choiceD2->response = "You're cautious to void stepping on the blood-stained wood.";
    choiceD2->changesScenes = true;
    choiceD2->nextScene = sceneG;
    sceneD->addChoice(choiceD2);
    
    Choice* choiceD3 = new Choice();
    choiceD3->description = "Return to foyer.";
    choiceD3->response = "You feel relieved leaving the den.";
    choiceD3->changesScenes = true;
    choiceD3->nextScene = sceneA;
    sceneD->addChoice(choiceD3);
    
    // SCENE E - UPSTAIRS HALLWAY 2
    
    // SCENE F - DESK
    Choice* choiceF1 = new Choice();
    choiceF1->description = "Take a closer look at the newspaper clippings.";
    choiceF1->response = "\"30 Carat Diamond Sold To Local Entrepreneur\", \"Montgomery Diamond On Display At State Geology Museum\", \"The Mystery Behind Mr. Montgomery's Personal Vault\", \"Brother Of Montgomery Estate Gone Missing Amid Criminal Allegations\"";
    sceneF->addChoice(choiceF1);
    
    Choice* choiceF2 = new Choice();
    choiceF2->description = "Look through drawers.";
    choiceF2->response = "All you find is a slip of paper that says 'Great Expectations - Charles Dickens'";
    choiceF2->dropsLoot = true;
    choiceF2->loot = "slip of paper";
    sceneF->addChoice(choiceF2);
    
    Choice* choiceF3 = new Choice();
    choiceF3->description = "Investigate the bookshelf instead.";
    choiceF3->response = "You back away from the desk and turn your attention to the bookshelf.";
    choiceF3->changesScenes = true;
    choiceF3->nextScene = sceneG;
    sceneF->addChoice(choiceF3);
    
    Choice* choiceF4 = new Choice();
    choiceF4->description = "Return to foyer.";
    choiceF4->response = "You feel relieved leaving the den.";
    choiceF4->changesScenes = true;
    choiceF4->nextScene = sceneA;
    sceneF->addChoice(choiceF4);
    
    // SCENE G - BOOKSHELF
    Choice* choiceG1 = new Choice();
    choiceG1->description = "Pull out 'Great Expectations' by Charles Dickens";
    choiceG1->response = "Nothing happens.";
    choiceG1->requiresItem = true;
    choiceG1->requiredItem = "slip of paper";
    sceneG->addChoice(choiceG1);
    
    Choice* choiceG2 = new Choice();
    choiceG2->description = "Put 'Harry Potter and the Chamber of Secrets' by J.K. Rowling back on the shelf.";
    choiceG2->response = "You a hear a 'click', and then the bookshelf swings open like a door, revealing a hidden room.";
    choiceG2->requiresItem = true;
    choiceG2->requiredItem = "book";
    choiceG2->changesScenes = true;
    choiceG2->nextScene = sceneH;
    sceneG->addChoice(choiceG2);
    
    Choice* choiceG3 = new Choice();
    choiceG3->description = "Investigate the desk instead.";
    choiceG3->response = "Overwhelmed by all the books, you turn your attention to the desk.";
    choiceG3->changesScenes = true;
    choiceG3->nextScene = sceneF;
    sceneG->addChoice(choiceG3);
    
    Choice* choiceG4 = new Choice();
    choiceG4->description = "Return to foyer.";
    choiceG4->response = "You feel relieved leaving the den.";
    choiceG4->changesScenes = true;
    choiceG4->nextScene = sceneA;
    sceneG->addChoice(choiceG4);
    
    // SCENE H - HIDDEN ROOM
    Choice* choiceH1 = new Choice();
    choiceH1->description = "Replace the diamond with the apple.";
    choiceH1->response = "You swap out the diamond with the apple as quickly as possible, careful not to throw off the weight and trigger the trap door. It seems to have worked, but just to be cautious, you hurry out of the hidden room and back into the foyer.";
    choiceH1->requiresItem = true;
    choiceH1->requiredItem = "apple";
    choiceH1->dropsLoot = true;
    choiceH1->loot = "diamond";
    choiceH1->changesScenes = true;
    choiceH1->nextScene = sceneA;
    sceneH->addChoice(choiceH1);
    
    Choice* choiceH2 = new Choice();
    choiceH2->description = "Take the diamond, despite what your instincts tell you.";
    choiceH2->response = "As soon as you remove the diamond from the pedestal, the bookshelf slams shut leaving you locked in the dark. There's no way out, there never was.";
    choiceH2->isExit = true;
    sceneH->addChoice(choiceH2);
    
    Choice* choiceH3 = new Choice();
    choiceH3->description = "Read the journal.";
    choiceH3->response = "The skeleton's bones crumble as you remove the journal from their grasp. You turn to the last journal entry, it's dated fifty years ago. \"What a fool I was thinking I could steal my brother's precious diamond. Even in death, he managed to get the last laugh. I fear this is where I'll die. I knew about the hidden room, but I didn't know the diamond was sitting on a weighted trap. The second I removed the diamond, I was locked in here. The irony, that I would kill my own brother and lock myself in the room only he knew exists.\"";
    choiceH3->dropsLoot = true;
    choiceH3->loot = "journal";
    sceneH->addChoice(choiceH3);
    
    Choice* choiceH4 = new Choice();
    choiceH4->description = "Return to den.";
    choiceH4->response = "You leave the hidden room, the door somehow knows to close itself behind you.";
    choiceH4->changesScenes = true;
    choiceH4->nextScene = sceneD;
    sceneH->addChoice(choiceH4);
}

Scene* SceneData::getFirstScene()
{
    if(firstScene != NULL)
    {
        return firstScene;
    }
    else
    {
        return new Scene();
    }
}
