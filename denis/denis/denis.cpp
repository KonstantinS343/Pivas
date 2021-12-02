#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
int inf = 10000;

vector<vector<int>> graph;
int v, j;
vector<bool> useds(1000);
int len = 1;
void dlina(vector<vector<int>> graph, int k, int n) {
    bool check = false;
    vector<int> vert;
    int y = 0;
    vector<int> dest(graph.size());
    for (int i = 0; i < graph.size(); i++) {
        dest[i] = 0;
    }
    vert.push_back(k);
    for (int i = 0; i < graph.size();i++) {
        int index = vert[i];
        dest[k] = 0;
        for (j = 0; j < graph[index].size(); j++) {
            int to = graph[index][j];
            if (dest[index] + len > dest[to] && index!=n ) {
                dest[to] = dest[index] + len;
            }

            
             for (int counter = 0; counter <vert.size() ; counter++) {
                if (to == vert[counter] ) {


                    break;
                }
                if (to != vert[counter]) {
                    if (counter == (vert.size() - 1)) {
                       vert.push_back(to);
                       
                        
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < graph.size(); i++) {
        cout <<dest[i] << " ";
    }
    cout << "\n" << dest[n];
   /* cout << k<<" ";
    for (int i = 0; i < graph.size(); i++) {
        for (j = 0; j < graph[k].size(); j++) {
            if (find(graph[k].begin(), graph[k].end(), i) != graph[k].end()) {
                check = true;
            }
       }
        if (!useds[i] && check) {
            dlina(graph, i, n);
        }
    }*/
    /*cout << "Максимальное расстояние равно:" << ;*/
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

    bool again = true;
    while (again == true) {
        cout << "\nВыберите два центра:";
        cin >> k;
        cin >> n;
        dlina(graph, k-1, n-1);
        cout << "\nХотите ввести ещё вершины?(y/n)";
        cin >> uslov;
        if (uslov == 'n') {
            again = false;
        }
    }
}