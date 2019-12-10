#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <TextureButton.hpp>
#include <Vector2.hpp>

namespace godot {
    // TODO: change it to Node2d and try debugging to find the error
    class Triangle : public TextureButton {
        GODOT_CLASS(Triangle, TextureButton)
        public:
            static void _register_methods();

            Triangle();
            ~Triangle();
            
            void init(Vector2);
            void _init();

            void _process(float delta);
    };
}
#endif