#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Godot.hpp>
#include <TextureButton.hpp>

namespace godot {
    class Triangle : public TextureButton {
        GODOT_CLASS(Triangle, TextureButton)
        public:
            static void _register_methods();

            Triangle();
            ~Triangle();
            
            void init(real_t, real_t);
            void _init();

            void _process(float delta);
    };
}
#endif