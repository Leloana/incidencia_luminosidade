#ifndef SCENEPARSER_H
#define SCENEPARSER_H

#include <string>
#include <vector>
#include "Obstacles.h"
#include "FotonPoint.h"
#include "TargetPoint.h"

class SceneParser {
public:
    static void load(const std::string& filePath, 
                     std::vector<Obstacles*>& obstacles, 
                     std::vector<FotonPoint*>& fotons, 
                     std::vector<TargetPoint*>& targets);

    static void runCalculations(std::vector<TargetPoint*>& targets, 
                                std::vector<FotonPoint*>& fotons, 
                                std::vector<Obstacles*>& obstacles);

    static void printResults(std::ostream& os, const std::vector<TargetPoint*>& targets); 
};

#endif