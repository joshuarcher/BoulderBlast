#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp

/////////////////////////////////////////
/////             ACTOR             /////
/////////////////////////////////////////


Actor::Actor(StudentWorld* world, int startX, int startY, int imageID, unsigned int hitPoints, Direction startDir)
: GraphObject(imageID, startX, startY, startDir), m_alive(true), m_sWorld(world), m_hp(hitPoints)
{
    setVisible(true);
}

bool Actor::isAlive() const
{
    return m_alive;
}

void Actor::setDead()
{
    m_alive = false;
    setVisible(false);
}

void Actor::decHitPoints(unsigned int amt)
{
    if (m_hp == 0 || amt == 0) {
        return;
    }
    m_hp--;
    decHitPoints(amt - 1);
}

StudentWorld* Actor::getWorld() const
{
    return m_sWorld;
}

bool Actor::allowsAgentColocation() const
{
    return false;
}

bool Actor::allowsBoulder() const
{
    return false;
}

bool Actor::countsInFactoryCensus() const
{
    return false;
}

bool Actor::stopsBullet() const
{
    return true;
}

bool Actor::isDamageable() const
{
    return true;
}

void Actor::damage(unsigned int damageAmt)
{
    decHitPoints(damageAmt);
}

bool Actor::isSwallowable() const
{
    return false;
}

bool Actor::isStealable() const
{
    return false;
}

unsigned int Actor::getHitPoints() const
{
    return m_hp;
}

void Actor::getHitPoints(int amt)
{
    m_hp = amt;
}

bool Actor::tryToBeKilled(unsigned int damageAmt)
{
    damage(damageAmt);
    if (m_hp == 0) {
        return true;
    }
    return false;
}


/////////////////////////////////////////
/////             AGENT             /////
/////////////////////////////////////////

Agent::Agent(StudentWorld* world, int startX, int startY, int imageID, unsigned int hitPoints, Direction startDir)
: Actor(world, startX, startY, imageID, hitPoints, startDir)
{
    
}

bool Agent::moveIfPossible()
{
    return true;
}

bool Agent::canPushBoulders() const
{
    return false;
}

bool Agent::needsClearShot() const
{
    return false;
}

int Agent::shootingSound() const
{
    return 0;
}

bool Agent::canMove(int x, int y) const
{
    return false;
}






/////////////////////////////////////////
/////             PLAYER            /////
/////////////////////////////////////////

Player::Player(StudentWorld* world, int startX, int startY)
: Agent(world, startX, startY, IID_PLAYER, 20, right), m_ammo(20)
{
    
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
                getWorld()->playSound(shootingSound());
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

bool Player::isDamageable() const
{
    return true;
}

void Player::damage(unsigned int damageAmt)
{
    decHitPoints(2);
    
    if (getHitPoints() == 0) {
        getWorld()->playSound(SOUND_PLAYER_DIE);
        setDead();
    }
    
    getWorld()->playSound(SOUND_PLAYER_IMPACT);
    
}

bool Player::canPushBoulders() const
{
    return true;
}

bool Player::needsClearShot() const
{
    return false;
}

int Player::shootingSound() const
{
    return SOUND_PLAYER_FIRE;
}

unsigned int Player::getHealthPct() const
{
    double health = getHitPoints();
    
    health = (health/20) * 100;
    return health;
}

unsigned int Player::getAmmo() const
{
    return m_ammo;
}

void Player::restoreHealth()
{
    getHitPoints(20);
}

void Player::increaseAmmo()
{
    m_ammo += 20;
}

/////////////////////////////////////////
/////             WALL              /////
/////////////////////////////////////////

Wall::Wall(StudentWorld* world, int startX, int startY)
: Actor(world, startX, startY, IID_WALL, 0, none)
{
    
}

void Wall::doSomething()
{
    return;
}

bool Wall::stopsBullet() const
{
    return true;
}






