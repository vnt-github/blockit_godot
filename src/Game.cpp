#include "Game.h"
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include "grid.h"
#include "block.h"

using namespace godot;

void Game::_register_methods() {
    register_method("_init", &Game::_init, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("_ready", &Game::_ready, GODOT_METHOD_RPC_MODE_DISABLED);
    register_method("init", &Game::init, GODOT_METHOD_RPC_MODE_DISABLED);
	register_method("_on_finished", &Game::_on_finished, GODOT_METHOD_RPC_MODE_DISABLED);
	register_signal<Game>("state_changed", "turn", GODOT_VARIANT_TYPE_INT);
}

void Game::_init() {
    ResourceLoader* resourceLoader = ResourceLoader::get_singleton();
    GridScene = resourceLoader->load("res://grid/Grid.tscn");
    BlockScene = resourceLoader->load("res://block/Block.tscn");
	PoolStringArray states;
	states.append("first_turn");
	states.append("black_turn");
	states.append("white_turn");
	states.append("black_override");
	states.append("white_override");
	_init_states(states);

	// grid->_rows = 4;
	// grid->_columns = 4;
}

void Game::_ready() {
	Godot::print("=============Game _ready============");
	Godot::print(String::num(grid_rows));
	Godot::print(String::num(grid_columns));
	//godot::Grid* grid = Object::cast_to<godot::Grid>(GridScene->instance());
	godot::Grid* new_grid = godot::Grid::_new();
	new_grid->init(grid_rows, grid_columns);
	add_child(new_grid);
	Array childrens = new_grid->get_children();
	for (int i = 0; i < childrens.size(); i++)
	{
		Godot::print("children");
		Godot::print(childrens[i]);
	}
	
	print_states();
}

void Game::init(int rows, int columns) {
    Godot::print("Game init grid init");
    grid_rows = rows;
    grid_columns = columns;
	// grid->_rows = 2;
	// grid->_columns = 2;    
    //int rows=2;
    //int columns=2;
    //add_child(grid);
    //grid->init(rows, columns);
    //grid->set_position(Vector2(x, y));
    // // TODO: call grid.init here

    // godot::Block* block = Object::cast_to<godot::Block>(BlockScene->instance());
    // add_child(block);
    // block->set_position(Vector2(x, y));

}

Game::Game()
{

}

Game::~Game()
{

}


void Game::change_turn(int first_move) {
	if (state == (int)_states["first_turn"] || !state) {
		Godot::print("null state");
		Godot::print(String::num(state));
		switch (first_move)
		{
		//for the black turn
		case 1:
			state = (int)_states["white_turn"];
			break;
		//for the white turn
		case 2:
			state = (int)_states["black_turn"];
			break;
		}
	}
	else if (state == (int)_states["black_turn"]) {
		Godot::print("black current_state");
		Godot::print(String::num(state));
		state = (int)_states["white_turn"];
	}
	else if (state == (int)_states["white_turn"]) {
		Godot::print("white current_state");
		Godot::print(String::num(state));
		state = (int)_states["black_turn"];
	}
	emit_signal("state_changed", state);
}


void Game::_on_finished(int first_move) {
	Godot::print("game _on_finished override");
	change_turn(first_move);
}