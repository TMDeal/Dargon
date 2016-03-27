#ifndef BSPCALLBACK_HPP
#define BSPCALLBACK_HPP

#include "libtcod/libtcod.hpp"
#include "Game.hpp"
#include "Map.hpp"

class BspCallBack : public ITCODBspCallback{
    public:
        BspCallBack(Map &map) :map(map), roomNum(0){}
        bool visitNode(TCODBsp *node, void *userData){
            if(node->isLeaf()){
                int x, y, w, h;
                TCODRandom *rng = TCODRandom::getInstance();
                w = rng->getInt(ROOM_MIN_SIZE, node->w-2);
                h = rng->getInt(ROOM_MIN_SIZE, node->h-2);
                x = rng->getInt(node->x+1, node->x+node->w-w-1);
                y = rng->getInt(node->y+1, node->y+node->h-h-1);
                game.createRoom(roomNum == 0, x, y, x+w-1, y+h-1);

                if(roomNum != 0){
                    map.dig(lastx, lasty, x+w/2, lasty);
                    map.dig(x+w/2, lasty, x+w/2, y+h/2);
                }
                lastx = x+w/2;
                lasty = y+h/2;
                roomNum++;
            }
            return true;
        }

    private:
        Map &map;
        int roomNum;
        int lastx, lasty;
};

#endif /* BSPCALLBACK_HPP */
