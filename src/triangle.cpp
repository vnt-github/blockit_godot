#include "triangle.h"
#include <ResourceLoader.hpp>
#include <Texture.hpp>
#include <TextureButton.hpp>
#include "block.h"
#include <Sprite.hpp>

using namespace godot;

void Triangle::_register_methods() {
    // NOTE: this is mandatory for godot to know what to _process()
    register_method("_process", &Triangle::_process);
    register_method("_init", &Triangle::_init);
    register_method("_ready", &Triangle::_ready);
	register_method("_on_pressed", &Triangle::_on_pressed);
	register_method("_on_state_changed", &Triangle::_on_state_changed);
	register_signal<Triangle>("finished", "override", GODOT_VARIANT_TYPE_STRING);
}

Triangle::Triangle() {
	is_occupied_by = owners::none;
}

Triangle::~Triangle() {
}

void Triangle::_init() {
}
void Triangle::_ready() {
	// set_position(position);
}

void Triangle::init(Vector2 pos, double rotation) {
    // TODO: Unhandled exception at 0x0000000002746A80 in Godot_v3.1.1-stable_win64.exe: 0xC0000005: Access violation executing location 0x0000000002746A80.
    // - [x] unmatched Node2d and Texture Button
    set_position(pos);
}

void Triangle::_on_pressed() {
	ResourceLoader* resourceLoader = ResourceLoader::get_singleton();
	String texture_path;
	if (is_occupied_by != owners::none) return;

	String triangle_texture_path;

	Node* parent = get_parent();

	Block* block = static_cast<Block*>(get_node(".."));

	Godot::print("parent name");
	Godot::print(get_parent()->get_name());
	Godot::print(block->get_name());

	// TODO: fill this into a functino get block type
	// TODO: fix this working by HACK: block_type on texture of Sprite
	auto texture = static_cast<Sprite*>(get_node("../Sprite"))->get_texture();
	String block_texture_path = texture->get_path();
	Godot::print(block_texture_path);
	owners block_type;

	if (block_texture_path == String("res://art/white_block.png")) {
		block_type = owners::white;
	}
	else if (block_texture_path == String("res://art/black_block.png")) {
		block_type = owners::black;
	}
	else {
		block_type == owners::none;
	}

	String is_none = (block_type == owners::none ? "none" : "not none");
	String is_black = (block_type == owners::black ? "black" : "not black");
	String is_white = (block_type == owners::white ? "white" : "not white");

	Godot::print(is_none);
	Godot::print(is_black);
	Godot::print(is_white);

	switch (is_occupied_by)
	{
	case owners::none:
		Godot::print("first turn none");
		if (_turn == 0) {
			if (block_type == owners::white) {
				set_normal_texture(resourceLoader->load(String("res://art/white_triangle.png")));
				set_hover_texture(resourceLoader->load(String("res://art/black_triangle.png")));
				is_occupied_by = owners::white;
			} else {
				set_normal_texture(resourceLoader->load(String("res://art/black_triangle.png")));
				set_hover_texture(resourceLoader->load(String("res://art/white_triangle.png")));
				is_occupied_by = owners::black;
			}
			emit_signal("finished", "override");
		}
		//TODO: add logic to check the override only to enter here
		else if (_turn == 1 && block_type == owners::white /** is_override **/) {
			set_normal_texture(resourceLoader->load(String("res://art/white_triangle.png")));
			set_hover_texture(resourceLoader->load(String("res://art/black_triangle.png")));
			is_occupied_by = owners::white;
			emit_signal("finished", "override");
		}
		//TODO: add logic to check the override only to enter here
		else if (_turn == 2 && block_type == owners::black /** is_override **/) {
			set_normal_texture(resourceLoader->load(String("res://art/black_triangle.png")));
			set_hover_texture(resourceLoader->load(String("res://art/white_triangle.png")));
			is_occupied_by = owners::black;
			emit_signal("finished", "override");
		}
		set_visible(true);
		break;
		// get current turn and set is_occupied_by assuming it's not possible to call event on disabled
	// safe checks
	case owners::black:
		// get current turn
		// Godot::print("black");
		set_normal_texture(resourceLoader->load(String("res://art/white_triangle.png")));
		set_hover_texture(resourceLoader->load(String("res://art/black_triangle.png")));
		is_occupied_by = owners::white;
		break;
	case owners::white:
		// get current turn
		// Godot::print("white");
		set_normal_texture(resourceLoader->load(String("res://art/black_triangle.png")));
		set_hover_texture(resourceLoader->load(String("res://art/white_triangle.png")));
		is_occupied_by = owners::black;
		break;
	default:
		Godot::print("invalid _on_pressed called on ");
		break;
	}
	//set_disabled(true);
	Godot::print("_on_pressed");
	Godot::print(is_visible());
	Godot::print("is_pressed done");
	Godot::print("finished sent");
}

void Triangle::_process(float delta) {
}

void Triangle::_on_state_changed(int turn) {
	_turn = turn;
}