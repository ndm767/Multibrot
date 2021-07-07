#version 330 core

in vec3 fPos;

out vec4 outColor;

uniform float multiExp;
uniform float scale;
uniform float iterations;
uniform vec2 userPos;

const float MAX_ITER = 1000000.0;

vec2 compExp(vec2 z, float power) {

    vec2 ret = vec2(0, 0);

    if (power < 0.0) {
        return ret;
    }

    ret.x =
        pow((z.x * z.x + z.y * z.y), power / 2.0) * cos(power * atan(z.y, z.x));
    ret.y =
        pow((z.x * z.x + z.y * z.y), power / 2.0) * sin(power * atan(z.y, z.x));

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
    vec2 compPos = vec2(fPos.xy * scale);
    compPos += userPos;
    float val = multibrot(compPos, multiExp, iterations);
    outColor = vec4(val, val, val, 1.0);
}