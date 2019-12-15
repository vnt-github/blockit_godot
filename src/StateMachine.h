#pragma once

#include <Godot.hpp>
#include <Node2D.hpp>
#include <map>
#include <iterator>
#include <vector>

namespace godot {

	/**
	abstract class for state machine meant to be inherited to facilitate state management.

	provides interface for parent with the basic state specific function
	and tells parent what action to perform next
	*/
	class StateMachine : public Node2D {
		GODOT_CLASS(StateMachine, Node2D);
	public:
		// Game states
		static void _register_methods();

		StateMachine();
		~StateMachine();


		void _init();
		void _ready();

		void _init_states(PoolStringArray);

		// call to change state which in turn calls other functions
		void _set_state(int new_state);

		void _physics_process(float delta);

		void _process(float delta);

		void print_states();

	private:
		Dictionary _states;
		Variant parent;
		int state = 0;
		int previous_state = 0;


		// state specific logic called in *_process methods
		virtual void _state_logic(float delta);

		// state transitions called in *_process methods
		int _get_transition(float delta);

		// state initiation logic
		void _enter_state(int new_state, int old_state);

		// state cleanup logic
		void _exit_state(int old_state, int new_state);
	};
};