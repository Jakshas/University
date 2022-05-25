// Jakub Szajner 315700
#include "router.h"

void write_table(vector<Network> *vect){
    for (auto &&v1 : *vect){
        if (v1.route != "D" && v1.distance == UINT32_MAX)
        {
            continue;
        }
        cout << to_string(v1.ip[0])+'.'+to_string(v1.ip[1])+'.'+to_string(v1.ip[2])+'.'+to_string(v1.ip[3])+'/'+to_string(v1.ip[4]);
        if (v1.reachable)
        {
            cout <<" distance "<< v1.distance;
        }else{
            cout <<" unreachable";
        }
        
        if (v1.route == "D")
        {            
            cout << " connected directly"<< endl;
        }else{
            cout << " via " << v1.route << endl;
        }
    }
    cout << endl;
}

void delete_disabled(vector<Network> *vect){
    for (size_t i = 0; i < vect->size(); i++)
    {
        if ((vect->at(i).route != "D" && chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - vect->at(i).last_recived).count() >= 15) )
        {
            vect->erase(vect->begin()+i);
            i--;
        }
    }
}

void load(char const *argv[], vector<Network> *vect){
    int n;
    ifstream MyReadFile(argv[1]);
    MyReadFile >> n;
    for (int i = 0; i < n; i++)
    {
        string ip, d;
        int distance;
        MyReadFile >> ip;
        MyReadFile >> d;
        MyReadFile >> distance;
        Network net(get_network(convert_ip(ip)),distance);
        net.last_recived = chrono::steady_clock::now();
        vect->push_back(net);
        
    }
}

bool find_in_vector(vector<Network> *vect, unsigned char * ip){
    for (auto &&v : *vect)
    {
        bool flag = true;
        for (int i = 0; i < 4; i++)
        {
            if (v.ip[i] != ip[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return true;
        }
    }
    return false;
}