extends Node2D

# Declare member variables here. Examples:
# var a = 2
# var b = "text"

# Called when the node enters the scene tree for the first time.
func _ready():
	print($Triangle.t_method())
	print($Block.b_method())
	print($Grid.set_grid_size(10))
	print($Grid.get_grid_size())
	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
