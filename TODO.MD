- [ ] can i make a parent triangle class with conditional black and white asset loaded
- [ ] networking design? single server or peer to peer hosting and joining
- [ ] the cross 2 triangle block is not readily intuitive
    - [ ] smaller block seperating borders
- [ ] make sure to add comments everywher for easier future understanding
- [ ] hearthstone server and online setup
- [ ] finish candy crush godot tutorial
- [ ] finish ntw cpp gdnative tutorial
- [ ] figure out nested packed scene how to do
- [x] triangle texture button bit mask
    - [a] https://godotengine.org/qa/26137/texturebutton-wont-allow-png-mask: select the triangle.png click the import tab and import as bitmap and use the alpha and threshold(for 1 and 0 bit i guess) anything < 1
- [ ] blocks dynamic triangles array and spawn
    - [ ] mostly error caused due to mismatch of class inheritence etc.
- [ ] setup gdnative cpp debugger for unix socket error
    - [ ] try setting up mvs debugger thread like in c++ maze tutorial series.


- [ ] triangle button not disabled
    - [1] get parent block [black|white]
    - [2] get turn [black|white]
        - [ ] if 1 == 2 

- [ ] triangle placed handling
    - [ ] black or white
    - [ ] triangle state record
        - [ ] is_occupied_by: [none|black|white]
            - [ ] if !is_occupied_by disable: false
            - [ ] else: disabled: true
        - [ ] on succesfull state update emit randomize grid blocks

- [1] equi distribute blocks
- [2] implement state based turn system
- [2] make the logic for triangles detection block geometry agonstic to extend gameplay to non square grids
	- [ ] polyit => blockit with regular polygons made up of triangles
