#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

// ============================================================================
// CORE OOP CONCEPTS 1 & 2: ABSTRACTION & ENCAPSULATION
// ============================================================================
// - Abstraction: Hides calculation specifics behind a pure virtual interface.
// - Encapsulation: Restricts direct access to internal data ('name') via 'private'
//   and exposes it through controlled public methods.
class Calculator {
private:
    string name; // Encapsulated private data

public:
    Calculator(const string& calcName) : name(calcName) {}
    virtual ~Calculator() = default;

    // Public getter (controlled access to private data)
    string getName() const {
        return name;
    }

    // Pure virtual function: Makes this an Abstract Base Class (Abstraction)
    virtual void calculate() = 0;

    // Compile-time Polymorphism: Function Overloading
    void showResult(const string& label, double value) {
        cout << "[Result] " << label << ": " << fixed << setprecision(2) << value << "\n";
    }
};

// ============================================================================
// CORE OOP CONCEPT 3: INHERITANCE
// ============================================================================
// Derived classes inherit common attributes and interface from Calculator.

// 1. Basic Arithmetic Calculator
class ArithmeticCalculator : public Calculator {
public:
    ArithmeticCalculator() : Calculator("Basic Arithmetic Calculator") {}

    // Runtime Polymorphism: Overriding the pure virtual function
    void calculate() override {
        double a, b;
        char op;

        cout << "\n--- " << getName() << " ---\n";
        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter operator (+, -, *, /): ";
        cin >> op;
        cout << "Enter second number: ";
        cin >> b;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Invalid numeric input.\n";
            return;
        }

        switch (op) {
            case '+': showResult("Sum", a + b); break;
            case '-': showResult("Difference", a - b); break;
            case '*': showResult("Product", a * b); break;
            case '/':
                if (b == 0) {
                    cout << "Error: Cannot divide by zero.\n";
                } else {
                    showResult("Quotient", a / b);
                }
                break;
            default:
                cout << "Error: Unsupported operator '" << op << "'.\n";
        }
    }
};

// 2. BMI Calculator (Health & Fitness)
class BMICalculator : public Calculator {
public:
    BMICalculator() : Calculator("BMI Calculator") {}

    // Runtime Polymorphism: Overriding the pure virtual function
    void calculate() override {
        double weight, height;

        cout << "\n--- " << getName() << " ---\n";
        cout << "Enter weight in kg: ";
        cin >> weight;
        cout << "Enter height in meters: ";
        cin >> height;

        if (cin.fail() || weight <= 0 || height <= 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Weight and height must be positive numbers.\n";
            return;
        }

        double bmi = weight / (height * height);
        showResult("BMI Score", bmi);

        if (bmi < 18.5)      cout << "Category: Underweight\n";
        else if (bmi < 24.9) cout << "Category: Normal weight\n";
        else if (bmi < 29.9) cout << "Category: Overweight\n";
        else                 cout << "Category: Obese\n";
    }
};

// 3. Loan & Interest Calculator (Finance / Loan EMI)
class LoanCalculator : public Calculator {
public:
    LoanCalculator() : Calculator("Loan EMI & Interest Calculator") {}

    // Runtime Polymorphism: Overriding the pure virtual function
    void calculate() override {
        double principal, annualRate;
        int tenureMonths;

        cout << "\n--- " << getName() << " ---\n";
        cout << "Enter loan principal amount: ";
        cin >> principal;
        cout << "Enter annual interest rate (%): ";
        cin >> annualRate;
        cout << "Enter loan duration (tenure in months): ";
        cin >> tenureMonths;

        if (cin.fail() || principal <= 0 || annualRate < 0 || tenureMonths <= 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Invalid inputs. Principal and months must be positive.\n";
            return;
        }

        double emi;
        double monthlyRate = annualRate / (12.0 * 100.0);

        if (monthlyRate == 0) {
            emi = principal / tenureMonths;
        } else {
            double factor = pow(1.0 + monthlyRate, tenureMonths);
            emi = (principal * monthlyRate * factor) / (factor - 1.0);
        }

        double totalPayment = emi * tenureMonths;
        double totalInterest = totalPayment - principal;

        showResult("Monthly EMI", emi);
        showResult("Total Interest Payable", totalInterest);
        showResult("Total Amount to Repay", totalPayment);
    }
};

// 4. Academic Calculator (Marks, Percentage & Grade)
class AcademicCalculator : public Calculator {
public:
    AcademicCalculator() : Calculator("Academic Marks & Grade Calculator") {}

    // Runtime Polymorphism: Overriding the pure virtual function
    void calculate() override {
        double obtained, total;

        cout << "\n--- " << getName() << " ---\n";
        cout << "Enter marks obtained: ";
        cin >> obtained;
        cout << "Enter total maximum marks: ";
        cin >> total;

        if (cin.fail() || obtained < 0 || total <= 0 || obtained > total) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Obtained marks must be between 0 and total marks.\n";
            return;
        }

        double percentage = (obtained / total) * 100.0;
        showResult("Score Percentage", percentage);

        cout << "Grade: ";
        if (percentage >= 90.0)      cout << "A+ (Outstanding)\n";
        else if (percentage >= 80.0) cout << "A (Excellent)\n";
        else if (percentage >= 70.0) cout << "B (Good)\n";
        else if (percentage >= 60.0) cout << "C (Satisfactory)\n";
        else if (percentage >= 50.0) cout << "D (Pass)\n";
        else                         cout << "F (Fail)\n";
    }
};

// ============================================================================
// CORE OOP CONCEPT 4: RUNTIME POLYMORPHISM
// ============================================================================
int main() {
    // Instantiate concrete derived objects
    ArithmeticCalculator arithmetic;
    BMICalculator bmi;
    LoanCalculator loan;
    AcademicCalculator academic;

    int choice = -1;

    do {
        cout << "\n========================================\n";
        cout << "            CAL-GEN CONSOLE             \n";
        cout << "========================================\n";
        cout << "1. " << arithmetic.getName() << "\n";
        cout << "2. " << bmi.getName() << "\n";
        cout << "3. " << loan.getName() << "\n";
        cout << "4. " << academic.getName() << "\n";
        cout << "0. Exit\n";
        cout << "----------------------------------------\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice. Please enter a valid number.\n";
            continue;
        }

        // Base class pointer: will point to different child objects at runtime
        Calculator* selectedCalculator = nullptr;

        switch (choice) {
            case 1: selectedCalculator = &arithmetic; break;
            case 2: selectedCalculator = &bmi; break;
            case 3: selectedCalculator = &loan; break;
            case 4: selectedCalculator = &academic; break;
            case 0:
                cout << "Thank you for using CalGen. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select 0, 1, 2, 3, or 4.\n";
        }

        // Runtime Polymorphism: Dynamic dispatch to calculate() of chosen calculator
        if (selectedCalculator != nullptr) {
            selectedCalculator->calculate();
        }

    } while (choice != 0);

    return 0;
}
