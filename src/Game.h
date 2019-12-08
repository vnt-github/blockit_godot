#pragma once

#include <Godot.hpp>
#include <Node.hpp>
#include <Ref.hpp>
#include <PackedScene.hpp>

namespace godot {
    class Game: public Node {
        GODOT_CLASS(Game, Node);
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