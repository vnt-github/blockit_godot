#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Godot.hpp>
#include <TextureButton.hpp>

namespace godot {
    class Triangle : public TextureButton {
        GODOT_CLASS(Triangle, TextureButton)
        public:
            // QUERY: can we initialize it's value here like String t_data=1;
            String t_data;
            static void _register_methods();

            Triangle();
            ~Triangle();

            void _init();

            void _process(float delta);

            String t_method();
    };
}
#endif