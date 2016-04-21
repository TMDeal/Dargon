#include "Gui.hpp"
#include "Game.hpp"
#include "templates_out/projectPaths.h"
#include "algorithm"

Gui::Gui(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight)
{
    TCODConsole::setCustomFont((getResPath() + "terminal.png").c_str());
    TCODConsole::initRoot(screenWidth, screenHeight, "Dargon", false);
    this->con = new TCODConsole(screenWidth, PANEL_HEIGHT);

    logs.push_back(new Message("WELCOME", TCODColor::lightGrey));
}

Gui::~Gui()
{
}

void Gui::addLog(const TCODColor &col, std::string fmt, ...)
{
    va_list args;
    char buffer[256];
    va_start(args, fmt);
    vsprintf(buffer, fmt.c_str(), args);
    va_end(args);

    char *lineBegin = buffer;
    char *lineEnd;

    do{
        if(logs.size() == MSG_HEIGHT){
            Message *tmp = logs.at(0);
            logs.erase(std::remove(logs.begin(), logs.end(), tmp), logs.end());
            delete tmp;
        }

        lineEnd = strchr(lineBegin, '\n');
        if(lineEnd){
            *lineEnd = '\0';
        }

        logs.push_back(new Message(string(lineBegin), col));
    }while(lineEnd);
}

void Gui::renderBar(int x, int y, std::string name, float value, float maxValue, 
        const TCODColor &barColor, const TCODColor &backColor)
{
    con->setDefaultBackground(backColor);
    con->rect(x, y, BAR_WIDTH, 1, false, TCOD_BKGND_SET);

    int barFillWidth = static_cast<int>(value / maxValue * BAR_WIDTH);
    if(barFillWidth > 0){
        con->setDefaultBackground(barColor);
        con->rect(x, y, barFillWidth, 1, false, TCOD_BKGND_SET);
    }

    con->setDefaultForeground(TCODColor::white);
    con->printEx(x+BAR_WIDTH/2, y, TCOD_BKGND_NONE, TCOD_CENTER,
            "%s: %g/%g", name.c_str(), value, maxValue);
}

void Gui::renderMouseLook()
{
    if(!game.levelMap->isInFov(game.mouse.cx, game.mouse.cy)){
        return;
    }
    std::string buffer;
    switch(game.tiles[game.mouse.cx][game.mouse.cy].flag){
        case HAS_MONSTER:
            buffer = game.find<Monster>(game.monsters, game.mouse.cx, game.mouse.cy).getInfo();
            break;
        case HAS_PLAYER:
            buffer = game.player->getInfo();
        case HAS_ITEM:
            break;
        case SAFE:
            break;
    }
    con->setDefaultBackground(TCODColor::lightGrey);
    con->print(1, 0, buffer.c_str());
}

void Gui::renderLog()
{
    int y = 1;
    float colorFade = 0.4f;
    for(logIter iter = logs.begin(); iter != logs.end(); iter++){
        Message *message = *iter;
        con->setDefaultForeground(message->col * colorFade);
        con->print(MSG_X, y, message->text.c_str());
        y++;
        if(colorFade < 1.0f){
            colorFade +=0.3f;
        }
    }
}

void Gui::render()
{
    TCODConsole::root->setDefaultBackground(TCODColor::black);
    con->setDefaultBackground(TCODColor::black);
    TCODConsole::root->clear();
    con->clear();
    renderLog();
    game.player->displayStats();
    renderMouseLook();
    TCODConsole::blit(con, 0, 0, screenWidth, PANEL_HEIGHT,
            TCODConsole::root, 0, screenHeight - PANEL_HEIGHT);
}
