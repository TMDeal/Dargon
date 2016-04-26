#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <vector>
#include "Item.hpp"

typedef std::vector<Item*>::iterator ItemIter;

class Container{
    public:
        Container();
        ~Container();

        void printToConsole(TCODConsole &con);
        void add(Item *item);
        void remove(Item *item);
        int size() const;
        int full() const;
        Item* at(int index);
    private:
        std::vector<Item*> contents;
        unsigned int actualSize;
        unsigned int maxSize;
};

#endif /* CONTAINER_HPP */
