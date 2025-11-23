// generally avoid goto statements (theyre just jump (jne) statements in assembly)

#include <iostream>

int main()
{
    for (int i = 1; i < 5; ++i)
    {
        for (int j = 1; j < 5; ++j)
        {
            std::cout << i << " * " << j << " = " << i * j << '\n';

            if ((i * j) % 9 == 0)
            {
                std::cout << "leaving both loops but not the function\n";
                goto end_loop;
            }
        }
    }

    end_loop:
    std::cout << "we have left both loops, break would have left inner loop, and "
    "return would not have run this following code so in that case goto is useful"
    " but this is like actually the only usecase for this really bad method thats old";

    return 0;
}