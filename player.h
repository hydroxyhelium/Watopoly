#ifndef PLAYER
#define PLAYER
#include <vector>
#include <string>
class Property;

class Player
{
    std::string name;
    std::vector<Property *> owned;
    int assets;
    bool bankruptcy;
    // TutionPaid was not present in the UML
    bool tutionPaid;
    int position;
    int previousPosition; // this has been added keeping in mind that previousPosition must be know for graphic purposes
    int RUTR;             // number of roll up the rim cards used.
    bool atTims;
    int turnsAtTims; // number of turns at DC tims when atTims is true.
    int prevRoll;    // indicates the last roll of the dice.

public:
    Player(std::string name, int assets, int position);
    std::vector<Property *> getProp();
    void removeProp(Property *p);
    void addProp(Property *p);
    void addAssets(int amount); // note initially int amount was not given but to my best understanding it should accept a parameter of type int.
    // Get Assets was not present in UML
    int getAssets();
    void setAssets(int assests);
    void setBankruptcy(bool B);
    int getRUTR();
    void setRUTR(int num);
    bool getAtTims();
    void setAtTims(bool value);
    void transfer(Player *p);
    void setPosition(int position);
    int getPosition();
    int getPreviousPosition();
    void setPreviousPosition(int position);
    std::string getName();
    bool getBankruptcy();
    bool getTutionPaid();
    void setTutionPaid(bool tutionPaid);
    void setTurnsAtTims(int turns);
    int getTurnsAtTims();
    // forgot to store previous roll sum, so storing that rn.
    int getPrevRoll();
    void setPrevRoll(int roll);
    
};

#endif // PLAYER

/*
class Player {
    string name;
    std::vector<Property*> owned;
    bool tutionPaid;
    bool bankrupt;
    int Assets;
    int position;
    int timCount;
    int prevRoll;
    bool statusTim;
    public:
        int getAssets();
        void addIncrement(Card& Property);
        std::vector<Card> getProperty();
        int getIncrement(Card& Property);
        void removeProperty(Card& Property);
        void roll();
        int getPrev() const;
        int getTimCount();
        void setTimCount(int count);
};
*/
