/** TODO: build this
 *  - [ ] make it more generic handling more triangles
 * 
 */

/**
 * class for each block, inheriting 4 triangles
 */

#include "block.h"
#include "triangle.h"
#include <SceneTree.hpp>
#include <ResourceLoader.hpp>

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

void Block::_init() {
    ResourceLoader* resourceLoader = ResourceLoader::get_singleton();
    TriangleScene = resourceLoader->load("res://triangle/Triangle.tscn");
}

// TODO: what will be best x_pos, y_pos to represent left upper corner, centre etc.
void Block::init(int x_pos, int y_pos) {
    set_position(Vector2(x_pos, y_pos));
    // TODO: Error: ERROR: _get_socket_error: Socket error: 10054
    //       At: drivers/unix/net_socket_posix.cpp:190
    // godot::Triangle* triangle1 = static_cast<godot::Triangle*>(TriangleScene->instance());
    // add_child(triangle1);
}


void Block::_ready() {

}

void Block::_process(float delta) {

}
