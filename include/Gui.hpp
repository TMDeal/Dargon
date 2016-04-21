#ifndef GUI_HPP
#define GUI_HPP

#include <vector>
#include <string>
#include <cstdarg>
#include <cstring>

#include "libtcod/libtcod.hpp"

typedef struct Message{
    std::string text;
    TCODColor col;

    Message(std::string text, TCODColor col)
        :text(text), col(col){}
}Message;

typedef std::vector<Message*>::iterator logIter;

class Gui{
    public:
        Gui(int screenWidth, int screenHeight);
        ~Gui();
        void render();
        void renderLog();
        void renderMouseLook();
        void renderBar(int x, int y, std::string name, float value, float maxValue, 
                const TCODColor &barColor, const TCODColor &backColor);
        void addLog(const TCODColor &col, std::string fmt, ...);

        const static int PANEL_HEIGHT = 7;
        const static int BAR_WIDTH = 20;
        const static int MSG_X=BAR_WIDTH+2;
        const static int MSG_HEIGHT=PANEL_HEIGHT-1;

    private:
        TCODConsole *con;
        int screenWidth, screenHeight;
        std::vector<Message*> logs;
};

#endif /* GUI_HPP */
