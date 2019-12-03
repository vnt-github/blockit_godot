/** TODO: build this
 *  - [ ] make it more generic handling more triangles
 * 
 */



#ifndef BLOCK_H
#define BLOCK_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <triangle.h>

namespace godot {
    /** TODO: build this
     * 
     */


    /**
     * class for each block, inheriting 4 triangles
     */
    class Block : public Node2D {
        GODOT_CLASS(Block, Node2D);
        // TODO: define dynamic array of Blocks
        private:
            Triangle triangles[4];
        public:
            static void _register_methods();

            Block();
            ~Block();

            void _init();
            void _process(float delta);
    };
}
#endif