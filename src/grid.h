#pragma once

#include "block.h"
#include <map>
#include <vector>
#include <Godot.hpp>
#include <Node2D.hpp>
#include <Ref.hpp>
#include <PackedScene.hpp>
#include "StateMachine.h"

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
    class Grid : public StateMachine {
        GODOT_CLASS(Grid, Node2D);
        public:
            static void _register_methods();

            Grid();
            ~Grid();

            void _on_finished(int, String, String);
            void _init();
            void _ready();
            void init(int, int);
            void _process();
            void touch_input();
			int _rows;
			int _columns;
            std::map<String, Block*> blocks;
            //NOTE: adjacent are for unsymmetrics shapes in place of blocks
            //std::map<String, std::map<String, Block*>> adjacents;
            std::vector<std::vector<Block*>> blocks_matrix;
        // TODO: define dynamic array of Blocks
        private:
            // REVIEW: may be make it const. determine effect on all scenerios.
            // NOTE:  this is 2d dynamic array: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
            // REVIEW: when does this allocate memory of grid_size and with what value
            // Block** blocks = new Block*[grid_size];
            Ref<PackedScene> BlockScene;
            Ref<PackedScene> TriangleScene;
			Vector2 grid_margins;
            // TODO: 2d array of blocks init on _init or init and spawned (add_child) on_ready
    };
}