#include "team.h"
#include <iostream>
#include <vector>
#include <array>
#include <cmath>
using namespace std;

void Team::showTeamData(){
    cout << name << endl;
    for(int i = 0; i < scores.size(); i++){
        cout << scores[i][0] << ":" << scores[i][1] << " ";
    }
    cout << endl;
}

array<int, 2> Team::averageScore(){
    int conceded = 0;
    int scored = 0;
    for(int i = 0; i < 5; i++){
        conceded += scores[i][1];
        scored += scores[i][0];
    }
    array<int, 2> score = {static_cast<int>(round(scored / 5.0)), static_cast<int>(round(conceded / 5.0))};
    return score;
}

array<int, 2> Team::prediction(Team t){
    array<int, 2> avg1 = averageScore();
    array<int, 2> avg2 = t.averageScore();
    array<int, 2> prediction = {static_cast<int>(round((avg1[0] + avg2[1]) / 2.0)), static_cast<int>(round((avg1[1] + avg2[0]) / 2.0))};
    return prediction;
}
