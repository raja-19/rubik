#include "rubik.h"

using namespace std;

glm::mat4 model[27];
int movetype;
int cube[27] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
bool finishmove = false;

const int All[27] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
const int Front[9] {0, 1, 2, 3, 4, 5, 6, 7, 8};
const int Back[9] {20, 19, 18, 23, 22, 21, 26, 25, 24};
const int Left[9] {18, 9, 0, 21, 12, 3, 24, 15, 6};
const int Right[9] {2, 11, 20, 5, 14, 23, 8, 17, 26};
const int Up[9] {18, 19, 20, 9, 10, 11, 0, 1, 2};
const int Down[9] {6, 7, 8, 15, 16, 17, 24, 25, 26};
const int Middle[9] {19, 10, 1, 22, 13, 4, 25, 16, 7};
const int Equator[9] {3, 4, 5, 12, 13, 14, 21, 22, 23};
const int Standing[9] {9, 10, 11, 12, 13, 14, 15, 16, 17};

void initRubik(uint VAO[], uint VBO[], uint EBO[]) {
    float verts[27][144];
    fstream fs("rubik.txt");
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 144; j++) {
            fs >> verts[i][j];
        }
    }

    uint elems[] {
        0 * 4 + 0, 0 * 4 + 1, 0 * 4 + 2, 0 * 4 + 2, 0 * 4 + 3, 0 * 4 + 0,
        1 * 4 + 0, 1 * 4 + 1, 1 * 4 + 2, 1 * 4 + 2, 1 * 4 + 3, 1 * 4 + 0,
        2 * 4 + 0, 2 * 4 + 1, 2 * 4 + 2, 2 * 4 + 2, 2 * 4 + 3, 2 * 4 + 0,
        3 * 4 + 0, 3 * 4 + 1, 3 * 4 + 2, 3 * 4 + 2, 3 * 4 + 3, 3 * 4 + 0,
        4 * 4 + 0, 4 * 4 + 1, 4 * 4 + 2, 4 * 4 + 2, 4 * 4 + 3, 4 * 4 + 0,
        5 * 4 + 0, 5 * 4 + 1, 5 * 4 + 2, 5 * 4 + 2, 5 * 4 + 3, 5 * 4 + 0,
    };

    glGenVertexArrays(27, VAO);
    glGenBuffers(27, VBO);
    glGenBuffers(27, EBO);

    for (int i = 0; i < 27; i++) {
        glBindVertexArray(VAO[i]);
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO[i]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(verts[i]), verts[i], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[i]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elems), elems, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(0 * sizeof(float)));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void cyclicShift(int i, int j, int k, int l, bool inverse) {
    if (inverse) {
        swap(cube[i], cube[l]); 
        swap(cube[i], cube[k]);
        swap(cube[i], cube[j]);
        return;
    }
    swap(cube[i], cube[j]); 
    swap(cube[i], cube[k]);
    swap(cube[i], cube[l]);
}

void moveSide(const int side[9], bool inverse) {
    cyclicShift(side[0], side[2], side[8], side[6], inverse);
    cyclicShift(side[1], side[5], side[7], side[3], inverse);
}

void finishMove() {
    memcpy(model, animationmodel, sizeof(animationmodel));
    switch (movetype) {
        case X:  moveSide(Right, false);
                 moveSide(Middle, true);
                 moveSide(Left, true);
                 break;
        case Xi: moveSide(Right, true);
                 moveSide(Middle, false);
                 moveSide(Left, false);
                 break;
        case Y:  moveSide(Up, false);
                 moveSide(Equator, true);
                 moveSide(Down, true);
                 break;
        case Yi: moveSide(Up, true);
                 moveSide(Equator, false);
                 moveSide(Down, false);
                 break;
        case Z:  moveSide(Front, false);
                 moveSide(Standing, false);
                 moveSide(Back, true);
                 break;
        case Zi: moveSide(Front, true);
                 moveSide(Standing, true);
                 moveSide(Back, false);
                 break;
        case F:  moveSide(Front, false);
                 break;
        case Fi: moveSide(Front, true);
                 break;
        case B:  moveSide(Back, false);
                 break;
        case Bi: moveSide(Back, true);
                 break;
        case R:  moveSide(Right, false);
                 break;
        case Ri: moveSide(Right, true);
                 break;
        case L:  moveSide(Left, false);
                 break;
        case Li: moveSide(Left, true);
                 break;
        case U:  moveSide(Up, false);
                 break;
        case Ui: moveSide(Up, true);
                 break;
        case D:  moveSide(Down, false);
                 break;
        case Di: moveSide(Down, true);
                 break;
        case M:  moveSide(Middle, false);
                 break;
        case Mi: moveSide(Middle, true);
                 break;
        case E:  moveSide(Equator, false);
                 break;
        case Ei: moveSide(Equator, true);
                 break;
        case S:  moveSide(Standing, false);
                 break;
        case Si: moveSide(Standing, true);
                 break;
    }
    movetype = NONE; 
    finishmove = false;
}
