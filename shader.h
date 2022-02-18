#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Shader {
public:
    uint id;
    Shader(const std::string& vertfile, const std::string& fragfile);
    ~Shader();
    void use();
    void uniform1i(const std::string& name, int val);
    void uniform1f(const std::string& name, float val);
    void uniform3fv(const std::string& name, glm::vec3 val);
    void uniformMatrix4fv(const std::string& name, glm::mat4 val);
private:
    uint loadShader(const std::string& file, uint type);
    std::string readSource(const std::string& file);
};
