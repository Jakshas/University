#include <iostream>
#include <ratio>
using namespace std;

typedef ratio<1,1> jeden;
typedef ratio_add<jeden,ratio<1,2>> dwa;
typedef ratio_add<dwa,ratio<1,3>> trzy;
typedef ratio_add<trzy,ratio<1,4>> cztery;
typedef ratio_add<cztery,ratio<1,5>> piec;
typedef ratio_add<piec,ratio<1,6>> szesc;
typedef ratio_add<szesc,ratio<1,7>> siedem;
typedef ratio_add<siedem,ratio<1,8>> osiem;
typedef ratio_add<osiem,ratio<1,9>> dziewiec;
typedef ratio_add<dziewiec,ratio<1,10>> dziesiec;
typedef ratio_add<dziesiec,ratio<1,11>> jedenascie;
typedef ratio_add<jedenascie,ratio<1,12>> dwanascie;
typedef ratio_add<dwanascie,ratio<1,13>> trzynascie;
typedef ratio_add<trzynascie,ratio<1,14>> czternacie;
typedef ratio_add<czternacie,ratio<1,15>> pietnascie;
typedef ratio_add<pietnascie,ratio<1,16>> szesnascie;
typedef ratio_add<szesnascie,ratio<1,17>> siedemnascie;
typedef ratio_add<siedemnascie,ratio<1,18>> osiemnascie;
typedef ratio_add<osiemnascie,ratio<1,19>> dziewietnascie;
typedef ratio_add<dziewietnascie,ratio<1,20>> dwadziescia;

int main(int argc, char const *argv[])
{   
    cout<<dwadziescia::num<<"/"<<dwadziescia::den;
}