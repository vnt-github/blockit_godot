#include "grid.h"

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
}

/**
 * REVIEW: _init functions
 * initialized the grid with appropriate number of blocks
 */
void Grid::_init() {
}

void Grid::_process(float delta) {

}