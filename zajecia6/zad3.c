int Addition(int a, int b) {
    return a + b;
}

int Subtraction(int a, int b) {
    return a - b;
}

int Multiplication(int a, int b) {
    return a * b;
}


int main()
{
    int input;
    int (*func)(int, int);
    
    while (input != 4) {
        printf("#################################\n\n");
        printf("# Press 1 for Addition\n");
        printf("# Press 2 for Subtraction\n");
        printf("# Press 3 for Multiplication\n");
        printf("# Press 4 to quit\n");
        
        printf("Input: ");
        scanf("%d", &input);
        
        switch (input) {
            case 1: {
            func = &Addition;
            int first_num;
            int second_num;
            
            printf("Enter first number: ");
            scanf("%d", &first_num);
            printf("Enter second number: ");
            scanf("%d", &second_num);
            
            printf("%d \n", (func)(first_num, second_num));
            break;
            }
            case 2: {
            func = &Subtraction;
            int first_num;
            int second_num;
            
            printf("Enter first number: ");
            scanf("%d", &first_num);
            printf("Enter second number: ");
            scanf("%d", &second_num);
            
            printf("%d \n", (func)(first_num, second_num));
            break;
            }
            case 3: {
            func = &Multiplication;
            int first_num;
            int second_num;
            
            printf("Enter first number: ");
            scanf("%d", &first_num);
            printf("Enter second number: ");
            scanf("%d", &second_num);
            
            printf("%d \n", (func)(first_num, second_num));
            break;
            }
            case 4:
            break;
            default:
            printf("Wrong option");
            break;
        }
    }
    
    

    return 0;
}
