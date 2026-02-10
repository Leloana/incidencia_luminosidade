#include "../include/SceneParser.h"
#include "../include/Rectangle.h"
#include "../include/Circle.h"
#include "../include/Line.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm> 
#include <iomanip>  

using namespace std;

void SceneParser::load(const string& filePath, 
                       vector<Obstacles*>& obstaclesList, 
                       vector<FotonPoint*>& fotonList, 
                       vector<TargetPoint*>& targetPointList) {

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
            int id, x, y, h, w;
            int rf;
            ss >> id >> rf >> x >> y >> h >> w;
            // double reductionFactor = 1.0 - (rf / 100.0);
            obstaclesList.push_back(new Rectangle(id, rf, (double)x, (double)y, w, h));

        } else if(word == "C") {
            int id, x, y, r;
            int rf;
            ss >> id >> rf >> x >> y >> r;
            // double reductionFactor = 1.0 - (rf / 100.0);
            obstaclesList.push_back(new Circle(id, rf, (double)x, (double)y, r));

        } else if(word == "L") {
            int id, x, y, endX, endY;
            int rf;
            ss >> id >> rf >> x >> y >> endX >> endY;
            // double reductionFactor = 1.0 - (rf / 100.0);
            obstaclesList.push_back(new Line(id, rf, (double)x, (double)y, (double)endX, (double)endY));

        } else if(word == "F") {
            int id;
            double intensity,x,y;
            ss >> id >> intensity >> x >> y;
            fotonList.push_back(new FotonPoint(id, intensity, (double)x, (double)y));

        } else if(word == "P") {
            int id;
            double x,y;
            ss >> id >> x >> y;
            targetPointList.push_back(new TargetPoint(id, (double)x, (double)y));
        }  
        else {
            cerr << "Aviso: Linha ignorada por formato desconhecido: " << line << endl;
        }         
    }
    
    MyReadFile.close();
}

void SceneParser::runCalculations(vector<TargetPoint*>& targets, vector<FotonPoint*>& fotons, vector<Obstacles*>& obstacles) {
    for (size_t i = 0; i < targets.size(); ++i) {
        for (size_t j = 0; j < fotons.size(); ++j) {

            double currentIntensity = fotons[j]->intensity;

            for (size_t k = 0; k < obstacles.size(); ++k) {
                int crossings = obstacles[k]->countIntersections(fotons[j]->position, targets[i]->position);

                for (int c = 0; c < crossings; ++c) {
                    // Cálculo do Fator de Redução (RF)
                    double rf = 1.0 - (obstacles[k]->reductionFactor / 100.0);
                    
                    currentIntensity *= rf;
                    
                }
            }
            // Verifica se o valor final faz sentido (não é negativo ou infinito)
            targets[i]->totalLuminosity += currentIntensity;
        }
    }
}

void SceneParser::printResults(ostream& os, const vector<TargetPoint*>& targets) {
    vector<TargetPoint> sortedTargets;

    sortedTargets.reserve(targets.size());

    for (const auto& targetPtr : targets) {
        sortedTargets.push_back(*targetPtr);
    }
    
    sort(sortedTargets.begin(), sortedTargets.end(), [](const TargetPoint& a, const TargetPoint& b) {
        return a.Id < b.Id;
    });

    os << fixed << setprecision(2);
    for (size_t i = 0; i < sortedTargets.size(); ++i) {
        os << "P" << sortedTargets[i].Id << " = " << sortedTargets[i].totalLuminosity << endl;
    }
}