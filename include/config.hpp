#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>

struct Config {
    int screen_width;
    int screen_height;
};

Config getConfig(const std::string& filename);


#endif /* CONFIG_HPP */
