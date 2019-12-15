#pragma once

#include <Godot.hpp>
#include <Node.hpp>
#include <Ref.hpp>
#include <PackedScene.hpp>
#include "StateMachine.h"

enum owners { none, black, white };

namespace godot {
    class Game: public StateMachine {
        GODOT_CLASS(Game, Node2D);
        public:
            static void _register_methods();

            Game();
            ~Game();

            void init(int, int);
            void _init();
            void _ready();
        private:
            Ref<PackedScene> GridScene;
            Ref<PackedScene> BlockScene;
    };
}