#pragma once

#include "3d.h"
#include "rubik.h"
#include "run.h"

extern glm::mat4 animationmodel[27];
extern float animationstart;
extern glm::mat4 animationmatrix;

void animate(glm::vec3 axis, const int side[]);

void animate();
