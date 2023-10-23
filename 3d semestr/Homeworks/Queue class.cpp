#include <iostream>
#include <stdlib.h>
#include <cstring>

#define MEM_SIZE 256
#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

class Queue {
public:
    int *data;
    unsigned int l = 0, r = 0, n = MEM_SIZE;
    // data - наш массив
    // k - колицество занятых ячеек
    // n - кoличество выделенных под массив ячеек

    Queue() {
        data = (int *) malloc(n);
    }

    Queue(int k) {
        data = (int *) malloc(n * sizeof(k));
        data[r++] = k;
    }

    Queue(const Queue &other) {
        unsigned int dif = other.r - other.l;

        // memory relocation
        if (n < dif) {
            n *= 2;
            while (n < dif) {
                n *= 2;
            }
        } else {
            while (n / 2 > dif) {
                n /= 2;
            }
        }
        data = (int *) realloc(data, n * sizeof(int));

        //copying
        for (unsigned int i = other.l; i < other.r; i++) {
            data[i - other.l] = other.data[i];
        }
        l = 0;
        r = other.r - other.l;
    }

    ~Queue() {
        if (data) {
            free(data);
        }
    }

    unsigned int size() {
        return r - l;
    }

    unsigned int memory() {
        return n;
    }

    int back() {
        return data[r - 1];
    }

    int front() {
        return data[l];
    }

    int memory_relocate() {
        unsigned int oldn = n;
        while (n / 2 > r - l and n > MEM_SIZE) {
            n /= 2;
        }
        while (n - 2 < r - l) {
            n *= 2;
        }
        if (n == oldn and r < n - 1) {
            return 0;
        }

        if (l == 0) {
            data = (int *) realloc(data, n * sizeof(int));
        } else {
            int *ndata = (int *) malloc(n * sizeof(int));
            for (int i = l; i < r; i++) {
                ndata[i - l] = data[i];
            }
            free(data);

            data = ndata;
            r = r - l;
            l = 0;
        }
        return 1;
    }

    int memory_relocate(unsigned int size) {
        unsigned int oldn = n;
        while (n / 2 > size and n > MEM_SIZE) {
            n /= 2;
        }
        while (n - 2 < size) {
            n *= 2;
        }
        if (n == oldn and l + size < n - 1) {
            return 0;
        }

        if (l == 0) {
            data = (int *) realloc(data, n * sizeof(int));
        } else {
            int *ndata = (int *) malloc(n * sizeof(int));
            for (int i = l; i < MIN(r, l + size); i++) {
                ndata[i - l] = data[i];
            }
            free(data);

            data = ndata;
            r = MIN(r - l, size);
            l = 0;
        }
        return 1;
    }

    void push(int t) {
        if (r > n - 2) {
            if (!memory_relocate()) {
                n *= 2;
                data = (int *) realloc(data, n * sizeof(t));
            }
        }

        data[r++] = t;
    }

    int pop() {
        int t = data[l++];
        memory_relocate();
        return t;
    }

    void print(int t) {
        cout << "{ ";
        for (int i = l; i < MIN(r - 1, t); i++) {
            cout << data[i] << ", ";
            if ((i - l) % 10 == 9) {
                cout << endl << "  ";
            }
        }
        if (r - 1 >= l) {
            cout << data[r - 1] << " }\n";
        }
    }

    Queue &operator=(Queue &other) {
        unsigned int dif = other.r - other.l;

        // memory relocation
        if (n < dif) {
            n *= 2;
            while (n < dif) {
                n *= 2;
            }
        } else {
            while (n / 2 > dif) {
                n /= 2;
            }
        }
        data = (int *) realloc(data, n * sizeof(int));

        //copying
        for (unsigned int i = other.l; i < other.r; i++) {
            data[i - other.l] = other.data[i];
        }
        l = 0;
        r = other.r - other.l;
        return *this;
    }

    Queue operator+(Queue &other) {
        unsigned int i, dif = r - l, t = r - l + other.r - other.l;
        Queue new_queue;
        while (new_queue.n < t) {
            new_queue.n *= 2;
        }
        new_queue.data = (int *) realloc(new_queue.data, new_queue.n * sizeof(int));
        for (i = l; i < r; i++) {
            new_queue.data[i - l] = data[i];
        }
        for (i = other.l; i < other.r; i++) {
            new_queue.data[i - other.l + dif] = other.data[i];
        }
        new_queue.l = 0;
        new_queue.r = t;

        return new_queue;
    }

    Queue &operator+=(Queue &other) {
        unsigned int i, dif = r - l;
        if (r + other.r - other.l > n - 2) {
            memory_relocate(r - l + other.r - other.l);
        }
        for (i = other.l; i < other.r; i++) {
            data[r + i - other.l] = other.data[i];
        }
        r = r + other.r - other.l;
        return *this;
    }

    bool operator==(Queue &other) {
        if (r - l != other.r - other.l) {
            return false;
        }
        for (int i = 0; i < r - l; i++) {
            if (data[l + i] != other.data[other.l + i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(Queue &other) {
        if (*this == other) {
            return false;
        }
        return true;
    }

    bool operator<=(Queue &other) {
        for (int i = 0; i < MIN(r - l, other.r - other.l); i++) {
            if (data[l + i] > other.data[other.l + i]) {
                return false;
            }
        }
        if (r - l > other.r - other.l) {
            return false;
        }
        return true;
    }

    bool operator>=(Queue &other) {
        for (int i = 0; i < MIN(r - l, other.r - other.l); i++) {
            if (data[l + i] < other.data[other.l + i]) {
                return false;
            }
        }
        if (r - l < other.r - other.l) {
            return false;
        }
        return true;
    }

    bool operator<(Queue &other) {
        if (*this >= other) {
            return false;
        }
        return true;
    }

    bool operator>(Queue &other) {
        if (*this <= other) {
            return false;
        }
        return true;
    }


};

ostream &operator<<(ostream &out, Queue &queue) {
    out << "{ ";
    for (int i = queue.l; i < queue.r; i++) {
        out << queue.data[i] << ", ";
        if ((i - queue.l) % 10 == 9) {
            out << endl << "  ";
        }
    }
    if (queue.r - 1 >= queue.l) {
        out << queue.data[queue.r - 1] << " }\n";
    }
    return out;
}

istream &operator>>(istream &in, Queue &queue) {
    int t;
    in >> t;
    queue.push(t);
    return in;
}

void func(Queue &a) {
    printf("%d %d %d %d\n", a.l, a.r, a.size(), a.memory());
}

int main() {
    Queue a(5);
    Queue b;
    printf("%d %d %d %d\n", a.l, a.r, a.size(), a.memory());

    for (int i = 0; i < 9; i++) {
        cin >> a;
    }

    for (int i = 10; i < 2785; i++) {
        a.push(i);
    }
    printf("%d %d %d %d\n", a.l, a.r, a.size(), a.memory());

    a.print(10000);
    printf("%d %d %d %d\n", a.l, a.r, a.size(), a.memory());

    for (int i = 0; i < 1423; i++) {
        printf("a[%d] = %d;  ", i, a.pop());
        if (i % 5 == 4) {
            cout << endl;
        }
    }
    printf("\n%d %d %d %d\n", a.l, a.r, a.size(), a.memory());


    func(a);
    printf("%d %d %d %d\n", a.l, a.r, a.size(), a.memory());

    cout << a;
    printf("%d %d %d %d\n", a.l, a.r, a.size(), a.memory());

    b = a;
    printf("b: %d %d %d %d\n", b.l, b.r, b.size(), b.memory());

    a.pop();
    printf("a: front: %d %d %d %d %d\n", a.front(), a.l, a.r, a.size(), a.memory());
    printf("b: front: %d %d %d %d %d\n", b.front(), b.l, b.r, b.size(), b.memory());

    a += b;
    printf("a: front: %d %d %d %d %d\n", a.front(), a.l, a.r, a.size(), a.memory());
    printf("b: front: %d %d %d %d %d\n", b.front(), b.l, b.r, b.size(), b.memory());

    Queue c = b + a;
    printf("a: front: %d %d %d %d %d\n", a.front(), a.l, a.r, a.size(), a.memory());
    printf("b: front: %d %d %d %d %d\n", b.front(), b.l, b.r, b.size(), b.memory());
    printf("c: front: %d %d %d %d %d\n", c.front(), c.l, c.r, c.size(), c.memory());

    if (a == a) {
        printf("a == a\n");
    }
    if (a <= a) {
        printf("a <= a\n");
    }
    if (a >= a) {
        printf("a >= a\n");
    }
    if (a < a) {
        printf("a < a\n");
    }
    if (a == b) {
        printf("a == b\n");
    }
    if (c < b) {
        printf("c < b\n");
    }
    if (c > b) {
        printf("c > b\n");
    }
    if (c >= b) {
        printf("c >= b\n");
    }
    if (c <= b) {
        printf("c <= b\n");
    }

    return 0;
}