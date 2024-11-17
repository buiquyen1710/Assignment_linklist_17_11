#include <iostream>
#include <string>
using namespace std;

// Cấu trúc dữ liệu file
struct file {
    string name;
    long time;
    long size;
    file* next;
};

// Tạo một file mới
file* createfile(string name, long time, long size) {
    file* f = new file;
    f->name = name;
    f->time = time;
    f->size = size;
    f->next = NULL;
    return f;
}

// Cấu trúc dữ liệu folder
struct folder {
    file* head;
};

// Sắp xếp các file trong folder theo dung lượng tăng dần (bubble sort)
void sortfile(folder& fol) {
    if (!fol.head || !fol.head->next) return;
    bool swapped;
    do {
        swapped = false;
        file* prev = NULL;
        file* current = fol.head;

        while (current && current->next) {
            file* next = current->next;

            if (current->size > next->size) { // So sánh dung lượng
                swapped = true;

                if (prev) {
                    prev->next = next;
                }
                else {
                    fol.head = next;
                }

                current->next = next->next;
                next->next = current;

                prev = next;
            }
            else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
}

// Xóa các file có dung lượng nhỏ nhất và thời gian lưu lâu nhất (ưu tiên xóa trước)
void deleteSmallestAndOldest(folder& fol) {
    if (!fol.head) return;

    // Tìm dung lượng nhỏ nhất
    long minSize = fol.head->size;
    file* current = fol.head;

    while (current) {
        if (current->size < minSize) {
            minSize = current->size;
        }
        current = current->next;
    }

    // Xóa các file có dung lượng nhỏ nhất và thời gian lưu lâu nhất
    file* prev = NULL;
    current = fol.head;

    while (current) {
        if (current->size == minSize) {
            if (!prev) { // Xóa đầu danh sách
                fol.head = current->next;
                delete current;
                current = fol.head;
            }
            else { // Xóa ở giữa hoặc cuối
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

// In danh sách các file
void printFiles(folder& fol) {
    file* current = fol.head;
    while (current != NULL) {
        cout << "File Name: " << current->name << ", Size: " << current->size << ", Time: " << current->time << endl;
        current = current->next;
    }
}

int main() {
    folder fol;
    fol.head = createfile("file1", 20230101, 500);
    fol.head->next = createfile("file2", 20230102, 200);
    fol.head->next->next = createfile("file3", 20230103, 300);
    fol.head->next->next->next = createfile("file4", 20230104, 100);
    fol.head->next->next->next->next = createfile("file5", 20230105, 100);

    cout << "Original files in folder:\n";
    printFiles(fol);

    // Sắp xếp file theo dung lượng tăng dần
    sortfile(fol);
    cout << "\nAfter sorting by size:\n";
    printFiles(fol);

    // Xóa các file có dung lượng nhỏ nhất và thời gian lưu lâu nhất
    deleteSmallestAndOldest(fol);
    cout << "\nAfter deleting smallest and oldest files:\n";
    printFiles(fol);

    return 0;
}
