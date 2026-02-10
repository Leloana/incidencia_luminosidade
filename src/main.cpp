//FONTES
//https://developers.google.com/edu/c++/getting-started?hl=pt-br - Iniciar arquivo e ver sintaxe
//https://www.w3schools.com/CPP/cpp_files.asp - Ler e escrever arquivos
//https://www.geeksforgeeks.org/cpp/stringstream-c-applications/ - Lidar com as linhas
// https://www.w3schools.com/cpp/cpp_classes.asp - Classes e objetos
// https://www.w3schools.com/cpp/cpp_list.asp - Listas

#include<iostream>
#include<fstream> //ler arquivos
#include <string>
#include <sstream> //string stream para quebrar string
#include <list>

#include "../include/Obstacles.h"
#include "../include/Rectangle.h"
#include "../include/Circle.h"
#include "../include/Line.h"
#include "../include/FotonPoint.h"
#include "../include/TargetPoint.h"

using namespace std;

int main() {
    cout << "# Teste Programador C++ - Incidenciade Luminosidade #" << endl;
    
    // ofstream MyFile("filename.txt"); //cria um arquivo
    // MyFile << "Files can be tricky, but it is fun enough!"; //escreve no arquivo
    // MyFile.close(); //fecha o arquivo
    list <Obstacles*> obstaclesList;
    list <FotonPoint*> fotonList;
    list <TargetPoint*> targetPointList;
    // e quebrando a linha em palavras usando stringstream
    ifstream MyReadFile("../regiao.txt");
    string line; 
    string word;

    while (getline(MyReadFile, line)) { 
        if (line.empty()) continue;
        stringstream ss(line);
        ss >> word; // Precisamos saber apenas a primeira palavra para identificar o tipo de linha (R, C, L, F, P)
        if(word == "R") {
            Rectangle* rect = new Rectangle();
            ss >> rect->Id;
            ss >> rect->reductionFactor;
            ss >> rect->position.x;
            ss >> rect->position.y;
            ss >> rect->width;
            ss >> rect->height;
            obstaclesList.push_back(rect);
            // Processar linha de retângulo
        } else if(word == "C") {
                Circle* circ = new Circle();
                ss >> circ->Id;
                ss >> circ->reductionFactor;
                ss >> circ->position.x;
                ss >> circ->position.y;
                ss >> circ->radius;
                obstaclesList.push_back(circ);
            // Processar linha de círculo
        } else if(word == "L") {
            // Processar linha de linha
            Line* line = new Line();
            ss >> line->Id;
            ss >> line->reductionFactor;
            ss >> line->position.x;
            ss >> line->position.y;
            ss >> line->endPosition.x;
            ss >> line->endPosition.y;
            obstaclesList.push_back(line);
        } else if(word == "F") {
            // Processar linha de fonte de luz
            FotonPoint* foton = new FotonPoint();
            ss >> foton->Id;
            ss >> foton->intensity;
            ss >> foton->position.x;
            ss >> foton->position.y;
            fotonList.push_back(foton);
        } else if(word == "P") {
            // Processar linha de ponto alvo
            TargetPoint* targetPoint = new TargetPoint();
            ss >> targetPoint->Id;
            ss >> targetPoint->position.x;
            ss >> targetPoint->position.y;
            targetPointList.push_back(targetPoint);
        }           
    }
    MyReadFile.close();

    cout << "================ Dados dos Obstaculos ================" << endl;
    for (Obstacles* obs : obstaclesList) {
        obs->printData(); 
    }

    cout << "================ Dados dos FotonPoints ================" << endl;
    for (FotonPoint* foton : fotonList) {
        foton->printData(); 
    }

    cout << "================ Dados dos Pontos Alvo ================" << endl;
    for(TargetPoint* targetPoint : targetPointList) {
        targetPoint->printData(); 
    }

    for (Obstacles* obs : obstaclesList) {
        delete obs; 
    }
    for(FotonPoint* foton : fotonList) {
        delete foton; 
    }
    for(TargetPoint* targetPoint : targetPointList) {
        delete targetPoint; 
    }

    obstaclesList.clear();
    fotonList.clear();
    targetPointList.clear();

    return 0;
}
