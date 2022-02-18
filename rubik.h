#pragma once
 
#include "3d.h"
#include "animation.h"
#include <fstream>

extern glm::mat4 model[27];
extern int movetype;
extern int cube[27];
extern bool finishmove;

extern const int All[27];
extern const int Front[9];
extern const int Back[9];
extern const int Left[9];
extern const int Right[9];
extern const int Up[9]; 
extern const int Down[9];
extern const int Middle[9];
extern const int Equator[9];
extern const int Standing[9];

enum {NONE, X, Xi, Y, Yi, Z, Zi, F, Fi, B, Bi, L, Li, R, Ri, U, Ui, D, Di, M, Mi, E, Ei, S, Si};

void initRubik(uint VAO[], uint VBO[], uint EBO[]);

void cyclicShift(int i, int j, int k, int l, bool inverse);

void moveSide(const int side[9], bool inverse);

void finishMove();
