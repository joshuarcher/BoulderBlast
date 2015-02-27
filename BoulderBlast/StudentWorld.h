#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include <string>
#include <list>

class Actor;
class Agent;
class Player;

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetDir);
    virtual ~StudentWorld(){cleanUp();};
    
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    
    std::list<Actor*> getActors() const;
    
    // Can agent move to x,y?  (dx and dy indicate the direction of motion)
    bool canAgentMoveTo(Agent* agent, int x, int y, int dx, int dy) const;
    
    // Can a boulder move to x,y?
    bool canBoulderMoveTo(int x, int y) const;
    
    // Is the player on the same square as an Actor?
    bool isPlayerColocatedWith(int x, int y) const;
    
    // Try to cause damage to something at a's location.  (a is only ever
    // going to be a bullet.)  Return true if something stops a --
    // something at this location prevents a bullet from continuing.
    bool damageSomething(Actor* a, unsigned int damageAmt);
    
    // Swallow any swallowable object at a's location.  (a is only ever
    // going to be a hole.)
    bool swallowSwallowable(Actor* a);
    
    // If a bullet were at x,y moving in direction dx,dy, could it hit the
    // player without encountering any obstructions?
    bool existsClearShotToPlayer(int x, int y, int dx, int dy) const;
    
    // If a factory is at x,y, how many items of the type that should be
    // counted are in the rectangle bounded by x-distance,y-distance and
    // x+distance,y+distance?  Set count to that number and return true,
    // unless an item is on the factory itself, in which case return false
    // and don't care about count.  (The items counted are only ever going
    // KleptoBots.)
    bool doFactoryCensus(int x, int y, int distance, int& count) const;
    
    // If an item a that can be stolen is at x,y, return a pointer to it;
    // otherwise, return a null pointer.  (Stealable items are only ever
    // going be goodies.)
    Actor* getColocatedStealable(int x, int y) const;
    
    // Restore player's health to the full amount.
    void restorePlayerHealth();
    
    // Increase the amount of ammunition the player has
    void increaseAmmo();
    
    // Are there any jewels left on this level?
    bool anyJewels() const;
    
    // Reduce the count of jewels on this level by 1.
    bool decJewels() const;
    
    // Indicate that the player has finished the level.
    void setLevelFinished();
    
    // Add an actor to the world
    void addActor(Actor* a);
    
private:
    std::list<Actor*> m_actorList;
    Actor* m_player;
};

inline
std::list<Actor*> StudentWorld::getActors() const
{
    return m_actorList;
}





//class Actor;
//
//// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
//
//class StudentWorld : public GameWorld
//{
//public:
//    StudentWorld(std::string assetDir);
//    
//    ~StudentWorld(){cleanUp();};
//    
//    virtual int init();
//    virtual int move();
//    virtual void cleanUp();
//    
//    std::list<Actor*> getActors() const;
//    
//
////	virtual int init()
////	{
////		return GWSTATUS_CONTINUE_GAME;
////	}
////
////	virtual int move()
////	{
////		  // This code is here merely to allow the game to build, run, and terminate after hitting enter a few times 
////		decLives();
////		return GWSTATUS_PLAYER_DIED;
////	}
////
////	virtual void cleanUp()
////	{
////	}
//
//private:
//    std::list<Actor*> m_actorList;
//    Actor* m_player;
//    
//};
//
//inline
//std::list<Actor*> StudentWorld::getActors() const
//{
//    return m_actorList;
//}

#endif // STUDENTWORLD_H_
