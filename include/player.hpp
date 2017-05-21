#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL_events.h>
#include <SDL2pp/Point.hh>
#include <SDL2pp/Optional.hh>
#include <string>

#include "direction.hpp"
#include "actor.hpp"

namespace SDL2pp {
    class Renderer;
}

class Player : public Actor {
    private:
        typedef Actor super;
    public:
        Player(const std::string& name, const Sprite& sprite);
        Player(const std::string& name, const Sprite& sprite, const SDL2pp::Point& coordinates);
        ~Player();

        void update(SDL2pp::Optional<SDL_Event> event) override;

        bool move(Direction dir);
};

#endif /* PLAYER_HPP */
