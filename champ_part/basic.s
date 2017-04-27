.name "BhQsSb"
.comment "BhQsSb is a basic prog"


entry:
	sti r1, %:live0, %1
	sti r1, %:live1, %1
	sti r1, %:live2, %1
	sti r1, %:live3, %1
	sti r1, %:live4, %1
	sti r1, %:live5, %1
	sti r1, %:live6, %1
	sti r1, %:live7, %1
	sti r1, %:live8, %1
	sti r1, %:live9, %1
	sti r1, %:live10, %1
	sti r1, %:live11, %1
	sti r1, %:live12, %1
	sti r1, %:live13, %1
	sti r1, %:live14, %1
	sti r1, %:live15, %1
	sti r1, %:live, %1
live: live %42
	sti r1, %:live16, %1
	sti r1, %:live17, %1
	sti r1, %:live18, %1
	sti r1, %:live19, %1
	sti r1, %:live20, %1
	sti r1, %:live21, %1
	sti r1, %:live22, %1
	sti r1, %:live23, %1
	sti r1, %:live24, %1
	sti r1, %:live25, %1
	sti r1, %:live26, %1
	sti r1, %:live27, %1
	sti r1, %:live28, %1
	sti r1, %:live29, %1
	sti r1, %:live30, %1

live0: live %42
live1: live %42
live2: live %42
live3: live %42
live4: live %42
live5: live %42
live6: live %42
live7: live %42
live8: live %42
live9: live %42
live10: live %42
live11: live %42
live12: live %42
live13: live %42
live14: live %42
live15: live %42
live16: live %42
live17: live %42
live18: live %42
live19: live %42
live20: live %42
live21: live %42
live22: live %42
live23: live %42
live24: live %42
live25: live %42
live26: live %42
live27: live %42
live28: live %42
live29: live %42
live30: live %42

fork:
	fork %:entry
	add r2, r2, r2
	zjmp %300
