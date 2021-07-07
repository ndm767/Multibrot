#include "Window.h"

int main(int argc, char *argv[]) {
    Window win(400, 400);

    while (win.isRunning()) {
        win.clear();

        win.update();
        win.processEvents();
    }

    return 0;
}