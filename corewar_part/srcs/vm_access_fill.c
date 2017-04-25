#include "vm.h"

void			fill_args(t_instruction *ins, t_vm *vm, int pc, int label_size)
{
	unsigned char	ocp;

	ins->nb_arg = 0;
	ocp = ins->ocp;
	while (ocp && ins->nb_arg < 3)
	{
		ins->size += dispatch_access(ocp)\
						(ins->args + ins->nb_arg, vm, &pc, label_size);
		ins->nb_arg += 1;
		ocp <<= 0x2;
	}
}

int				fill_reg(t_insarg_i *arg, t_vm *vm, int *pc, int label_size)
{
	arg->type = reg_arg;
	arg->value = read_char(vm, pc);
	return (1);
	(void)label_size;
}

int				fill_ind(t_insarg_i *arg, t_vm *vm, int *pc, int label_size)
{
	arg->type = ind_arg;
	arg->value = read_short(vm, pc);
	return (2);
	(void)label_size;
}

int				fill_dir(t_insarg_i *arg, t_vm *vm, int *pc, int label_size)
{
	arg->type = dir_arg;
	if (label_size == 4)
		arg->value = read_int(vm, pc);
	else
		arg->value = read_short(vm, pc);
	return (label_size);
}

int				fill_null(t_insarg_i *arg, t_vm *vm, int *pc, int label_size)
{
	(void)arg;
	(void)vm;
	(void)pc;
	(void)label_size;
	return (0);
}
