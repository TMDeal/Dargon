#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <SDL2pp/SDL.hh>
#include <SDL2pp/SDLImage.hh>
#include <SDL2pp/SDLTTF.hh>
#include <SDL2pp/Mixer.hh>
#include <SDL2pp/Window.hh>
#include <SDL2pp/Renderer.hh>

#include "config.hpp"

class System {
    private:
        bool m_running;
        Config m_config;
        SDL2pp::SDL m_sdl;
        SDL2pp::SDLImage m_sdl_image;
        SDL2pp::SDLTTF m_sdl_ttf;
        SDL2pp::Mixer m_mixer;

        SDL2pp::Window m_window;
        SDL2pp::Renderer m_renderer;
    public:
        System(const Config& config);

        void handleEvents();
        void update();
        void draw();

        bool running() const;
        void quit();
};

#endif /* SYSTEM_HPP */
