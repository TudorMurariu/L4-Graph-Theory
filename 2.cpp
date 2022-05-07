#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
using namespace std;

int l,n;
deque<int> cod;

struct nod{
    int pre;
};

nod v[100001];

int get_min()
{
    bool fr[cod.size() + 1] = {0};
    for(auto &i: cod)
        fr[i] = 1;

    for(int i=0;i <= cod.size();i++)
        if(fr[i] == 0)
            return i;
    return -1;
}

void decodare()
{
    for(int i=0;i<l;i++)
    {
        int y = get_min();
        int x = cod.front();
        //cout << y << " " << x << endl;
        v[y].pre = x;
        cod.pop_front();
        cod.push_back(y);
    }
}

int main()
{
    ifstream f("input.txt");

    f >> l;
    n = l+1;
    for(int i=0;i<l;i++)
    {
        int x;
        f >> x;
        cod.push_back(x);
    }

    for(int i=0;i<n;i++)
        v[i].pre = -1;

    decodare();

    cout << n << endl;
    for(int i=0;i<n;i++)
        cout << v[i].pre << " ";

    return 0;
}
