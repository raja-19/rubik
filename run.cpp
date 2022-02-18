#include "run.h"

float prevt = 0.0, curt;
const float delta = 0.5;

using namespace std;

void run(GLFWwindow * window) {
    Shader shader("vert.glsl", "frag.glsl");
    uint VAO[27], VBO[27], EBO[27];
    initRubik(VAO, VBO, EBO);
    glEnable(GL_DEPTH_TEST);

    for (int i = 0; i < 27; i++) {
        model[i] = glm::translate(glm::mat4(1), 0.27f * glm::vec3(i % 3 - 1, 1 - (i % 9) / 3, 1 - i / 9));
        animationmodel[i] = model[i];
    }

    while (!glfwWindowShouldClose(window)) {
        curt = glfwGetTime();
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.use();

        view = glm::lookAt(eye, center, up);
        proj = glm::perspective(glm::radians(45.0), (double) W / H, 0.1, 100.0);

        if (movetype == NONE) {
            for (int i = 0; i < 27; i++) {
                glBindVertexArray(VAO[i]);
                shader.uniformMatrix4fv("mvp", proj * view * model[i]);
                glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void *)(0 * sizeof(uint)));
            }
        } else {
            animate();
            for (int i = 0; i < 27; i++) {
                glBindVertexArray(VAO[i]);
                shader.uniformMatrix4fv("mvp", proj * view * animationmodel[i]);
                glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void *)(0 * sizeof(uint)));
            }
        }
        if (finishmove) finishMove();
        glfwSwapBuffers(window);
        glfwPollEvents();
        prevt = curt;
    }
    glDeleteVertexArrays(27, VAO);
    glDeleteBuffers(27, VBO);
    glDeleteBuffers(27, EBO);
}
