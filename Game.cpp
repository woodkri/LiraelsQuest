/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This class runs the game. It includes a pointer to the character and
**      each of the Space classes, a bool for winning the game, and a time limit
**      variable. It also includes a constructor and destructor as well as functions
**      to play the game, and print a map.
************************************************************************************/

#include "Game.hpp"
#include "AbhorsenHouse.hpp"
#include "Belisaere.hpp"
#include "ClayrGlacier.hpp"
#include "Death.hpp"
#include "NorthernBorder.hpp"
#include "Wall.hpp"

Game::Game() {
    abhorsenHouse = new AbhorsenHouse;
    belisaere = new Belisaere;
    clayrGlacier = new ClayrGlacier;
    death = new Death;
    northernBorder = new NorthernBorder;
    wall = new Wall;
    lirael = new Lirael;
    won = false;
    timeLimit = 50;

    //Set up spacial relationships
    abhorsenHouse->setBelow(death);
    belisaere->setBelow(death);
    clayrGlacier->setBelow(death);
    northernBorder->setBelow(death);
    wall->setBelow(death);

    wall->setTop(abhorsenHouse);
    abhorsenHouse->setBottom(wall);
    abhorsenHouse->setTop(belisaere);
    belisaere->setBottom(abhorsenHouse);
    belisaere->setTop(clayrGlacier);
    clayrGlacier->setBottom(belisaere);
    clayrGlacier->setTop(northernBorder);
    northernBorder->setBottom(clayrGlacier);

    lirael->setLocation(abhorsenHouse);
}

/************************************************************************************
 * This function drives the game with the menu function from Space's derived classes.
 * Option 1 affects her pack or gives her more information, option 2 affects her
 * strength/health, and option 3 allows her to move between Spaces. Some derived
 * classes have additional options that are fully handled within the derived class.
************************************************************************************/
void Game::play() {
    std::cout << "Welcome to the Old Kingdom! You've arrived just in time. The kingdom is in danger of annihilation \n"
              "from Chlorr of the Mask, an ancient necromancer who has recently come out of hiding. Your mission is \n"
              "to help Lirael, the Abhorsen-in-waiting, acquire all the objects and knowledge she needs in order to \n"
              "defeat Chlorr and save the kingdom, before she dies or time runs out. Each choice she makes counts as \n"
              "one move. Let's begin!\n\n";
    while (lirael->getStrength() > 0 && !won && timeLimit > 0) {
        std::cout << "Lirael has " << timeLimit << " moves left.\n\n";
        int choice = lirael->getLocation()->menu();
        if (choice == 1) {
            if (lirael->getLocation() == death && lirael->getMirror()) {
                std::cout << "Lirael walks further into Death, conscious of the strong current in the river \n"
                          "beneath her feet, threatening to carry her on past the ninth precinct, never to \n"
                          "return to Life again. She walks carefully through the first precinct, almost to \n"
                          "the first gate, before pulling out her Dark Mirror. With one eye focused on the \n"
                          "mirror and the other looking into death, she whispers what she wants to see. The \n"
                          "mirror shows the sun falling and rising, rewinding time until at last she sees \n"
                          "her mother, on the eve of Lirael's tenth birthday. Arielle speaks her message to \n"
                          "her daughter: 'Lirael, child, you must do as I say and quick, else the entire kingdom \n"
                          "will be destroyed by the masked necromancer Chlorr. Return to Life and seek the Northern \n"
                          "border. Bring your bells with you, and your companion the Dog. Together you can banish \n"
                          "the evil that has befallen the Old Kingdom!'\n\n";
            }
            else if (lirael->getLocation() == death) {
                std::cout << "Lirael does not have a Dark Mirror yet.\n\n";
            }
            else {
                PackItems item = lirael->getLocation()->getObject();
                lirael->addItem(item);
            }
        }
        else if (choice == 2) {
            if (lirael->getLocation() == death) {
                if (lirael->getBells()) {
                    std::cout << "Lirael stumbles upon one of the Greater Dead as she explores the border between \n"
                              "Life and Death. She quickly feels for her bell bandolier, relieved that she has not \n"
                              "forgotten to bring it with her. She knows she will need to use her bells to defeat \n"
                              "the Dead creature, but which one?\n\n";
                    Bells bell = lirael->useBell();
                    if (bell == RANNA) {
                        std::cout << "Lirael rings Ranna the Sleeper and must resist the urge to fall asleep herself.\n"
                                  "Luckily, the Dead creature is not too strong and the sound of the bell puts it \n"
                                  "to sleep. The current grabs hold of the creature and carries it away. For now, \n"
                                  "Lirael is safe.\n\n";
                    }
                    else if (bell == MOSRAEL) {
                        std::cout << "Lirael rings Mosrael the Waker and the creature in front of her seems to grow \n"
                                  "even stronger. As it lunges towards her, she stumbles backwards and loses her \n"
                                  "footing. The river sees it chance and pulls her under, sweeping her further into \n"
                                  "Death, never to return to Life again.\n\n";
                        lirael->addStrength(-100);
                    }
                    else if (bell == KIBETH) {
                        std::cout << "Lirael rings Kibeth the Walker and tries her hardest to keep her own legs \n"
                                  "still. Luckily the Dead creature in front of her is not too strong, and Kibeth \n"
                                  "sends it walking further into death.\n\n";
                    }
                    else if (bell == DYRIM) {
                        std::cout << "Lirael rings Dyrim the Speaker, and a grating voice comes out of the Dead \n"
                                  "creature in front of her. Its twisted mouth tries to form words, but only manages \n"
                                  "to croak out a few syllables. Its newfound voice distracts it enough that it loses\n"
                                  "its footing and the river pulls it under.\n\n";
                    }
                    else if (bell == BELGAER) {
                        std::cout << "Lirael rings Belgaer the Thinker in the hopes that restoring some memories of \n"
                                  "its human life to the creature will keep it from attacking. As it grapples with \n"
                                  "the flood of memories from its previous life, Lirael is able to sneak away and \n"
                                  "continue her walk along the border.\n\n";
                    }
                    else if (bell == SARANETH) {
                        std::cout << "Lirael rings Saraneth the Binder, binding the creature's will to her own. She \n"
                                  "sends the creature walking further into Death until it is pulled under and swept \n"
                                  "away by the current.\n\n";
                    }
                    else if (bell == ASTARAEL) {
                        std::cout << "Lirael rings Astarael, the most dangerous of all the bells, and the one usually\n"
                                  "only used as a last resort. The creature and all others nearby are swept away \n"
                                  "further into Death, but so is Lirael. She will never again return to Life.\n\n";
                        lirael->addStrength(-100);
                    }
                }
                else {
                    std::cout << "Lirael realizes with a sickening feeling that she has entered death unprepared, \n"
                              "with no bell bandolier to fend off the dead creatures around her. The Dead see their \n"
                              "chance and strike before she is able to move back towards her body in Life.\n\n";
                    lirael->addStrength(-100);
                }
            }
            else if (lirael->getLocation() == northernBorder) {
                if (lirael->getBells()) {
                    std::cout << "Lirael can see Chlorr along the wall at the border. She approaches with her \n"
                              "bell bandolier at the ready. She knows she will need to use her bells to defeat \n"
                              "Chlorr, but which one?\n\n";
                    Bells bell = lirael->useBell();
                    if (bell == RANNA) {
                        std::cout << "Lirael rings Ranna and resists the urge to fall asleep, though her eyelids \n"
                                  "droop. Chlorr looks tired as well, but the bell isn't enough to put her to sleep; \n"
                                  "she's much too strong. Chlorr pulls out her own bell and rings it, sending \n"
                                  "Lirael and everyone nearby into Death, never to return again.\n\n";
                        lirael->addStrength(-100);
                        lirael->setLocation(death);
                    }
                    else if (bell == MOSRAEL) {
                        std::cout << "Lirael rings Mosrael the Waker, as her companions look on in horror. The \n"
                                  "bell's peal brings Dead spirits back to life all around them, and Lirael is \n"
                                  "sent far into death in return.\n\n";
                        lirael->addStrength(-100);
                        lirael->setLocation(death);
                    }
                    else if (bell == KIBETH) {
                        std::cout << "Lirael rings Kibeth the Walker, which sends Chlorr walking away from her body \n"
                                  "and into Death. Before hope has a chance to surface in Lirael's heart, she \n"
                                  "sees Chlorr come back into Life before her, bell at the ready. Kibeth is strong, \n"
                                  "but the necromancer is stronger. She rings her own bell, sending Lirael and \n"
                                  "everyone nearby into Death, never to return again.\n\n";
                        lirael->addStrength(-100);
                        lirael->setLocation(death);
                    }
                    else if (bell == DYRIM) {
                        std::cout << "Lirael rings Dyrim the Speaker. Chlorr has a confused look on her face \n"
                                  "as she tries to speak to Lirael and no words come out. The bell has silenced \n"
                                  "Lirael's enemy but it has not killed her, and as soon as Chlorr realizes what has \n"
                                  "happened, she pulls out her own bell to ring. Chlorr chooses her bells carefully, \n"
                                  "and sends Lirael and everyone nearby into Death, never to return again.\n\n";
                        lirael->addStrength(-100);
                        lirael->setLocation(death);
                    }
                    else if (bell == BELGAER) {
                        std::cout << "Lirael rings Belgaer the Thinker, which brings long forgotten memories to \n"
                                  "what's left of Chlorr's mind. She briefly remembers herself as a girl, trying \n"
                                  "to save her parents and do good in the world. This memory doesn't last long before\n"
                                  "she recalls the more tangible presence of bells calling to her from the bandolier \n"
                                  "across her chest. She picks a bell and rings it, sending Lirael and everyone \n"
                                  "nearby into Death, never to return again.\n\n";
                        lirael->addStrength(-100);
                        lirael->setLocation(death);
                    }
                    //Lirael needs dog to defeat Chlorr.
                    else if (bell == SARANETH && lirael->getDog()) {
                        std::cout << "As Lirael rings Saraneth the Binder, she feels Chlorr's will begin to bend \n"
                                  "towards her own. She's not under the bell's sway enough for Lirael to force her \n"
                                  "back into Death though, and Lirael begins to panic as she realizes this. She \n"
                                  "glances over her shoulder to the Disreputable Dog, who adds her howl to the \n"
                                  "peal of the bell. No ordinary howl, but one tinged with Free Magic. The \n"
                                  "combination of sounds forces Chlorr into Death and keeps her walking towards \n"
                                  "the ninth precinct, never to return to Life again.\n\n";
                        won = true;
                    }
                    else if (bell == SARANETH && !lirael->getDog()) {
                        std::cout << "As Lirael rings Saraneth the Binder, she feels Chlorr's will begin to bend \n"
                                  "towards her own. She's not under the bell's sway enough for Lirael to force her \n"
                                  "back into Death though, and Lirael begins to panic as she realizes this. Her \n"
                                  "panic turns into a heavy sense of loss as she realizes that this bell alone is \n"
                                  "not strong enough to defeat Chlorr. Chlorr realizes her own strength as well, \n"
                                  "and with a smug grin on her face, she turns her hand to her own bell bandolier. \n"
                                  "She picks a bell and rings it, sending Lirael and everone nearby into Death, \n"
                                  "never to return again.\n\n";
                        lirael->addStrength(-100);
                        lirael->setLocation(death);
                    }
                    else if (bell == ASTARAEL) {
                        std::cout << "Lirael rings Astarael, with a heavy heart. She knows this bell will send \n"
                                  "Chlorr back into Death for good, but she also knows that it will send her \n"
                                  "there too. Chlorr is defeated, but so is Lirael.\n\n";
                        lirael->addStrength(-100);
                        lirael->setLocation(death);
                    }
                }
                else {
                    std::cout << "Lirael approaches Chlorr without her bell bandolier at the ready. She tries to \n"
                              "fight off the masked necromancer but without her bells, she falls under the sway of \n"
                              "Chlorr's will. Chlorr sends Lirael into death, past each of the nine gates to \n"
                              "never return again.\n\n";
                    lirael->addStrength(-100);
                    lirael->setLocation(death);
                }
            }
            else if (lirael->getLocation() == wall) {
                if (lirael->getBells()) {
                    Bells bell = lirael->useBell();
                    if (bell == RANNA) {
                        std::cout << "Lirael rings Ranna the Sleeper and must resist the urge to fall asleep herself.\n"
                                "Luckily, the Dead creature is not too strong and the sound of the bell puts it \n"
                                "to sleep. Lirael is able to escape.\n\n";
                    }
                    else if (bell == MOSRAEL) {
                        std::cout << "Lirael rings Mosrael the Waker and the creature in front of her seems to grow \n"
                                "even stronger. It lunges towards her and she tries to fight back. She gets in a \n"
                                "few swings before escaping and running away, taking some damage in the struggle.\n\n";
                        lirael->addStrength(-25);
                    }
                    else if (bell == KIBETH) {
                        std::cout << "Lirael rings Kibeth the Walker and tries her hardest to keep her own legs \n"
                                "still. Luckily the Dead creature in front of her is not too strong, and Kibeth \n"
                                "sends it walking back to death.\n\n";
                    }
                    else if (bell == DYRIM) {
                        std::cout << "Lirael rings Dyrim the Speaker, and a grating voice comes out of the Dead \n"
                                "creature in front of her. Its twisted mouth tries to form words, but only manages \n"
                                "to croak out a few syllables. Its newfound voice distracts it enough that Lirael is\n"
                                "able to run away before it strikes.\n\n";
                    }
                    else if (bell == BELGAER) {
                        std::cout << "Lirael rings Belgaer the Thinker in the hopes that restoring some memories of \n"
                                "its human life to the creature will keep it from attacking. As it grapples with \n"
                                "the flood of memories from its previous life, Lirael is able to sneak away and \n"
                                "continue her walk along the wall.\n\n";
                    }
                    else if (bell == SARANETH) {
                        std::cout << "Lirael rings Saraneth the Binder, binding the creature's will to her own. She \n"
                                "sends the creature walking into Death until it is pulled under and swept away by \n"
                                "the current.\n\n";
                    }
                    else if (bell == ASTARAEL) {
                        std::cout << "Lirael rings Astarael, the most dangerous of all the bells, and the one usually\n"
                                "only used as a last resort. The creature and all others nearby are swept away \n"
                                "into Death, but so is Lirael. She will never again return to Life.\n\n";
                        lirael->addStrength(-100);
                    }
                }
                else {
                    std::cout << "Lirael realizes with a sickening feeling that she has approached the Wall\n"
                            "unprepared, with no bell bandolier. The Dead creature  sees its chance and strikes.\n\n";
                    lirael->addStrength(-100);
                }
            }
            else if (lirael->getLocation() == belisaere) {
                if (lirael->getMaxStrength() == 50) {
                    int newStrength = lirael->getLocation()->getHealthChange() + lirael->getMaxStrength();
                    lirael->setMaxStrength(newStrength);
                    lirael->addStrength(25);
                }
                else {
                    std::cout << "Lirael already has a golden hand, Sam cannot make her another one.\n\n";
                }
            }
            else {
                int newStrength = lirael->getLocation()->getHealthChange() + lirael->getStrength();
                lirael->addStrength(newStrength);
            }
        }
        else if (choice == 3) {
            if (lirael->getLocation() != death) {
                std::cout << "Where do you want to move? N for north, S for south, D for below into death: ";
                char userChoice;
                std::cin >> userChoice;
                if (userChoice == 'N' || userChoice == 'n') {
                    if (lirael->getLocation() == northernBorder) {
                        std::cout << "Lirael cannot move north from here.\n\n";
                    }
                    else {
                        Space* moveTo = lirael->getLocation()->getTop();
                        lirael->setLocation(moveTo);
                    }
                }
                else if (userChoice == 'S' || userChoice == 's') {
                    if (lirael->getLocation() == wall) {
                        std::cout << "Lirael cannot move south from here.\n\n";
                    }
                    else {
                        Space* moveTo = lirael->getLocation()->getBottom();
                        lirael->setLocation(moveTo);
                    }
                }
                else if (userChoice == 'D' || userChoice == 'd') {
                    Space* moveTo = lirael->getLocation()->getBelow();
                    //Save Lirael's current location so she can move back here.
                    Space* prev = lirael->getLocation();
                    lirael->setLocation(moveTo);
                    lirael->getLocation()->setAbove(prev);
                }
                else {
                    std::cout << "Invalid input.\n\n";
                }
            }
            else {
                std::cout << "Lirael will move back towards her body in Life.\n\n";
                Space* moveTo = lirael->getLocation()->getAbove();
                lirael->setLocation(moveTo);
            }
        }
        std::cout << "Enter 1 to continue.\n";
        int cont;
        std::cin >> cont;
        while (cont != 1) {
            std::cout << "Please try again.\n";
            std::cin >> cont;
        }
        print();
        timeLimit--;
    }
    if (won) {
        std::cout << "Congratulations, you have won the game and saved the Old Kingdom!\n";
    }
    else if (lirael->getStrength() <= 0) {
        std::cout << "Oh no, you've lost the game! Lirael died before she was able to save the Old Kingdom.\n";
    }
    else {
        std::cout << "Oh no, you've lost the game! Lirael ran out of time to save the Old Kingdom and Chlorr \n"
                  "has destroyed everything.\n";
    }
}

/************************************************************************************
 * This function prints a map of the Old Kingdom, everywhere but Death, which is
 * under the other spaces. It also gives the user an update on Lirael's health.
************************************************************************************/
void Game::print() {
    std::cout << "                    Old Kingdom Map                    \n";
    std::cout << "--------------------------------------------------------\n";
    std::cout << "|                   Northern Border                    |\n";
    std::cout << "|------------------------------------------------------|\n";
    std::cout << "||----------------------|                              |\n";
    std::cout << "||   Clayr's Glacier    |                              |\n";
    std::cout << "||----------------------|                              |\n";
    std::cout << "|                              |----------------------||\n";
    std::cout << "|                              |       Belisaere      ||\n";
    std::cout << "|                              |----------------------||\n";
    std::cout << "|                                                      |\n";
    std::cout << "|                                                      |\n";
    std::cout << "|                                                      |\n";
    std::cout << "|                                                      |\n";
    std::cout << "|                                                      |\n";
    std::cout << "|              |------------------------|              |\n";
    std::cout << "|              |    Abhorsen's House    |              |\n";
    std::cout << "|              |------------------------|              |\n";
    std::cout << "|------------------------------------------------------|\n";
    std::cout << "|                      the Wall                        |\n";
    std::cout << "--------------------------------------------------------\n\n";
    std::cout << "Death is underneath the Kingdom and cannot be found on a map.\n\n";
    std::cout << "Lirael is currently in " << lirael->getLocation()->getName() << ".\n\n";

    if (lirael->getStrength() > 0) {
        std::cout << "Lirael's health is " << lirael->getStrength() << std::endl;
    }
}

Game::~Game() {
    delete abhorsenHouse;
    delete belisaere;
    delete clayrGlacier;
    delete death;
    delete northernBorder;
    delete wall;
    delete lirael;
}