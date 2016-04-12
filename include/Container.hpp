#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <vector>
#include "Actor.hpp"

typedef std::vector<Actor*>::iterator ActorIter;

class Container{
    public:
        Container(int size);
        ~Container();

        void add(Actor *actor);
        void remove(Actor *actor);
    private:
        std::vector<Actor*> actors;
        int size;
};

#endif /* CONTAINER_HPP */
