#include <iostream>
#include <stdlib.h>
#include <cstring>

void Usage()
{
    std::cout << "Usage: dummy --help" << std::endl;
}

int main(int argc, char **argv, char **env)
{
    std::cout << "Hello, world!" << std::endl;

    for (int i = 0; i < argc; ++i)
    {
        if (strcmp(argv[i], "--help") == 0 )
        {
            Usage();
        }
        else
        {
            std::cout << "argv #" << i << " = [" << argv[i] << "]" << std::endl;
        }
    }

    size_t n = 10;//sizeof(env) / sizeof(char *);
    for (size_t i = 0; i < n; ++i)
    {
        std::cout << "envvar #" << i << " = [" << env[i] << "]" << std::endl;
    }
    return 0;
}
