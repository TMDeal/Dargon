#include <SDL2pp/Point.hh>
#include "player.hpp"

using SDL2pp::Point;
using SDL2pp::Optional;
using SDL2pp::Renderer;

Player::Player(const std::string& name, const Sprite& sprite) 
    :super(name, sprite, Point(0, 0))
{}

Player::Player(const std::string& name, const Sprite& sprite, const Point& coordinates) 
    :super(name, sprite, coordinates)
{}

Player::~Player() = default;

void Player::update(Optional<SDL_Event> event) {
    if(event) {
        switch(event->key.keysym.sym) {
            case SDLK_UP:
                move(Direction::UP);
                break;
            case SDLK_DOWN:
                move(Direction::DOWN);
                break;
            case SDLK_LEFT:
                move(Direction::LEFT);
                break;
            case SDLK_RIGHT:
                move(Direction::RIGHT);
                break;
        }
    }
}

bool Player::move(Direction dir) {
    m_coordinates += Directions[static_cast<int>(dir)];
    return true;
}
