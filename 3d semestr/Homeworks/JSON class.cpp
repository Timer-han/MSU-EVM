#include <iostream>

using namespace std;

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

    Integer(int value) {
        this->value = value;
    };

    /* Методы для чтения/записи приватных полей. */
    int Value() const {
        return value;
    };

    int &Value() {
        return value;
    };

    std::string ToString() const override {
        char *str = "";
        sprintf(str, "%d", value);
        return (string) str;
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

    Double(double value) {
        this->value = value;
    };

    double Value() const {
        return value;
    };

    double &Value() {
        return value;
    };

    std::string ToString() const override {
        char *str;
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
    Node **values;
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
    };

    const Node *operator[](size_t index) const {
        if (index < lengh) {
            return values[index];
        }
    };

    std::string ToString() const override {
        string str = "[";
        str += values[0]->ToString();
        for (int i = 1; i < lengh; i++) {
            str += ", ";
            str += values[i]->ToString();
        }
        str += "]";
        return str;
    };

    void Print(std::ostream &out) const override {
        out << "[" << values[0]->ToString();
        for (int i = 1; i < lengh; i++) {
            out << ", " << values[i];
        }
        out << "]";
    };
};

int main(){

}