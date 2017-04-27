.name "test st ld too long"
.comment "Args (%513) must roll on idx_mod and became %1"

ld 513, r2
st r2, 559
