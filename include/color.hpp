#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>
#include <algorithm>
#include <functional>

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    Color() : r(255), g(255), b(255), a(255) {}
    Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b), a(255) {}
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}

    bool operator==(const Color& other) const {
        return r == other.r && g == other.g && b == other.b && a == other.a;
    }

    bool operator!=(const Color& other) const {
        return !operator ==(other);
    }

    Color& operator=(const Color& other) {
        if(this == &other) {
            return *this;
        }

        r = other.r;
        g = other.g;
        b = other.b;
        a = other.a;

        return *this;
    }

    const Color& operator+(const Color& other) {
        r = std::min(r + other.r, 255);
        g = std::min(g + other.g, 255);
        b = std::min(b + other.b, 255);
        a = std::min(a + other.a, 255);
        return *this;
    }

    const Color& operator+(int offset) {
        r = std::min(r + offset, 255);
        g = std::min(g + offset, 255);
        b = std::min(b + offset, 255);
        a = std::min(a + offset, 255);
        return *this;
    }

    const Color& operator+=(const Color& other) {
        return *this + other;
    }

    const Color& operator+=(int offset) {
        return *this + offset;
    }

    const Color& operator-(const Color& other) {
        r = std::max(r - other.r, 0);
        g = std::max(g - other.g, 0);
        b = std::max(b - other.b, 0);
        a = std::max(a - other.a, 0);
        return *this;
    }

    const Color& operator-(int offset) {
        r = std::max(r - offset, 0);
        g = std::max(g - offset, 0);
        b = std::max(b - offset, 0);
        a = std::max(a - offset, 0);
        return *this;
    }

    const Color& operator-=(const Color& other) {
        return *this - other;
    }

    const Color& operator-=(int offset) {
        return *this - offset;
    }

    const Color& operator*(const Color& other) {
        r = std::min(r * other.r, 255);
        g = std::min(g * other.g, 255);
        b = std::min(b * other.b, 255);
        a = std::min(a * other.a, 255);
        return *this;
    }

    const Color& operator*(int offset) {
        r = std::min(r * offset, 255);
        g = std::min(g * offset, 255);
        b = std::min(b * offset, 255);
        a = std::min(a * offset, 255);
        return *this;
    }

    const Color& operator*=(const Color& other) {
        return *this * other;
    }

    const Color& operator*=(int offset) {
        return *this * offset;
    }

    const Color& operator/(const Color& other) {
        r = std::max(r / other.r, 0);
        g = std::max(g / other.g, 0);
        b = std::max(b / other.b, 0);
        a = std::max(a / other.a, 0);
        return *this;
    }

    const Color& operator/(int offset) {
        r = std::max(r / offset, 0);
        g = std::max(g / offset, 0);
        b = std::max(b / offset, 0);
        a = std::max(a / offset, 0);
        return *this;
    }

    const Color& operator/=(const Color& other) {
        return *this / other;
    }

    const Color& operator/=(int offset) {
        return *this / offset;
    }
};

namespace std {
    template<>
    struct hash<Color> {
        size_t operator()(const Color& color) const {
            std::size_t seed = 0;
            std::hash<uint8_t> hasher;
            seed ^= hasher(color.r) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= hasher(color.g) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= hasher(color.b) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= hasher(color.a) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
}

#endif /* COLOR_HPP */
