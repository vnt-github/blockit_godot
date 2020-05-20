extends Node2D

onready var gameScene = preload("res://Game.tscn")

func _ready():
	# # RESOLVED: QUERY: difference between theses two: https://oneshotrpg.com/tutorial/werewolf-style-game/dollar-sign-vs-get-node/
	# var test = load("res://grid/Grid.gdns").new()
	# # this loads the Grid.gdns as resource and .new() instantiates it and then calls get_block on this instance
	# print(test.get_block(1,2))
	# yield(get_tree().create_timer(5.0), "timeout")
	
	var game = gameScene.instance()
	game.init(3, 4);
	add_child(game);
	
	# yield(get_tree().create_timer(5.0), "timeout")
	
	# yield(get_tree().create_timer(2.0), "timeout")
	# game.init(1, 2);
	# this just calls get_block on already instanced child node of game_windows, gw_grid_child
	# print($gw_grid_child.get_block(1,2))
	# print(get_node("gw_grid_child").get_block(1, 2));
	# var grid = gridScene.instance()
	# add_child(grid)
	# grid.init(2, 2)
	# remove_child(game)
	# game.queue_free()
	# var game2 = gameScene.instance()
	# game2.init(3,4)
	# add_child(game2)
	

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
