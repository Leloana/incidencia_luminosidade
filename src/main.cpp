//FONTES
//https://developers.google.com/edu/c++/getting-started?hl=pt-br - Iniciar arquivo e ver sintaxe
//https://www.w3schools.com/CPP/cpp_files.asp - Ler e escrever arquivos
//https://www.geeksforgeeks.org/cpp/stringstream-c-applications/ - Lidar com as linhas
// https://www.w3schools.com/cpp/cpp_classes.asp - Classes e objetos
// https://www.w3schools.com/cpp/cpp_list.asp - Listas

//https://en.wikipedia.org/wiki/Triangle_inequality - Desigualdade triangular
//https://stackoverflow.com/questions/26315401/explanation-of-ccw-algorithm - ccw

#include <iostream>
#include <fstream>
#include <vector>


#include "../include/SceneParser.h" 

using namespace std;

int main() {
    cout << "# Teste Programador C++ - Incidencia de Luminosidade #" << endl;

    vector<Obstacles*> obstaclesList;
    vector<FotonPoint*> fotonList;
    vector<TargetPoint*> targetPointList;

    SceneParser::load("../regiao.txt", obstaclesList, fotonList, targetPointList);

    string CaminhoCheckInput = "../output/check_input.txt";
    ofstream check_input(CaminhoCheckInput); 

    if (!check_input.is_open()) {
        cerr << "Erro: Nao foi possivel criar o arquivo em " << CaminhoCheckInput << endl;
        cerr << "Verifique se a pasta 'output' existe na raiz do projeto." << endl;
        return 1;
    }

    for (auto obs : obstaclesList) obs->printData(check_input); 
    for (auto foton : fotonList) foton->printData(check_input); 
    for(auto target : targetPointList) target->printData(check_input); 
    
    check_input.close();  
    cout << "Arquivo de check_input gerado com sucesso em: " << CaminhoCheckInput << endl;

    SceneParser::runCalculations(targetPointList, fotonList, obstaclesList);

    string caminhoSaida = "../output/saida.txt";
    ofstream saida(caminhoSaida); 

    if (!saida.is_open()) {
        cerr << "Erro: Nao foi possivel criar o arquivo em " << caminhoSaida << endl;
        cerr << "Verifique se a pasta 'output' existe na raiz do projeto." << endl;
        return 1;
    }
    
    SceneParser::printResults(saida, targetPointList);

    cout << "Arquivo de saida gerado com sucesso em: " << caminhoSaida << endl;
    

    return 0;
}