#include "vm.h"

int		vm_h_opc_tool(t_vm *vm, t_process *p, \
									t_instruction *ins, int err)
{
	if (err)
	{
		vm_pc_move(vm, p, ins, 0);
		return (1);
	}
	return (0);
}
