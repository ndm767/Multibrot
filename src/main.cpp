#include "QuadRenderer.h"
#include "Shader.h"
#include "Window.h"

int main(int argc, char *argv[]) {
    Window win(400, 400);

    Shader s("shaders/vert.glsl", "shaders/frag.glsl");

    QuadRenderer quad;

    float multibrotExponent = 2.0f;
    float xPos = 0;
    float yPos = 0;
    float scale = 1.0f;
    float iterations = 100.0f;

    while (win.isRunning()) {
        win.clear();

        s.useShader();
        s.setUniform1f("multiExp", multibrotExponent);
        s.setUniformVec2f("userPos", xPos, yPos);
        s.setUniform1f("scale", scale);
        s.setUniform1f("iterations", iterations);
        quad.render();

        win.update();
        win.processEvents(xPos, yPos, scale);
    }

    return 0;
}