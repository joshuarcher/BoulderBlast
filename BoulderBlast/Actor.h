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
    
    virtual void doSomething() = 0;
    
    // GETTERS
    int getAmmo();
    int getHp();
    
    // SETTERS
    void setAmmo(int am);
    void setHp(int hp);
    
private:
    int m_ammo;
    int m_hp;
    StudentWorld* m_sWorld;
    
};

class Player : public Actor
{
public:
    Player(int startX, int startY, StudentWorld* sWorld);
    void doSomething()
    {
        std::cerr << "PLAYER DOING SOMETHING\n";
    }
    
private:
    
    
};

class Wall : public Actor
{
public:
    Wall(int startX, int startY, StudentWorld* sWorld);
    void doSomething()
    {
        std::cerr << "WALL DOING SOMETHING\n";
    }
private:
};



#endif // ACTOR_H_
