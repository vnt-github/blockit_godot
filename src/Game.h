#pragma once

#include <Godot.hpp>
#include <Node.hpp>
#include <Ref.hpp>
#include <PackedScene.hpp>
#include "StateMachine.h"
#include "grid.h"

enum class owners { none, black, white };

namespace godot {
    class Game: public StateMachine {
        GODOT_CLASS(Game, Node2D);
        public:
            static void _register_methods();

            Game();
            ~Game();

			void _on_finished(int, String);
            void init(int, int);
            void _init();
            void _ready();
			void change_turn(int);
        private:
            Ref<PackedScene> GridScene;
            Ref<PackedScene> BlockScene;
            int grid_rows;
            int grid_columns;
			Grid* grid;
    };
}