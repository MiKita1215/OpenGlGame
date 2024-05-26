#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader {
public:
    void load(const char* vertexPath, const char* fragmentPath);
    void use();
private:
    unsigned int ID;
};

#endif // SHADER_H
