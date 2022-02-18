#include "init.h"

using namespace std;

int W, H;

GLFWwindow * initWindow(const string& title, int width, int height) {
    W = width, H = height;
    glfwInit();
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow * window = glfwCreateWindow(W, H, title.c_str(), NULL, NULL);
    if (!window) {
        cout << "Failed to initialize GLFW window" << endl;
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cout << "Failed to initialize glad" << endl;
        glfwTerminate();
        exit(1);
    }
    return window;
}
