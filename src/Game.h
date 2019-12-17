#pragma once

#include <Godot.hpp>
#include <Node.hpp>
#include <Ref.hpp>
#include <PackedScene.hpp>
#include "StateMachine.h"
#include "grid.h"

enum owners { none, black, white };

namespace godot {
    class Game: public StateMachine {
        GODOT_CLASS(Game, Node2D);
        public:
            static void _register_methods();

            Game();
            ~Game();

            void init();
            void _init();
            void _ready();
        private:
            Ref<PackedScene> GridScene;
            Ref<PackedScene> BlockScene;
            Grid* grid;
    };
}