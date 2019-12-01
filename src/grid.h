#ifndef GRID_H
#define GRID_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <block.h>

namespace godot {
    /** TODO: build this
     * 
     */

    /**
     * class for Grid consisting blocks.
     * based on windows information and game options it generates
     * and places blocks for the main game on initialization.
     * also contains logic for randomization and determining
     * blocked and hence turn based on override. 
     */
    class Grid : public Node2D {
        GODOT_CLASS(Grid, Node2D);
        // TODO: define dynamic array of Blocks
        private:
            // REVIEW: may be make it const. determine effect on all scenerios.
            const static int max_no_blocks = 20;
            Block blocks[max_no_blocks][max_no_blocks];
        public:
            static void _register_methods();

            Grid();
            ~Grid();

            void _init();
            void _process(float delta);
    };
}
#endif