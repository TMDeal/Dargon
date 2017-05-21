#include <iostream>
#include <fstream>
#include <json/json.h>
#include "config.hpp"
#include "res_paths.hpp"

Config getConfig(const std::string& filename) {
    Json::Value root;
    Json::Reader reader;
    Config config;

    std::ifstream config_file(RES_DIRECTORY + filename + ".json");

    if(!reader.parse(config_file, root)) {
        std::cout << "Could not find " + filename + " config file in " + RES_DIRECTORY + "!"<< std::endl;
        std::cout << "using defaults..." << std::endl;
    }

    config.screen_width = root.get("screen-width", 620).asInt();
    config.screen_height = root.get("screen-height", 480).asInt();
    config.fps = root.get("fps", 60).asInt();

    return config;
}
