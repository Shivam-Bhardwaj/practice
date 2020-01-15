#include <stdio.h>
void slogan();
int main()
{
    int c = 5;
    c = slogan();
    printf("\n%d", c);
    return 0;
}

void slogan( )
{
    printf("\n Only the best use C!");
}