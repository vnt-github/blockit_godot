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
    register_method("set_grid_size", &Grid::set_grid_size);
    register_method("get_grid_size", &Grid::get_grid_size);
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
}

void Grid::_process(float delta) {

}

/**
 * checks validity for grid size and sets it to new value
 * 
 * @param[in] new_grid_size the new_grid_size
 */
bool Grid::set_grid_size(int new_grid_size) {
    if (new_grid_size < 0 || new_grid_size > 20) return false;
    grid_size = new_grid_size;
    return true;
}

/**
 * returns grid_size.
 *
 * @return grid_size int
 */
int Grid::get_grid_size() {
    return grid_size;
}

