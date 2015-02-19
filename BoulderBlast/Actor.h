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
    Actor(int imageID, int startX, int startY, Direction dir = none, StudentWorld* sWorld = nullptr);
    
    virtual ~Actor()
    {
        getGraphObjects().erase(this);
    }
    
    virtual void doSomething() = 0;
    bool isAlive();
    
    virtual bool canMove(int x, int y) const = 0;
    
    virtual StudentWorld* getWorld() const;
    virtual void setDead();
    
    // GETTERS
    
    int getHp();
    
    // SETTERS
    
    void setHp(int hp);
    
    
    
private:
    int m_hp;
    bool m_alive;
    StudentWorld* m_sWorld;
    
};

class Player : public Actor
{
public:
    Player(int startX, int startY, StudentWorld* sWorld);
    void doSomething();
    
    virtual bool canMove(int x, int y) const;
    
    void setAmmo(int am);
    int getAmmo();
    
private:
    int m_ammo;
    
};

class Wall : public Actor
{
public:
    Wall(int startX, int startY, StudentWorld* sWorld);
    
    virtual ~Wall()
    {
        getGraphObjects().erase(this);
    }
    
    void doSomething()
    {
    }
    
    virtual bool canMove(int x, int y) const
    {
        return false;
    }
    
private:
};



#endif // ACTOR_H_
