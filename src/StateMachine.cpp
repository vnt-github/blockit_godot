#include "StateMachine.h"

using namespace godot;

void StateMachine::_register_methods() {
	register_method("_ready", &StateMachine::_ready);
	register_method("_init", &StateMachine::_init);
	
	register_method("_set_state", &StateMachine::_set_state);
	register_method("_state_logic", &StateMachine::_state_logic);

	register_method("_get_transition", &StateMachine::_get_transition);

	register_method("_enter_state", &StateMachine::_enter_state);
	register_method("_exit_state", &StateMachine::_exit_state);

	register_method("_process", &StateMachine::_process);
	register_method("_physics_process", &StateMachine::_physics_process);

	register_method("_init_states", &StateMachine::_init_states);

}

void StateMachine::_init_states(PoolStringArray states) {
	for(int i = 0; i < states.size(); i++)
	{
		_states[states[i]] = i;
	}
}

void StateMachine::print_states() {
	//Array keys = _states.keys();
	//Godot::print("_states size");
	//Godot::print(keys[0]);
	//Godot::print("---------");
	Array keys = _states.keys();
	Array values = _states.values();
	for (int i = 0; i < keys.size(); i++) {
		Godot::print("key");
		Godot::print(keys[i]);
		Godot::print("value");
		Godot::print(values[i]);
	}
}

StateMachine::StateMachine() {}
StateMachine::~StateMachine() {}

void StateMachine::_ready() {
	parent = get_parent();
}

void StateMachine::_init() {}

void StateMachine::_set_state(int new_state) {
	previous_state = state;
	if (!previous_state) return;
	_exit_state(previous_state, new_state);

	if (!new_state) return;
	_enter_state(new_state, previous_state);
}

void StateMachine::_state_logic(float delta) {
	String log = String("base _sate_logic called with delta");
	Godot::print(log);
};

int StateMachine::_get_transition(float delta) {
	return state;
}

void StateMachine::_enter_state(int new_state, int old_state) {

}

void StateMachine::_exit_state(int old_state, int new_state) {

}

void StateMachine::_physics_process(float delta) {

}

void StateMachine::_process(float delta) {
	if (!state) return;
	
	_state_logic(delta);
	int transition = _get_transition(delta);

	if (!transition) return;
	
	_set_state(transition);

}