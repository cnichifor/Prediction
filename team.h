#pragma once
#include <vector>
#include <string>
#include <array>

class Team {
private:
    std::string name;
    std::vector<std::array<int, 2>> scores;

public:
    void setName(const std::string& name) {
        this->name = name;
    }
    std::string getName() const {
        return name;
    }

    void setScores(const std::vector<std::array<int, 2>>& scores) {
        this->scores = scores;
    }
    std::vector<std::array<int, 2>> getScores() const {
        return scores;
    }

    void showTeamData(); // Definition elsewhere
    std::array<int, 2> averageScore();
    std::array<int, 2> prediction(Team t);
};
