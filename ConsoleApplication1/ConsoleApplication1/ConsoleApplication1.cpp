#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
int inf = 10000;

vector<vector<int>> graph;
int v, j;
vector<vector<int>> dlina(vector<vector<int>> graph,int k,int n) {
    vector<int> index;
    int len = 1;
    vector<int> dlina;
    vector<bool> used;
    index.push_back(k-1);
    for (int i = 0; i < graph.size(); i++) {
        dlina[i] = 0;
    }
    for (int i = 0; i < graph.size(); i++) {
        int vert = index[i];
        used[i] = true;
        if (used[i] == true) {
            continue;
        }
        for (int j = 0; j < graph[i].size(); j++) {
            if (size(graph.at(i)) == 0) {
                break;
            }
            int to = graph.at(i).at(j);
            if (dlina[i] + len > dlina[to]) {
                dlina[to] = dlina[i] + len;
            }

        }
    }
}
int main() {
    setlocale(0, "ru");
    bool d = true, g = true;
    int n, l, u = 0, k = 0, edge;
    char uslov;
    string str;
    string file;
    vector<int> radius;
    string path = "file.txt";
    ifstream fin;
    fin.open(path);
    if (!fin.is_open()) {
        return 0;
    }
    else {
        fin >> str;
        n = stoi(str);
        graph.resize(n);
        for (int i = 0; i < n; i++) {
            fin >> str;

            for (int j = 0; j < n; j++) {
                fin >> str;
                file = str;

                if (str == ";") {
                    break;
                }
         
                u = stoi(str);
                u--;
                graph.at(i).push_back(u);


            }
        }
    }
    fin.close();
    k = 0;
    cout << endl;
    int s = 0, sizec = 1;
    int index;
    vector <bool> used(n);
    vector<int> dest(n);
    for (int i = 0; i < n; i++) {
        dest[i] = inf;
    }
    int len = 1;
    for (int vert = 0; vert < n; vert++) {
        dest[vert] = 0;
        vector<int> change(1);
        if (size(graph.at(vert)) == 0) {
            break;
        }
        sizec = 1;
        index = 0;
        change[0] = vert;
        int ch = 0;
        for (int i = 0; i < graph.size(); i++) {
            index = change[i];

            used[index] = true;
            for (int cou = 0; cou < graph.at(index).size(); cou++) {
                if (size(graph.at(i)) == 0) {
                    break;
                }

                int to = graph[index][cou];


                if (dest[index] + len < dest[to]) {
                    dest[to] = dest[index] + len;
                }


                for (int counter = 0; counter < sizec; counter++) {
                    if (to == change[counter]) {


                        break;
                    }
                    if (to != change[counter]) {
                        if (counter == (sizec - 1)) {
                            change.resize(sizec + 1);
                            sizec++;
                            ch++;
                            change[ch] = to;
                            break;
                        }
                    }


                }

            }
        }
        int max = dest[0];
        for (int maximum = 0; maximum < n; maximum++) {
            if (max < dest[maximum]) {
                max = dest[maximum];

            }
        }
        radius.push_back(max);
        for (int i = 0; i < n; i++) {
            dest[i] = inf;
        }
    }
    for (int i = 0; i < radius.size(); i++) {
        cout << radius[i];
        cout << " ";
    }
    int min = radius[0];
    for (int minimum = 0; minimum < radius.size(); minimum++) {
        if (min > radius[minimum]) {
            min = radius[minimum];
        }
    }
    cout << min;
    vector <int> center;
    for (int i = 0; i < radius.size(); i++) {
        if (radius[i] == min) {
            center.push_back(i);
        }
    }
    cout << "\nЦентрами являются вершины:";
    for (int i = 0; i < center.size(); i++) {
        cout << center[i] + 1 << " ";
    }

    bool again=true;
    while (again == true) {
        cout << "\nВыберите два центра:";
        cin >> k;
        cin >> n;
         dlina(graph,k,n);
         cout << "Хотите ввести ещё вершины?";
        cin >> uslov;
        if (uslov == 'n') {
            again = false;
        }
    }
}