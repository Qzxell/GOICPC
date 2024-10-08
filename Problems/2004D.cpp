#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#include <cmath>

using namespace std;

const int MAX_N = 2e5 + 5;
const int MAX_Q = 2e5 + 5;
const int INF = 1e9 + 7;

struct Node {
    int key;
    int degree;
    Node* parent;
    Node* child;
    Node* left;
    Node* right;
    bool mark;
};

class FibonacciHeap {
private:
    Node* minNode;
    int numNodes;

public:
    FibonacciHeap() : minNode(nullptr), numNodes(0) {}

    void insert(int key) {
        Node* newNode = new Node{key, 0, nullptr, nullptr, nullptr, nullptr, false};
        if (minNode == nullptr) {
            minNode = newNode;
        } else {
            newNode->right = minNode;
            newNode->left = minNode->left;
            minNode->left->right = newNode;
            minNode->left = newNode;
            if (newNode->key < minNode->key) {
                minNode = newNode;
            }
        }
        numNodes++;
    }

    int extractMin() {
        Node* min = minNode;
        if (min != nullptr) {
            if (min->child != nullptr) {
                Node* child = min->child;
                do {
                    Node* nextChild = child->right;
                    child->right = min->right;
                    child->left = min->left;
                    min->left->right = child;
                    min->right->left = child;
                    child->parent = nullptr;
                    child = nextChild;
                } while (child != min->child);
            }
            min->left->right = min->right;
            min->right->left = min->left;
            if (min == min->right) {
                minNode = nullptr;
            } else {
                minNode = min->right;
                consolidate();
            }
            numNodes--;
            return min->key;
        }
        return -1;
    }

    void consolidate() {
        int maxDegree = (int)log2(numNodes) + 1;
        vector<Node*> degreeTable(maxDegree, nullptr);
        Node* current = minNode;
        do {
            Node* next = current->right;
            int degree = current->degree;
            while (degreeTable[degree] != nullptr) {
                Node* other = degreeTable[degree];
                if (current->key > other->key) {
                    swap(current, other);
                }
                link(other, current);
                degreeTable[degree] = nullptr;
                degree++;
            }
            degreeTable[degree] = current;
            current = next;
        } while (current != minNode);
        minNode = nullptr;
        for (int i = 0; i < maxDegree; i++) {
            if (degreeTable[i] != nullptr) {
                if (minNode == nullptr) {
                    minNode = degreeTable[i];
                } else {
                    degreeTable[i]->right = minNode;
                    degreeTable[i]->left = minNode->left;
                    minNode->left->right = degreeTable[i];
                    minNode->left = degreeTable[i];
                    if (degreeTable[i]->key < minNode->key) {
                        minNode = degreeTable[i];
                    }
                }
            }
        }
    }

    void link(Node* y, Node* x) {
        y->right->left = y->left;
        y->left->right = y->right;
        y->parent = x;
        if (x->child == nullptr) {
            x->child = y;
            y->right = y;
            y->left = y;
        } else {
            y->right = x->child;
            y->left = x->child->left;
            x->child->left->right = y;
            x->child->left = y;
        }
        if (y->key < x->child->key) {
            x->child = y;
        }
        x->degree++;
        y->mark = false;
    }
    int size() const{
    return numNodes;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<string> colors(n);
        for (int i = 0; i < n; i++) {
            cin >> colors[i];
        }

        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (colors[i][0] == colors[j][0] || colors[i][1] == colors[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        FibonacciHeap heap;
        vector<int> distances(n, INF);
        vector<int> previous(n, -1);

        for (int i = 0; i < q; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;

            heap.insert(0);
            distances[x] = 0;

            while (heap.size() > 0) {
                int currentNode = heap.extractMin();
                for (int neighbor : graph[currentNode]) {
                    int distance = distances[currentNode] + abs(neighbor - currentNode);
                    if (distance < distances[neighbor]) {
                        distances[neighbor] = distance;
                        previous[neighbor] = currentNode;
                        heap.insert(distance);
                    }
                }
            }

            if (distances[y] == INF) {
                cout << -1 << "\n";
            } else {
                cout << distances[y] << "\n";
            }
        }
    }

    return 0;
}
