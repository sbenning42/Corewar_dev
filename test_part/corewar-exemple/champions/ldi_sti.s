.name "test sti ldi"
.comment "Dump memory after 50 cycles"

load:

ldi %:load, %1, r2
sti r2, %:store, %42

store:
