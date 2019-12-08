/** TODO: build this
 *  - [ ] make it more generic handling more triangles
 * 
 */

/**
 * class for each block, inheriting 4 triangles
 */

#include "block.h"

using namespace godot;

void Block::_register_methods() {
    register_method("_process", &Block::_process);
    register_method("_init", &Block::_init);
    register_method("_ready", &Block::_ready);
    register_method("init", &Block::init);
}

Block::Block() {
}

Block::~Block() {}


// TODO: what will be best x_pos, y_pos to represent left upper corner, centre etc.
void Block::init(int x_pos, int y_pos) {
    // set_position(Vector2(x_pos, y_pos));
}

void Block::_init() {
}

void Block::_ready() {

}

void Block::_process(float delta) {

}
