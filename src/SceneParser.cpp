#include "../include/SceneParser.h"
#include "../include/Rectangle.h"
#include "../include/Circle.h"
#include "../include/Line.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void SceneParser::load(const string& filePath, 
                       list<Obstacles*>& obstaclesList, 
                       list<FotonPoint*>& fotonList, 
                       list<TargetPoint*>& targetPointList) {

    ifstream MyReadFile(filePath);
    
    if (!MyReadFile.is_open()) {
        cerr << "Erro: Nao foi possivel abrir o arquivo " << filePath << endl;
        return;
    }

    string line;
    string word;

    while (getline(MyReadFile, line)) { 
        if (line.empty()) continue;
        
        stringstream ss(line);
        ss >> word; 

        if(word == "R") {
            int id, x, y, w, h;
            float rf;
            ss >> id >> rf >> x >> y >> w >> h;
            obstaclesList.push_back(new Rectangle(id, rf, x, y, w, h));

        } else if(word == "C") {
            int id, x, y, r;
            float rf;
            ss >> id >> rf >> x >> y >> r;
            obstaclesList.push_back(new Circle(id, rf, x, y, r));

        } else if(word == "L") {
            int id, x, y, endX, endY;
            float rf;
            ss >> id >> rf >> x >> y >> endX >> endY;
            obstaclesList.push_back(new Line(id, rf, x, y, endX, endY));

        } else if(word == "F") {
            int id, x, y;
            float intensity;
            ss >> id >> intensity >> x >> y;
            fotonList.push_back(new FotonPoint(id, intensity, x, y));

        } else if(word == "P") {
            int id, x, y;
            ss >> id >> x >> y;
            targetPointList.push_back(new TargetPoint(id, x, y));
        }           
    }
    
    MyReadFile.close();
}