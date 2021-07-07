#version 330 core

in vec3 fPos;

out vec4 outColor;

const float MAX_ITER = 100.0;

vec2 compMult(vec2 a, vec2 b) {
    vec2 ret = vec2(0, 0);
    ret.x = a.x * b.x - a.y * b.y;
    ret.y = a.x * b.y + a.y * b.x;
    return ret;
}

vec2 compExp(vec2 z, float power) {
    if (power <= 0) {
        return vec2(0, 0);
    }

    vec2 ret = z;
    for (float i = 1; i < power; i++) {
        ret = compMult(ret, z);
    }

    return ret;
}

float multibrot(vec2 c, float power, float iter) {
    vec2 z = vec2(0, 0);
    for (float i = 0; i < MAX_ITER; i++) {

        z = compExp(z, power) + c;

        if (length(z) > 2)
            return i / iter;
        if (i >= iter) {
            break;
        }
    }

    return iter;
}

void main() {
    vec2 compPos = vec2(fPos.xy);
    float val = multibrot(compPos, 3.0, 10.0);
    outColor = vec4(val, val, val, 1.0);
}