#include "Container.hpp"
#include "Gui.hpp"
#include <algorithm>

Container::Container()
    : maxSize(28), actualSize(0)
{
}

Container::~Container()
{
    contents.clear();
}

void Container::printToConsole(TCODConsole &con)
{
    con.setDefaultBackground(TCODColor::white);
    int shortcut = 'a';
    int y = 1;
    if(actualSize != 0){
        for(ItemIter iter = contents.begin(); iter != contents.end(); iter++){
            Item *item = *iter;
            con.print(2, y, "(%c) %s", shortcut, item->name.c_str());
            y++;
            shortcut++;
        }
    }
}

void Container::add(Item *item)
{
    if(contents.size() < maxSize){
        contents.push_back(item);
        actualSize++;
    }
}

int Container::size() const
{
    return actualSize;
}

int Container::full() const
{
    return actualSize == maxSize;
}

Item* Container::at(int index)
{
    return contents.at(index);
}


void Container::remove(Item *item)
{
    contents.erase(std::remove(contents.begin(), contents.end(), item), contents.end());
    actualSize--;
}
