// TODO: difference between #define "block.h" and #defind<block.h>
#include "grid.h"
#include "block.h"
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>

using namespace godot;

/** TODO: build this
 * 
 */

/**
 * class for grid consisting blocks
 */


void Grid::_register_methods() {
    register_method("_process", &Grid::_process);
    register_method("_init", &Grid::_init);
    register_method("_ready", &Grid::_ready);
    register_method("init", &Grid::init);

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
}

void Grid::_ready() {
}

void Grid::init(int rows, int columns) {
    // godot::Block* block = static_cast<godot::Block*>(BlockScene->instance());
    // add_child(block);
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < columns; j++) {
            // godot::Block* block = static_cast<godot::Block*>(BlockScene->instance());
            // add_child(block);
            // int margin = 10;
            // block->init(1*margin, 1*margin);
    //     }
    // }
}

void Grid::_process(float delta) {

}
