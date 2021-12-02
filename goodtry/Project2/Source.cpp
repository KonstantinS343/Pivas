#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
 int inf = 10000;

vector<vector<pair<int, int>>> graph;
int v,j;

int main() {
    bool d = true,g=true;
    int n,  l, u = 0, k = 0,edge;
    char uslov;
    string str;
    string file;
    vector<int> radius;
    cout << "The graph is weighted - 1;\nThe graph is unweighted - 2;\n";
    cin >> uslov;
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
            k = 0;
             for (int j = 0; j < n; j++) {
                fin >> str;
                file = str;
               
                if (str == ";") {
                    break;
                }
                graph.at(i).resize(j+1);
                u = stoi(str);
                u--;
                fin >> str;
                file = str;
                
                edge = stoi(str);
                if (uslov == '2') {
                    edge = 1;
                }
                graph.at(i).at(k).first = u;
                graph.at(i).at(k).second = edge;
                k += 1;
                
                
            }
        }
    }
    fin.close();
    k = 0;
    cout << endl;
    cout << "The adjacency list:\n---------------\n";
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < graph.at(i).size(); j++) {
            cout << graph.at(i).at(j).first+1  << " ";
           }
        cout << ";";
        cout << std::endl;
    }
    cout << "-----------------\n";
    int s=0,sizec=1;
    int index;
    vector <bool> used(n );
    vector<int> dest(n );
    for (int i = 0; i < n ; i++) {
        dest[i] = inf;
    }
    for (int vert = 0; vert < n; vert++) {
        dest[vert] = 0;
        vector<int> change(1);
        
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

                int to = graph[index][cou].first;

                int len = graph[index][cou].second;

                if (dest[index] + len <dest[to]) {
                    dest[to] = dest[index] + len;
                }

               
                for (int counter = 0; counter < sizec; counter++) {
                    if (to == change[counter]) {
                        
                        
                        break;
                    }
                    if (to != change[counter]) {
                        if(counter==(sizec-1)){
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
    int min = radius[0];
    for (int minimum = 0; minimum < radius.size(); minimum++) {
        if (min > radius[minimum]) {
            min = radius[minimum];
        }
    }
    cout << "The radius is:";
    cout << min;
}
