#ifndef BSPCALLBACK_HPP
#define BSPCALLBACK_HPP

#include "libtcod/libtcod.hpp"
#include "Game.hpp"
#include "Map.hpp"

class BspCallBack : public ITCODBspCallback{
    public:
        BspCallBack(Map &levelMap) :levelMap(levelMap), rng(TCODRandom::getInstance()), roomNum(0){}
        bool visitNode(TCODBsp *node, void *userData){
            if(node->isLeaf()){
                int x, y, w, h;
                w = rng->getInt(ROOM_MIN_SIZE, node->w-2);
                h = rng->getInt(ROOM_MIN_SIZE, node->h-2);
                x = rng->getInt(node->x+1, node->x+node->w-w-1);
                y = rng->getInt(node->y+1, node->y+node->h-h-1);
                createRoom(roomNum == 0, x, y, x+w-1, y+h-1);

                if(roomNum != 0){
                    levelMap.dig(lastx, lasty, x+w/2, lasty);
                    levelMap.dig(x+w/2, lasty, x+w/2, y+h/2);
                }
                lastx = x+w/2;
                lasty = y+h/2;
                roomNum++;
            }
            return true;
        }

        void placeActor(int x, int y, bool playerStart=false){
            if(playerStart){
                game.player->place(x, y);
            }
            int roomMonsters = rng->getInt(0, MAX_ROOM_MONSTERS);
            if(roomMonsters > 0){
                if(levelMap.canPlace(x, y)){
                    game.monsters.push_back(new Monster(x, y));
                }
                roomMonsters--;
            }
        }

        void createRoom(bool first, int x1, int y1, int x2, int y2)
        {
            levelMap.dig(x1, y1, x2, y2);
            int x;
            int y;
            if(first){
                x = (x1 + x2) / 2;
                y = (y1 + y2) / 2;
                placeActor(x, y, first);
            }
            else{
                x = rng->getInt(x1, x2);
                y = rng->getInt(y1, y2);
                placeActor(x, y);
            }
        }

    private:
        Map &levelMap;
        TCODRandom *rng;
        int roomNum;
        int lastx, lasty;
};

#endif /* BSPCALLBACK_HPP */
