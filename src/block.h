/** TODO: build this
 *  - [ ] make it more generic handling more triangles
 * 
 */



#ifndef BLOCK_H
#define BLOCK_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Ref.hpp>
#include <PackedScene.hpp>

namespace godot {
    /** TODO: build this
     * 
     */


    /**
     * class for each block, inheriting 4 triangles
     */
    class Block : public Node2D {
        GODOT_CLASS(Block, Node2D);
        // TODO: define dynamic array of Blocks
        public:
            static void _register_methods();

            Block();
            ~Block();

            void init(Vector2);
            void _init();
            void _ready();
            void _process(float delta);
            String block_types[2];
	private:
		Ref<PackedScene> BlockTriangleScene;
    };
}
#endif