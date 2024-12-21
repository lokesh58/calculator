# calculator

A calculator that calculates an expression.
eg : 2 + 3 \* 4 / 7

## Implementation Details

The calculator supports the following operations:

- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)
- Modulus (`%`)

### Class Structure

- `Calculator`: Main class that provides the `calculate` method to evaluate expressions.
  - `calculate(const std::string &expression)`: Evaluates the given expression and returns the result.
  - `parse_infix_expression(const std::string &expression)`: Parses the infix expression into tokens.
  - `convert_to_postfix(const std::vector<Token> &infix)`: Converts infix tokens to postfix notation.
  - `evaluate_postfix(const std::vector<Token> &postfix)`: Evaluates the postfix expression and returns the result.

### Token Structure

- `Token`: Represents a single token in the expression.
  - `TokenType`: Enum to distinguish between operators and operands.
  - `Operator`: Enum to represent different operators.

### Build Instructions

1. Clone the repository:

   ```sh
   git clone git@github.com:lokesh58/calculator.git
   cd calculator
   ```

2. Create a build directory and navigate into it:

   ```sh
   mkdir build
   cd build
   ```

3. Run CMake to configure the project:

   ```sh
   cmake ..
   ```

4. Build the project:

   ```sh
   make
   ```

5. Run the calculator:
   ```sh
   ./calculator
   ```
