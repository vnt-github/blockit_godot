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
#include <TextureButton.hpp>

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
	BlockTriangleScene = resourceLoader->load("res://triangle/Triangle.tscn");
}

// TODO: what will be best x_pos, y_pos to represent left upper corner, centre etc.
void Block::init(Vector2 pos) {
    ResourceLoader* resourceLoader = ResourceLoader::get_singleton();
    set_position(pos);
    Sprite* block = static_cast<Sprite*>(get_node("Sprite"));
    TextureButton* TriangleLeftNode = static_cast<TextureButton*>(get_node("TriangleLeft"));
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

    block->set_texture(resourceLoader->load(block_texture_path));
    TriangleLeftNode->set_normal_texture(resourceLoader->load(String("res://art/white_triangle.png")));
    TriangleLeftNode->set_hover_texture(resourceLoader->load("res://art/black_triangle.png"));
    // TODO: Error: ERROR: _get_socket_error: Socket error: 10054
    //       At: drivers/unix/net_socket_posix.cpp:190
    // godot::Triangle* triangle1 = static_cast<godot::Triangle*>(TriangleScene->instance());
    // add_child(triangle1);
}


void Block::_ready() {
	Triangle* triangle = static_cast<godot::Triangle*>(BlockTriangleScene->instance());
	// TODO: why below gives error
    //triangle->init(get_position());
	add_child(triangle);
}

void Block::_process(float delta) {

}
