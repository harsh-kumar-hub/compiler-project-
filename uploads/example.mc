// Example MiniC Program

// Function to calculate factorial
int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to check if a number is prime
bool isPrime(int num)
{
    int i;
    int temp;
    
    if (num <= 1)
    {
        return false;
    }
    
    i = 2;
    while (i < num)
    {
        temp = num;
        while (temp >= i)
        {
            temp = temp - i;
        }
        if (temp == 0)
        {
            return false;
        }
        i = i + 1;
    }
    return true;
}

// Main function (required entry point)
void main()
{
    int num;
    print "Hello from MiniC!";
    read num;
    print num;
} 