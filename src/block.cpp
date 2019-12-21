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
#include "Game.h"

using namespace godot;

void Block::_register_methods() {
    register_method("_process", &Block::_process);
    register_method("_init", &Block::_init);
    register_method("_ready", &Block::_ready);
    register_method("init", &Block::init);
	register_method("_on_finished", &Block::_on_finished);
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
	// position = pos;
    set_position(pos);
	// set_scale(Vector2(0.3, 0.3));
    //Sprite* block = static_cast<Sprite*>(get_node("Sprite"));
    //TextureButton* TriangleLeftNode = static_cast<TextureButton*>(get_node("TriangleLeft"));
    // TODO: Sprite* block = Object::cast_to<Sprite>(get_node("Sprite"));
    // TODO: TextureButton* TriangleLeftNode = Object::cast_to<TextureButton>(get_node("TriangleLeft"));


    // QUERY: why below does't work gives same unix socket error
    // String block_texture_path = String("res://art/") + block_types[num] + String("_block.png");
    // block->set_texture(resourceLoader->load("res://art/"+ block_types[num] + "_block.png"));

    //block->set_texture(resourceLoader->load(block_texture_path));
    //TriangleLeftNode->set_normal_texture(resourceLoader->load(String("res://art/white_triangle.png")));
    //TriangleLeftNode->set_hover_texture(resourceLoader->load("res://art/black_triangle.png"));
    // TODO: Error: ERROR: _get_socket_error: Socket error: 10054
    //       At: drivers/unix/net_socket_posix.cpp:190
    // godot::Triangle* triangle1 = Object::cast_to<godot::Triangle>(TriangleScene->instance());
    // add_child(triangle1);
}


void Block::_ready() {
	ResourceLoader* resourceLoader = ResourceLoader::get_singleton();
	Triangle* TriangleLeft = static_cast<Triangle*>(get_node("TriangleLeft"));
	TextureButton* TriangleRight = static_cast<TextureButton*>(get_node("TriangleRight"));
	TextureButton* TriangleUp = static_cast<TextureButton*>(get_node("TriangleUp"));
	TextureButton* TriangleDown = static_cast<TextureButton*>(get_node("TriangleDown"));
	Ref<Resource> blackTriangle = resourceLoader->load("res://art/black_triangle.png");
	Ref<Resource> whiteTriangle = resourceLoader->load("res://art/white_triangle.png");
	int max = 1;
	int min = 0;
	int range = max - min + 1;
	// TODO: int num = srand(time(0)) % range + min;
	int num = rand() % range + min;
	Ref<Resource> hover_resource;
	String block_texture_path;
	if (num == 0) {
		block_texture_path = String("res://art/black_block.png");
		block_type = owners::black;
		hover_resource = blackTriangle;
	}
	else {
		block_texture_path = String("res://art/white_block.png");
		block_type = owners::white;
		hover_resource = whiteTriangle;
	}

	//TriangleLeft->set_normal_texture(blackTriangle);
	TriangleLeft->set_hover_texture(hover_resource);
	Node* game = get_parent()->get_parent();
	TriangleLeft->connect("finished", game, "_on_finished");
	TriangleLeft->connect("finished", this, "_on_finished");
	game->connect("state_changed", TriangleLeft, "_on_state_changed");
	TriangleLeft->block_type = block_type;

	//TriangleRight->set_normal_texture(blackTriangle);
	TriangleRight->set_hover_texture(hover_resource);

	//TriangleUp->set_normal_texture(blackTriangle);
	TriangleUp->set_hover_texture(hover_resource);

	//TriangleDown->set_normal_texture(blackTriangle);
	TriangleDown->set_hover_texture(hover_resource);

	static_cast<Sprite*>(get_node("Sprite"))->set_texture(resourceLoader->load(block_texture_path));
	// set_position(position);
	//Triangle* triangle = static_cast<godot::Triangle*>(BlockTriangleScene->instance());

    // TODO: Triangle* triangle = Object::cast_to<godot::Triangle>(BlockTriangleScene->instance());
	// TODO: why below gives error
	//double degree_in_radiants_90 = 1.57;
    //triangle->init(get_position(), degree_in_radiants_90);
	//add_child(triangle);
}

void Block::_process(float delta) {

}

void Block::_on_finished() {
	Godot::print("block _on_finished");
}