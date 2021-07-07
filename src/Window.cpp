#include "Window.h"

Window::Window(int w, int h) {
    running = true;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);

    rWindow = SDL_CreateWindow("Multibrot", SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED, w, h,
                               SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    rContext = SDL_GL_CreateContext(rWindow);
    SDL_GL_MakeCurrent(rWindow, rContext);

    glewExperimental = true;
    glewInit();
}

Window::~Window() {
    SDL_GL_DeleteContext(rContext);
    SDL_DestroyWindow(rWindow);
    SDL_Quit();
}

void Window::clear() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::update() { SDL_GL_SwapWindow(rWindow); }

void Window::processEvents(float &xPos, float &yPos, float &scale) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
                running = false;
                break;
            case SDL_SCANCODE_W:
                yPos += scale / 2.0f;
                break;
            case SDL_SCANCODE_S:
                yPos -= scale / 2.0f;
                break;
            case SDL_SCANCODE_A:
                xPos -= scale / 2.0f;
                break;
            case SDL_SCANCODE_D:
                xPos += scale / 2.0f;
                break;
            case SDL_SCANCODE_Q:
                scale *= 1.1f;
                break;
            case SDL_SCANCODE_E:
                scale /= 1.1f;
            default:
                break;
            }
        }
    }
}