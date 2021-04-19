using namespace std;

void pierwiastek(int a,int b){

    int i = 2;
    while (a!=0)
    {
        if (((double)a)/((double)a)>(1.0/((double)i)))
        {
            a = (a * i) - b;
            b = b*i;
        }
        i++;
    }
    
}

int main(int argc, char const *argv[])
{
    pierwiastek(5,6);
    return 0;
}

