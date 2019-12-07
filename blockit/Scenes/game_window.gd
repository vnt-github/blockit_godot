extends Node2D

# Declare member variables here. Examples:
# var a = 2
# var b = "text"

# Called when the node enters the scene tree for the first time.
func _ready():
	# RESOLVED: QUERY: difference between theses two: https://oneshotrpg.com/tutorial/werewolf-style-game/dollar-sign-vs-get-node/
	var test = load("res://Scenes/Grid.gdns").new()
	# this loads the Grid.gdns as resource and .new() instantiates it and then calls get_block on this instance
	print(test.get_block(1,2))
	# this just calls get_block on already instanced child node of game_windows, gw_grid_child
	print($gw_grid_child.get_block(1,2)) or print(get_node("gw_grid_child").get_block(1, 2));
	

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
