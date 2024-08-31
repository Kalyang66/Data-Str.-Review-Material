#include<iostream>
#include<stack>
#include<queue>
#include<fstream>
using namespace std;

struct vertex{
    int value;
    vertex *next;
};
void DFS(vertex *arr[], int source, int n){
    stack<int> s; // Initialize stack
    bool *visited = new bool[n]; // Initialize visited array
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    s.push(source);
    int v;
    int next;
    vertex *curr = nullptr;
    while(!s.empty()){ // Perform DFS
        v = s.top();
        s.pop();
        if(!visited[v]){
            cout << v << " ";
            visited[v] = true;
        }
        curr = arr[v];
        while(curr != nullptr){ // Push adjacent vertices to stack
            next = curr->value;
            if(!visited[next]){
                s.push(next);
            }
            curr = curr->next;
        }
    }
    cout << endl;
    delete [] visited;
}

void DFS(int **graph, int source, int n){
    stack<int> s; // Initialize stack
    bool *visited = new bool[n]; // Initialize visited array
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    s.push(source);
    while(!s.empty()){ // Perform DFS
        int v = s.top();
        s.pop();
        if(!visited[v]){
            cout << v << " ";
            visited[v] = true;
        }
        for(int i = 0; i < n; i++){ // Push adjacent vertices to stack
            if(graph[v][i] != 0 && !visited[i]){
                s.push(i);
            }
        }
    }
    cout << endl;
    delete [] visited;
}

void BFS(vertex *arr[], int source, int n){
    queue<int> q; // Initialize queue
    bool *visited = new bool[n]; // Initialize visited array
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    q.push(source);
    int v;
    int next;
    vertex *curr = nullptr;
    while(!q.empty()){ // Perform BFS
        v = q.front();
        q.pop();
        if(!visited[v]){
            cout << v << " ";
            visited[v] = true;
        }
        curr = arr[v];
        while(curr != nullptr){ // Push adjacent vertices to queue
            next = curr->value;
            if(!visited[next]){
                q.push(next);
            }
            curr = curr->next;
        }
    }
    cout << endl;
    delete [] visited;
}


void BFS(int **graph, int source, int n){
    queue<int> q; // Initialize queue
    bool *visited = new bool[n]; // Initialize visited array
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    q.push(source);
    int v;
    while(!q.empty()){ // Perform BFS
        v = q.front();
        q.pop();
        if(!visited[v]){
            cout << v << " ";
            visited[v] = true;
        }
        for(int i = 0; i < n; i++){ // Push adjacent vertices to queue
            if(graph[v][i] != 0 && !visited[i]){
                q.push(i);
            }
        }
    }
    cout << endl;
    delete [] visited;
}

void DFS(int **graph, int source, int n){
    stack<int> s; // Initialize stack
    bool *visited = new bool[n]; // Initialize visited array
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    s.push(source);
    while(!s.empty()){ // Perform DFS
        int v = s.top();
        s.pop();
        if(!visited[v]){
            cout << v << " ";
            visited[v] = true;
        }
        for(int i = 0; i < n; i++){ // Push adjacent vertices to stack
            if(graph[v][i] != 0 && !visited[i]){
                s.push(i);
            }
        }
    }
    cout << endl;
    delete [] visited;
}

void insertVertex(vertex *arr[], int x, int y){
    vertex *v = new vertex;
    v->value = y;
    v->next = nullptr;
    if(arr[x] ==  nullptr){
        arr[x] = v;
    }
    else{
        vertex *curr = arr[x];
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = v;
    }
}

int main(){

    ifstream input("input.txt");
    int x = 0;

    vertex *arr[9];
    for(int i = 0; i < 9; i++){
        arr[i] = nullptr;
    }

    int n = 9;
    int source = 0;
    int **graph = new int*[n];
    for(int i = 0; i < n; i++){
        graph[i] = new int[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            graph[i][j] = 0;
        }
    }

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            input >> x;
            graph[i][j] = x;
            if(x == 1){
                insertVertex(arr, i, j);
            }
        }
    }

    cout << "\nBreadth First Search (Adjacency Matrix) starting from vertex 0:" << endl;
    BFS(graph, source, n);

    cout << "\nBreadth First Search (Adjacency List) starting from vertex 0:" << endl;
    BFS(arr, source, n);
    
    cout << "\nDepth First Search (Adjacency Matrix) starting from vertex 0:" << endl;
    DFS(graph, source, n);

    cout << "\nDepth First Search (Adjacency List) starting from vertex 0:" << endl;
    DFS(arr, source, n);

    for(int i = 0; i < n; i++){
        delete [] graph[i];
    }
    delete [] graph;

    return 0;
}