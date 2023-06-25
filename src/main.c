
#include "push_swap.h"

int error_handling(int argc, char **argv)
{
    int i;

if (argc == 1 || argv[2])
    return (1);
i=0;
while (argv[1][i])
{
    if (!(argv[1][i] >= '0' && argv[1][i] <= '9') && argv[1][i] != ' ')
        return (1);
    i++;
}
return (0);
}

int main(int argc, char **argv)
{
    if (error_handling(argc, argv))
    {
        write(2, "Error\n", 6);
        return (1);
    }
    ft_printf("good :)\n");
    return (0);
}
