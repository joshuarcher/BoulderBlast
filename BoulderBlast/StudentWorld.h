#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include <string>
#include <list>

class Actor;

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetDir);
    
    ~StudentWorld(){cleanUp();};
    
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    

//	virtual int init()
//	{
//		return GWSTATUS_CONTINUE_GAME;
//	}
//
//	virtual int move()
//	{
//		  // This code is here merely to allow the game to build, run, and terminate after hitting enter a few times 
//		decLives();
//		return GWSTATUS_PLAYER_DIED;
//	}
//
//	virtual void cleanUp()
//	{
//	}

private:
    std::list<Actor*> m_actorList;
};

#endif // STUDENTWORLD_H_
