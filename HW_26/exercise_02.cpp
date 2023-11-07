#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// class Serializable {
//     public:
//     virtual void serialize(std::ofstream&) = 0;
//     virtual void deserialize(std::ifstream&) = 0;
//     virtual ~Serializable() = default;
// };

class ICommand /*: public Serializable*/ {
    public:
    virtual double execute() = 0;
    virtual std::string getCommand() = 0;
    virtual double getA() = 0;
    virtual double getB() = 0;
    virtual ~ICommand() = default;
};

class Add : public ICommand {
    public:
    Add(const double &a, const double &b) : m_a(a), m_b(b) {}

    double execute() override {
        return m_a + m_b;
    }

    std::string getCommand() override {
        return "Add";
    }

    double getA() override {
        return m_a;
    }

    double getB() override {
        return m_b;
    }

    private:
    double m_a, m_b;
};

class Subtract : public ICommand {
    public:
    Subtract(const double &a, const double &b) : m_a(a), m_b(b) {}

    double execute() override {
        return m_a - m_b;
    }

    std::string getCommand() override {
        return "Subtract";
    }

    double getA() override {
        return m_a;
    }

    double getB() override {
        return m_b;
    }


    private:
    double m_a, m_b;
};

class Multiply : public ICommand {
    public:
    Multiply(const double &a, const double &b) : m_a(a), m_b(b) {}

    double execute() override {
        return m_a * m_b;
    }

    std::string getCommand() override {
        return "Multiply";
    }

    double getA() override {
        return m_a;
    }

    double getB() override {
        return m_b;
    }


    private:
    double m_a, m_b;
};

class Divide : public ICommand {
    public:
    Divide(const double &a, const double &b) : m_a(a), m_b(b) {}

    double execute() override {
        if(m_b == 0) {
            std::cerr << "Cannot divide by zero!";
            return 0;
        }
        return m_a / m_b;
    }

    std::string getCommand() override {
        return "Divide";
    }

    double getA() override {
        return m_a;
    }

    double getB() override {
        return m_b;
    }

    // void serialize(std::ofstream& file) override {
    //     file.app;
    //     file << this->getCommand() << " " << this->getA() << " " << this->getB() << "\n";
    //     file << this->execute() << "\n";
    // }

    // void deserialize(std::ifstream& file) override {
        
    // }

    private:
    double m_a, m_b;
};

int main() {
    std::vector<ICommand*> commands;

    Add add(4.5, 13.5);
    ICommand *commandAdd(&add);
    commands.push_back(commandAdd);

    Divide divide(12, 3);
    ICommand *commandDivide(&divide);
    commands.push_back(commandDivide);

    Subtract sub(0, 2.6);
    ICommand *commandSub(&sub);
    commands.push_back(commandSub);

    Multiply mult(14.5, 20);
    ICommand *commandMult(&mult);
    commands.push_back(commandMult);

    Divide divZero(12, 0);
    ICommand *commandDivZero(&divZero);
    commands.push_back(commandDivZero);

    for(size_t i = 0; i < commands.size(); ++i) {
        std::cout << ">>>" << commands[i]->getCommand() << " " << commands[i]->getA() << " " << commands[i]->getB() << std::endl;
        std::cout << ">>>" << commands[i]->execute() << std::endl;
    }

    std::cout << std::endl;

    return 0;
}