#include "animation.h"

using namespace std;

glm::mat4 animationmodel[27];
float animationstart;
glm::mat4 animationmatrix;

void animate(glm::vec3 axis, const int side[]) {
    if (curt - animationstart >= delta) {
        animationmatrix = glm::rotate(glm::mat4(1), glm::radians(-90.0f), axis);
        finishmove = true;
    } else {
        animationmatrix = glm::rotate(glm::mat4(1), glm::radians(-90.0f * (curt - animationstart) / delta), axis);
    }
    int sz = side == All ? 27 : 9;
    for (int i = 0; i < sz; i++) {
        animationmodel[cube[side[i]]] = animationmatrix * model[cube[side[i]]];    
    }
}

void animate() {
    switch (movetype) {
        case X:  animate(glm::vec3(1, 0, 0), All);
                 break;
        case Xi: animate(glm::vec3(-1, 0, 0), All);
                 break;
        case Y:  animate(glm::vec3(0, 1, 0),  All);
                 break;
        case Yi: animate(glm::vec3(0, -1, 0), All);
                 break;
        case Z:  animate(glm::vec3(0, 0, 1),  All);
                 break;
        case Zi: animate(glm::vec3(0, 0, -1), All);
                 break;
        case F:  animate(glm::vec3(0, 0, 1),  Front);
                 break;
        case Fi: animate(glm::vec3(0, 0, -1), Front);
                 break;
        case B:  animate(glm::vec3(0, 0, -1), Back);
                 break;
        case Bi: animate(glm::vec3(0, 0, 1), Back);
                 break;
        case R:  animate(glm::vec3(1, 0, 0),  Right);
                 break;
        case Ri: animate(glm::vec3(-1, 0, 0), Right);
                 break;
        case L:  animate(glm::vec3(-1, 0, 0), Left);
                 break;
        case Li: animate(glm::vec3(1, 0, 0), Left);
                 break;
        case U:  animate(glm::vec3(0, 1, 0),  Up);
                 break;
        case Ui: animate(glm::vec3(0, -1, 0), Up);
                 break;
        case D:  animate(glm::vec3(0, -1, 0), Down);
                 break;
        case Di: animate(glm::vec3(0, 1, 0), Down);
                 break;
        case M:  animate(glm::vec3(-1, 0, 0), Middle);
                 break;
        case Mi: animate(glm::vec3(1, 0, 0), Middle);
                 break;
        case E:  animate(glm::vec3(0, -1, 0), Equator);
                 break;
        case Ei: animate(glm::vec3(0, 1, 0), Equator);
                 break;
        case S:  animate(glm::vec3(0, 0, 1),  Standing);
                 break;
        case Si: animate(glm::vec3(0, 0, -1), Standing);
                 break;
    }
}
