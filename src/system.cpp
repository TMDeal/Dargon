#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL2pp/SDL.hh>
#include <SDL2pp/SDLImage.hh>
#include <SDL2pp/SDLTTF.hh>
#include <SDL2pp/Mixer.hh>
#include <SDL2pp/Window.hh>
#include <SDL2pp/Renderer.hh>
#include <SDL2pp/Optional.hh>
#include "system.hpp"
#include "direction.hpp"

using SDL2pp::NullOpt;
using SDL2pp::SDL;
using SDL2pp::SDLImage;
using SDL2pp::SDLTTF;
using SDL2pp::Mixer;
using SDL2pp::Window;
using SDL2pp::Renderer;

System::System(const Config& config)
    :m_running(true),
    m_config(config),
    m_sdl(std::make_unique<SDL>(SDL_INIT_VIDEO | SDL_INIT_AUDIO)),
    m_sdl_image(std::make_unique<SDLImage>(IMG_INIT_PNG)),
    m_sdl_ttf(std::make_unique<SDLTTF>()),
    m_mixer(std::make_unique<Mixer>(MIX_DEFAULT_FREQUENCY,
            MIX_DEFAULT_FORMAT,
            MIX_DEFAULT_CHANNELS, 4096)),
    m_window(std::make_unique<Window>("Dargon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            m_config.screen_width, m_config.screen_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)),
    m_renderer(std::make_unique<Renderer>(*m_window.get(), -1, SDL_RENDERER_ACCELERATED)),
    m_sprite_sheet(*m_renderer.get(), "sprites"),
    m_player("Rogue", m_sprite_sheet.makeSprite("male-default", Color(0, 0, 255)))
{}

System::~System() = default;

void System::update() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                quit();
            case SDL_KEYDOWN:
                m_player.update(event);
            default:
                break;
        }
    }
}

void System::draw() {
    m_renderer->SetDrawColor(0, 0, 0);
    m_renderer->Clear();
    m_player.render(*m_renderer.get());
    m_renderer->Present();
}

bool System::running() const {
    return m_running;
}

void System::quit() {
    m_running = false;
}
