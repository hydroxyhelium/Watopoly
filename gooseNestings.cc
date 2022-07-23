#include "gooseNestings.h"
#include <iostream>
#include "errorclass.h"

void gooseNestings :: addOwner(Player *p){
    // This Should be empty
    throw IllegalMove();
}

bool gooseNestings :: isNewOwnable(){
    return false;
}

Player * gooseNestings ::getOwner() {
    return nullptr;
}

void gooseNestings :: applyRule(Player *p) {
    std::cout << "Goose Attack!" << std::endl;
}


