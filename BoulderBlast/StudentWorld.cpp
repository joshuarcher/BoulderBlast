#include "StudentWorld.h"
#include "Level.h"
#include "Actor.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp

StudentWorld::StudentWorld(std::string assetDir)
:GameWorld(assetDir), m_player(nullptr)
{
    
}

int StudentWorld::init()
{
    // load level from asset directory
    Level lev(assetDirectory());
    
    Level::LoadResult result = lev.loadLevel("level00.dat");
        if (result == Level::load_fail_file_not_found)
        {
            cerr << "Could not find level00.dat data file\n";
            return GWSTATUS_LEVEL_ERROR;
        }
        else if (result == Level::load_fail_bad_format)
        {
            cerr << "Your level was improperly formatted\n";
            return GWSTATUS_LEVEL_ERROR;
        }
    
        else if (result == Level::load_success)
        {
            cerr << "Successfully loaded level\n";
            
            for(int i = 0; i < VIEW_WIDTH; i++)
            {
                for(int j = 0; j < VIEW_HEIGHT; j++)
                {
                    
                    Level::MazeEntry ge = lev.getContentsOf(i,j);
                    switch (ge)
                    
                    {
                        case Level::player:
                            m_player = new Player(i,j,this);
                            break;
                        case Level::wall:
                            m_actorList.push_front(new Wall(i,j,this));
                            // m_actorList.push_front(new Wall(i,j,this));
                            break;
                        case Level::empty:
                            cerr << "Empty space\n";
                            break;
                    }
                }
            }
        }
    
    
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // for each actor
    // do something
    decLives();
    m_player->doSomething();
    for (list<Actor*>::iterator p = m_actorList.begin(); p != m_actorList.end(); ++p) {
        if ((*p)->isVisible()) {
            (*p)->doSomething();
        }
    }
    
    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
    // for each actor
    // fucking delete it
    delete m_player;
    
    for (list<Actor*>::iterator p = m_actorList.begin(); p!= m_actorList.end(); ++p) {
        delete *p;
        p = m_actorList.erase(p);
    }
    
    
    
}