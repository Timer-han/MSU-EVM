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


    // overloading operators
    Integer operator+(Integer value) const{
        value.value += this->value;
        return value;
    }

    template<typename Type>
    Integer operator+(Type value) const{
        Integer a(value + this->value);
        return a;
    }

    Integer operator-(Integer value) const{
        value.value = this->value - value.value;
        return value;
    }

    template<typename Type>
    Integer operator-(Type value) const{
        Integer a(this->value - value);
        return a;
    }

    Integer operator*(Integer value) const{
        value.value = this->value * value.value;
        return value;
    }

    template<typename Type>
    Integer operator*(Type value) const{
        Integer a(this->value * value);
        return a;
    }

    Integer operator/(Integer value) const{
        value.value = this->value / value.value;
        return value;
    }

    template<typename Type>
    Integer operator/(Type value) const{
        Integer a(this->value / value);
        return a;
    }

    Integer &operator=(Integer value) {
        this->value = value.value;
        return *this;
    }

    template<typename Type>
    Integer &operator=(Type value) {
        this->value = value;
        return *this;
    }

    template<typename Type>
    Integer & operator+=(Type value) {
        *this = *this + value;
        return *this;
    }

    template<typename Type>
    Integer & operator-=(Type value) {
        this->value = this->value - value;
        return *this;
    }

    template<typename Type>
    Integer & operator*=(Type value) {
        this->value = this->value * value;
        return *this;
    }

    template<typename Type>
    Integer & operator/=(Type value) {
        this->value = this->value / value;
        return *this;
    }

    bool operator<(Integer value) const{
        return this->value < value.value;
    }

    template<typename Type>
    bool operator<(Type value) const{
        return this->value < value;
    }

    template<typename Type>
    bool operator==(Type value) const{
        double a = this->value, eps = a;
        while (eps + a > a){
            eps /= 2;
        }
        eps *= 4;

        return ((*this - value) < eps and (value - *this) < eps);
    }

    template<typename Type>
    bool operator!=(Type value) const{
        return !(*this == value);
    }

    template<typename Type>
    bool operator>(Type value) const{
        return value < *this;
    }

    template<typename Type>
    bool operator>=(Type value) const{
        return value < *this or value == *this;
    }

    template<typename Type>
    bool operator<=(Type value) const{
        return value > *this or value == *this;
    }
    // end of overloading operators


    std::string ToString() const override {
        char *str = new char[10];
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

    Double(double value) : value(value) {};

    double Value() const {
        return value;
    };

    double &Value() {
        return value;
    };

    // overloading operators
    Double operator+(Double value) const{
        value.value += this->value;
        return value;
    }

    template<typename Type>
    Double operator+(Type value) const{
        Double a(value + this->value);
        return a;
    }

    Double operator-(Double value) const{
        value.value = this->value - value.value;
        return value;
    }

    template<typename Type>
    Double operator-(Type value) const{
        Double a(this->value - value);
        return a;
    }

    Double operator*(Double value) const{
        value.value = this->value * value.value;
        return value;
    }

    template<typename Type>
    Double operator*(Type value) const{
        Double a(this->value * value);
        return a;
    }

    Double operator/(Double value) const{
        value.value = this->value / value.value;
        return value;
    }

    template<typename Type>
    Double operator/(Type value) const{
        Double a(this->value / value);
        return a;
    }

    Double &operator=(Double value) {
        this->value = value.value;
        return *this;
    }

    template<typename Type>
    Double &operator=(Type value) {
        this->value = value;
        return *this;
    }

    template<typename Type>
    Double & operator+=(Type value) {
        *this = *this + value;
        return *this;
    }

    template<typename Type>
    Double & operator-=(Type value) {
        this->value = this->value - value;
        return *this;
    }

    template<typename Type>
    Double & operator*=(Type value) {
        this->value = this->value * value;
        return *this;
    }

    template<typename Type>
    Double & operator/=(Type value) {
        this->value = this->value / value;
        return *this;
    }

    bool operator<(Double value) const{
        return this->value < value.value;
    }

    template<typename Type>
    bool operator<(Type value) const{
        return this->value < value;
    }

    template<typename Type>
    bool operator==(Type value) const{
        double a = this->value, eps = a;
        while (eps + a > a){
            eps /= 2;
        }
        eps *= 4;

        return ((*this - value) < eps and (value - *this) < eps);
    }

    template<typename Type>
    bool operator!=(Type value) const{
        return !(*this == value);
    }

    template<typename Type>
    bool operator>(Type value) const{
        return value < *this;
    }

    template<typename Type>
    bool operator>=(Type value) const{
        return value < *this or value == *this;
    }

    template<typename Type>
    bool operator<=(Type value) const{
        return value > *this or value == *this;
    }
    // end of overloading operators

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


ostream &operator<<(ostream &out, Integer value){
    out << value.Value();
    return out;
}

ostream &operator<<(ostream &out, Double value){
    out << value.Value();
    return out;
}

int main() {
    Double a = 5, b = 6;
    cout << " a = " << a << ", b = " << b << endl;
    cout << "(a < b)  " << (a < b) << endl;
    cout << "(a > b)  " << (a > b) << endl;
    cout << "(a <= b) " << (a <= b) << endl;
    cout << "(a >= b) " << (a >= b) << endl;
    cout << "(a == b) " << (a == b) << endl;
    cout << "(a != b) " << (a != b) << endl;

    cout << "(a < a)  " << (a < a) << endl;
    cout << "(a > a)  " << (a > a) << endl;
    cout << "(a <= a) " << (a <= a) << endl;
    cout << "(a >= a) " << (a >= a) << endl;
    cout << "(a == a) " << (a == a) << endl;
    cout << "(a != a) " << (a != a) << endl;


    cout << "(a + b)  " << (a + b) << endl;
    cout << "(a - b)  " << (a - b) << endl;
    cout << "(a * b)  " << (a * b) << endl;
    cout << "(a / b)  " << (a / b) << endl;
    cout << "(a += b) " << (a += b) << endl;
    cout << " b       " << a << endl;


    List m;
    for (int i = 0; i < 1000; ++i) {
        a = i;
        m.AddNode(*a);
    }
    return 0;
}