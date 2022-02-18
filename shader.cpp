#include "shader.h"

using namespace std;

Shader::Shader(const string& vertfile, const string& fragfile) {
    uint vertshader = loadShader(vertfile, GL_VERTEX_SHADER);
    uint fragshader = loadShader(fragfile, GL_FRAGMENT_SHADER);

    id = glCreateProgram();
    glAttachShader(id, vertshader);
    glAttachShader(id, fragshader);
    glLinkProgram(id);

    int ok;
    glGetProgramiv(id, GL_LINK_STATUS, &ok);
    if (ok) {
        cout << "Shader program linked successfully" << endl;
    } else {
        char infolog[512];
        glGetProgramInfoLog(id, 512, NULL, infolog);
        cout << "Shader program linking failed\n" << infolog << endl;
    }
}

Shader::~Shader() {
    glDeleteProgram(id);
}

void Shader::use() {
    glUseProgram(id);
}

void Shader::uniform1i(const string& name, int val) {
    int loc = glGetUniformLocation(id, name.c_str());
    glUniform1f(loc, val);
}

void Shader::uniform1f(const string& name, float val) {
    int loc = glGetUniformLocation(id, name.c_str());
    glUniform1f(loc, val);
}

void Shader::uniform3fv(const string& name, glm::vec3 val) {
    int loc = glGetUniformLocation(id, name.c_str());
    glUniform3fv(loc, 1, glm::value_ptr(val));
}

void Shader::uniformMatrix4fv(const string& name, glm::mat4 val) {
    int loc = glGetUniformLocation(id, name.c_str());
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(val));
}

uint Shader::loadShader(const string& file, uint type) {
    uint shader = glCreateShader(type);
    string _src = readSource(file);
    const char * src = _src.c_str();
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    int ok;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
    if (ok) {
        cout << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment")
           << " shader compiled successfully" << endl; 
    } else {
        char infolog[512];
        glGetShaderInfoLog(shader, 512, NULL, infolog);
        cout << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment")
            << " shader compilation failed\n" << infolog << endl;

    }
    return shader;
}

string Shader::readSource(const string& file) {
    fstream fs(file);
    string line;
    stringstream ss;
    while (getline(fs, line)) {
        ss << line << '\n';
    }
    return ss.str();
}
