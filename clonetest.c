
// void
// printf(int fd, const char *s, ...)
// {
//   write(fd, s, strlen(s));
// }

// int stack[4096] __attribute__ ((aligned (4096)));
// int main(int argc, char *argv[])
// {
//     printf(1, "Stack ", stack);
//     int tid = clone(stack, NULL, NULL, NULL);
//     if (tid < 0)
//     {
//         printf(2, "Error!\n");
//     }
//     else if (tid == 0)
//     {

//     }
//     else
//     {

//     }
//     exit();
// }