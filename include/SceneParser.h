#ifndef SCENEPARSER_H
#define SCENEPARSER_H

#include <string>
#include <list>
#include "Obstacles.h"
#include "FotonPoint.h"
#include "TargetPoint.h"

class SceneParser {
public:
    static void load(const std::string& filePath, 
                     std::list<Obstacles*>& obstacles, 
                     std::list<FotonPoint*>& fotons, 
                     std::list<TargetPoint*>& targets);
};

#endif