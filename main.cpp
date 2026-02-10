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

using namespace std;
class Obstacles {
    public:
        int Id;
        float reductionFactor;
        int x;
        int y;
};

class Rectangle : public Obstacles {
    public:
        int width;
        int height;
};

int main() {
    cout << "Teste Programador C++ - Incidenciade Luminosidade" << endl;
  
    ofstream MyFile("filename.txt"); //cria um arquivo
    
    MyFile << "Files can be tricky, but it is fun enough!"; //escreve no arquivo

    MyFile.close(); //fecha o arquivo
 
    // Esse bloco define a leitura do arquivo, iterando sobre cada linha 
    // e quebrando a linha em palavras usando stringstream
    ifstream MyReadFile("regiao.txt");
    string line; 
    string word;
    while (getline(MyReadFile, line)) { 
        stringstream ss(line);

        ss >> word; // Precisamos saber apenas a primeira palavra para identificar o tipo de linha (R, C, L, F, P)
        if(word == "R") {
            Rectangle rect;
            ss >> rect.Id;
            ss >> rect.reductionFactor;
            ss >> rect.x;
            ss >> rect.y;
            ss >> rect.width;
            ss >> rect.height;
            cout << "Rectangle: " << rect.Id << ", " << rect.reductionFactor << ", " << rect.x << ", " << rect.y << ", " << rect.width << ", " << rect.height << endl;
            // Processar linha de retângulo
        } else if(word == "C") {
            // Processar linha de círculo
        } else if(word == "L") {
            // Processar linha de linha
        } else if(word == "F") {
            // Processar linha de fonte de luz
        } else if(word == "P") {
            // Processar linha de ponto alvo
        }
        cout << word << endl;           
    }
    MyReadFile.close();

    return 0;
}
