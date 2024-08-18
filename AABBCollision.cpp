//
// Created by Ronald on 8/17/2024.
//

#include "AABBCollision.h"

void update() {
    void calcAABB();
}

bool AABBCollision::checkCollision(class AABBCollision other) {

    if (edgeR <= other.edgeL) return false;
    if (edgeL >= other.edgeR) return false;
    if (edgeB <= other.edgeT) return false;
    if (edgeT >= other.edgeB) return false;
    return true;
}

 void AABBCollision::calcAABB() {
    edgeL = x;
    edgeR = x + w;
    edgeT = y;
    edgeB = y + h;
}

void AABBCollision::setSize(float Width, float Height) {
    Width = w;
    Height = h;
}


