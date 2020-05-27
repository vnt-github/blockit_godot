// TODO: difference between #define "block.h" and #defind<block.h>
#include "grid.h"
#include "block.h"
#include "triangle.h"
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include <Input.hpp>
#include <map>
#include <vector>

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
    register_method("_on_finished", &Grid::_on_finished, GODOT_METHOD_RPC_MODE_DISABLED);

	//TODO: fix below it's not exporting it to godot
	register_property<Grid, Vector2>("grid_margins", &Grid::grid_margins, Vector2());

}

// TODO: where to initialize and set value of grid_size
// TODO: how to initialize
Grid::Grid() {
	_rows = 0;
	_columns = 0;
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
	Godot::print(String::num(Grid::_rows));
    Godot::print(String::num(_rows));
    Godot::print("=================_ready end===============");
	//TODO: set the _rows and _columns from the Game init
	for (int i = 0; i < _rows; i++) {
        std::vector<Block*> row;
		for (int j = 0; j < _columns; j++) {
			Block* block = static_cast<Block*>(BlockScene->instance());
            //godot::Block* block = Object::cast_to<godot::Block>(BlockScene->instance());
			int margin = 150;
			block->init(i, j, grid_margins + Vector2(j*margin, i*margin));
			add_child(block);
            blocks[block->get_name()] = block;
            row.push_back(block);
		}
        blocks_matrix.push_back(row);
	}
}

void Grid::init(int rows, int columns) {
    Godot::print("=================init begin===============");
    Godot::print(String::num(rows));
    Godot::print(String::num(columns));
    Godot::print("=================init set===============");
    _rows = rows;
    _columns = columns;
	Godot::print(String::num(_rows));
	Godot::print(String::num(_columns));
	Godot::print("=================init end===============");
}

void Grid::touch_input() {
    Input* input = Input::get_singleton();
    if(input->is_action_just_pressed("ui_touch")) {
        Vector2 first_touch = get_global_mouse_position();
        Godot::print(first_touch);
        //Block* block = blocks[1][1];
        //block->set_visible(false);
        //std::map<String, Block*> aux_blocks = blocks;


        // godot::Block* block = static_cast<godot::Block*>(BlockScene->instance());
		//Block* block = Block::_new();
        // TODO: godot::Block* block = Object::cast_to<godot::Block>(BlockScene->instance());
        // block->init(first_touch);
        // add_child(block);


        //godot::Triangle* triangle = Object::cast_to<godot::Triangle>(TriangleScene->instance());
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

void Grid::_on_finished(int first_move, String block_name, String triangle_direction) {
    ResourceLoader* resourceLoader = ResourceLoader::get_singleton();
    Godot::print("game _on_finished override");
    Godot::print("triangle_direction");
    Godot::print(triangle_direction);
    Godot::print(bool(String("TriangleLeft") == triangle_direction));
    Block* block = blocks[block_name];
    Ref<Resource> blackTriangle = resourceLoader->load("res://art/black_triangle.png");
    Ref<Resource> whiteTriangle = resourceLoader->load("res://art/white_triangle.png");

    if (triangle_direction == String("TriangleLeft")) {
        if (block->grid_j > 0) {
            Block* adjacent = blocks_matrix[block->grid_i][block->grid_j - 1];
            Triangle* TriangleAdjacent = static_cast<Triangle*>(adjacent->get_node("TriangleRight"));
            //TriangleAdjacent->set_normal_texture(blackTriangle);
            TriangleAdjacent->set_visible(false);
            Godot::print(block->get_path());
            Godot::print(adjacent->get_path());
            Godot::print(TriangleAdjacent->get_path());
        }
    }
    else if (triangle_direction == String("TriangleRight")) {
        if (block->grid_j < _columns - 1) {
            Block * adjacent = blocks_matrix[block->grid_i][block->grid_j + 1];
            Triangle* TriangleAdjacent = static_cast<Triangle*>(adjacent->get_node("TriangleLeft"));
            TriangleAdjacent->set_visible(false);
            Godot::print(block->get_path());
            Godot::print(adjacent->get_path());
            Godot::print(TriangleAdjacent->get_path());
        }
    }
    else if (triangle_direction == String("TriangleUp")) {
        if (block->grid_i > 0) {
            Block* adjacent = blocks_matrix[block->grid_i - 1][block->grid_j];
            Triangle* TriangleAdjacent = static_cast<Triangle*>(adjacent->get_node("TriangleDown"));
            //TriangleAdjacent->set_normal_texture(resourceLoader->load(String("res://art/white_triangle.png")));
            TriangleAdjacent->set_visible(false);
            Godot::print(block->get_path());
            Godot::print(adjacent->get_path());
            Godot::print(TriangleAdjacent->get_path());
        }
    }
    else if (triangle_direction == String("TriangleDown")) {
        if (block->grid_i < _rows - 1) {
            Block* adjacent = blocks_matrix[block->grid_i + 1][block->grid_j];
            Triangle* TriangleAdjacent = static_cast<Triangle*>(adjacent->get_node("TriangleUp"));
            //TriangleAdjacent->set_normal_texture(resourceLoader->load(String("res://art/white_triangle.png")));
            TriangleAdjacent->set_visible(false);
            Godot::print(block->get_path());
            Godot::print(adjacent->get_path());
            Godot::print(TriangleAdjacent->get_path());
        }
    }


    /*if (triangle_direction == String("TriangleLeft")) {
        if (block->grid_j > 0) {
            Block* adjacent = blocks_matrix[block->grid_i][block->grid_j - 1];
            Triangle* TriangleAdjacent = static_cast<Triangle*>(adjacent->get_node("TriangleRight"));
            Triangle* TriangleSelected = static_cast<Triangle*>(block->get_node("TriangleLeft"));
            Godot::print(TriangleSelected->is_occupied_by == TriangleAdjacent->is_occupied_by ? String("blocked") : String("not blocked"));
        }
    }
    else if (triangle_direction == String("TriangleRight")) {
        if (block->grid_j < _columns - 1) {
            Block* adjacent = blocks_matrix[block->grid_i][block->grid_j + 1];
            Triangle* TriangleAdjacent = static_cast<Triangle*>(adjacent->get_node("TriangleLeft"));
            Triangle* TriangleSelected = static_cast<Triangle*>(block->get_node("TriangleRight"));
            Godot::print(TriangleSelected->is_occupied_by == TriangleAdjacent->is_occupied_by ? String("blocked") : String("not blocked"));
        }
    }
    else if (triangle_direction == String("TriangleUp")) {
        if (block->grid_i > 0) {
            Block* adjacent = blocks_matrix[block->grid_i - 1][block->grid_j];
            Triangle* TriangleAdjacent = static_cast<Triangle*>(adjacent->get_node("TriangleDown"));
            Triangle* TriangleSelected = static_cast<Triangle*>(block->get_node("TriangleUp"));
            Godot::print(TriangleSelected->is_occupied_by == TriangleAdjacent->is_occupied_by ? String("blocked") : String("not blocked"));
        }
    }
    else if (triangle_direction == String("TriangleDown")) {
        if (block->grid_i < _rows - 1) {
            Block* adjacent = blocks_matrix[block->grid_i + 1][block->grid_j];
            Triangle* TriangleAdjacent = static_cast<Triangle*>(adjacent->get_node("TriangleUp"));
            Triangle* TriangleSelected = static_cast<Triangle*>(block->get_node("TriangleDown"));
            Godot::print(TriangleSelected->is_occupied_by == TriangleAdjacent->is_occupied_by ? String("blocked") : String("not blocked"));
        }
    }*/
    //block->set_visible(false);
}