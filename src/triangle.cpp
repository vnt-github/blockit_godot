#include "triangle.h"

using namespace godot;

void Triangle::_register_methods() {
    // NOTE: this is mandatory for godot to know what to _process()
    register_method("_process", &Triangle::_process);
    register_method("_init", &Triangle::_init);
}

Triangle::Triangle() {}

Triangle::~Triangle() {}

void Triangle::_init() {
}

void Triangle::init(real_t x_pos, real_t y_pos) {
    Godot::print(Vector2(x_pos, y_pos));
    Godot::print(get_position());
    // TODO: Unhandled exception at 0x0000000002746A80 in Godot_v3.1.1-stable_win64.exe: 0xC0000005: Access violation executing location 0x0000000002746A80.
    // set_position(get_position());
}

void Triangle::_process(float delta) {
}