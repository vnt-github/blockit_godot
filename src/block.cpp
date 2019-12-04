/** TODO: build this
 *  - [ ] make it more generic handling more triangles
 * 
 */

/**
 * class for each block, inheriting 4 triangles
 */

#include "block.h"
#include "triangle.h"

using namespace godot;

void Block::_register_methods() {
    register_method("_process", &Block::_process);
    register_method("_init", &Block::_init);
    register_method("b_method", &Block::b_method);
}

Block::Block() {}

Block::~Block() {}

void Block::_init() {
    for (int i = 0; i < 4; i++) {
        triangles[i] = Triangle();
        triangles[i].t_data = i;
    }
    
}

void Block::_process(float delta) {

}

String Block::b_method() {
    int result = 0;
    for (int i = 0; i < 4; i++) {
        result+=triangles[i].t_method();
    }
    
    return result;
    
}