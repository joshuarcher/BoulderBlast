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
:GameWorld(assetDir)
{
    
}

int StudentWorld::init()
{
    // load level from asset directory
    Level lev(assetDirectory());
    
    Level::LoadResult result = lev.loadLevel("level00.dat");
        if (result == Level::load_fail_file_not_found)
            cerr << "Could not find level00.dat data file\n";
        else if (result == Level::load_fail_bad_format)
            cerr << "Your level was improperly formatted\n";
        else if (result == Level::load_success)
        {
            cerr << "Successfully loaded level\n";
            
            for(int i = 0; i < 15; i++)
            {
                for(int j = 0; j < 15; j++)
                {
                    Level::MazeEntry ge = lev.getContentsOf(i,j);
                    switch (ge)
                    {
                        case Level::player:
                            m_actorList.push_front(new Player(i,j,this));
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
    
    return GWSTATUS_PLAYER_DIED;
}

void StudentWorld::cleanUp()
{
    // for each actor
    // fucking delete it
    
}