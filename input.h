#pragma once

#include "3d.h"
#include "rubik.h"
#include "animation.h"

void keyboard(GLFWwindow * window, int key, int scancode, int action, int mods);

void reshape(GLFWwindow * window, int width, int height);

void setCallbacks(GLFWwindow * window);
