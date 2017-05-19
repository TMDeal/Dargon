#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "system.hpp"

System::System()
    :m_running(true),
    m_sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO),
    m_sdl_image(IMG_INIT_PNG),
    m_sdl_ttf(),
    m_mixer(MIX_DEFAULT_FREQUENCY,
            MIX_DEFAULT_FORMAT,
            MIX_DEFAULT_CHANNELS, 4096),
    m_window("Dargon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE),
    m_renderer(m_window, -1, SDL_RENDERER_ACCELERATED)
{}

void System::handleEvents() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                quit();
            default:
                break;
        }
    }
}

void System::update() {
    return;
}

void System::draw() {
    m_renderer.SetDrawColor(0, 0, 255).Clear().Present();
}

bool System::running() const {
    return m_running;
}

void System::quit() {
    m_running = false;
}
