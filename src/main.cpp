#include "QuadRenderer.h"
#include "Shader.h"
#include "Window.h"

int main(int argc, char *argv[]) {
    Window win(400, 400);

    Shader s("shaders/vert.glsl", "shaders/frag.glsl");

    QuadRenderer quad;

    while (win.isRunning()) {
        win.clear();

        s.useShader();
        quad.render();

        win.update();
        win.processEvents();
    }

    return 0;
}