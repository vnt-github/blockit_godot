#include "triangle.h"
#include <ResourceLoader.hpp>
#include <Texture.hpp>
#include <TextureButton.hpp>

using namespace godot;

void Triangle::_register_methods() {
    // NOTE: this is mandatory for godot to know what to _process()
    register_method("_process", &Triangle::_process);
    register_method("_init", &Triangle::_init);
    register_method("_ready", &Triangle::_ready);
	register_method("_on_pressed", &Triangle::_on_pressed);
}

Triangle::Triangle() {}

Triangle::~Triangle() {}

void Triangle::_init() {
	is_occupied_by = none;
}
void Triangle::_ready() {
    Godot::print(get_position());
}

void Triangle::init(Vector2 pos) {
    // TODO: Unhandled exception at 0x0000000002746A80 in Godot_v3.1.1-stable_win64.exe: 0xC0000005: Access violation executing location 0x0000000002746A80.
    // - [x] unmatched Node2d and Texture Button
    set_position(pos);
}

void Triangle::_on_pressed() {
	ResourceLoader* resourceLoader = ResourceLoader::get_singleton();
	String texture_path;
	if (is_occupied_by != none) return;
	is_occupied_by = owners(rand() % 2); // get current turn; // for now it's random
	is_occupied_by = static_cast<owners>(rand() % 2 + 1);
	switch (is_occupied_by)
	{
	case none:
		Godot::print("invalid none");
		// get current turn and set is_occupied_by assuming it's not possible to call event on disabled
	// safe checks
	case black:
		is_occupied_by = black; // get current turn
		Godot::print("black");
		texture_path = String("res://art/black_triangle.png");
		break;
	case white:
		is_occupied_by = white; // get current turn
		Godot::print("white");
		texture_path = String("res://art/white_triangle.png");
		break;
	default:
		Godot::print("invalid _on_pressed called on ", is_occupied_by);
		break;
	}
	set_disabled(true);
	set_normal_texture(resourceLoader->load(texture_path));
	Godot::print("_on_pressed", is_occupied_by, is_visible());
}

void Triangle::_process(float delta) {
}