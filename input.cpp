#include "input.h"
#include <GLFW/glfw3.h>

using namespace std;

void keyboard(GLFWwindow * window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }    
    if (movetype != NONE) return;
    if (key == GLFW_KEY_X && !mods && action == GLFW_PRESS) {
        movetype = X;
        animationstart = glfwGetTime();
    }    
    if (key == GLFW_KEY_X && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
        movetype = Xi;
        animationstart = glfwGetTime();
    }    
    if (key == GLFW_KEY_Y && !mods && action == GLFW_PRESS) {
        movetype = Y;
        animationstart = glfwGetTime();
    }    
    if (key == GLFW_KEY_Y && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
        movetype = Yi;
        animationstart = glfwGetTime();
    }    
    if (key == GLFW_KEY_Z && !mods && action == GLFW_PRESS) {
        movetype = Z;
        animationstart = glfwGetTime();
    } 
    if (key == GLFW_KEY_Z && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
        movetype = Zi;
        animationstart = glfwGetTime();
    }    
    if (key == GLFW_KEY_F && !mods && action == GLFW_PRESS) {
        movetype = F;
        animationstart = glfwGetTime();
    }    
    if (key == GLFW_KEY_F && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
        movetype = Fi;
        animationstart = glfwGetTime();
    } 
    if (key == GLFW_KEY_B && !mods && action == GLFW_PRESS) {
        movetype = B;
        animationstart = glfwGetTime();
    }    
    if (key == GLFW_KEY_B && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
        movetype = Bi;
        animationstart = glfwGetTime();
    } 
    if (key == GLFW_KEY_L && !mods && action == GLFW_PRESS) {
        movetype = L;
        animationstart = glfwGetTime();
    }    
    if (key == GLFW_KEY_L && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
        movetype = Li;
        animationstart = glfwGetTime();
    } 
    if (key == GLFW_KEY_R && !mods && action == GLFW_PRESS) {
        movetype = R;
        animationstart = glfwGetTime();
    }    
    if (key == GLFW_KEY_R && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
        movetype = Ri;
        animationstart = glfwGetTime();
    } 
    if (key == GLFW_KEY_U && !mods && action == GLFW_PRESS) {
        movetype = U;
        animationstart = glfwGetTime();
    }    
    if (key == GLFW_KEY_U && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
        movetype = Ui;
        animationstart = glfwGetTime();
    } 
    if (key == GLFW_KEY_D && !mods && action == GLFW_PRESS) {
        movetype = D;
        animationstart = glfwGetTime();
    }    
    if (key == GLFW_KEY_D && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
        movetype = Di;
        animationstart = glfwGetTime();
    } 
    if (key == GLFW_KEY_M && !mods && action == GLFW_PRESS) {
        movetype = M;
        animationstart = glfwGetTime();
    }    
    if (key == GLFW_KEY_M && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
        movetype = Mi;
        animationstart = glfwGetTime();
    } 
    if (key == GLFW_KEY_E && !mods && action == GLFW_PRESS) {
        movetype = E;
        animationstart = glfwGetTime();
    }    
    if (key == GLFW_KEY_E && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
        movetype = Ei;
        animationstart = glfwGetTime();
    } 
    if (key == GLFW_KEY_S && !mods && action == GLFW_PRESS) {
        movetype = S;
        animationstart = glfwGetTime();
    }    
    if (key == GLFW_KEY_S && mods == GLFW_MOD_SHIFT && action == GLFW_PRESS) {
        movetype = Si;
        animationstart = glfwGetTime();
    } 
}

void reshape(GLFWwindow * window, int width, int height) {
    W = width, H = height;
    glViewport(0, 0, width, height); 
}

void setCallbacks(GLFWwindow * window) {
    glfwSetWindowSizeCallback(window, reshape);
    glfwSetKeyCallback(window, keyboard);
}
