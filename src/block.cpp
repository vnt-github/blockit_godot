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
#include <Sprite.hpp>
#include <Texture.hpp>

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
}

// TODO: what will be best x_pos, y_pos to represent left upper corner, centre etc.
void Block::init(int x_pos, int y_pos) {
    ResourceLoader* resourceLoader = ResourceLoader::get_singleton();
    set_position(Vector2(x_pos, y_pos));
    Sprite* block = static_cast<Sprite*>(get_node("Sprite"));
    Node2D* TriangleLeftNode = static_cast<Node2D*>(get_node("TriangleLeft"));
    Sprite* TriangleLeft = static_cast<Sprite*>(TriangleLeftNode->get_node("Sprite"));
    block->set_scale(Vector2(0.2, 0.2));
    int max = 2;
    int min = 0;
    int range = max - min + 1;
    // TODO: int num = srand(time(0)) % range + min;
    int num = rand() % range + min;
    String block_texture_path;
    if (num==0) {
        block_texture_path = String("res://art/black_block.png");
    } else {
        block_texture_path = String("res://art/white_block.png");
    }

    // QUERY: why below does't work gives same unix socket error
    // String block_texture_path = String("res://art/") + block_types[num] + String("_block.png");
    // block->set_texture(resourceLoader->load("res://art/"+ block_types[num] + "_block.png"));

    Godot::print(block_texture_path);
    block->set_texture(resourceLoader->load(block_texture_path));
    TriangleLeft->set_texture(resourceLoader->load(String("res://art/white_triangle.png")));
    // TODO: Error: ERROR: _get_socket_error: Socket error: 10054
    //       At: drivers/unix/net_socket_posix.cpp:190
    // godot::Triangle* triangle1 = static_cast<godot::Triangle*>(TriangleScene->instance());
    // add_child(triangle1);
}


void Block::_ready() {

}

void Block::_process(float delta) {

}
