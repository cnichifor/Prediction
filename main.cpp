#include <iostream>
#include <fstream>
#include "team.h"
#include "functions.h"
using namespace std;

int main(){
    Team b;
    Team l;
    readTeam(b, "barcelona");
    readTeam(l, "leganes");
    b.showTeamData();
    l.showTeamData();

    array<int, 2> score = b.prediction(l);
    cout << b.getName() << " Predicted score " << score[0] << ":" << score[1] << endl;

    
    return 0;
}