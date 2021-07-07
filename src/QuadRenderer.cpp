#include "QuadRenderer.h"

QuadRenderer::QuadRenderer() {
    float verts[] = {-1.0f, -1.0f, 0.0f, -1.0f, 1.0f, 0.0f,
                     1.0f,  -1.0f, 0.0f, 1.0f,  1.0f, 0.0f};

    unsigned inds[] = {0, 1, 2, 1, 2, 3};

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), verts, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned), inds,
                 GL_STATIC_DRAW);
}

QuadRenderer::~QuadRenderer() {
    glDeleteBuffers(1, &EBO);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}

void QuadRenderer::render() {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
}