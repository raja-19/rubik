#include "init.h"
#include "input.h"
#include "run.h"

using namespace std;

int main() {
    GLFWwindow * window = initWindow("rubik", 800, 600);
    setCallbacks(window);
    run(window);
    glfwTerminate();
    return 0;
}
