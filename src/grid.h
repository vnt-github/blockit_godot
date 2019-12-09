#pragma once

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Ref.hpp>
#include <PackedScene.hpp>

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
        public:
            static void _register_methods();

            Grid();
            ~Grid();

            void _init();
            void _ready();
            void init(int, int);
            void _process();
            void touch_input();
        // TODO: define dynamic array of Blocks
        private:
            // REVIEW: may be make it const. determine effect on all scenerios.
            // NOTE:  this is 2d dynamic array: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
            // REVIEW: when does this allocate memory of grid_size and with what value
            // Block** blocks = new Block*[grid_size];
            Ref<PackedScene> BlockScene;
            Ref<PackedScene> TriangleScene;
    };
}