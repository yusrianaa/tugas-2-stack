#include <iostream>
#include <stdexcept>

using namespace std;

class StackArray {
    static constexpr int CAP = 5;
    int a[CAP];
    int t = -1;
public:
    bool empty() const { 
        return t == -1; 
    }
    
    void push(int x) {
        if (t == CAP - 1) throw overflow_error("penuh");
        a[++t] = x;
    }
    
    void pop() {
        if (empty()) throw underflow_error("kosong");
        --t;
    }
    
    int top() const {
        if (empty()) throw underflow_error("kosong");
        return a[t];
    }
};

int main() {
    StackArray s;
    int pilihan, nilai;

    do {
        cout << "\n===============================\n";
        cout << "       MENU STACK ARRAY        \n";
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
            // Menangkap error jika stack penuh (overflow) atau kosong (underflow)
            cout << "\n[ERROR]: Stack " << e.what() << "!\n";
        }

    } while (pilihan != 5);

    return 0;
}