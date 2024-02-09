//According to the C++17 standard, what is the output of this program?    
#include <iostream>

int main() {
    int i = 1;
    int const& a = i > 0 ? i : 1;
    i = 2;
    std::cout << i << a;
}

//21
/*
The line of code i > 0 ? i : 1; is a conditional expression. It checks if the value of i is greater than 0. If it is, the result is i; otherwise, the result is 1.
Now, the tricky part is the reference a. When we say a = i > 0 ? i : 1;, we are assigning the result of the conditional expression to a. But here's the catch: the result is a temporary value (we call it a "prvalue"), not directly i. So, a is bound to this temporary value.
When we later do i = 2;, it changes the value of i, but since a was bound to the temporary value, it doesn't get affected by this change. So, even though i becomes 2, a remains 1.
#include <iostream>

int main() {
    int i = 1;
    int const& a = i;
    i = 2;
    std::cout << i << a;
}
//22
*/
