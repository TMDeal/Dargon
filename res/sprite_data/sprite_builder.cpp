#include <sstream>
#include <fstream>
#include <string>
#include <json/json.h>

const std::string DATA_FILES[] = {"fonts", "sprites"};

void getSizeData(Json::Value& root, std::ifstream& file) {
    std::string line, index;
    int value;
    int values_to_read = 4;

    for(int i = 0; i < values_to_read; i++) {
        while(getline(file, line)) {
            if(!line.empty()) {
                break;
            }
        }
        std::stringstream sstream(line);
        sstream >> index;
        sstream >> value;
        root[index] = value;
    }
}

void getTypeData(Json::Value& root, std::ifstream& file) {
    std::string line, index, token;

    //get line until there is not an empty line
    while(getline(file, line)) {
        if(!line.empty()) {
            break;
        }
    }

    std::stringstream sstream(line);
    sstream >> index;
    Json::Value types;

    while(getline(sstream, token, ',')) {
        types.append(token);
    }

    root[index] = types;
}

void getSpriteData(Json::Value& root, std::ifstream& file) {
    int i = 0;
    std::string line, index, token;
    int sprites_per_row = root.get("sprites-per-row", 0).asInt();

    while(getline(file, line)) {
        if(line.empty()) {
            continue;
        }
        std::stringstream sstream(line);
        sstream >> index;
        std::string type;
        while(getline(sstream, token, '=')) {
            if(token == "type") {
                continue;
            }
            type = token;
        }

        root["sprites"][index]["x"] = i % sprites_per_row;
        root["sprites"][index]["y"] = 0 + (i / sprites_per_row);
        root["sprites"][index]["type"] = type;
        i++;
    }
}

int main(int argc, char *argv[])
{
    Json::StyledWriter json_writer;

    Json::Value root;
    std::ifstream in_file(argv[1]);
    std::ofstream out_file(argv[2]);

    if(in_file.is_open()) {
        getSizeData(root, in_file);
        getTypeData(root, in_file);
        getSpriteData(root, in_file);
    }

    out_file << json_writer.write(root);
    in_file.close();
    out_file.close();

    return EXIT_SUCCESS;
}
