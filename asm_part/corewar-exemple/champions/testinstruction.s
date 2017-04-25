.name "test"
.comment "teeeeeeeeeest"

live:
	live	%42
	live	%:live

ld:
	ld		%42, r1
	ld		%:ld, r2
	ld		:ld, r3
	ld		42, r4

st:
	st		r5, r6
	st		r7, 42
	st		r8, :st

add:
	add		r9, r10, r11
	
sub:
	sub		r12, r13, r14

and:
	and		r15, r16, r1
	and		r1, %42, r2
	and		r1, %:xor, r2
	and		r1, 42, r2
	and		r1, :xor, r2
	and		%42, r2, r3
	and		%:xor, r2, r3
	and		42, r2, r3
	and		:xor, r2, r3
	and		%:xor, %-42, r16
	and		%42, -42, r16

or:
	or		r15, r16, r1
	or		r1, %42, r2
	or		r1, %:or, r2
	or		r1, 42, r2
	or		r1, :or, r2
	or		%42, r2, r3
	or		%:or, r2, r3
	or		42, r2, r3
	or		:or, r2, r3
	or		%:or, %-42, r16
	or		%42, -42, r16

xor:
	xor		r15, r16, r1
	xor		r1, %42, r2
	xor		r1, %:and, r2
	xor		r1, 42, r2
	xor		r1, :and, r2
	xor		%42, r2, r3
	xor		%:and, r2, r3
	xor		42, r2, r3
	xor		:and, r2, r3
	xor		%:and, %-42, r16
	xor		%42, -42, r16

zjmp:
	zjmp	%42
	zjmp	%:zjmp

ldi:
	ldi		r1, r2, r3
	ldi		r1, %-42, r3
	ldi		r1, %:ldi, r3
	ldi		%42, r2, r3
	ldi		%:ldi, %:ldi, r3
	ldi		:ldi, r2, r3
	ldi		-42, %-42, r3

sti:
	sti		r1, r2, r3
	sti		r1, r2, %42
	sti		r1, %:sti, %-42
	sti		r1, %42, r4
	sti		r1, r2, %:sti
	sti		r16, r2, %42
	sti		r16, %:sti, %-42
	sti		r16, %42, r4
	sti		r16, r2, %:sti

fork:
	fork	%42
	fork	%:fork

aff:
	aff		r16
