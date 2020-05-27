#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Godot.hpp>
#include <TextureButton.hpp>
#include <Vector2.hpp>
#include "Game.h"

namespace godot {
    // TODO: change it to Node2d and try debugging to find the error
    class Triangle : public TextureButton {
        GODOT_CLASS(Triangle, TextureButton)
        public:
            static void _register_methods();

            Triangle();
            ~Triangle();
            
            void init(Vector2, double);
            void _init();
            void _ready();

            void _process(float delta);
			void _on_pressed();
			void _on_state_changed(int);
			int _turn;
            owners is_occupied_by;
            int64_t block_type;
            // TODO: why we cannot have Vector2 or int64_t block_type type as an attribute below these??
			// Vector2 a_position;
    };
}
#endif