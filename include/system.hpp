#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <memory>
#include "config.hpp"
#include "sprite.hpp"
#include "player.hpp"
#include "level.hpp"

namespace SDL2pp {
    class SDL;
    class SDLImage;
    class SDLTTF;
    class Mixer;
    class Window;
    class Renderer;
}

enum System_State {
    STARTING,
    IDLE,
    NEW_TURN,
    WINDOW_RESIZED
};

class System {
    private:
        bool m_running;
        System_State m_state;
        Config m_config;

        std::unique_ptr<SDL2pp::SDL> m_sdl;
        std::unique_ptr<SDL2pp::SDLImage> m_sdl_image;
        std::unique_ptr<SDL2pp::SDLTTF> m_sdl_ttf;
        std::unique_ptr<SDL2pp::Mixer> m_mixer;
        std::unique_ptr<SDL2pp::Window> m_window;
        std::unique_ptr<SDL2pp::Renderer> m_renderer;

        SpriteSheet m_sprite_sheet;

        Player m_player;
        Level m_level;
    public:
        System(const Config& config);
        ~System();

        void update();
        void draw();

        bool running() const;
        void quit();
};

#endif /* SYSTEM_HPP */
