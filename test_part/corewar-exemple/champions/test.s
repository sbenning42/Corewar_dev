#by zaz, still not as good as rainbowdash though
#2013

.name		"Test"
.comment	"teeeeeeeeeest !"

	st		r2, :entry
entry:
	sti		r1, %:beegees_gen, %16
	sti		r1, %:beegees, %1
	live	%4239423
	st		r2, 15
	ld		%-6, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16

beegees_gen:
	live	%4239423
	live	%4239423
	fork	%:beegees_gen

beegees:
	zjmp	%:beegees_gen
	aff		r16

