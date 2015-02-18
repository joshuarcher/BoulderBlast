#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp

/////////////////////////////////////////
/////             ACTOR             /////
/////////////////////////////////////////

Actor::Actor(int imageID, int startX, int startY, Direction dir, StudentWorld* sWorld)
: GraphObject(imageID, startX, startX, dir), m_sWorld(sWorld), m_ammo(0), m_hp(0)
{
    setVisible(true);
    
}

int Actor::getAmmo()
{
    return m_ammo;
}

int Actor::getHp()
{
    return m_hp;
}

void Actor::setAmmo(int am)
{
    m_ammo = am;
}

void Actor::setHp(int hp)
{
    m_hp = hp;
}



/////////////////////////////////////////
/////             PLAYER            /////
/////////////////////////////////////////

Player::Player(int startX, int startY, StudentWorld* sWorld)
:Actor(IID_PLAYER, startX, startY, right, sWorld)
{
    setHp(20);
    setAmmo(20);
}






/////////////////////////////////////////
/////             WALL              /////
/////////////////////////////////////////

Wall::Wall(int startX, int startY, StudentWorld* sWorld)
:Actor(IID_WALL, startX, startY, none, sWorld)
{
    setHp(0);
}



