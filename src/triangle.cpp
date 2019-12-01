#include "triangle.h"

using namespace godot;

void Triangle::_register_methods() {
    // NOTE: this is mandatory for godot to know what to _process()
    register_method("_process", &Triangle::_process);
}

Triangle::Triangle() {}

Triangle::~Triangle() {}

void Triangle::_init() {}

void Triangle::_process(float delta) {
}