#ifndef PATHCALLBACK_HPP
#define PATHCALLBACK_HPP

#include "libtcod/libtcod.hpp"
#include "Enums.hpp"
#include "Game.hpp"

class PathCallBack : public ITCODPathCallback{
    public:
        float getWalkCost( int xFrom, int yFrom, int xTo, int yTo, void *userData ) const{
            Tile_Flag flag = game.tiles[xTo][yTo].flag;
            float cost = 0;
            switch(flag){
                case SAFE:
                    cost++;
                    break;
                case HAS_PLAYER:
                case HAS_MONSTER:
                case HAS_ITEM:
                    break;
            }
            return cost;
        }
};

#endif /* PATHCALLBACK_HPP */
