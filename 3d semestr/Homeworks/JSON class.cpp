#include <iostream>
#include <typeinfo>

using namespace std;

class Integer;

class Double;

class List;

class Node;

class Node {
public:
    /* Любые данные можно преобразовать в строку или вывести в поток вывода. */
    virtual std::string ToString() const = 0;

    virtual void Print(std::ostream &out) const = 0;

    /* Каждый объект типа Node в действительности является числом или списком.
    Эти методы должны конвертировать объект в указанный тип данных.
    В случае, если конвертация невозможна, требуется выбросить исключение.
    */

    const Integer &AsInteger() const;

    Integer &AsInteger();

    const Double &AsDouble() const;

    Double &AsDouble();

    const List &AsList() const;

    List &AsList();

    virtual ~Node() {}
};

class Integer : public Node {
private:
    int value;

public:
    Integer() {};

    Integer(int value) : value(value) {};

    /* Методы для чтения/записи приватных полей. */
    int Value() const {
        return value;
    };

    int &Value() {
        return value;
    };


    std::string ToString() const override {
        char *str = new char[10];
        sprintf(str, "%d", value);
        return (std::string) str;
    };

    void Print(std::ostream &out) const override {
        out << value;
        return;
    };
};

class Double : public Node {
private:
    double value;

public:
    Double() {};

    Double(double value) : value(value) {};

    double Value() const {
        return value;
    };

    double &Value() {
        return value;
    };


    std::string ToString() const override {
        char *str = new char[10];
        sprintf(str, "%lf", value);
        return (string) str;
    };


    void Print(std::ostream &out) const override {
        out << value;
        return;
    };
};

class List : public Node {
private:
    // Элементы списка. Каждый элемент --- указатель на Node для
    // того, чтобы обеспечить полиморфное поведение.
    Node **values{};
    size_t count;
    size_t lengh;

public:
    List() {
        count = 0;
        lengh = 0;
    };

    List(Node **values, size_t count) {
        this->values = new Node *[count];
        for (int i = 0; i < count; i++) {
            this->values[i] = values[i];
        }
        this->lengh = count;
        this->count = count;
    };

    const Node *const *Values() const {
        return values;
    };

    Node **&Values() {
        return values;
    };

    // Функция добавляет элемент в список.
    void AddNode(Node *node) {
        if (count == 0) {
            values = new Node *[1];
            lengh = 0;
            count = 1;
        } else if (lengh + 1 >= count) {
            count *= 2;
            Node **arr = values;
            values = new Node *[count];
            for (int i = 0; i < lengh; i++) {
                values[i] = arr[i];
            }
        }
        values[lengh++] = node;

    };

    /* Получить элемент списка для чтения или записи.
     * Методы должны выбрасывать исключение в случае некорректного индекса.
 */
    Node *operator[](size_t index) {
        if (index < lengh) {
            return values[index];
        }
        return nullptr;
    };

    const Node *operator[](size_t index) const {
        if (index < lengh) {
            return values[index];
        }
        return nullptr;
    };

    std::string ToString() const override {
        string str = "\n[\n";
        str += values[0]->ToString();
        for (int i = 1; i < lengh; i++) {
            str += ", ";
            if (i % 5 == 0){
                str += "\n";
            }
            str += values[i]->ToString();
        }
        str += "\n]\n";
        return str;
    };


    void Print(std::ostream &out) const override {
        out << this->ToString();
    };
};


const Integer &Node::AsInteger() const {
    if (dynamic_cast<const Integer *>(this)) {
        throw "Can't convert to Integer!";
    }
    return *(dynamic_cast<const Integer *>(this));
};

Integer &Node::AsInteger() {

    if (dynamic_cast<Integer *>(this)) {
        throw "Can't convert to Integer!";
    }
    return *(dynamic_cast<Integer *>(this));

};

const Double &Node::AsDouble() const {
    if (dynamic_cast<const Double *>(this)) {
        throw "Can't convert to Double!";
    }
    return *(dynamic_cast<const Double *>(this));
};

Double &Node::AsDouble() {
    if (dynamic_cast<Double *>(this)) {
        throw "Can't convert to Integer!";
    }
    return *(dynamic_cast<Double *>(this));
};

const List &Node::AsList() const {
    if (dynamic_cast<const List *>(this)) {
        throw "Can't convert to Integer!";
    }
    return *(dynamic_cast<const List *>(this));
};

List &Node::AsList() {
    if (dynamic_cast<List *>(this)) {
        throw "Can't convert to Integer!";
    }
    return *(dynamic_cast<List *>(this));
};


ostream &operator<<(ostream &out, Integer value) {
    out << value.Value();
    return out;
}

ostream &operator<<(ostream &out, Double value) {
    out << value.Value();
    return out;
}

int main() {
    Double b = 6;
    Integer *a = new Integer(5);


    List *subarr = new List();
    for (int i = 0; i < 10; ++i) {
        subarr->AddNode(new Integer(i));
        subarr->AddNode(new Double(i * i * i / 0.232 * 12.124));
    }
    subarr->Print(cout);

    List *arr = new List(subarr->Values(), 20);

    for (int i = 1; i < 100; ++i) {
        arr->AddNode(new Double(1./i));
        arr->AddNode(new Double(i * i * i / 0.232 * 12.124));
    }
    arr->AddNode(subarr);

    arr->Print(cout);
    return 0;
}