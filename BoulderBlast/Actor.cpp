#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp

/////////////////////////////////////////
/////             ACTOR             /////
/////////////////////////////////////////

Actor::Actor(int imageID, int startX, int startY, Direction dir, StudentWorld* sWorld)
: GraphObject(imageID, startX, startY, dir), m_sWorld(sWorld), m_hp(0), m_alive(true)
{
    setVisible(true);
    
}

int Actor::getHp()
{
    return m_hp;
}

void Actor::setHp(int hp)
{
    m_hp = hp;
}

bool Actor::isAlive()
{
    return m_alive;
}

StudentWorld* Actor::getWorld() const
{
    return m_sWorld;
}

void Actor::setDead()
{
    m_alive = false;
}



/////////////////////////////////////////
/////             PLAYER            /////
/////////////////////////////////////////

Player::Player(int startX, int startY, StudentWorld* sWorld)
:Actor(IID_PLAYER, startX, startY, right, sWorld), m_ammo(20)
{
    setHp(20);
}

int Player::getAmmo()
{
    return m_ammo;
}

void Player::setAmmo(int am)
{
    m_ammo = am;
}

void Player::doSomething()
{
    if (!isAlive())
        return;
    
    int keyStroke;
    if (getWorld()->getKey(keyStroke))
    {
        switch (keyStroke)
        {
            case KEY_PRESS_ESCAPE:
                setDead();
                break;
            case KEY_PRESS_SPACE:
                getWorld()->playSound(SOUND_PLAYER_FIRE);
                break;
            case KEY_PRESS_UP:
                setDirection(up);
                if (canMove(getX(), getY() + 1))
                    moveTo(getX(), getY() + 1);
                break;
            case KEY_PRESS_DOWN:
                setDirection(down);
                if (canMove(getX(), getY() - 1))
                    moveTo(getX(), getY() - 1);
                break;
            case KEY_PRESS_LEFT:
                setDirection(left);
                if (canMove(getX() - 1, getY()))
                    moveTo(getX() - 1, getY());
                break;
            case KEY_PRESS_RIGHT:
                setDirection(right);
                if (canMove(getX() + 1, getY()))
                    moveTo(getX() + 1, getY());
                break;
            default:
                break;
        }
    }
    
}

bool Player::canMove(int x, int y) const
{
    std::list<Actor*> actorList = getWorld()->getActors();
    
    
    for (std::list<Actor*>::iterator p = actorList.begin(); p != actorList.end(); ++p) {
        if ((*p)->getX() == x && (*p)->getY() == y) {
            return false;
        }
    }
    
    return true;
}





/////////////////////////////////////////
/////             WALL              /////
/////////////////////////////////////////

Wall::Wall(int startX, int startY, StudentWorld* sWorld)
:Actor(IID_WALL, startX, startY, none, sWorld)
{
    setHp(0);
}



