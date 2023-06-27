// Code for generating random number.
int printRandoms(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    // Returning the generated number.
    return num;
}


// Function for swaping any two numbers. This function is made for swaping the positions of numbers in array so they can be randomized in any order.
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


// In this function two random number between 0 to 9 will get generated and for each value of i.. Use of this function is to select any index and send them to swap function.. In short all the values in the array of questions will be now in any order.
void randomize(int *ptr, int n){
    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        // Now the random selected index are put in the array and the numbers at that index number gets swap.
        swap((ptr + i), (ptr + j));
    }
    
}


// This function is for generating options.
// Here we have taken a 
void options(int *ptr, int o1){
    int r, o2, o3, o4, o5, o6, o7;
    r = printRandoms(2, 9);
    // Here I have formed 6 different options which are incorrect answer.
    o2 = o1 + r;
    o3 = o1 - r;
    o4 = o1 + 10;
    o5 = o1 - 10;
    o6 = o1 + 2;
    o7 = o1 - 4;
    // Here storing all the incorrect answers in an array.
    int arr[6];
    arr[0] = o2;
    arr[1] = o3;
    arr[2] = o4;
    arr[3] = o5;
    arr[4] = o6;
    arr[5] = o7;
    // Randomizing the sequence in which they are stored in the array.
    randomize(arr, 6);
    // Now storing first 3 fake options in the main option array. As i have randomized the options earlier we don't know which kind of fake option will get stored.
    for (int i = 0; i < 3; i++)
    {
        *(ptr + i) = arr[i];
    }
    // storing the correct answer at the last.
    *(ptr + 3) = o1;
    // Now randomizing the original options array so that the correct options gets stored in any sequence.
    randomize(ptr, 4);
}

void printfile(FILE *ptr)
{
    char space[11] = "         ";
    char c;
    printf("Sr.no    NAME            ACCURACY(%%)         TIME(s)\n");
    for (int count, i = 0; i < 5; i++)
    {
        c = getc(ptr);
        if(c == EOF){
            printf("....................................................");
            break;
        }
        printf("%d        ", (i + 1));
        printf("%c", c);
        count = 0;
        while (c != ' ')
        {
            count++;
            c = getc(ptr);
            printf("%c", c);
        }
        for (; count <= 10; count++)
        {
            printf(" ");
        }
        printf("%s", space);


        count = 0;
        do
        {
            count++;
            c = getc(ptr);
            printf("%c", c);
        } while (c != ' ');

        for (; count <= 5; count++)
        {
            printf(" ");
        }
        printf("%s", space);

        do
        {
            c = getc(ptr);
            printf("%c", c);
        } while (c != '\n');
    }
}