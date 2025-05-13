#ifndef OBJMESH_H
#define OBJMESH_H

#include "VisualObject.h"
#include <string>

class ObjMesh : public VisualObject
{
public:
    ObjMesh(const std::string& filename);

    QVector3D GetDimensions();

private:
	bool readObjFile(const std::string& filename);
};

#endif // OBJMESH_H
