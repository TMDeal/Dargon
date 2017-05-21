#include <SDL2pp/Renderer.hh>
#include "actor.hpp"

using SDL2pp::Renderer;
using SDL2pp::Point;

Actor::Actor(const std::string& name, Sprite sprite)
    :m_name(name), m_sprite(sprite), m_coordinates(Point(0, 0))
{}

Actor::Actor(const std::string& name, Sprite sprite, const Point& coordinates)
    :m_name(name), m_sprite(sprite), m_coordinates(coordinates)
{}

Actor::~Actor() = default;

void Actor::render(Renderer& renderer) {
    m_sprite.render(renderer, m_coordinates);
}
