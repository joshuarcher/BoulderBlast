#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameConstants.h"
#include <iostream>
class StudentWorld;

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class Actor : public GraphObject
{
public:
    Actor(StudentWorld* world, int startX, int startY, int imageID, unsigned int hitPoints, Direction startDir);
    
    // Action to perform each tick
    virtual void doSomething() = 0;
    
    // Is this actor alive?
    bool isAlive() const;
    
    // Mark this actor as dead
    void setDead();
    
    // Reduce this actor's hit points
    void decHitPoints(unsigned int amt);
    
    // Get this actor's world
    StudentWorld* getWorld() const;
    
    //
    // Can an agent occupy the same square as this actor?
    virtual bool allowsAgentColocation() const;
    
    // Can a boulder occupy the same square as this actor?
    virtual bool allowsBoulder() const;
    
    // Does this actor count when a factory counts items near it?
    virtual bool countsInFactoryCensus() const;
    
    // Does this actor stop bullets from continuing?
    virtual bool stopsBullet() const;
    
    // Can this actor be damaged by bullets?
    virtual bool isDamageable() const;
    
    // Cause this Actor to sustain damageAmt hit points of damage.
    virtual void damage(unsigned int damageAmt);
    
    // Can this actor be pushed by a to location x,y?
    //virtual bool bePushedBy(Agent* a, int x, int y);
    
    // Can this actor be swallowed by a hole?
    virtual bool isSwallowable() const;
    
    // Can this actor be picked up by a KleptoBot?
    virtual bool isStealable() const;
    
    // How many hit points does this actor have left?
    virtual unsigned int getHitPoints() const;
    
    // Set this actor's hit points to amt.
    virtual void getHitPoints(int amt);
    
    // Make the actor sustain damage.  Return true if this kills the
    // actor, and false otherwise.
    virtual bool tryToBeKilled(unsigned int damageAmt);
    
private:
    bool m_alive;
    StudentWorld* m_sWorld;
    unsigned int m_hp;
};

/////////////////////////////////////////
/////             AGENT             /////
/////////////////////////////////////////

class Agent : public Actor
{
public:
    Agent(StudentWorld* world, int startX, int startY, int imageID, unsigned int hitPoints, Direction startDir);
    
    // Move to the adjacent square in the direction the agent is facing
    // if it is not blocked, and return true.  Return false if the agent
    // can't move.
    bool moveIfPossible();
    
    // Return true if this agent can push boulders (which means it's the
    // player).
    virtual bool canPushBoulders() const;
    
    // Return true if this agent doesn't shoot unless there's an unobstructed
    // path to the player.
    virtual bool needsClearShot() const;
    
    // Return the sound effect ID for a shot from this agent.
    // player).
    virtual int shootingSound() const;
    
    // Return true if space specified is unobstructed
    virtual bool canMove(int x, int y) const;
};

/////////////////////////////////////////
/////             PLAYER            /////
/////////////////////////////////////////

class Player : public Agent
{
public:
    Player(StudentWorld* world, int startX, int startY);
    virtual void doSomething();
    // mine
    virtual bool canMove(int x, int y) const;
    
    virtual bool isDamageable() const;
    virtual void damage(unsigned int damageAmt);
    virtual bool canPushBoulders() const;
    virtual bool needsClearShot() const;
    virtual int shootingSound() const;
    
    
    // Get player's health percentage
    unsigned int getHealthPct() const;
    
    // Get player's amount of ammunition
    unsigned int getAmmo() const;
    
    // Restore player's health to the full amount.
    void restoreHealth();
    
    // Increase player's amount of ammunition.
    void increaseAmmo();
private:
    int m_ammo;
};


class Wall : public Actor
{
public:
    Wall(StudentWorld* world, int startX, int startY);
    virtual void doSomething();
    virtual bool stopsBullet() const;
};

//class Wall : public Actor
//{
//public:
//    Wall(int startX, int startY, StudentWorld* sWorld);
//    
//    virtual ~Wall()
//    {
//        getGraphObjects().erase(this);
//    }
//    
//    void doSomething()
//    {
//    }
//    
//    virtual bool canMove(int x, int y) const
//    {
//        return false;
//    }
//    
//private:
//};



#endif // ACTOR_H_
