# CalGen Console (OOP in C++)

A clean, single-file C++ console application demonstrating the core pillars of Object-Oriented Programming (OOP).

## Core OOP Concepts Demonstrated

1. **Abstraction**
   - Implemented via the abstract base class `Calculator`.
   - Defines a common interface with pure virtual function `virtual void calculate() = 0;`.
   - External callers interact with the abstract interface without needing to know internal formulas.

2. **Encapsulation**
   - Data members such as `name` are kept `private` within `Calculator`.
   - Controlled access is provided through public getter methods (`getName()`).

3. **Inheritance**
   - Derived classes (`ArithmeticCalculator`, `BMICalculator`, `LoanCalculator`, `AcademicCalculator`) inherit from `Calculator`.
   - Base constructor delegation initializes common attributes.

4. **Polymorphism**
   - **Runtime (Dynamic) Polymorphism**: Virtual function overriding (`override`). In `main()`, a base-class pointer (`Calculator* selectedCalculator`) points to concrete derived objects at runtime to execute `selectedCalculator->calculate()`.
   - **Compile-Time (Static) Polymorphism**: Function overloading demonstrated by `showResult(...)` variants.

## Compilation & Execution

### Direct Compile with g++:
```bash
g++ -std=c++11 -static main.cpp -o calgen.exe
./calgen.exe
```

