//FONTES
//https://developers.google.com/edu/c++/getting-started?hl=pt-br - Iniciar arquivo e ver sintaxe
//https://www.w3schools.com/CPP/cpp_files.asp - Ler e escrever arquivos
//https://www.geeksforgeeks.org/cpp/stringstream-c-applications/ - Lidar com as linhas
// https://www.w3schools.com/cpp/cpp_classes.asp - Classes e objetos
// https://www.w3schools.com/cpp/cpp_list.asp - Listas

#include <iostream>
#include <list>

#include "../include/SceneLoader.h" 

using namespace std;

// Função auxiliar para limpar memória (opcional, mas deixa a main mais limpa ainda)
template <typename T>
void clearList(list<T*>& lst) {
    for (auto item : lst) {
        delete item;
    }
    lst.clear();
}

int main() {
    cout << "# Teste Programador C++ - Incidencia de Luminosidade #" << endl;

    // 1. Criação das Listas
    list<Obstacles*> obstaclesList;
    list<FotonPoint*> fotonList;
    list<TargetPoint*> targetPointList;

    // 2. Carregamento (Delegação para o SceneLoader)
    SceneLoader::load("../regiao.txt", obstaclesList, fotonList, targetPointList);

    // 3. Uso dos dados
    cout << "================ Dados dos Obstaculos ================" << endl;
    for (auto obs : obstaclesList) obs->printData(); 

    cout << "================ Dados dos FotonPoints ================" << endl;
    for (auto foton : fotonList) foton->printData(); 

    cout << "================ Dados dos Pontos Alvo ================" << endl;
    for(auto target : targetPointList) target->printData(); 

    // 4. Limpeza de Memória
    clearList(obstaclesList);
    clearList(fotonList);
    clearList(targetPointList);

    return 0;
}