#include "DcTims.h"
#include "applyRuleTims.h"

void DcTims :: addOwner(Player *p){
    // This Should be empty
}

bool DcTims :: isNewOwnable(){
    return false;
}

Player * DcTims :: getOwner() {
    return nullptr;
}

void DcTims :: applyRule(Player *p) {
    takingInput(p);
}
