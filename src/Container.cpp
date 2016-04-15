#include "Container.hpp"
#include <algorithm>

Container::Container(int size)
    :size(size)
{
}

Container::~Container()
{
}

void Container::add(Actor *actor)
{
    if(actors.size() < size){
        actors.push_back(actor);
    }
}

void Container::remove(Actor *actor)
{
    actors.erase(std::remove(actors.begin(), actors.end(), actor), actors.end());
}
