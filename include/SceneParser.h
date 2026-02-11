#ifndef SCENEPARSER_H
#define SCENEPARSER_H

#include <string>
#include <vector>
#include "Obstacles.h"
#include "FotonPoint.h"
#include "TargetPoint.h"

/*
 * @file SceneParser.h
 * @brief Representa o parser de cena para carregar e processar dados de incidência luminosa.
 * Esta classe é responsável por carregar os dados de um arquivo de cena, processar os fótons e alvos,
 * e calcular a incidência luminosa em cada ponto-alvo.
*/

class SceneParser {
public:

    /**
     * @brief Lê o arquivo de texto e constrói a cena na memória.
     * * Faz o "parse" (análise) linha por linha do arquivo .txt, instanciando
     * dinamicamente os objetos corretos (Retângulos, Círculos, Linhas, Fótons
     * e Alvos) e populando os vetores passados por referência.
     * * @param filePath Caminho para o arquivo de texto (ex: "../regiao.txt").
     * @param obstacles Vetor onde serão armazenados os ponteiros dos obstáculos lidos.
     * @param fotons Vetor onde serão armazenados os ponteiros das fontes de luz.
     * @param targets Vetor onde serão armazenados os ponteiros dos pontos alvo.
     */
    static void load(const std::string& filePath, 
                     std::vector<Obstacles*>& obstacles, 
                     std::vector<FotonPoint*>& fotons, 
                     std::vector<TargetPoint*>& targets);

    /**
     * @brief Executa o motor principal de cálculo de colisões e luminosidade.
     * * Avalia cada Fóton contra cada Ponto Alvo. Para cada trajetória gerada,
     * verifica a interseção com todos os Obstáculos da cena. Aplica o Fator de 
     * Redução (reductionFactor) iterativamente a cada colisão detectada e 
     * acumula a intensidade de luz resultante no TargetPoint.
     * * @param targets Vetor contendo os pontos alvo que receberão a luz.
     * @param fotons Vetor contendo as fontes emissoras de luz.
     * @param obstacles Vetor contendo os obstáculos geométricos que atenuam a luz.
     */
    static void runCalculations(std::vector<TargetPoint*>& targets, 
                                std::vector<FotonPoint*>& fotons, 
                                std::vector<Obstacles*>& obstacles);

    /**
     * @brief Imprime o relatório final de luminosidade.
     * * Ordena os TargetPoints por ID (garantindo que P0 venha antes de P1, etc.) 
     * e formata a saída com duas casas decimais, gravando o resultado no 
     * fluxo de dados especificado (seja no console ou em um arquivo .txt).
     * * @param os Fluxo de saída de dados (ex: std::cout ou std::ofstream).
     * @param targets Vetor contendo os pontos alvo já processados com sua luminosidade total.
     */
    static void printResults(std::ostream& os, const std::vector<TargetPoint*>& targets); 
};

#endif