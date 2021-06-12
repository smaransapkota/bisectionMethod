#include <stdio.h>
#include <math.h>
#define f(x) 2 * x *x *x - 5
void main()
{
    float xu, xl, xm, fu, fl, fm, e;
    int iter = 1;
up:
    printf("Enter Two Guess:\n");
    scanf("%f%f", &xu, &xl);
    printf("Enter Tolorable Error:\n");
    scanf("%f", &e);
    fu = f(xu);
    fl = f(xl);
    printf("fu = %f\nfl= %f", fu, fl);
    if (fu * fl > 0.0)
    {
        printf("\nSign are not opposite so the guess is incorrect.\n");
        goto up;
    }
    printf("\nIteration\t\txu\t\txl\t\txm\t\tf(xm)\n");
    do
    {
        xm = (xu + xl) / 2;
        fm = f(xm);
        printf("%d\t\t%f\t%f\t%f\t%f\n", iter, xu, xl, xm, fm);
        if (fu * fm < 0)
        {
            xl = xm;
            fl = fm;
        }
        else
        {
            xu = xm;
            fu = fm;
        }
        iter = iter + 1;
    } while (fabs(fm) > e);
    printf("\nRoot is: %f", xm);
}