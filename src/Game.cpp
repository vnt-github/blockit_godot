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
	grid = static_cast<godot::Grid*>(GridScene->instance());
	grid->_rows = 4;
	grid->_columns = 4;
}

void Game::_ready() {
	print_states();
	add_child(grid);
	grid->_rows = 3;
	grid->_columns = 3;
}

void Game::init() {
    int rows = 3;
	int columns = 4;
    Godot::print("Game init grid init");
	grid->_rows = 2;
	grid->_columns = 2;
    grid->init(rows, columns);
    
    //godot::Grid* grid = static_cast<godot::Grid*>(GridScene->instance());
    //int rows=2;
    //int columns=2;
    //add_child(grid);
    //grid->init(rows, columns);
    //grid->set_position(Vector2(x, y));
    // // TODO: call grid.init here

    // godot::Block* block = static_cast<godot::Block*>(BlockScene->instance());
    // add_child(block);
    // block->set_position(Vector2(x, y));

}

Game::Game()
{

}

Game::~Game()
{

}