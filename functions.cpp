#include "team.h"
#include <fstream>
#include <sstream>
#include <array>
#include <vector>
#include <string>
#include <iostream>


void readTeam(Team& t, const std::string& name) {
    std::ifstream file(name + ".data");
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << name << ".data" << std::endl;
        return;
    }

    // Read the team name
    std::string teamName;
    std::getline(file, teamName); // Read the entire first line as team name
    t.setName(teamName);

    // Read the scores
    std::vector<std::array<int, 2>> pairs;
    std::string line;
    if (std::getline(file, line)) { // Read the second line containing scores
        std::stringstream ss(line);
        std::string pair_str;

        while (std::getline(ss, pair_str, ' ')) {
            size_t colon_pos = pair_str.find(':');
            if (colon_pos == std::string::npos) {
                std::cerr << "Error: Malformed score pair \"" << pair_str << "\"" << std::endl;
                continue;
            }

            int first = std::stoi(pair_str.substr(0, colon_pos));
            int second = std::stoi(pair_str.substr(colon_pos + 1));
            pairs.push_back({first, second});
        }
    }

    t.setScores(pairs);
    file.close();
}
