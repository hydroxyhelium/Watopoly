#include "rez.h"
#include "player.h"
#include "mapclass.h"
#include "errorclass.h"

//  Rez(Player *owner, std::string name, int position, bool mortaged);
//     void addOwner(Player *p);
//     bool isNewOwnable() override;
//     void applyRule(Player *p) override;
//     Player *getOwner() override;  // this is to get the owner of the property
//     void setMortgaged(Player *p); // this is to set the mortgaged status of the property
//     void unMortgaged(Player *p);  // // this is to unmortage the property

Rez::Rez(Player *owner, std::string name, int position, bool mortaged) : owner{owner}, mortgaged{mortgaged}, cost{200}, name{name}, position{position}
{
}

void Rez::addOwner(Player *p)
{
    if (p->getAssets() < cost)
    {
        throw IllegalMove();
    }
    else
    {
        owner = p;
    }
}

bool Rez::isNewOwnable()
{
    if (owner)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Rez::applyRule(Player *p)
{
    if (owner == p || mortgaged)
    {
        return;
    }
    else
    {
        int count = 0;

        for (int i = 0; i < otherRez.size(); i++)
        {
            if (otherRez[i]->getOwner() == p)
            {
                count++;
            }
        }
        int rent;

        if (count + 1 == 1)
        {
            rent = 25;
        }
        else if (count + 1 == 2)
        {
            rent = 50;
        }
        else if (count + 1 == 3)
        {
            rent = 100;
        }
        else
        {
            rent = 200;
        }

        if (rent > p->getAssets())
        {
            throw NoRent(rent);
        }
        else
        {
            p->setAssets(p->getAssets() - rent);
            owner->setAssets(owner->getAssets() + rent);
        }
    }
}

Player *Rez::getOwner()
{
    return owner;
}

void Rez::setMortgaged(Player *p)
{
    if (owner != p || mortgaged)
    {
        throw NotOwner();
    }
    else
    {
        p->setAssets(p->getAssets() + (cost / 2));
        mortgaged = true;
    }
}

void Rez::unMortgaged(Player *p)
{

    if (owner != p)
    {
        throw NotOwner();
    }
    else
    {
        if (!mortgaged)
        {
            throw IllegalMove();
        }
        else
        {
            if (p->getAssets() < (0.6) * cost)
            {
                throw IllegalMove();
            }
            p->setAssets(p->getAssets() - (cost) * (0.6));
            mortgaged = false;
        }
    }
}

void Rez::setOtherRez(std::vector<Property *> otherRez)
{
    this->otherRez = otherRez;
}

std::string Rez::getName()
{
    return name;
}

int Rez::getPrice()
{
    return cost;
}

bool Rez::isMortgaged()
{
    return mortgaged;
}