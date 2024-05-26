#ifndef TEXTURE_H
#define TEXTURE_H

class Texture {
public:
    void load(const char* path);
    void bind();
private:
    unsigned int ID;
};

#endif // TEXTURE_H
