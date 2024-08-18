//
// Created by User on 8/17/2024.
//

#ifndef AABBCOLLISION_H
#define AABBCOLLISION_H



class AABBCollision {

public:

    bool checkCollision(class AABBCollision);
    void calcAABB();
    void setSize(float, float);

    float x;
    float y;
    //Width of our aabb object
    float w;
    //Height of our aabb object
    float h;

    float edgeL;
    float edgeR;
    float edgeB;
    float edgeT;

    bool isDead;

};



#endif //AABBCOLLISION_H
