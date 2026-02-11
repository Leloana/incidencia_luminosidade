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

/**
 * @file SceneParser.cpp
 * @brief Implementação dos métodos do módulo de parser de cena.
 * * Veja detalhes da interface e documentação dos parâmetros no arquivo SceneParser.h.
 */

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
        // Ao ler a primeira palavra, identificamos o tipo de objeto e extraímos os parâmetros correspondentes para criar as instâncias corretas, armazenando-as nos vetores apropriados.
        if(word == "R") {
            int id, x, y, h, w;
            int rf;
            ss >> id >> rf >> x >> y >> h >> w;
            obstaclesList.push_back(new Rectangle(id, rf, (double)x, (double)y, w, h));

        } else if(word == "C") {
            int id, x, y, r;
            int rf;
            ss >> id >> rf >> x >> y >> r;
            obstaclesList.push_back(new Circle(id, rf, (double)x, (double)y, r));

        } else if(word == "L") {
            int id, x, y, endX, endY;
            int rf;
            ss >> id >> rf >> x >> y >> endX >> endY;
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
    // Para cada alvo analisamos cada foton, e para cada foton analisamos cada obstaculo
    for (size_t i = 0; i < targets.size(); ++i) {
        for (size_t j = 0; j < fotons.size(); ++j) {

            double currentIntensity = fotons[j]->intensity;

            for (size_t k = 0; k < obstacles.size(); ++k) {
                // Crossings sao as intersecoes entre o raio de luz (do foton ao alvo) e o obstaculo, podendo ser 0, 1 ou 2 dependendo do tipo de obstaculo e da trajetória do raio
                int crossings = obstacles[k]->countIntersections(fotons[j]->position, targets[i]->position);
                // Como a luz decai a cada obstaculo deveremos fazer o calculo do fator de redução (RF) para cada crossing detectado, multiplicando a intensidade atual pela redução percentual do obstaculo.
                for (int c = 0; c < crossings; ++c) {
                    // Cálculo do Fator de Redução (RF)
                    double rf = 1.0 - (obstacles[k]->reductionFactor / 100.0);
                    
                    currentIntensity *= rf;
                    
                }
            }
            targets[i]->totalLuminosity += currentIntensity;
        }
    }
}

void SceneParser::printResults(ostream& os, const vector<TargetPoint*>& targets) {
    //Vetor que ordenará os pontos garantindo o print correto
    vector<TargetPoint> sortedTargets;

    sortedTargets.reserve(targets.size());//aloca

    // Copia os dados dos ponteiros para o vetor de objetos, facilitando a ordenação por ID
    for (const auto& targetPtr : targets) {
        sortedTargets.push_back(*targetPtr);
    }
    // Ordena os pontos por ID
    sort(sortedTargets.begin(), sortedTargets.end(), [](const TargetPoint& a, const TargetPoint& b) {
        return a.Id < b.Id;
    });

    // Print final
    os << fixed << setprecision(2);
    for (size_t i = 0; i < sortedTargets.size(); ++i) {
        os << "P" << sortedTargets[i].Id << " = " << sortedTargets[i].totalLuminosity << endl;
    }
}