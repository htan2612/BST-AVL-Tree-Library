#include <iostream>
#include "BST.h"
#include "AVL.h"
using namespace std;

int main() {
    Node* bstRoot = nullptr;
    Node* avlRoot = nullptr;
    bool useAVL = false;

    int choice, key;

    while (true) {
        if (useAVL) cout << "Tree Library [AVL]\n";
        else cout << "Tree Library [BST]\n";
        cout << "1. Insert  2. Delete  3. Search\n";
        cout << "4. InOrder 5. PreOrder 6. PostOrder 7. LevelOrder\n";
        cout << "8. Switch BST/AVL  9. Height&Size  0. Exit\nSelect: ";
        
        cin >> choice;

        Node*& root = useAVL ? avlRoot : bstRoot;

        switch (choice) {
            case 1: cin >> key;
                root = useAVL ? insertAVL(root,key) : Insert(root,key); break;
            case 2: cin >> key;
                root = useAVL ? deleteAVL(root,key) : Delete(root,key); break;
            case 3: cin >> key;
                cout << (Search(root,key) ? "Tim thay!" : "Khong co"); break;
            case 4: inOrder(root);    cout << endl; break;
            case 5: preOrder(root);   cout << endl; break;
            case 6: postOrder(root);  cout << endl; break;
            case 7: levelOrder(root); cout << endl; break;
            case 8: useAVL = !useAVL; cout << "Chuyen sang " << (useAVL ? "AVL" : "BST") << "\n"; break;
            case 9: cout << "Height=" << Height(root) << " Size=" << sizeOf(root) << "\n"; break;
            case 0: return 0;
        }
    }
}