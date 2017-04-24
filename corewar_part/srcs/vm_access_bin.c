#include "vm.h"

int				vm_pc(t_vm *vm, int pc)
{
	return (((pc % vm->gconfig.mem_size) + \
				(pc < 0 ? vm->gconfig.mem_size : 0)));
}

unsigned char	bin_access(t_vm *vm, int pc)
{
	return (vm->memory[vm_pc(vm, pc)]);
}

unsigned char	*bin_access_w(t_vm *vm, int pc)
{
	return (vm->memory + vm_pc(vm, pc));
}

char			bin_char(t_vm *vm, int pc)
{
	return ((char)bin_access(vm, pc));
}
