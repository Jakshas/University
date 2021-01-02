double wyr=1;
double sum=0;

for (double i = 2.0; wyr> Math.pow(10,-10); i++)
{
    wyr= 1.0/(Math.pow(i,2));
    sum = sum + wyr;
}
