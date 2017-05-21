#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <SDL_events.h>
#include <SDL2pp/Optional.hh>
#include <SDL2pp/Point.hh>
#include <string>
#include "sprite.hpp"

namespace SDL2pp {
    class Renderer;
}

class Actor {
    protected:
        std::string m_name;
        Sprite m_sprite;
        SDL2pp::Point m_coordinates;
    public:
        Actor(const std::string& name, Sprite sprite);
        Actor(const std::string& name, Sprite sprite, const SDL2pp::Point& coordinates);
        virtual ~Actor();

        virtual void update(SDL2pp::Optional<SDL_Event> event) = 0;
        virtual void render(SDL2pp::Renderer& renderer);
};

#endif /* ACTOR_HPP */
