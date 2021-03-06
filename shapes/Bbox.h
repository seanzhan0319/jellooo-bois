#ifndef BBOX_H
#define BBOX_H

#include "Shape.h"

class Bbox : public Shape
{
public:
    Bbox();
    ~Bbox();
    void drawBbox();
    void drawPlane();
    void drawFloor();

    void tick(float current) override;
    void setGravity(float scale, glm::vec3 new_direction) override;
    virtual void setParam1(int inp) override;
    virtual void setParam2(int inp) override;

private:
    virtual void generateVertexData() override;
};


#endif // BBOX_H
