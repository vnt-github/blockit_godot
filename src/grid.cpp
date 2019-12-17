// TODO: difference between #define "block.h" and #defind<block.h>
#include "grid.h"
#include "block.h"
#include "triangle.h"
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include <Input.hpp>

using namespace godot;

/** TODO: build this
 * 
 */

/**
 * class for grid consisting blocks
 */


void Grid::_register_methods() {
    register_method("_init", &Grid::_init, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_ready", &Grid::_ready, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("init", &Grid::init, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_process", &Grid::_process, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("touch_input", &Grid::touch_input, GODOT_METHOD_RPC_MODE_DISABLED);

	//TODO: fix below it's not exporting it to godot
	register_property<Grid, Vector2>("grid_margins", &Grid::grid_margins, Vector2());

}

// TODO: where to initialize and set value of grid_size
// TODO: how to initialize
Grid::Grid() {
}

Grid::~Grid() {
}

/**
 * REVIEW: _init functions use
 * initialized the grid with appropriate number of blocks
 */
void Grid::_init() {
    ResourceLoader* resourceLoader = ResourceLoader::get_singleton();
    BlockScene = resourceLoader->load("res://block/Block.tscn");
    TriangleScene = resourceLoader->load("res://triangle/Triangle.tscn");
	grid_margins = Vector2(30, 200);
}

void Grid::_ready() {
    Godot::print("=================_ready begin===============");
    Godot::print(String::num(this->_rows));
	Godot::print(String::num(_rows));
    Godot::print(String::num(_columns));
    Godot::print("=================_ready end===============");
	//TODO: set the _rows and _columns from the Game init
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			godot::Block* block = static_cast<godot::Block*>(BlockScene->instance());
			int margin = 150;
			block->init(grid_margins + Vector2(i*margin, j*margin));
			add_child(block);
		}
	}
}

void Grid::init(int rows, int columns) {
    Godot::print("=================init begin===============");
	Godot::print(String::num(_rows));
	Godot::print(String::num(_columns));
    Godot::print(String::num(rows));
    Godot::print(String::num(columns));
    Godot::print("=================init set===============");
    _rows = rows;
	Godot::print(String::num(_rows));
	Godot::print(String::num(_columns));
	Godot::print("=================init end===============");

    _columns = columns;
    //for (int i = 0; i < rows; i++) {
    //    for (int j = 0; j < columns; j++) {
    //        godot::Block* block = static_cast<godot::Block*>(BlockScene->instance());
    //        int margin = 150;
    //        block->init(grid_margins + Vector2(i*margin, j*margin));
    //        add_child(block);
    //    }
    //}
}

void Grid::touch_input() {
    Input* input = Input::get_singleton();
    if(input->is_action_just_pressed("ui_touch")) {
        Vector2 first_touch = get_global_mouse_position();
        Godot::print(first_touch);

        /*godot::Block* block = static_cast<godot::Block*>(BlockScene->instance());
        block->init(first_touch);
        add_child(block);*/


        //godot::Triangle* triangle = static_cast<godot::Triangle*>(TriangleScene->instance());
        // Triangle* triangle = Object::cast_to<Triangle>(TriangleScene->instance());
        //triangle->init(first_touch);
        //add_child(triangle);
        // TODO: RESOLVED: why above does not work?
            // - [x] unmatched type of the node and the attached gdnative scripts class(was of type Node2d in godot and in cpp its was TextureButton)
    }
}

void Grid::_process() {
    touch_input();
}