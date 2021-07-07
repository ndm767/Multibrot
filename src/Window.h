#pragma once

#include <GL/glew.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

class Window {
  public:
    Window(int w, int h);
    ~Window();

    bool isRunning() { return running; }

    void clear();

    void update();
    void processEvents(float &xPos, float &yPos, float &scale);

  protected:
    bool running;

    SDL_Window *rWindow;
    SDL_GLContext rContext;
};