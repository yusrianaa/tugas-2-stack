#include <iostream>
#include <stdexcept>

using namespace std;

// Struktur Node untuk Linked List
struct Node {
    int data;
    Node* next;
};

class StackLinkedList {
private:
    Node* topNode; // Pointer penunjuk puncak stack

public:
    // Constructor
    StackLinkedList() {
        topNode = nullptr; // Inisialisasi stack kosong
    }

    // Destructor untuk membersihkan memori heap
    ~StackLinkedList() {
        while (!empty()) {
            pop();
        }
    }

    // Cek apakah stack kosong
    bool empty() const {
        return topNode == nullptr;
    }

    // Menambah data ke stack (Push)
    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = topNode; // Hubungkan node baru ke node teratas sebelumnya
        topNode = newNode;       // Geser posisi top ke node baru
    }

    // Menghapus data teratas dari stack (Pop)
    void pop() {
        if (empty()) {
            throw underflow_error("kosong");
        }
        Node* temp = topNode;    // Simpan node teratas sementara
        topNode = topNode->next; // Geser top ke node berikutnya
        delete temp;             // Hapus node lama dari memori
    }

    // Melihat data teratas (Top)
    int top() const {
        if (empty()) {
            throw underflow_error("kosong");
        }
        return topNode->data;
    }
};

int main() {
    StackLinkedList s;
    int pilihan, nilai;

    do {
        cout << "\n===============================\n";
        cout << "     MENU STACK LINKED LIST    \n";
        cout << "===============================\n";
        cout << "1. Push (Tambah Data)\n";
        cout << "2. Pop (Hapus Data Teratas)\n";
        cout << "3. Top (Lihat Data Teratas)\n";
        cout << "4. Cek Apakah Kosong\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        try {
            switch (pilihan) {
                case 1:
                    cout << "Masukkan angka yang ingin di-push: ";
                    cin >> nilai;
                    s.push(nilai);
                    cout << "Berhasil menambahkan " << nilai << " ke dalam stack.\n";
                    break;
                case 2:
                    s.pop();
                    cout << "Berhasil menghapus elemen teratas (pop).\n";
                    break;
                case 3:
                    cout << "Elemen teratas saat ini: " << s.top() << endl;
                    break;
                case 4:
                    if (s.empty()) {
                        cout << "Stack saat ini KOSONG.\n";
                    } else {
                        cout << "Stack TIDAK kosong.\n";
                    }
                    break;
                case 5:
                    cout << "Keluar dari program.\n";
                    break;
                default:
                    cout << "Pilihan tidak valid! Silakan pilih angka 1-5.\n";
            }
        } catch (const exception& e) {
            cout << "\n[ERROR]: Stack " << e.what() << "!\n";
        }

    } while (pilihan != 5);

    return 0;
}