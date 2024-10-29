#include <iostream>
using namespace std;

typedef struct Node {
    int heso;
    int somu;
    Node* next;
} Node;

typedef struct List {
    Node* first_node;
} List;

void Init_List(List* lst) {
    lst->first_node = NULL;
}

void Dispose_List(List* lst) {
    while(lst->first_node != NULL) {
        Node* temp = lst->first_node;
        lst->first_node = temp->next;
        delete [] temp;
    }
}

void Dispose_Node(Node* node) {
    delete [] node;
}

Node* Make_Node(int heso, int somu) {
    Node* new_node = new Node;
    new_node->heso = heso;
    new_node->somu = somu;
    new_node->next = NULL;
    return new_node;
}

void Add_Last(List* lst, int heso, int somu) {
    Node* new_node = Make_Node(heso, somu);
    if (heso) {
        if (lst->first_node == NULL) {
            lst->first_node = new_node;
        } 
        else {
            Node* f_node = lst->first_node;
            while (f_node->next != NULL) {
                f_node = f_node->next;
            }
            f_node->next = new_node;
        }
    }
    else {
        Dispose_Node(new_node);
    }
}

void Nhap_List(List* lst) {
    int i = 0;
    int somu, heso;
    cout << "Nhap da thuc f(x)" << endl;
    do {
        i++;
        cout << "Nhap so hang thu " << i << endl;
        cout << "Nhap so mu: "; cin >> somu;
        cout << "Nhap he so cua x^" << somu << ": "; cin >> heso;
        Add_Last(lst, heso, somu);
    } while (somu != 0);
    cout << "Ket thuc nhap" << endl;
}

void In_List(List* lst) {
    Node* f_node = lst->first_node;
    cout << "f(x) = ";
    while (f_node != NULL) {
        if (f_node->somu != 0) cout << f_node->heso << "x^" << f_node->somu;
        else cout << f_node->heso;
        if (f_node->next != NULL) cout << " + ";
        f_node = f_node->next; 
    }
}

int main() {
    List lst;
    Init_List(&lst);
    Nhap_List(&lst);
    In_List(&lst);
    return 0;
}